//
// PAC-MAN | Alejandro V.
//

#include <iostream>
#include <vector>

#define MAP_VERTICAL 29
#define MAP_HORIZONTAL 120

// Variables
enum TILES { EMPTY = ' ', WALL = '#', POINT = '.' };

enum INPUT { QUIT, UP, DOWN, LEFT, RIGHT, UNKNOWN };
INPUT currentInput = INPUT::UNKNOWN;

TILES map[MAP_VERTICAL][MAP_HORIZONTAL];

bool run = true;

// Funciones

void Setup() {
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
}



void Inputs() {
	char input;
	std::cin >> input;
	switch (input)
	{
	case 'q':
	case 'Q':
		currentInput = INPUT::QUIT;
		break;
	case 'o':
	case 'O':
		currentInput = INPUT::UP;
		break;
	case 'l':
	case 'L':
		currentInput = INPUT::DOWN;
		break;
	case 'k':
	case 'K':
		currentInput = INPUT::LEFT;
		break;
	case ';':
		currentInput = INPUT::RIGHT;
		break;

	default:
		break;
	}
}

void Logic() {
	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	case UNKNOWN:
		break;
	default:
		break;
	}
}

void Draw() {
	// Limpia la pantalla
	system("cls");
	// Imprime el mapa
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			std::cout << (char)map[i][j];
		}
		std::cout << std::endl;
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