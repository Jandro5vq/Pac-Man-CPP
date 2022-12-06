//
// PAC-MAN | Alejandro V.
//

#include <iostream>
#include <vector>
#include <conio.h>

#define MAP_VERTICAL 29
#define MAP_HORIZONTAL 120
#define PLAYER 'O'
#define PTS_NUM 5

// Variables
enum TILES { EMPTY = ' ', WALL = '#', POINT = '$' };

enum INPUT { QUIT, UP, DOWN, LEFT, RIGHT, UNKNOWN };
INPUT currentInput = INPUT::UNKNOWN;

TILES map[MAP_VERTICAL][MAP_HORIZONTAL];

bool run = true;

int player_x;
int player_y;

int puntuacion_actual;
int puntuacion_total;

// Funciones

void Setup() {
	
	player_x = MAP_HORIZONTAL / 2;
	player_y = MAP_VERTICAL / 2;
	
	// Genera el mapa
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == 0 || j == MAP_HORIZONTAL - 1 || j == 0 || i == MAP_VERTICAL - 1)
			{
				map[i][j] = TILES::WALL;
			}
			else
			{
				map[i][j] = TILES::EMPTY;
			}
		}
	}

	for (size_t i = 0; i < PTS_NUM; i++)
	{
		int randx = rand() % MAP_HORIZONTAL + 1;
		int randy = rand() % MAP_VERTICAL + 1;
		map[randy][randx] = TILES::POINT;
	}

	map[12][0] = TILES::EMPTY;
	map[13][0] = TILES::EMPTY;
	map[14][0] = TILES::EMPTY;
	map[15][0] = TILES::EMPTY;

	map[12][MAP_HORIZONTAL-1] = TILES::EMPTY;
	map[13][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[14][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[15][MAP_HORIZONTAL - 1] = TILES::EMPTY;

	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (map[i][j] == TILES::POINT)
			{
				puntuacion_total++;
			}
		}
	}

}

void Inputs() {
	char input;
	input = _getch();
	switch (input)
	{
	case 'q':
	case 'Q':
		currentInput = INPUT::QUIT;
		break;
	case 'o':
	case 'O':
	case 'w':
	case 'W':
		currentInput = INPUT::UP;
		break;
	case 'l':
	case 'L':
	case 's':
	case 'S':
		currentInput = INPUT::DOWN;
		break;
	case 'k':
	case 'K':
	case 'a':
	case 'A':
		currentInput = INPUT::LEFT;
		break;
	case ';':
	case 'd':
	case 'D':
		currentInput = INPUT::RIGHT;
		break;

	default:
		break;
	}
}


void Logic() {

	int player_y_new = player_y;
	int player_x_new = player_x;

	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		player_y_new--;
		break;
	case DOWN:
		player_y_new++;
		break;
	case LEFT:
		player_x_new--;
		break;
	case RIGHT:
		player_x_new++;
		break;
	case UNKNOWN:
		break;
	default:
		break;
	}

	if (player_x_new < 0)
	{
		player_x_new = MAP_HORIZONTAL - 1;
	}

	player_x_new = player_x_new % MAP_HORIZONTAL;

	switch (map[player_y_new][player_x_new])
	{
	case TILES::WALL:
		break;

	case TILES::POINT:
		puntuacion_actual++;
		map[player_y_new][player_x_new] = TILES::EMPTY;

	default:
		player_y = player_y_new;
		player_x = player_x_new;
		break;
	}
}

void Draw() {
	// Limpia la pantalla
	system("cls");

	if (puntuacion_total != puntuacion_actual) {
		// Imprime el mapa y el personaje | i = x = Horizontal | j = y = Vertical |
		for (size_t i = 0; i < MAP_VERTICAL; i++)
		{
			for (size_t j = 0; j < MAP_HORIZONTAL; j++)
			{
				if (i == player_y && j == player_x)
				{
					std::cout << "\033[33m" << PLAYER << "\033[0m";
				}
				else
				{
					if (map[i][j] == WALL)
					{
						std::cout << "\033[47m" << (char)map[i][j] << "\033[0m";
					}
					else if (map[i][j] == POINT)
					{
						std::cout << "\033[41m" << (char)map[i][j] << "\033[0m";
					}
					else
					{
						std::cout << (char)map[i][j];
					}
				}
			}
			std::cout << std::endl;
		}
		std::cout << "\033[45m " << puntuacion_actual << '/' << puntuacion_total << " \033[0m";
	}
	else
	{
		std::cout << "\033[96m" <<
			R"(
			 ___  ___  ______    ____  ____      __   __  ___   __    _____  ___   
			|"  \/"  |/    " \  ("  _||_ " |    |"  |/  \|  "| |" \  (\"   \|"  \  
			 \   \  /// ____  \ |   (  ) : |    |'  /    \:  | ||  | |.\\   \    | 
			  \\  \//  /    ) :)(:  |  | . )    |: /'        | |:  | |: \.   \\  | 
			  /   /(: (____/ //  \\ \__/ //      \//  /\'    | |.  | |.  \    \. | 
			 /   /  \        /   /\\ __ //\      /   /  \\   | /\  |\|    \    \ | 
			|___/    \"_____/   (__________)    |___/    \___|(__\_|_)\___|\____\) 
			)" << "\033[92m" <<
			R"(
									By Alejandro Vazquez
			)" << "\033[0m" << "- Press Q to exit.";

	}
}

int main()
{
	Setup();
	Draw();
	while (run)
	{
		Inputs();
		Logic();
		Draw();
	}
}

