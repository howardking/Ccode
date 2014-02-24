VPATH = ../include
#CFLAGS = -I ../include
caller:caller.o counter.o
	gcc $(CFLAGS) $^ -o $@

caller.o: caller.c counter.c
	gcc $(CFALGS) -c $<

counter.o: counter.c
	gcc -c $<

#%: %.cc
#	g++ -o $@ $<

.PHONY:clean
clean:
	rm caller *.o
