include foo.mk
-include i-may-not-exist.mk
$(warning Finished include)

foo.mk: bar.mk
	m4 --define=FILENAME=$@ bar.mk > $@
please:
	echo $(MAKE-VERSION)
	echo $(CURDIR)
	echo $(MAKEFILE_LIST)
	echo $(MAKECMDGOALS)
	echo $(.VARIABLE)
	
