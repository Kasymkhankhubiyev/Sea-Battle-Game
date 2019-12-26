#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include <stdlib.h>
#include <iostream>

//#include "Game.h"


class Field
{
	size_t m_arr[20][20];
protected:
	static size_t ind;
public:
	void Draw_score();

	void Draw_field_line(size_t arr[20][20]);
	
	void Draw_player_field(size_t arr[20][20]);
};



#endif // !_GRAPHICS_H_
#pragma once
