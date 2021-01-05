service mysql start

# Changing the access rights
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*

# Creation of the website folder
mkdir /var/www/mywebsite

# SSL Configuration and Generation
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 90 -nodes -out /etc/nginx/ssl/mywebsite.pem -keyout /etc/nginx/ssl/mywebsite.key -subj "/C=FR/ST=Ile de France/L=Paris/O=Ecole 42/OU=bdruez/CN=mywebsite"

# MYSQL Configuration
mysql -u root -e "CREATE DATABASE wordpress;"
mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"
mysql -u root -e "CREATE USER 'user42'@'localhost' IDENTIFIED BY 'user42'"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'user42'@'localhost';"
mysql -u root -e "FLUSH PRIVILEGES;"
mysql -u root -e "EXIT;"

# NGINX Configuration
mv ./tmp/nginx-conf /etc/nginx/sites-available/mywebsite
ln -s /etc/nginx/sites-available/mywebsite /etc/nginx/sites-enabled/mywebsite
rm -rf /etc/nginx/sites-enabled/default

# PHPMYADMIN Configuration
mkdir /var/www/mywebsite/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz --strip-components 1 -C /var/www/mywebsite/phpmyadmin
mv ./tmp/phpmyadmin.inc.php /var/www/mywebsite/phpmyadmin/config.inc.php

# WORDPRESS Configuration
cd /tmp/
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/mywebsite
mv /tmp/wp-config.php /var/www/mywebsite/wordpress

service php7.3-fpm start
service nginx start

bash
