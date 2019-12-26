#include "player.h"

Player::Player()
{
	Score = 0;
	boat = 3;
	destroyer = 1;
	cruiser = 1;
	buttle_ship = 1;
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0;j < 20;j++)
		{
			my_field[i][j] = 0;
			battle_field[i][j] = 0;
		}
	}
}
size_t Player::make_shoot()
{
	return 0;
}

void Player::Set_ship_type()
{
	my_field[5][6] = 1; //ставим 3 катера
	my_field[1][1] = 1;
	my_field[17][7] = 1;

	my_field[4][5] = 2; //ставим эсминец
	my_field[4][6] = 2;

	my_field[10][7] = 3;//ставим крейсер
	my_field[10][8] = 3;
	my_field[10][9] = 3;

	my_field[1][20] = 4; //ставим линкор
	my_field[2][20] = 4;
	my_field[3][20] = 4;
	my_field[4][20] = 4;
}

void Player::Draw_player_field()
{
	system("cls");
	for (int i = 3; i >= 0; i--)
	{
		system("cls");	
		std::cout << "Now, PLAYER, this is your filed with ships" << std::endl << std::endl << std::endl;
		std::cout << "wait for		" << i << " seconds" << std::endl;
		Sleep(1000);
	}
	system("cls"); //выводим кол-во кораблей
	std::cout << "SEA BUTTLE -- Game for 2 palyers" << std::endl;
	for (int i = 0; i < 20;i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << my_field[i][j];
		}
		std::cout << std::endl;
	}
	size_t influx;
	std::cout << " If you are ready to play, press 1" << std::endl;
	std::cin >> influx;
}

size_t Player::Get_Score()
{
	return Score;
}

size_t Player::Get_ships()
{
	return boat + destroyer + cruiser + buttle_ship;
}

void Player::Draw_battle_field()
{
	system("cls"); //выводим кол-во кораблей
	std::cout << "SEA BUTTLE -- Game for 2 palyers" << std::endl;
	for (int i = 0; i < 20;i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << battle_field[i][j];
		}
		std::cout << std::endl;
	}
	size_t influx;
	std::cout << " If you are ready to play, press 1" << std::endl;
	std::cin >> influx;
}
