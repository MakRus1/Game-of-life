#include "Info.h"

enum Texture_Index {
	TEXTURE_INDEX_TITLE,
	TEXTURE_INDEX_INFORMATION,
	TEXTURE_INDEX_INFO_EN_0,
	TEXTURE_INDEX_INFO_EN_1,
	TEXTURE_INDEX_INFO_EN_2,
	TEXTURE_INDEX_INFO_RU_0,
	TEXTURE_INDEX_INFO_RU_1,
	TEXTURE_INDEX_INFO_RU_2,
	TEXTURE_INDEX_BACK_TO_MENU,
	TEXTURE_INDEX_TOTAL
};

Info::Info() : title_font(NULL), information_font(NULL), texture_array(NULL) {
	
}

void Info::Init_info() {
	title_font = TTF_OpenFont("Vogue Bold.ttf", 80);
	information_font = TTF_OpenFont("Vogue Bold.ttf", 60);
	info_font = TTF_OpenFont("Vogue Bold.ttf", 40);

	SDL_Color white = { 255, 255, 255, 255 };

	texture_array = new Texture * [TEXTURE_INDEX_TOTAL];

	texture_array[TEXTURE_INDEX_TITLE] = new Texture;
	texture_array[TEXTURE_INDEX_INFORMATION] = new Texture;
	texture_array[TEXTURE_INDEX_INFO_EN_0] = new Texture;
	texture_array[TEXTURE_INDEX_INFO_EN_1] = new Texture;
	texture_array[TEXTURE_INDEX_INFO_EN_2] = new Texture;
	texture_array[TEXTURE_INDEX_INFO_RU_0] = new Texture;
	texture_array[TEXTURE_INDEX_INFO_RU_1] = new Texture;
	texture_array[TEXTURE_INDEX_INFO_RU_2] = new Texture;
	texture_array[TEXTURE_INDEX_BACK_TO_MENU] = new Button;

	for (int i = 0; i < TEXTURE_INDEX_TOTAL; i++) {
		texture_array[i]->Set_Renderer(get_Renderer());
	}

	texture_array[TEXTURE_INDEX_TITLE]->Load_From_Renderer_Text(title_font, "Game of Life", white);
	TTF_CloseFont(title_font);

	string info_string_en_0 = "In the Game of Life there are two simple rules: ";
	string info_string_en_1 = "1. If a dead cell has exactly three living neighbours, then life is born in it";
	string info_string_en_2 = "2. If a living cell does not have two or three living neighobours, then the cell dies";

	string info_string_ru_0 = "В игре жизнь всего два простых правила: ";
	string info_string_ru_1 = "1. Если мертвая клетка имеет ровно трех живых соседей, то в ней зарождается жизнь";
	string info_string_ru_2 = "2. Если у живой клетки не два или три живых соседа, то клетка умирает";

	texture_array[TEXTURE_INDEX_INFORMATION]->Load_From_Renderer_Text(information_font, "Information about game:", white);
	texture_array[TEXTURE_INDEX_INFO_EN_0]->Load_From_Renderer_Text(info_font, info_string_en_0, white);
	texture_array[TEXTURE_INDEX_INFO_EN_1]->Load_From_Renderer_Text(info_font, info_string_en_1, white);
	texture_array[TEXTURE_INDEX_INFO_EN_2]->Load_From_Renderer_Text(info_font, info_string_en_2, white);
	texture_array[TEXTURE_INDEX_INFO_RU_0]->Load_From_Renderer_Text(info_font, info_string_ru_0, white);
	texture_array[TEXTURE_INDEX_INFO_RU_1]->Load_From_Renderer_Text(info_font, info_string_ru_1, white);
	texture_array[TEXTURE_INDEX_INFO_RU_2]->Load_From_Renderer_Text(info_font, info_string_ru_2, white);
	texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Load_From_Renderer_Text(information_font, "Back to menu", white);
	TTF_CloseFont(information_font);
}

void Info::Draw() {
	texture_array[TEXTURE_INDEX_TITLE]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_TITLE]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_TITLE]->Get_Height()) / 2 - 300);
	texture_array[TEXTURE_INDEX_INFORMATION]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_INFORMATION]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_INFORMATION]->Get_Height()) / 2 - 200);
	texture_array[TEXTURE_INDEX_INFO_EN_0]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_INFO_EN_0]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_INFO_EN_0]->Get_Height()) / 2 - 100);
	texture_array[TEXTURE_INDEX_INFO_EN_1]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_INFO_EN_1]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_INFO_EN_1]->Get_Height()) / 2 - 50);
	texture_array[TEXTURE_INDEX_INFO_EN_2]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_INFO_EN_2]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_INFO_EN_2]->Get_Height()) / 2 - 0);
	texture_array[TEXTURE_INDEX_INFO_RU_0]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_INFO_RU_0]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_INFO_RU_0]->Get_Height()) / 2 + 100);
	texture_array[TEXTURE_INDEX_INFO_RU_1]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_INFO_RU_1]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_INFO_RU_1]->Get_Height()) / 2 + 150);
	texture_array[TEXTURE_INDEX_INFO_RU_2]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_INFO_RU_2]->Get_Width()) / 2,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_INFO_RU_2]->Get_Height()) / 2 + 200);
	texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Draw(
		(SCREEN_WIDTH - texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Get_Width()) - 10,
		(SCREEN_HEIGHT - texture_array[TEXTURE_INDEX_BACK_TO_MENU]->Get_Height()) - 10);
}

int Info::Handle_event(SDL_Event* event) {
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