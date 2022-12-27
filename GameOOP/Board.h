#pragma once

#include <SDL.h>
#include <random>
#include "Globals.h"

class Board {
public:
	Board();

	void Draw_Board();
	void Tick();
	int Mod(int a, int b);
	int Neighbours(int x, int y);
	void Set_Renderer(SDL_Renderer* renderer);

	int get_Width();
	int get_Height();

	bool get_Cell(int x, int y);
	void set_Cell(int x, int y, bool condition);

private:
	SDL_Renderer* board_Renderer;
	int width, height;
	bool** board;
	bool** next_board;
};