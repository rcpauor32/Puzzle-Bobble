#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define NUM_ARROW_SPRITES 130

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

public:
	double player_angle;

	SDL_Texture* graphics = nullptr;
	SDL_Rect arrow[64];
	SDL_Point arrow_center;
	int arrow_pos = 0;

	iPoint position;

};

#endif