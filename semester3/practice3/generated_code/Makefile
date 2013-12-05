CC=/usr/local/bin/g++-4.7
CFLAGS=-Wall
LDFLAGS=
SOURCES=main.cpp control.cpp dosingfeeder.cpp mixablerecipebook.cpp mixer.cpp pounder.cpp scale.cpp
EXECUTABLE=cocktail.o

all:
	${CC} ${CFLAGS} -o ${EXECUTABLE} ${SOURCES} Rezeptbuch.o

clean:
	rm `find . -name "*o" ! -name "Rezeptbuch.o"`
