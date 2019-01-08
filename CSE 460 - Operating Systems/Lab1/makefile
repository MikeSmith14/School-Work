HEADERS = display_message.h

default: message

display_message.o: display_message.cpp $(HEADERS)
	gcc -c display_message.cpp -o display_message.o

main.o: main.cpp $(HEADERS)
	gcc -c main.cpp -o main.o

message: main.o display_message.o
	g++ main.o display_message.o -o message

clean:
	-rm -f main.o
	-rm -f display_message.o

