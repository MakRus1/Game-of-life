#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Globals.h"
#include "Scene.h"
#include "Texture.h"
#include "Button.h"
#include "Board.h"

class Game : public Scene {
public:
	Game();

	void Draw() override;
	int Handle_event(SDL_Event* event) override;
	void Init_game() override;

private:
	TTF_Font* font;

	Texture** texture_array;

	Board* current_board;
	Board* next_board;
};