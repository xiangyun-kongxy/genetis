objout :=build
libout :=bin
binout :=bin

ifeq ($(shell uname), Linux)
    libext :=so
else 
    ifeq ($(shell uname), Darwin)
        libext :=dylib
    endif
endif

CXXFLAGS = -std=c++11 -fPIC -g -O2 -D_DEBUG -DDEBUG -Ithird_part/leveldb/include -Ithird_part/xml -Isrc -Isrc/include
LDFLAGS = -fPIC -Lthird_part/bin -L$(libout) -lstdc++ -lpthread -luuid -ldl
CC = gcc

.PHONY: all build clean clean_leveldb
all: build

include modules.mk

build: third_part/bin/libleveldb.a $(libraries) $(binaries)

third_part/bin/libleveldb.a: third_part/bin
	make out-static/libleveldb.a -C ./third_part/leveldb
	cp third_part/leveldb/out-static/libleveldb.a third_part/bin/
	make clean -C ./third_part/leveldb

third_part/bin:
	@mkdir -p third_part/bin

clean_leveldb:
	rm -rf third_part/bin

clean:
	rm -rf $(objout) $(libout) $(binout)


