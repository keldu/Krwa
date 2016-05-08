#pragma once

#include "objects/World.h"
#include "gl/Render.h"
#include "logic/Player.h"

class State{
public:
    State(World&, Render&, Player&);

	bool running;

	void start();

protected:
	virtual void init() = 0;
	virtual void loop() = 0;

    Player* m_player;
	World* m_world;
	Render* m_render;
};
