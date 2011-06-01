CC = g++

CFLAGS = -Wall -fpic 
INCLUDES =  -I../../main -I$(NDDSHOME)/include -I$(NDDSHOME)/include/ndds -I../../shared/hyperic_sigar-1.6.4/include -DRTI_UNIX -DRTI_LINUX


SOURCES = net_load.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)

LDFLAGS = -shared 
libs_32 = -L../../shared/hyperic_sigar-1.6.4/lib -lsigar-x86-linux
libs_64 = -L../../shared/hyperic_sigar-1.6.4/lib -lsigar-amd64-linux


ifneq ($(TARGET), )
all: $(TARGET)
else
all:
	@echo "***************************************************************"
	@echo "You did not specifty the architecture you want to compile for,"
	@echo "please use one of the architectures defined in:"
	@echo "$(NDDSHOME)/lib."
	@echo "***************************************************************"
	@false
endif


i86%: $(OBJECTS)
	@echo "Compiling plugin for $(TARGET)"
	$(CC) $(LDFLAGS) -o libnet_load.so net_load.o $(libs_32)

x64%: $(OBJECTS)
	$(CC) $(LDFLAGS) -o libnet_load.so net_load.o $(libs_64)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f *.o *.so *~
