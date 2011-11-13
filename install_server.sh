#!/bin/bash

apt-get install lighttpd php5-cgi --no-install-recommends
touch /tmp/php-fastcgi.socket
chmod 777 /tmp/php-fastcgi.socket
