FROM debian:buster

RUN apt-get update && apt-get install -y wget && apt-get install -y vim
RUN apt-get install -y php7.3-fpm php7.3-mysql php7.3-common php7.3-curl php7.3-mbstring php7.3-json php7.3-ctype
RUN apt-get install -y nginx
RUN apt-get install -y mariadb-server mariadb-client
EXPOSE 3000
COPY ./srcs/init.sh ./
COPY ./srcs/nginx-conf ./tmp/nginx-conf
COPY ./srcs/phpmyadmin.inc.php ./tmp/phpmyadmin.inc.php
COPY ./srcs/wp-config.php ./tmp/wp-config.php

CMD bash init.sh
