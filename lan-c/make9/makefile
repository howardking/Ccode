CC = gcc

libs_for_gnu = -lgun
normal_libs = 


objects = main.o

app: $(objects) 
ifeq ($(CC), gcc) 
	$(CC) -o app $(objects) 
else 
	$(CC) -o app $(objects) $(normal_libs)
endif 

main.o: main.c
	$(CC) -c main.c

.PHONY: app 
