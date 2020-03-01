CC=g++
LIBS=-lm

volimage: volImage.o volDriver.o VolImage.h
	$(CC) *.o VolImage.h -o volimage $(LIBS)

volImage.o: VolImage.cpp
	$(CC) VolImage.cpp -c

volDriver.o: VolDriver.cpp
	$(CC) VolDriver.cpp -c


clean:
	@rm -f *.o

install:
	@mv volimage ~/bin

run:
	./volimage
