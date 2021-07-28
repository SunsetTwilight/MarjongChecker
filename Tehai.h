#pragma once
#include "Tile.h"

class Tehai
{
protected:
	Tile tiles[14]; //0-12 = ��v�A13 = ���̔v
	
public:

	Tehai(){}
	~Tehai(){}

	void SetTile(unsigned int num, unsigned int index) { tiles[index].SetTileNum(num); }
	Tile& GetTile(unsigned int num) { return tiles[num]; }
};




