#!/bin/sh

if [ ! -f /etc/nginx/ssl/inception.key ]; then
	echo -e "\033[1;33mSSL certificate not found, creating one for jcallejo.42.fr\033[0m"
	openssl req -x509 -nodes -days 42 -newkey rsa:2048 -keyout /etc/nginx/ssl/$DOMAIN_NAME.key -out /etc/nginx/ssl/$DOMAIN_NAME.crt -subj\
	"/c=ES/ST=Andalucia/L=Malaga/O=42Malaga/OU=cadet/CN=$DOMAIN_NAME"

else
	echo -e "\033[1;32mUsing existing SSL certificate for jcallejo.42.fr[0m"

fi


