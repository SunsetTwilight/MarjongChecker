#pragma once
#include "Tile.h"

class Tehai
{
protected:
	Tile tiles[14]; //0-12 = ��v�A13 = ���̔v
	
public:

	Tehai(){}
	~Tehai(){}

	void SetTile(unsigned int index, unsigned int num) { tiles[index].SetTileNum(num); }
	Tile& GetTile(unsigned int num) { return tiles[num]; }
};




