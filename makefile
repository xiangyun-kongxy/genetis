objout :=build
libout :=bin
binout :=bin

ifeq ($(shell uname), Linux)
flagext := -DLEVELDB_PLATFORM_POSIX -I/usr/local/include/c++/6.4.0
libext :=so
uselib :=-lpthread -luuid -ldl
uselibpath :=-L/usr/local/lib64
else 
ifeq ($(shell uname), Darwin)
flagext := -DLEVELDB_PLATFORM_POSIX -DOS_MACOSX -Wno-deprecated-declarations
libext :=dylib
uselib :=
uselibpath :=
endif
endif

CXXFLAGS = $(flagext) -std=c++11 -fPIC -g -Wall -Werror -Wno-unused-private-field -Wno-unused-variable -Wno-sign-compare -Ithird_part/leveldb/include -Ithird_part/leveldb -Ithird_part/xml -Isrc -Isrc/include
LDFLAGS = -fPIC -L$(libout) $(uselibpath) $(uselib) -lstdc++
CC = g++

.PHONY: all build clean
all: build

include modules.mk

build: $(libraries) $(binaries)

clean:
	rm -rf $(objout) $(libout) $(binout)


