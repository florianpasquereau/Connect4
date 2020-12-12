#!/bin/bash

CERTIFICATE_NAME=${PWD}/Certificate/connect4
RSA_LENGTH=2048
DAYS=365

openssl req \
	-newkey rsa:$RSA_LENGTH \
	-nodes \
	-keyout $CERTIFICATE_NAME.key \
	-x509 \
	-days $DAYS \
	-out $CERTIFICATE_NAME.crt

cat $CERTIFICATE_NAME.crt \
	$CERTIFICATE_NAME.key \
	> $CERTIFICATE_NAME.pem

rm $CERTIFICATE_NAME.crt \
	$CERTIFICATE_NAME.key

