#! /bin/sh

openssl genrsa -des3 -passout pass:x -out server.pass.key 2048

openssl rsa -passin pass:x -in server.pass.key -out server.key

rm server.pass.key

openssl req -new -key server.key -out server.csr

openssl x509 -req -sha256 -days 365 -in server.csr -signkey server.key -out server.crt

git clone https://github.com/eidheim/Simple-Web-Server.git && sudo mv -i * Simple-Web-Server; 

cd Simple-Web-Server;

juci .&
