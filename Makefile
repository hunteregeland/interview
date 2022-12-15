hash:
	make clean
	clear
	gcc -o hashtable hashtable.c
	./hashtable

clean:
	clear
	rm -f hashtable
	ls -l