#include "Window.h"
#include "Texture.h"
#include "Scene.h"
#include "Menu.h"
#include "Info.h"
#include "Game.h"

int main(int argc, char* argv[]) {
	Window* win = new Window;
	bool quit = false;

	Scene* scene = new Menu;
	scene->set_Renderer(win->get_Renderer());
	scene->Init_menu();

	SDL_Event event;

	while (!quit) {
		SDL_PollEvent(&event);
		scene->Clear();
		scene->Draw();
		scene->Render();
		switch (scene->Handle_event(&event)) {
		case 0:
			quit = true;
			break;
		case 1:
			delete scene;
			scene = new Menu;
			scene->set_Renderer(win->get_Renderer());
			scene->Init_menu();
			SDL_FlushEvent(SDLK_0);
			break;
		case 2:
			delete scene;
			scene = new Game;
			scene->set_Renderer(win->get_Renderer());
			scene->Init_game();
			SDL_FlushEvent(SDLK_0);
			break;
		case 3:
			delete scene;
			scene = new Info;
			scene->set_Renderer(win->get_Renderer());
			scene->Init_info();
			SDL_FlushEvent(SDLK_0);
			break;
		}
	}
	return 0;
}