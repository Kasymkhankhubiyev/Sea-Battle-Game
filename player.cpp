#include "player.h"

Player::Player()
{
	my_ind = ++ind;
	Score = 0;
	boat = 3;
	destroyer = 1;
	cruiser = 1;
	buttle_ship = 1;
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (i == 0 || i == 21)
			{
				my_field[i][j] = 95;
				battle_field[i][j] = 95;
			}
			else
			{
				if (j == 0 || j == 21)
				{
					my_field[i][j] = 124;
					battle_field[i][j] = 124;
				}
				else
				{
					my_field[i][j] = 32;
					battle_field[i][j] = 32;
				}
			}
		}
	}
}

bool Player::Compare1(size_t& x, size_t& y)
{
	if (battle_field[x][y] == 32)
	{
		battle_field[x][y] = 42;
		return true;
	}
	else return false;
}

size_t Player::Compare2(size_t& x, size_t& y) //boat = 35 , destroyer = 36, lincorn = 38, battle_ship == 64
{
	if (my_field[x][y] == 35 || my_field[x][y] == 36 || my_field[x][y] == 38 || my_field[x][y] == 64)
	{
		if (my_field[x][y] == 35)
		{
			boat = boat - 1;
		}
		else
		{
			if (my_field[x][y] == 36)
			{
				destroyer = destroyer - 1;
			}
			else
			{
				if (my_field[x][y] == 38)
				{
					cruiser = cruiser - 1;
				}
				else
				{
					if (my_field[x][y] == 64)
					{
						buttle_ship = buttle_ship - 1;
					}
				}
			}
		}
		my_field[x][y] == 88;
		return 1;
	}
	else return 0;
}

void Player::Make_shoot(size_t& x, size_t& y)
{
	std::srand(unsigned(std::time(0)));
	x = 1 + std::rand() % 20;
	y = 1 + std::rand() % 20;
}

void Player::Set_ship_type()
{
	my_field[5][6] = 35; //ставим 3 катера
	my_field[1][1] = 35;
	my_field[17][7] = 35;

	my_field[4][5] = 36; //ставим эсминец
	my_field[4][6] = 36;

	my_field[10][7] = 38;//ставим крейсер
	my_field[10][8] = 38;
	my_field[10][9] = 38;

	my_field[1][20] = 64; //ставим линкор
	my_field[2][20] = 64;
	my_field[3][20] = 64;
	my_field[4][20] = 64;
}

void Player::Wait_func()
{
	for (int i = 3; i >= 0; i--)
	{
		system("cls");
		std::cout << "Now, PLAYER " << my_ind << ", this is your filed with ships" << std::endl << std::endl << std::endl;
		std::cout << "wait for		" << i << " seconds" << std::endl;
		Sleep(1000);
	}
}

void Player::Draw_player_field()
{
	system("cls");
	Wait_func();
	system("cls"); //выводим кол-во кораблей
	std::cout << "SEA BATTLE -- Game for 2 palyers" << std::endl;
	for (int i = 0; i < 22;i++)
	{
		for (int j = 0; j < 22; j++)
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
	size_t n = boat + destroyer + cruiser + buttle_ship;
	return n;
}

void Player::Reset(size_t& x, size_t& y)
{
	battle_field[x][y] = 88;
}

void Player::ReDraw()
{
	system("cls");
	std::cout << "Battle field on the left and your ships on the right" << std::endl;
	for (int i = 0; i < 22;i++)
	{
		for (int j = 0; j < 22; j++)
		{
			std::cout << battle_field[i][j];

		}
		std::cout << "				";
		for (int k = 0;k < 22;k++)
		{
			std::cout << my_field[i][k];
		}
		std::cout << std::endl;
	}
}

void Player::Draw_battle_field()
{
	//Wait_func();
	//system("cls");
	std::cout << "Battle field on the left and your ships on the right" << std::endl;
	for (int i = 0; i < 22;i++)
	{
		for (int j = 0; j < 22; j++)
		{
			std::cout << battle_field[i][j];
			
		}
		std::cout << "				";
		for (int k = 0;k < 22;k++)
		{
			std::cout << my_field[i][k];
		}
		std::cout << std::endl;
	}
	/*size_t influx;
	std::cout << " If you are ready to play, press 1" << std::endl;
	std::cin >> influx;*/
}
