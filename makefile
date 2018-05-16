objout :=build
libout :=lib
binout :=bin

CXXFLAGS = -std=c++11 -g -Werror -D_DEBUG -DDEBUG -Ithird_part/leveldb/include -Ithird_part/xml -Isrc -Isrc/include
LDFLAGS = -Lthird_part/lib -L$(libout) -L/opt/local/lib -lstdc++

.PHONY: all build clean clean_leveldb
all: build

include modules.mk

build: third_part/lib/libleveldb.a $(libraries) $(binaries)

third_part/lib/libleveldb.a: third_part/lib
	make out-static/libleveldb.a -C ./third_part/leveldb
	cp third_part/leveldb/out-static/libleveldb.a third_part/lib/
	make clean -C ./third_part/leveldb

third_part/lib:
	@mkdir -p third_part/lib

clean_leveldb:
	rm -rf third_part/lib

clean:
	rm -rf $(objout) $(libout) $(binout)


