#include "Game.h"

enum Texture_Index {
	TEXTURE_INDEX_BACK_TO_MENU,
	TEXTURE_INDEX_TOTAL
};

Game::Game() : font(NULL), texture_array(NULL), current_board(NULL), next_board(NULL) {

}

void Game::Init_game() {
	current_board = new Board;
	next_board = new Board;

	current_board->Set_Renderer(get_Renderer());
	next_board->Set_Renderer(get_Renderer());

	font = TTF_OpenFont("Vogue Bold.ttf", 60);

	SDL_Color red = { 255, 25, 25, 200 };

	texture_array = new Texture * [TEXTURE_INDEX_TOTAL];

	texture_array[TEXTURE_INDEX_BACK_TO_MENU] = new Button;

	for (int i = 0; i < TEXTURE_INDEX_TOTAL; i++) {
		texture_array[i]->Set_Renderer(get_Renderer());
	}

	texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Load_From_Renderer_Text(font, "Back to menu", red);
	TTF_CloseFont(font);
}

void Game::Draw() {
	current_board->Draw_Board();
	current_board->Tick();
	texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Get_Width()) - 10,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Get_Height()) - 10);
	SDL_Delay(50);
}

int Game::Handle_event(SDL_Event* event) {
	switch (event->type) {
	case SDL_QUIT:
		return 0;
		break;
	case SDL_MOUSEBUTTONDOWN:
		texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Check(event);

		if (texture_array[TEXTURE_INDEX_BACK_TO_MENU]->is_Pressed()) {
			return 1;
		}
	}
	return -1;
}