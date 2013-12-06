//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

//Der Mixer mischt, entleert und reinigt den Mischbehälrter
class Mixer
{
    
public:
    //
    void clean();
    //
    Mixer();
    //
    void startDrain();
    //
    void startMixing();
    //
    void stopDrain();
    //
    void stopMixing();
    
private:
    //
    bool isCleaned;
    
    //
    bool istEmpty;
    
    
};

#endif
