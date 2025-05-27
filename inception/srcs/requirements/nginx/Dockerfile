
#Alpine install with Nginx
FROM alpine:3.20

#Set enviromental variables
ENV TERM xterm

#Commands to install needed packages
RUN apk update && apk upgrade  && apk add --no-cache nginx && apk add openssl && apk add envsubst

#Key storage for ssl
RUN mkdir -p /etc/nginx/ssl

#Actual Nginx config with data user
RUN adduser -D -H -S -G www-data www-data
RUN sed -i 's/user nginx;/user www-data;/' /etc/nginx/nginx.conf
RUN sed -i 's/keepalive_timeout 65;/keepalive_timeout 5;/' /etc/nginx/nginx.conf

#Copy the script and give it permissions
COPY tools/config.sh .
RUN chmod +x config.sh

#Copy the Nginx config file
COPY conf/nginx.conf .

#Clean cache
RUN rm -f /var/cache/apk/*

#Expose port to work with
EXPOSE 442

#Start Nginx
ENTRYPOINT [ "./config.sh"]
