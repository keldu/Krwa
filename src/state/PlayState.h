#pragma once

#include "State.h"

class PlayState : public State{
public:

    PlayState(World&,Render&,Player&);

protected:

	void init();
	void loop();
    void logic();

};
