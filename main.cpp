#include "Game.h"
#include "Graphics.h"
#include "player.h"

int main()
{
	Game game; //класс, который закручивает всю игруху
	Field field; //класс, рисующий поле
	//field.Draw_field_line();
	Player player1; //бот
	Player player2;//тоже бот
	size_t mode, tact;

	menu_print();//выводим главное меню
	size_t n;
	std::cin >> n;
	mode = n;
	if (n == 1) //выбор режима
	{//play myselfe
		std::cout << " You are the PLAYER 1 " << std::endl;
		player_choice_menu();
		size_t k;
		std::cin >> k;
		if (k == 1) //выбор типа задачи поля
		{
			player1.Set_ships_concole();
			player2.Set_ship_type();
		}
		if (k == 2) //поля задают боты
		{
			ship_types(); //4 по 1, 3 по 2, 2 по 3, и 1 по 4;			
			player1.Set_ship_type();
			player1.Draw_player_field(); //показываем игроку его поле			
			player2.Set_ship_type(); //теперь мы расставили корабли и можем переходить к бою, но для этого сначала нужно показать игрокам их поля;
			player2.Draw_player_field(); //показываем игроку его поле

		}
		tact = player1.Choice();
	}
	if (n == 2)
	{
		player_choice_menu(); //вывод меню выбора игрового режима
		size_t k;
		std::cin >> k;
		if (k == 1) //выбор типа задачи поля
		{
			player1.Set_ships_concole();
			player2.Set_ship_type();
		}
		if (k == 2) //поля задают боты
		{
			ship_types(); //4 по 1, 3 по 2, 2 по 3, и 1 по 4;			
			player1.Set_ship_type();
			player1.Draw_player_field(); //показываем игроку его поле			
			player2.Set_ship_type(); //теперь мы расставили корабли и можем переходить к бою, но для этого сначала нужно показать игрокам их поля;
			player2.Draw_player_field(); //показываем игроку его поле
			
		}
		if (n == 0)
		{
			game.Exit();
		}
		//очистка консоли и вызов нового текста;
	}
	if (n == 0)
	{
		game.Exit();
	}
	system("cls");
	size_t Score1 = player1.Get_Score();//записываем исходные данные
	size_t Score2 = player2.Get_Score();//счет
	size_t Ships1 = player1.Get_ships();//кол-во кораблей на поле (с каждым попаданием +1 очко)
	size_t Ships2 = player2.Get_ships();
	while (Score1 != 7 && Score2 != 7)//закручиваем игру
	{//two bots simple done!
		bool comp = false;
		system("cls");
		std::cout << " Player 1		Ships: " << Ships1 << "		Score:  " << Score1 << std::endl;
		std::cout << " Player 2		Ships: " << Ships2 << "		Score:  " << Score2 << std::endl;
		player1.Draw_battle_field();
		size_t x, y;
		size_t sc = 1;
			if (mode == 1&& tact ==1 ) { player1.PersonTactic(comp, x, y); }
			if ((mode == 1 && tact == 2)||(mode==2)) { player1.EasyTactic(comp, x, y); }
			sc = player2.Compare2(x, y);
			if (sc == 1)
			{
				std::cout << "Yes! right Shoot!" << std::endl;
				player1.Reset(x, y);
				player1.ReDraw(Ships1, Score1, Ships2, Score2);
				Score1 = Score1 + sc;
			}
			else
			{
				player1.ReDraw(Ships1, Score1, Ships2, Score2);
				std::cout << "Oh, you missed! Shoot better!" << std::endl;
			}
			Sleep(2000);
			comp = false;
			system("cls");
			std::cout << " Player 1		Ships: " << Ships1 << "		Score:  " << Score1 << std::endl;
			std::cout << " Player 2		Ships: " << Ships2 << "		Score:  " << Score2 << std::endl;
			if (mode == 2) { player2.Draw_battle_field(); }
			if (mode == 1) { std::cout << "Player 2 is shooting"; }
			player2.EasyTactic(comp, x, y);
			sc = player1.Compare2(x, y);
			if (mode == 2)
			{
				if (sc != 0)
				{
					std::cout << "Yes! right Shoot!" << std::endl;
					player2.Reset(x, y);
					player2.ReDraw(Ships1, Score1, Ships2, Score2);
					Score2 = Score2 + sc;
				}
				else
				{
					player2.ReDraw(Ships1, Score1, Ships2, Score2);
					std::cout << "Oh, you missed! Shoot better!" << std::endl;
				}
				Sleep(2000);
			}
			if (mode == 1)
			{
				if (sc != 0)
				{
					std::cout << "Yes! right Shoot!" << std::endl;
					Score2 = Score2 + sc;
				}
				else
				{
					player2.ReDraw(Ships1, Score1, Ships2, Score2);
					std::cout << "Oh, you missed! Shoot better!" << std::endl;
				}
			}
		}
		if (Score1 == 7)
		{
			std::cout << " Player 1 WON!!!  " << std::endl;
		}
		if (Score2 == 7)
		{
			std::cout << " Player 2 WON!!!  " << std::endl;
		}
		game.Exit();

		return 0;
}
///нужно считывать вводимый текст относительно клеток, нужно будет ввести редактор, считам поле как в шахматах "Е1" к примеру, Е в один блок, 1 в другой.
// еще сделаем функию выхода, если вводит текст "Exit" - тогда сворачиваем игру.
