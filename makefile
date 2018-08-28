objout :=build
libout :=bin
binout :=bin

ifeq ($(shell uname), Linux)
flagext := -DLEVELDB_PLATFORM_POSIX -I/usr/local/include/c++/6.4.0 -std=gnu++11
libext :=so
uselib :=-lpthread -luuid -ldl
uselibpath :=-L/usr/local/lib64
else 
ifeq ($(shell uname), Darwin)
flagext := -DLEVELDB_PLATFORM_POSIX -DOS_MACOSX -Wno-deprecated-declarations -std=gnu++11 -stdlib=libc++
libext :=dylib
uselib :=
uselibpath :=
endif
endif

CXXFLAGS = $(flagext) -fPIC -g -Wall -Werror -Wno-unused-private-field -Wno-unused-variable -Wno-sign-compare -Ithird_part/leveldb/include -Ithird_part/leveldb -Ithird_part/xml -Isrc/frame -Isrc -Isrc/app/mind -Isrc/include -Isrc/util
LDFLAGS = -fPIC -L$(libout) $(uselibpath) $(uselib)
CC = g++

.PHONY: all build clean install
all: build

include modules.mk

build: $(libraries) $(binaries)

install: build
	echo $(libraries)
	echo $(binaries)

clean:
	rm -rf $(objout) $(libout) $(binout)


