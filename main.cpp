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

	menu_print();//выводим главное меню
	size_t n;
	std::cin >> n;
	if (n == 1) //выбор режима
	{//play myselfe
				
	}
	if (n == 2)
	{
		player_choice_menu(); //вывод меню выбора игрового режима
		size_t k;
		std::cin >> k;
		if (k == 1) //выбор типа задачи поля
		{
			game.Exit();
		}
		if (k == 2) //поля задают боты
		{
			ship_types(); //4 по 1, 3 по 2, 2 по 3, и 1 по 4;
			
			player1.Set_ship_type();
			player1.Draw_player_field(); //показываем игроку его поле
			
			player2.Set_ship_type(); //теперь мы расставили корабли и можем переходить к бою, но для этого сначала нужно показать игрокам их поля;
			player2.Draw_player_field(); //показываем игроку его поле
			size_t Score1 = player1.Get_Score();//записываем исходные данные
			size_t Score2 = player2.Get_Score();//счет
			size_t Ships1 = player1.Get_ships();//кол-во кораблей на поле (с каждым попаданием +1 очко)
			size_t Ships2 = player2.Get_ships();
			while (Score1 != 7 && Score2 != 7)//закручиваем игру
			{
				bool comp = false;
				system("cls");
				std::cout << " Player 1		Ships: " << Ships1 << "		Score:  " << Score1 << std::endl;
				std::cout << " Player 2		Ships: " << Ships2 << "		Score:  " << Score2 << std::endl;
				player1.Draw_battle_field();
				size_t x, y;
				while (comp == false)
				{
					player1.Make_shoot(x, y);
					comp = player1.Compare1(x, y);
				}
				size_t sc = player2.Compare2(x, y);
				if (sc == 1)
				{
					std::cout << "Yes! right Shoot!" << std::endl;
					player1.Reset(x, y);
					player1.ReDraw();
					Score1 = Score1 + sc;
				}
				else std::cout << "Oh, you missed! Shoot better!" << std::endl;
				Sleep(2000);
				comp = false;
				system("cls");
				std::cout << " Player 1		Ships: " << Ships1 << "		Score:  " << Score1 << std::endl;
				std::cout << " Player 2		Ships: " << Ships2 << "		Score:  " << Score2 << std::endl;
				player2.Draw_battle_field();
				while (comp == false)
				{
					player2.Make_shoot(x, y);
					comp = player2.Compare1(x, y);
				}
				sc = player1.Compare2(x, y);
				if (sc == 1)
				{
					std::cout << "Yes! right Shoot!" << std::endl;
					player2.Reset(x, y);
					player2.ReDraw();
					Score2 = Score2 + sc;
				}
				else std::cout << "Oh, you missed! Shoot better!" << std::endl;
				Sleep(2000);
			}
			if (Score1 == 7)
			{
				std::cout << " Player 1 WON!!!  " << std::endl;
			}
			if (Score2 == 7)
			{
				std::cout << " Player 2 WON!!!  " << std::endl;
			}
			//нужно как-нибудь расставить.
			//пашем!!! 
			game.Exit();
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

	return 0;
}
///нужно считывать вводимый текст относительно клеток, нужно будет ввести редактор, считам поле как в шахматах "Е1" к примеру, Е в один блок, 1 в другой.
// еще сделаем функию выхода, если вводит текст "Exit" - тогда сворачиваем игру.
