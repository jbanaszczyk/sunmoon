# Makefile
# $Id: Makefile,v 1.3 2006-07-12 10:00:13 hkuno Exp $
#----- rules -------------------------------------------------------------
RM=del
TARGET=sunmoon.exe
CFLAGS=-W3 -MD -GX -O1 -nologo
.cpp.obj:
	cl $(CFLAGS) -c $<
.cpp.exe:
	cl $(CFLAGS) -DTEST -Fotest.obj -Fe$*.exe $< astro.lib

#----- objects and sources -----------------------------------------------
SRC=vec3.cpp degree.cpp jday.cpp \
	acoord.cpp atime.cpp \
	planets.cpp
OBJ=$(SRC:.cpp=.obj)

#----- target ------------------------------------------------------------
all: $(TARGET)

# for Windows
sunmoon.exe: sunmoon.obj astro.lib
	cl $(CFLAGS) $**

astro.lib: $(OBJ)
	lib /OUT:$@ $**

$(OBJ): $*.h defs.h Makefile

#----- test --------------------------------------------------------------
test: jday.test atime.test acoord.test

jday.test: $*.exe
	perl -n -e "print if /^j/,/^g2000/;" jday.cpp >in.tmp
	jday <in.tmp >out.tmp
	diff -w in.tmp out.tmp

atime.test: $*.exe
	perl -n -e "print if /^1997/../^1978/;" atime.cpp >in.tmp
	atime <in.tmp >out.tmp
	diff -w in.tmp out.tmp

acoord.test: $*.exe
	perl -n -e "print if /^1996/../^1997.11/;" acoord.cpp >in.tmp
	acoord <in.tmp >out.tmp
	diff -w in.tmp out.tmp

jday.exe atime.exe acoord.exe: astro.lib

#----- util --------------------------------------------------------------
clean:
	$(RM) *.obj *.lib  *.o *.a  *.bak *.tmp

cleanall: clean
	$(RM) *.exe *.map *.out

#end
