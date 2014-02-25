VPATH =  src include
#vpath = *.h include
CPPFLAGS = -I include

compare: compare.o
#	gcc -o $@ $<

%.o: %.c %.h
#	gcc $(CPPFLAGS) -c $^ #-o $@

.PHONY: clean
clean:
	rm *.o
	rm compare

