#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

using namespace std;

class Texture {
public:
	Texture();
	~Texture();

	void Set_Renderer(SDL_Renderer* renderer);
	bool Load_From_Renderer_Text(TTF_Font* font, string texture_text, SDL_Color text_color);
	void Free();
	void Set_Color(Uint8 red, Uint8 green, Uint8 blue);
	void Set_Alpha(Uint8 alpha);
	void Draw(int x, int y, SDL_Rect* clip = NULL,
		double = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	virtual void Check(SDL_Event* event) {}
	virtual bool is_Pressed() { return false; }

	int Get_X();
	int Get_Y();
	int Get_Width();
	int Get_Height();

private:
	SDL_Texture* mTexture;
	SDL_Renderer* mRenderer;

	int mX;
	int mY;
	int mWidth;
	int mHeight;
};