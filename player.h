#ifndef _PLAYER_H_
#define _PLAYER_H_

#include"Game.h"
#include "Graphics.h"

#include <windows.h>
#include <dos.h>
#include <stdio.h>


class Player
{
	size_t Score;
	size_t my_field[10][10];
	size_t battle_field[10][10];
	size_t boat;
	size_t destroyer;
	size_t cruiser;
	size_t buttle_ship;
public:
	Player();

	size_t make_shoot();

	void Set_ship_type();

	void Draw_player_field();

	size_t Get_Score();

	size_t Get_ships();

	void Draw_battle_field();
};
#endif // !_PLAYER_H_
#pragma once
