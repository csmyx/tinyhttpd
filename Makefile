all: httpd client

httpd: httpd.c
	gcc -g -W -Wall -lpthread -o httpd httpd.c

client: client.c
	gcc -g -W -Wall -o $@ $^

clean:
	rm httpd
	rm client
