all: MouseClickExample MouseClickFun MouseClickDelay

MouseClickExample: MouseClickExample.c
	gcc -o MouseClickExample MouseClickExample.c -Wall -framework ApplicationServices

MouseClickFun: MouseClickFun.c
	gcc -o MouseClickFun MouseClickFun.c -Wall -framework ApplicationServices

MouseClickDelay: MouseClickDelay.c
	gcc -o MouseClickDelay MouseClickDelay.c -Wall -framework ApplicationServices

clean:
	rm -rf MouseClickExample MouseClickFun MouseClickDelay