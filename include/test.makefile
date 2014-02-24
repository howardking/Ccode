#This is a Makefile uses other name
cc = hello 
cccc = $(cc) world
target:
	@echo $(cccc)
