CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lm

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

Control.o: Control.cpp
	${CC} ${CFLAGS} -c Control.cpp

DosingFeeder.o: DosingFeeder.cpp
	${CC} ${CFLAGS} -c DosingFeeder.cpp

MixableRecipeBook.o: MixableRecipeBook.cpp
	${CC} ${CFLAGS} -c MixableRecipeBook.cpp

Mixer.o: Mixer.cpp
	${CC} ${CFLAGS} -c Mixer.cpp

Pounder.o: Pounder.cpp
	${CC} ${CFLAGS} -c Pounder.cpp

Scale.o: Scale.cpp
	${CC} ${CFLAGS} -c Scale.cpp

link:
	${CC} ${CFLAGS} main.o Rezeptbuch.o Control.o DosingFeeder.o MixableRecipeBook.o Mixer.o Pounder.o Scale.o Rezeptbuch.o ${LDFLAGS} -o myCocktail
