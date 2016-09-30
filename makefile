strtheory: Stringy.c
	clang Stringy.c -o strtheory

run: strtheory
	./strtheory

clean:
	rm *~
