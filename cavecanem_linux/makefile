MAKE = make

ifeq ($(NDDSHOME), )
all: 
	@echo "***************************************************************"
	@echo "The environment variable 'NDDSHOME' is not set!"
	@echo "To use this makefile you need to set NDDSHOME to the directory"
	@echo "where you have RTI Data Distribution Service installed."
	@echo "***************************************************************"
	@false
else
all:
	@echo "***************************************************************"
	@echo "You did not specifty the architecture you want to compile for,"
	@echo "please use one of the architectures defined in:"
	@echo "$(NDDSHOME)/lib."
	@echo "***************************************************************"
	@false
endif

clean: 
	$(MAKE) -C main clean
	$(MAKE) -C plugins clean
	rm -f *~

dist:
	$(MAKE) -C main clean
	$(MAKE) -C plugins clean
	tar -cvzf ../cavecanem_linux-0.2.tar.gz ../cavecanem_linux


i86Linux2.4gcc3.2.2: TARGET := i86Linux2.4gcc3.2.2

i86Linux2.4gcc3.2: TARGET := i86Linux2.4gcc3.2

i86Linux2.6gcc3.4.3: TARGET := i86Linux2.6gcc3.4.3

i86Linux2.6gcc4.1.1: TARGET := i86Linux2.6gcc4.1.1

i86Linux2.6gcc4.1.2: TARGET := i86Linux2.6gcc4.1.2

i86Linux2.6gcc4.4.3: TARGET := i86Linux2.6gcc4.4.3

i86Suse10.1gcc4.1.0: TARGET := i86Suse10.1gcc4.1.0

x64Linux2.4gcc3.2.3: TARGET := x64Linux2.6gcc4.1.0

x64Linux2.6gcc3.4.5: TARGET := x64Linux2.6gcc3.4.5

x64Linux2.6gcc4.1.1: TARGET := x64Linux2.6gcc4.1.1

x64Linux2.6gcc4.1.2: TARGET := x64Linux2.6gcc4.1.2

x64Linux2.6gcc4.3.2: TARGET := x64Linux2.6gcc4.3.2

x64Linux2.6gcc4.4.3: TARGET := x64Linux2.6gcc4.4.3

x64Suse10.1gcc4.1.0: TARGET := x64Suse10.1gcc4.1.0

export TARGET

i86% x64%: 
	$(MAKE) -C main
	$(MAKE) -C plugins


# i86Linux2.4gcc3.2.2 i86Linux2.4gcc3.2 i86Linux2.6gcc3.4.3 i86Linux2.6gcc4.1.1 i86Linux2.6gcc4.1.2 i86Linux2.6gcc4.4.3 i86Suse10.1gcc4.1.0 x64Linux2.4gcc3.2.3 x64Linux2.6gcc3.4.5 x64Linux2.6gcc4.1.1 x64Linux2.6gcc4.3.2 x64Linux2.6gcc4.4.3 x64Suse10.1gcc4.1.0: 	
# 	$(MAKE) -C main
# 	$(MAKE) -C plugins

