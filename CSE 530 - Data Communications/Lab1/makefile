HEADERS = multiply.h

default: multiply

print.o: print.cpp $(HEADERS)
	gcc -c print.cpp -o print.o

multiply.o: multiply.cpp $(HEADERS)
	gcc -c multiply.cpp -o multiply.o

main.o: main.cpp $(HEADERS)
	gcc -c main.cpp -o main.o

multiply: main.o multiply.o print.o
	g++ main.o print.o multiply.o -o multiply

clean:
	-rm -f print.o
	-rm -f main.o
	-rm -f multiply.o
	-rm -f multiply
