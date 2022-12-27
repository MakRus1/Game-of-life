#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Globals.h"

class Scene {
private:
	SDL_Renderer* mRenderer;

public:
	Scene();

	void set_Renderer(SDL_Renderer* renderer);
	SDL_Renderer* get_Renderer();
	void Clear();

	void Render();

	virtual void Init_menu() {}
	virtual void Init_info() {}
	virtual void Init_game() {}
	virtual void Draw() {}
	virtual int Handle_event(SDL_Event* event) { return -1; }
	
};