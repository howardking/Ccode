LIBRARY = libio.a
DF      = df
AWK     = AWK

define hello
 @echo Creating $@...
 gcc -o $@ $^
endef

recursive := HELLO 

recursive += $(recursive) new stuff

missing_file:
	@touch $(LIBRARY)
	@ls -l | grep '$(LIBRARY)'
	@echo $(recursive)


#free-space := $(DF) . | $(AWK) 'NR == 2 { print $$4 }'

hello-world: hello-world.c
	@$(hello)
