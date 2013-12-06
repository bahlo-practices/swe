CC=g++
CFLAGS=-Wall
LDFLAGS=
SOURCES=Control.cpp DosingFeeder.cpp MixableRecipeBook.cpp Mixer.cpp Pounder.cpp Scale.cpp
MAIN=main.cpp
EXECUTABLE=cocktail.o
INCLUDE=Rezeptbuch.o
# Tests
TEST=test.cpp
TESTEXECUTABLE=test.o

all:
	${CC} ${CFLAGS} -o ${EXECUTABLE} ${MAIN} ${SOURCES} ${INCLUDE}

run: all
	./${EXECUTABLE}

test:
	${CC} ${CFLAGS} -o ${TESTEXECUTABLE} ${TEST} ${TESTSOURCES} ${INCLUDE} && ./${TESTEXECUTABLE}

clean:
	rm `find . -name "*o" ! -name "Rezeptbuch.o"`
