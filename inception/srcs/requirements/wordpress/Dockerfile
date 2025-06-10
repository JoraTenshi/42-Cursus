#Alpine for Wordpress
FROM alpine:3.20

#Enviromental variables setting
ENV TERM xterm
ENV WORDPRESS_CLI_VERSION=2.10.0
ENV PHP_VERSION=8.2

#Necesarry install of packages
RUN apk upgrade && apk upgrade && apk add --no-cache php${PHP_VERSION} && apk add php${PHP_VERSION}-phar && apk add php${PHP_VERSION}-phar && apk add php${PHP_VERSION}-curl \
    apk add php${PHP_VERSION}-mysqli && apk add php${PHP_VERSION}-tokenizer && apk add php${PHP_VERSION}-fpm && apk add php${PHP_VERSION}-iconv && apk add php${PHP_VERSION}-mbstring \
    apk add php${PHP_VERSION}-openssl && apk add php${PHP_VERSION}-xml && apk add php${PHP_VERSION}-opcache && apk add php${PHP_VERSION}-opcache && apk add php${PHP_VERSION}-json \
    apk add mariadb-client && apk add curl

#Install wordpress per se
RUN curl -o /usr/local/bin/wp - fL "https://github.com/wp-cli/wp-cli/releases/download/v{$WORDPRESS_CLI_VERSION}/wp-cli-${WORDPRESS_CLI_VERSION}.phar" && chmod +x /usr/local/bin/wp

#Install and configure PHP
RUN adduser -D -H -S -G www-data www-data && sed -i 's/^listen = s*/listen = 0.0.0.0:9000' /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s/user = nobody/user = www-data/" /etc/php${PHP_VERSION}/php-fpm.d/www-conf && sed -i "s/group = nobody/group = www-data" /etc/php${PHP_VERSION}/php-fpm.d/www-conf && \
    sed -i "s/memory_limit = 128M/memory_limit = 256M" /etc/php${PHP_VERSION}/php.ini && ln -fs /usr/bin/php${PHP_VERSION} /usr/bin/php && ln -s /usr/bin/php-fpm${PHP_VERSION} /usr/bin/php-fpm

#Get the config script
COPY tools/config.sh .
COPY tools/home.html .
RUN chmod +x config.sh

#Cleanup
RUN rm -rf /var/cache/apk/*

#Expose port
EXPOSE 9000

#Start the service
ENTRYPOINT [ "./config.sh" ]
