
compile: clean manager.exe

manager.exe: manager.o
	gcc $^ -o $@
	./manager

manager.o: manager.c
	gcc -c -g $^ -o $@

clean:
	rm -f *.o *.exe
