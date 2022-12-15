hash:
	make clean
	clear
	gcc -o hashtable hashtable.c
	./hashtable

link:
	make clean
	clear
	gcc -o linkedlist linkedlist.c
	./linkedlist

clean:
	clear
	rm -f hashtable
	ls -l