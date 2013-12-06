CC=/usr/local/bin/g++-4.7
CFLAGS=-Wall
LDFLAGS=
# Default
SOURCES=main.cpp Control.cpp Dosingfeeder.cpp MixableRecipeBook.cpp Mixer.cpp Pounder.cpp Scale.cpp
EXECUTABLE=cocktail.o
# Tests
TESTSOURCES=test.cpp control.cpp dosingfeeder.cpp mixablerecipebook.cpp mixer.cpp pounder.cpp scale.cpp
TESTEXECUTABLE=test.o

all:
	${CC} ${CFLAGS} -o ${EXECUTABLE} ${SOURCES} Rezeptbuch.o

run: all
	./${EXECUTABLE}

test:
	${CC} ${CFLAGS} -o ${TESTEXECUTABLE} ${TESTSOURCES} Rezeptbuch.o && ./${TESTEXECUTABLE}

clean:
	rm `find . -name "*o" ! -name "Rezeptbuch.o"`
