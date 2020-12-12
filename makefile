server:
	make -C serverConnect4

install: $(server)
	./Certificate/generateCertificate.sh