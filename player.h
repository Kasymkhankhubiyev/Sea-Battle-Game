#ifndef _PLAYER_H_
#define _PLAYER_H_

#include"Game.h"
#include "Graphics.h"

#include <windows.h>
#include <dos.h>
#include <stdio.h>
#include <ctime>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

class Player: public Field
{
	size_t my_ind;
	size_t Score;
	char my_field[22][22];
	char battle_field[22][22];
	size_t boat;
	size_t destroyer;
	size_t cruiser;
	size_t buttle_ship;
	size_t shoot;
	size_t tactic;
	//std::map<size_t, pair <size_t, size_t>> shoot_story;
public:
	Player();

	bool Compare1(size_t& x, size_t& y);

	size_t Compare2(size_t& x, size_t& y);

	void Make_shoot(size_t& x, size_t& y);

	void Set_ship_type();

	size_t Choice();

	void Set_ships_concole();

	void ReDraw(size_t&Ships1, size_t&Score1, size_t&Ships2, size_t& Score2);

	void Reset(size_t& x, size_t& y);

	void Draw();

	void Draw_player_field();

	size_t Get_Score();

	size_t Get_ships();

	void Draw_battle_field();

	void Wait_func();

	void PersonTactic(bool& comp, size_t&x, size_t& y);

	void EasyTactic(bool& comp, size_t&x, size_t& y);
};

#endif // !_PLAYER_H_
#pragma once
/*while (comp == false)
		{
			player2.Make_shoot(x, y);
			comp = player2.Compare1(x, y);
		}*/
