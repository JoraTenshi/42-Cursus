# Alpine Linux with WordPress and PHP
FROM alpine:3.20

# Set environment variables
ENV TERM xterm
ENV WORDPRESS_CLI_VERSION 2.10.0

# Update and install packages
RUN apk update && apk upgrade
RUN apk add --no-cache \
    php php-phar php-curl php-mysqli php-tokenizer php-fpm \
    php-iconv php-mbstring php-openssl php-xml php-opcache php-json \
    mariadb-client curl

    
# Install WordPress CLI
RUN curl -o /usr/local/bin/wp -fL "https://github.com/wp-cli/wp-cli/releases/download/v${WORDPRESS_CLI_VERSION}/wp-cli-${WORDPRESS_CLI_VERSION}.phar" && \
    chmod +x /usr/local/bin/wp

# Configure PHP-FPM
RUN adduser -D -H -S -G www-data www-data && \
    sed -i 's/^listen = .*/listen = 0.0.0.0:9000/' /etc/php83/php-fpm.d/www.conf && \
    sed -i "s/user = nobody/user = www-data/" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s/group = nobody/group = www-data/" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s/memory_limit = 128M/memory_limit = 256M/" /etc/php83/php.ini && \
    ln -fs /usr/bin/php83 /usr/bin/php && \
    ln -s /usr/sbin/php-fpm83 /usr/sbin/php-fpm

# Copy the configuration script and make it executable
COPY tools/config.sh .
COPY tools/home.html .
RUN chmod +x config.sh

# Clean up
RUN rm -f /var/cache/apk/*

# Expose the port
EXPOSE 9000

# Start the service
ENTRYPOINT [ "./config.sh" ]
