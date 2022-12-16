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

dll:
	make clean
	clear
	gcc -o doublylinkedlist doublylinkedlist.c
	./doublylinkedlist

clean:
	clear
	rm -f hashtable
	ls -l