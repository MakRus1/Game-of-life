#include "Board.h"

Board::Board() {
	board_Renderer = NULL;
	width = SCREEN_WIDTH / SCALE;
	height = SCREEN_HEIGHT / SCALE;

	board = new bool* [width];
	next_board = new bool* [width];

	for (int i = 0; i < width; i++) {
		board[i] = new bool[height];
		next_board[i] = new bool[height];
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			board[i][j] = false;
			next_board[i][j] = false;
		}
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	for (int i = 0; i < COUNT; i++) {
		board[gen() % width][gen() % height] = true;
	}
}

void Board::Set_Renderer(SDL_Renderer* renderer) {
	board_Renderer = renderer;
}

void Board::Draw_Board() {
	SDL_Rect cell;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cell = { i * SCALE, j * SCALE, SCALE, SCALE };
			if (board[i][j]) {
				SDL_SetRenderDrawColor(board_Renderer, 123, 145, 123, 255);
			}
			else {
				SDL_SetRenderDrawColor(board_Renderer, 1, 50, 32, 255);
			}
			SDL_RenderFillRect(board_Renderer, &cell);
		}
	}
}

int Board::Mod(int a, int b) {
	int ret = a % b;
	if (ret < 0) {
		ret += b;
	}
	return ret;
}

int Board::Neighbours(int x, int y) {
	int count = 0;
	// Проверка клеток справа
	if (board[Mod((x + 1), width)][Mod((y + 0), height)])
		count++;

	// Проверка клеток справа снизу
	if (board[Mod((x + 1), width)][Mod((y + 1), height)])
		count++;

	// Проверка клеток снизу
	if (board[Mod((x + 0), width)][Mod((y + 1), height)])
		count++;

	// Проверка клеток снизу слева
	if (board[Mod((x - 1), width)][Mod((y + 1), height)])
		count++;

	// Проверка клеток слева
	if (board[Mod((x - 1), width)][Mod((y + 0), height)])
		count++;

	// Проверка клеток слева сверху
	if (board[Mod((x - 1), width)][Mod((y - 1), height)])
		count++;

	// Проверка клеток сверху
	if (board[Mod((x + 0), width)][Mod((y - 1), height)])
		count++;

	// Проверка клеток справа сверху
	if (board[Mod((x + 1), width)][Mod((y - 1), height)])
		count++;

	return count;
}

void Board::Tick() {
	int neighbours;

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			neighbours = Neighbours(x, y);
			if (board[x][y] && !(neighbours == 2 || neighbours == 3)) 
				next_board[x][y] = false;
			if (!board[x][y] && neighbours == 3)
				next_board[x][y] = true;
		}
	}

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			board[x][y] = next_board[x][y];
		}
	}
}

bool Board::get_Cell(int x, int y) {
	return board[x][y];
}

void Board::set_Cell(int x, int y, bool condition) {
	board[x][y] = condition;
}

int Board::get_Width() {
	return width;
}

int Board::get_Height() {
	return height;
}