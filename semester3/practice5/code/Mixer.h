//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

//Der Mixer mischt, entleert und reinigt den Mischbehälrter
class Mixer
{

public:
    Mixer();
    void drain();
    void mix(int seconds);
    void clean();
private:
    bool isCleaned;

    void start();
    void stop();
    void open();
    void close();
};

#endif
