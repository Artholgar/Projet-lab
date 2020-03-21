CC=gcc
EXEC=Laby
CFLAGS=-ansi -Wall -pedantic
LDFLAGS=-lMLV
OBJ=./regen/Main.o ./regen/Laby.o ./regen/UnionFind.o ./regen/Mur.o ./regen/Affiche.o ./regen/Resolution.o

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

./regen/Main.o: ./include/Laby.h ./include/UnionFind.h ./include/Mur.h ./include/Affiche.h ./include/Resolution.h

./regen/Laby.o: ./include/Laby.h

./regen/UnionFind.o: ./include/UnionFind.h ./include/Laby.h

./regen/Mur.o: ./include/Mur.h ./include/Laby.h ./include/UnionFind.h

./regen/Affiche.o: ./include/Affiche.h ./include/Laby.h

./regen/Resolution.o: ./include/Resolution.h ./include/Laby.h

./regen: 
	mkdir ./regen

./regen/%.o: ./src/%.c ./regen
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f ./regen/*.o
	rm -rf ./regen

mrproper: clean
	rm -f $(EXEC)

install: $(EXEC)
	mkdir ./bin
	mv $(EXEC) ./bin/$(EXEC)
	make mrproper

uninstall: mrproper
	rm -f ./bin/$(EXEC)
	rm -rf ./bin
