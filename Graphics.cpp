#include "Graphics.h"

void Field::Draw_score()
{
	std::cout << " player 1 - Score:  " << std::endl;
}
void Field::Draw_field_line(size_t arr[20][20])
{
	std::cout << "SEA BUTTLE -- Game for 2 palyers" << std::endl;
	for (int i = 0; i < 20;i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}

}

void Field::Draw_player_field(size_t arr[20][20])
{
	std::cout << "SEA BUTTLE -- Game for 2 palyers" << std::endl;
	for (int i = 0; i < 20;i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
}
