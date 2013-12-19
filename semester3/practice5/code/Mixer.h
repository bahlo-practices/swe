//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

#include "Scale.h"

//Der Mixer mischt, entleert und reinigt den Mischbehälrter
class Mixer : public Observer
{

public:
    Mixer();
	Mixer(Scale&);

    void drain();
    void mix(int seconds);
    void clean();
private:
    bool isEmpty;
	Scale& scale;

    void start();
    void stop();
    void open();
    void close();

	void update();
};

#endif
