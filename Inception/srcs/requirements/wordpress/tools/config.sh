#!/bin/sh
# Wait for the database to be available
while ! mariadb -hmariadb -u$DB_USER -p$DB_PASS $DB_NAME &>/dev/null; do 
	echo -e "\033[1;33mWaiting for the database to be available...\033[0m"
	sleep 5
done

# Check if WordPress is installed
if ! [ -f /domains/$DOMAIN_NAME/public_html/wp-config.php ]; then

    # Create WordPress folder
    echo -e "\033[1;32mCreating WordPress folder at /domains/$DOMAIN_NAME/public_html\033[0m"
    mkdir -p /domains/$DOMAIN_NAME/public_html
    cd /domains/$DOMAIN_NAME/public_html
    echo -e "\033[1;32mSetting permissions for WordPress folder...\033[0m"
    chown -R www-data:www-data /domains/$DOMAIN_NAME/public_html

    # Download WordPress
    echo -e "\033[1;32mDownloading WordPress...\033[0m"
    wp core download --allow-root

    # Generate WordPress config file
   echo -e "\033[1;32mGenerating WordPress configuration file...\033[0m"
    wp config create \
    --dbname="$DB_NAME" \
    --dbuser="$DB_USER" \
    --dbpass="$DB_PASS" \
    --dbhost=mariadb \
    --dbcharset=utf8mb4 \
    --dbcollate=utf8mb4_general_ci \
    --extra-php <<PHP
    define('AUTOMATIC_UPDATER_DISABLED', true);
    define('WP_LIMIT_LOGIN_ATTEMPTS', true);
    define('WP_DEBUG', true);
    define('WP_DEBUG_LOG', true);
    define('WP_DEBUG_DISPLAY', false);
    define('WP_AUTO_UPDATE_CORE', 'minor');
    define('WP_POST_REVISIONS', false);
    define('EMPTY_TRASH_DAYS', 7);
    define('WP_MEMORY_LIMIT', '256M');

PHP

    # Generate WordPress salts for security.
    wp config shuffle-salts --allow-root

    # Install WordPress
    echo -e "\033[1;32mInstalling WordPress...\033[0m"
    exit_code=1
    while [ "$exit_code" -ne 0 ]; do
        wp core install --url="$DOMAIN_NAME" --title="$DOMAIN_NAME" --admin_user="$ADMIN_USER" --admin_password="$ADMIN_PASS" --admin_email="$ADMIN_EMAIL" --allow-root
        exit_code=$?
        if [ "$exit_code" -ne 0 ]; then
            echo -e "\033[1;31mFailed to install WordPress. Retrying in 5 seconds...\033[0m"
            sleep 5
        fi
    done

    # Create example user
    echo -e "\033[1;32mCreating an example user...\033[0m"
    wp user create "$USER_NAME" "$USER_EMAIL" --role=author --user_pass="$USER_PASS" --allow-root

    # Update WordPress plugins
    echo -e "\033[1;32mUpdating WordPress plugins...\033[0m"
    wp plugin update --all --allow-root

        # Rewrite permalinks
    echo -e "\033[1;32mRewriting WordPress permalinks...\033[0m"
    wp rewrite structure '/%postname%/' --hard

    # Check if post with ID 4 exists
    if ! wp post exists 4 --allow-root; then
        # Create a new main page
        echo -e "\033[1;32mCreating a new main page...\033[0m"
        wp post create /home.html --post_status=publish --post_type=page --post-status=publish --comment_status=open --post_title=home --allow-root

        # Delete Sample Page
        echo -e "\033[1;32mDeleting Sample Page...\033[0m"
        wp post delete 2 --force --allow-root
    fi

    else
    	echo -e "\033[1;32mWordPress is already installed. Skipping installation...\033[0m"
    	cd /domains/$DOMAIN_NAME/public_html
    fi

# Get the ID of the "home" page
HOME_ID=$(wp post list --post_type=page --pagename=home --field=ID --allow-root)

# Set the front page to be the "home" page
wp option update show_on_front page --allow-root
wp option update page_on_front $HOME_ID --allow-root

# Start PHP-FPM
echo -e "\033[1;32mStarting PHP-FPM...\033[0m"
php-fpm -FR
