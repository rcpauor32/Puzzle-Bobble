#include <math.h>
#include "../Globals.h"
#include "../Application.h"
#include "ModuleFadeToBlack.h"
#include "../ModuleRender.h"
#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_timer.h"

ModuleFadeToBlack::ModuleFadeToBlack()
{
	screen = { 0, 0, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE };
}

ModuleFadeToBlack::~ModuleFadeToBlack()
{}

bool ModuleFadeToBlack::Start()
{
	LOG("Preparing Fade Screen");
	SDL_SetRenderDrawBlendMode(App->render->renderer, SDL_BLENDMODE_BLEND);
	return true;
}


update_status ModuleFadeToBlack::Update()
{
	LOG("Fade Update start");
	if (start_time > 0)
	{
		Uint32 now = SDL_GetTicks() - start_time;
		float normalized = (float)now / (float)total_time;

		if (normalized > 1.0f)
			normalized = 1.0f;

		if (fading_in == false)
			normalized = 1.0f - normalized;

		LOG("%f", normalized);
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, (Uint8)(normalized * 255.0f));
		SDL_RenderFillRect(App->render->renderer, &screen);

		if (now >= total_time)
		{
			if (fading_in == true)
			{

				App->fade->module_out->Disable();
				App->fade->module_in->Enable();

				total_time += total_time;
				start_time = SDL_GetTicks();
				fading_in = false;
			}
			else
			{
				start_time = 0;
				already_fading = false;
			}
		}
	}
	LOG("Fade update end");
	return UPDATE_CONTINUE;
}

void ModuleFadeToBlack::FadeToBlack(Module* module_off, Module* module_on, float time)
{
	LOG("Fade to Black");
	if (already_fading == false) {
		already_fading = true;
		module_out = module_off;
		module_in = module_on;
		fading_in = true;
		start_time = SDL_GetTicks();
		total_time = (Uint32)(time * 0.5f * 1000.0f);
	}
}