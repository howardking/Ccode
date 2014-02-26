VPATH =  src include
#vpath = *.h include
CPPFLAGS = -I include

depend: compare.c
	gcc -M $(CPPFLAGS) $^ > $@
include depend

compare: compare.o
#	gcc -o $@ $<

%.o: %.c %.h
#	gcc $(CPPFLAGS) -c $^ #-o $@


.PHONY: clean
clean:
	rm *.o
	rm compare
