define parent
	echo "parent has two paramenters: $1,$2"
	$(call child,$1)
endef

   define child
	echo "child has one parameter: $1"
	echo "but child can also see parent's second parameter: $2"
   endef

scoping_issue:
	@$(call parent,one,two)

words := he the hen other the%
get-the:
	@echo he matches: $(filter he, $(words))
	@echo %he matches: $(filter %he, $(words))
	@echo he% matches: $(filter he%, $(words))
	@echo %he% matches: $(filter %he%, $(words))

find-tree:
	# PWD = $(PWD)
	# $(findstring /home/howard/Ccode/Makefile/make5,$(PWD))
	# $(findstring /home/git,$(PWD))

sources := count_words.c counter.c lexer.c
objects := $(subst .c,.o,$(sources))
subst-test:
	@echo $(objects)

CURRENT_PATH := $(subst /, ,$(HOME))
words:
	@echo My HOME patch has $(words $(CURRENT_PATH)) directories.
	@echo $(HOME)
	@echo $(MAKE_VERSION)

version_list := $(subst ., ,$(MAKE_VERSION))
minor_version:= $(word 2,$(version_list))
minor_vers2  := $(word $(words $(MAKEFILE_LIST)),$(MAKE_VERSION))

minor_ver:
	# echo $(MAKE_VERSION)
	# echo $(MAKEFILE_LIST)
	@echo $(minor_version)
	@echo $(minor_vers2)

stdout := $(shell echo normal message)
stderr := $(shell echo error message 1>&2)
shell-value:
	# $(stdout)
	# $(stderr)

emacsexist := $(wildcard ~/.emacs)
emacs_e:
	#echo $(emacsexist)

sourcedirs := $(sort				\
		$(notdir				\
		  $(shell find ../.. -name '*.c')))
source-dirs:
	@echo $(sourcedirs)

#$(call find-program, wildcard-pattern)
find-program = $(wildcard					\
		  $(addsuffix /$1,				\
		     $(sort					\
			$(subst :, ,				\
			   $(subst ::, :.:,			\
			      $(patsubst :%,.:%,		\
				 $(patsubst %:,%:.,$(PATH))))))))
find:
	@echo $(call find-program,*)
	@echo $(words $(call find-program,*))

# $(call find-program, filter-pattern)
#find-filter = $(filter $1
#		$(wildcard					\
#		  $(addsuffix /*,				\
#		     $(sort					\
#			$(subst :, ,				\
#			   $(subst ::, :.:,			\
#			      $(patsubst :%,.:%,		\
#				 $(patsubst %:,%:.,$(PATH)))))))))
#find2:
#	@echo $(call find-filter,%)
#	@echo $(words $(call find-filter,%))
