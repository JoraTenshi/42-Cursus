
#Alpine install for MariaDB
FROM alpine:3.20

#Set enviromental variables
ENV TERM xterm

#MariaDB install packages
RUN apk update && apk upgrade && apk add --no-cache mariadb && apk add mariadb-common && apk add mariadb-client && apk add openrc

#Remote conections
RUN sed -i 's/#bind-address/bind-address/' /etc/my.cnf.d/mariadb-server.cnf && sed -i 's/skip-networking/#skip-networking/' /etc/my.cnf.d/mariadb-server.cnf

#Service manager
RUN openrc && touch /run/openrc/softlevel

#Directory creation for database and mysql permissions
RUN mkdir -p /run/mysqld && chown -R mysql /run/mysqld && /etc/init.d/mariadb setup && chown -R mysql /var/lib/mysql

#Copy config file and give it permissions
COPY conf/config.sh .
RUN chmod +x config.sh

#Cleanup
RUN rm -rf /var/cache/apk/*

#Expose port
EXPOSE 3306

#Run it all
ENTRYPOINT [ "./config.sh" ]
