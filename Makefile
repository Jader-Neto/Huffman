make:
	gcc src/main.c src/list.c -Iinc -o build/Ezip.exe

run:
	./build/Ezip.exe

clean:
	rm -rf build
