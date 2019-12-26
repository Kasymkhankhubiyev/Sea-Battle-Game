#ifndef _GAME_H_
#define _GAME_H_

class Game
{
	bool run;
public:
	Game();
	int Execute();
	int Exit();
};

void menu_print();

void player_choice_menu();

void ship_types();


#endif // !_GAME_H_

#pragma once
