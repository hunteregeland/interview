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

queue_:
	make clean
	clear
	gcc -o queue queue.c
	./queue

atoi_:
	make clean
	clear
	gcc -o atoi atoi2.c
	./atoi

bubble:
	make clean
	clear
	gcc -o bubblesort bubblesort.c
	./bubblesort

clean:
	clear
	rm -f hashtable; rm -f bubblesort; rm -f atoi; rm -f hashprac; rm -f hashprac1; rm -f linkedlist; rm -f queue; rm -f stack
	ls -l