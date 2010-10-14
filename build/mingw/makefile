projectname     = garnet
configuration   = debug

intdir      = ./objs
outdir      = ../../lib

srcdir      = ../../src


src0        = $(srcdir)/galloc.c
src1        = $(srcdir)/glinkedlist.c
src2        = $(srcdir)/glogger.c
src3        = $(srcdir)/gstring.c

obj0        = $(intdir)/galloc.o
obj1        = $(intdir)/glinkedlist.o
obj2        = $(intdir)/glogger.o
obj3        = $(intdir)/gstring.o

objs        = $(obj0) $(obj1) $(obj2) $(obj3)

target_ext  = a
target      = $(outdir)/lib$(projectname).$(target_ext)


# 
# コマンドカテゴリ
# 
cc      = gcc
cflags  = -O2 -Wall -Wextra -Wformat=2 -Wcast-qual -Wcast-align \
          -Wfloat-equal -Wpointer-arith -fsigned-char \
          -I"../../include" -I"../Win32/garnet_static" \
          -D_DEBUG

rm      = rm
rmflags = -v


ar      = ar
arflags = -srcv


# 
# レシピ
# 
.PHONY: all
all: $(target)

$(target): $(objs)
	$(ar) $(arflags) $@ $(objs)

$(obj0): $(src0)
	@if [ ! -d $(intdir) ]; then mkdir -vp $(intdir); fi
	$(cc) $(cflags) -c $< -o $@

$(obj1): $(src1)
	@if [ ! -d $(intdir) ]; then mkdir -vp $(intdir); fi
	$(cc) $(cflags) -c $< -o $@

$(obj2): $(src2)
	@if [ ! -d $(intdir) ]; then mkdir -vp $(intdir); fi
	$(cc) $(cflags) -c $< -o $@

$(obj3): $(src3)
	@if [ ! -d $(intdir) ]; then mkdir -vp $(intdir); fi
	$(cc) $(cflags) -c $< -o $@


.PHONY: clean
clean:
	$(rm) $(rmflags) $(target) $(objs)


.PHONY: build
build: all


.PHONY: rebuild
rebuild: clean all
