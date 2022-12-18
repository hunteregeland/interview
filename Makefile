hash:
	make clean
	clear
	gcc -o hashtable hashtable.c
	./hashtable

hashprac1:
	make clean
	clear
	gcc -o hashprac hashprac1.c
	./hashprac

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

stack_:
	make clean
	clear
	gcc -o stack stack.c
	./stack

clean:
	clear
	rm -f hashtable
	ls -l