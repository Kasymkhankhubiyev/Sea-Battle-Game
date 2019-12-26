#include "Game.h"
#include "Graphics.h"
#include "player.h"

int main()
{
	Game game; //класс, который закручивает всю игруху
	Field field; //класс, рисующий поле
	//field.Draw_field_line();

	menu_print();//выводим главное меню
	size_t n;
	std::cin >> n;
	if (n == 1) //выбор режима
	{
		//start with;;
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
			Player player1; //бот
			player1.Set_ship_type();
			player1.Draw_player_field(); //показываем игроку его поле
			Player player2;//тоже бот
			player2.Set_ship_type(); //теперь мы расставили корабли и можем переходить к бою, но для этого сначала нужно показать игрокам их поля;
			player2.Draw_player_field(); //показываем игроку его поле

			size_t Score1 = player1.Get_Score();
			size_t Score2 = player2.Get_Score();
			size_t Ships1 = player1.Get_ships();
			size_t Ships2 = player2.Get_ships();
			while (Score1 != 7 && Score2 != 7)//закручиваем игру
			{
				system("cls");
				std::cout << " Player 1		Ships: " << Ships1 << "		Score:  " << Score1 << std::endl;
				std::cout << " Player 2		Ships: " << Ships2 << "		Score:  " << Score2 << std::endl;

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

	return game.Execute();
}
///нужно считывать вводимый текст относительно клеток, нужно будет ввести редактор, считам поле как в шахматах "Е1" к примеру, Е в один блок, 1 в другой.
// еще сделаем функию выхода, если вводит текст "Exit" - тогда сворачиваем игру.
