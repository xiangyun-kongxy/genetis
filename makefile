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

CXXFLAGS = -std=c++11 -fPIC -fno-rtti -g -O2 -D_DEBUG -DDEBUG -Ithird_part/leveldb/include -Ithird_part/xml -Isrc -Isrc/include -I/usr/local/include/c++/6.4.0
LDFLAGS = -fPIC -Lthird_part/bin -L$(libout) -L/usr/local/lib64 -lstdc++ -lpthread -luuid -ldl
CC = g++

.PHONY: all build clean clean_leveldb
all: build

include modules.mk

build: third_part/bin/libleveldb.$(libext) $(libraries) $(binaries)

third_part/bin/libleveldb.$(libext): third_part/bin
	make -C ./third_part/leveldb
	cp third_part/leveldb/out-shared/libleveldb.$(libext) third_part/bin/
	make clean -C ./third_part/leveldb

third_part/bin:
	@mkdir -p third_part/bin

clean_leveldb:
	rm -rf third_part/bin

clean:
	rm -rf $(objout) $(libout) $(binout)


