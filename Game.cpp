#include "Game.h"
#include "Graphics.h"         //system("cls"); - функция очистки консоли!

Game::Game()
{
	run = true;
}
int Game::Execute()
{
	while (run);
	return 0;
}

int Game::Exit()
{
	run = false;
	return 0;
}

void menu_print()
{
	std::cout << "Hello! This is a game Sea Buttle!" << std::endl;
	std::cout << "You can to play with bot, or just set bots to play." << std::endl;
	std::cout << "Pleas, chose your variant:" << std::endl;
	std::cout << "1. to play whith a bot		press 1" << std::endl;
	std::cout << "2. to set two bots to play		press 2" << std::endl;
	std::cout << std::endl << std::endl << std::endl << "to Exit				press 0" << std::endl;
}

void player_choice_menu()
{
	system("cls");
	std::cout << "if you want to set ships yourselfe	press 1" << std::endl;
	std::cout << "if you want intelegence to do that		press 2" << std::endl;
	std::cout << std::endl << std::endl << std::endl << "to Exit				press 0" << std::endl;
}

void ship_types()
{
	system("cls");
	std::cout << "There are four types of ships. They are:" << std::endl;
	std::cout << "	1 - torpedo boat   It takes 1 cage" << std::endl; //торпедный катер
	std::cout << "	2 - destroyer	   It takes 2 cages" << std::endl; //эспинец
	std::cout << "	3 - cruiser		   It takes 3 cages" << std::endl; //крейсер
	std::cout << "	4 - buttle ship	   It takes 4 cages" << std::endl; //линкор
}
