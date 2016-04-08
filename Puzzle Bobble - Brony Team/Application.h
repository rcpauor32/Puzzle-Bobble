#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 11

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModulePlayer;
class Module;
class ModuleFadeToBlack;
class ModuleSceneMainMenu;
class ModuleScene1to3;
class ModuleScene4to6;
class ModuleParticles;
class ModuleAudio;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleSceneMainMenu* scene_mainmenu;
	ModuleScene1to3* scene_1to3;
	ModuleScene4to6* scene_4to6;
	ModuleParticles* particles;
	ModuleAudio* audio;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__