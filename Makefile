CC=gcc
EXEC=Laby
CFLAGS=-ansi -Wall -pedantic
LDFLAGS=-lMLV
OBJ=./Main.o ./Laby.o ./UnionFind.o ./Mur.o ./Affiche.o ./Resolution.o

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

./Main.o: ./include/Laby.h ./include/UnionFind.h ./include/Mur.h ./include/Affiche.h ./include/Resolution.h

./Laby.o: ./include/Laby.h

./UnionFind.o: ./include/UnionFind.h ./include/Laby.h

./Mur.o: ./include/Mur.h ./include/Laby.h ./include/UnionFind.h

./Affiche.o: ./include/Affiche.h ./include/Laby.h

./Resolution.o: ./include/Resolution.h ./include/Laby.h

%.o: ./src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)

install: $(EXEC)
	mkdir ./bin
	mv $(EXEC) ./bin/
	mv *.o ./bin/
	make mrproper

uninstall: mrproper
	rm -f ./bin/$(EXEC)
	rm -f ./bin/*.o
	rm -rf ./bin
