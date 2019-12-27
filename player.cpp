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
		my_field[x][y] = 88;
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

void Player::Draw()
{
	for (int i = 0; i < 22;i++)
	{
		for (int j = 0; j < 22; j++)
		{
			std::cout << my_field[i][j];
		}
		std::cout << std::endl;
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

void Player::Set_ships_concole() //во всех формулах, кроме катера, нужно поменять местами х и у!
{
	size_t x, y;
	for (int i = 1;i <= 4;i++)
	{
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 4 boats, inpute their coordinates (x,y) one by one" << std::endl;
		std::cout << "Boat number "<< i << ":   " << std::endl;
		Draw();
		std::cin >> x >> y;
		my_field[y][x] = 35;
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 4 boats, inpute their coordinates (x,y) one by one" << std::endl;
		std::cout << "Boat number " << i << ":   " << std::endl;
		Draw();
	}
	size_t y1, y2, y3;
	size_t x1, x2, x3;
	for (int i = 1;i <= 3;i++)
	{
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 3 destroyers, inpute their coordinates (xi,yi)" << std::endl;
		std::cout << "Destroyer number " << i << ":   " << std::endl;
		Draw();
		std::cout << "Horizintal		press 1" << std::endl;
		std::cout << "Vertical			press 2" << std::endl;
		size_t n;
		std::cin >> n;
		if (n == 1)
		{
			std::cout << " Horizontal  $$" << std::endl;
			std::cout << "Set y:   ";
			std::cin >> y;
			std::cout << "Set x1 x2:  ";//нужно проверки навставлять с зацикливанием.
			std::cin >> x >> x1;
			my_field[x][y] = 36;
			my_field[x1][y] = 36;
		}
		if (n == 2)
		{
			std::cout << " Vertical  $$" << std::endl;
			std::cout << "Set x:   ";
			std::cin >> x;
			std::cout << "Set y1 y2:  ";//нужно проверки навставлять с зацикливанием.
			std::cin >> y >> y1;
			my_field[x][y] = 36;
			my_field[x][y1] = 36;
		}
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 3 destroyers, inpute their coordinates x, then two coordinat y" << std::endl;
		std::cout << "Destroyer number " << i << ":   " << std::endl;
		Draw();
	}
	for (int i = 1;i <= 2;i++)
	{
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 2 cruisers, inpute their coordinates (xi,yi)" << std::endl;
		std::cout << "Cruiser number " << i << ":   " << std::endl;
		Draw();
		std::cout << "Horizintal		press 1" << std::endl;
		std::cout << "Vertical			press 2" << std::endl;
		size_t n;
		std::cin >> n;
		if (n == 1)
		{
			std::cout << " Horizontal  &&&" << std::endl;
			std::cout << "Set y:   ";
			std::cin >> y;
			std::cout << "Set x1 x2,x3:  ";//нужно проверки навставлять с зацикливанием.
			std::cin >> x >> x1 >> x2;
			my_field[x][y] = 38;
			my_field[x1][y] = 38;
			my_field[x2][y] = 38;
		}
		if (n == 2)
		{
			std::cout << " Vertical  &&&" << std::endl;
			std::cout << "Set x:   ";
			std::cin >> x;
			std::cout << "Set y1 y2,y3:  ";//нужно проверки навставлять с зацикливанием.
			std::cin >> y >> y1 >> y2;
			my_field[x][y] = 38;
			my_field[x][y1] = 38;
			my_field[x][y2] = 38;
		}
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 2 cruisers, inpute their coordinates x, then two coordinat y" << std::endl;
		std::cout << "Cruiser number " << i << ":   " << std::endl;
		Draw();
	}
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 1 Battle Ship, inpute their coordinates (xi,yi)" << std::endl;
		std::cout << "Battle Ship number 1:   " << std::endl;
		Draw();
		std::cout << "Horizintal		press 1" << std::endl;
		std::cout << "Vertical			press 2" << std::endl;
		size_t n;
		std::cin >> n;
		if (n == 1)
		{
			std::cout << " Horizontal  @@@@" << std::endl;
			std::cout << "Set y:   ";
			std::cin >> y;
			std::cout << "Set x1 x2,x3,x4:  ";//нужно проверки навставлять с зацикливанием.
			std::cin >> x >> x1 >> x2>>x3;
			my_field[x][y] = 64;
			my_field[x1][y] = 64;
			my_field[x2][y] = 64;
			my_field[x3][y] = 64;
		}
		if (n == 2)
		{
			std::cout << " Vertical  &&&" << std::endl;
			std::cout << "Set x:   ";
			std::cin >> x;
			std::cout << "Set y1 y2,y3,y4:  ";//нужно проверки навставлять с зацикливанием.
			std::cin >> y >> y1 >> y2>>y3;
			my_field[x][y] = 64;
			my_field[x][y1] = 64;
			my_field[x][y2] = 64;
			my_field[x][y3] = 64;
		}
		system("cls");
		std::cout << "Pleas set your ships" << std::endl;
		std::cout << "You have 1 Battle Ship, inpute their coordinates (xi,yi)" << std::endl;
		std::cout << "Battle Ship number 1:   " << std::endl;
		Draw();

		std::cout << "Well Done! Let's go to the BATTLE!" << std::endl << " Are you ready?			" << "Press 1 to continue" << std::endl;
		std::cout << " Press 0 to Exit	" << std::endl;
		size_t cont;
		std::cin >> cont;
	}

void Player::ReDraw(size_t&Ships1, size_t&Score1, size_t&Ships2, size_t& Score2)
{
	system("cls");
	std::cout << " Player 1		Ships: " << Ships1 << "		Score:  " << Score1 << std::endl;
	std::cout << " Player 2		Ships: " << Ships2 << "		Score:  " << Score2 << std::endl;
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

size_t Player::Choice()
{
	system("cls");
	std::cout << "Pleas, choose tactic:	" << std::endl;
	std::cout << "Play yourselfe			press 1" << std::endl;
	std::cout << "Play with Intelegence		press 2" << std::endl;
	size_t k;
	std::cin >> k;//Error func;
	return k;
}

void Player::Draw_battle_field()
{
	//Wait_func();
	//system("cls");
	std::cout << "Now is PLAYER" << my_ind << std::endl;
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

void Player::PersonTactic(bool& comp, size_t&x, size_t& y)
{
	while (comp == false) 
	{
		std::cout << "MAKE SHOOT!" << std::endl;
		std::cout << "Input coordinate (x,y)";
		size_t u, v;
		std::cin >> u >> v;
		std::cout << "You shot at (" << u << v << ") coordinate" << std::endl;
		x = u;
		y = v;
		comp = Compare1(x, y);
	}
}

void Player::EasyTactic(bool& comp, size_t&x, size_t& y)
{
	while (comp == false)
	{
		Make_shoot(x, y);
		comp = Compare1(x, y);
	}
}
