
#Alpine install with Nginx
FROM alpine:3.20

#Set enviromental variables
ENV TERM xterm

#Commands to install needed packages
RUN apk update && apk upgrade  && apk add nginx && apk add openssl

#Key storage for ssl
RUN mkdir -p /etc/nginx/ssl

#Actual ssl command to set it up
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=ES/ST=Andalucia/L=Malaga/O=42/OU=42/CN=jcallejo.42.ft/UID=jcallejo"

#Directory for Nginx files
RUN mkdir -p /var/run/nginx

#Copy modified conf for Nginx conf file
COPY conf/nginx.conf /etc/nginx/nginx.conf

#Rights for ssl
#RUN [ "chmod", "755", "/var/www/html" ]
#RUN [ "chown", "-R", "www-data:www-data", "/var/www/html" ]

RUN [ "nginx", "-g", "daemon off;" ]
