all: add.so
add.so:
	gcc -shared -fPIC -mavx -o add.so add.c
clean:
	rm -f add.so
