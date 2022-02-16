hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/DoubleLinkedList.o -c ./src/DoubleLinkedList.cpp
	g++ -I ./include/ -o ./bin/Test  ./lib/Node.o ./lib/DoubleLinkedList.o ./src/Test.cpp
calistir:
	./bin/Test