OBJECT = linkedlist.o
SRC = linkedlist.c

CC = gcc

TARGET = linkedlist

$(TARGET) : $(OBJECT)
		$(CC) -o $(TARGET) $(OBJECT)

$(OBJECT) : $(SRC)
		$(CC) -c $(SRC)

clear:
	rm $(OBJECT) $(TARGET)

edit:
	vim $(SRC)
