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
flagext := -DLEVELDB_PLATFORM_POSIX -DOS_MACOSX -Wno-deprecated-declarations -std=gnu++11 -stdlib=libc++ -I/usr/local/lib/wx/include/osx_cocoa-unicode-3.1 -I/usr/local/include/wx-3.1 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__
libext :=dylib
uselib := -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL -lwx_osx_cocoau_xrc-3.1 -lwx_osx_cocoau_html-3.1 -lwx_osx_cocoau_qa-3.1 -lwx_osx_cocoau_adv-3.1 -lwx_osx_cocoau_core-3.1 -lwx_baseu_xml-3.1 -lwx_baseu_net-3.1 -lwx_baseu-3.1
uselibpath := -L/usr/local/lib
endif
endif

CXXFLAGS = $(flagext) -fPIC -g -Wall -Werror -Wno-unused-private-field -Wno-unused-variable -Wno-sign-compare -Ithird_part/leveldb/include -Ithird_part/leveldb -Ithird_part/xml -Isrc/frame -Isrc -Isrc/app/mind -Isrc/include -Isrc/util -Isrc/app
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


