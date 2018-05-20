objout :=build
libout :=bin
binout :=bin

ifeq ($(shell uname), Linux)
libext :=so
uselib :=-lpthread -luuid -ldl
uselibpath :=-L/usr/local/lib64
else 
ifeq ($(shell uname), Darwin)
libext :=dylib
uselib :=
uselibpath :=
endif
endif

CXXFLAGS = -std=c++11 -fPIC -g -Wall -Werror -Wno-unused-variable -Wno-sign-compare -DDEBUG -DLEVELDB_PLATFORM_POSIX -Ithird_part/leveldb/include -Ithird_part/leveldb -Ithird_part/xml -Isrc -Isrc/include -I/usr/local/include/c++/6.4.0
LDFLAGS = -fPIC -pthread -Lthird_part/bin -L$(libout) $(uselibpath) $(uselib) -lstdc++
CC = g++

.PHONY: all build clean
all: build

include modules.mk

build: $(libraries) $(binaries)

clean:
	rm -rf $(objout) $(libout) $(binout)


