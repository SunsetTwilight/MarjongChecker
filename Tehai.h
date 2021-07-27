#pragma once
#include "DefaultFormChecker.h"
#include "DefaultCompleteFace.h"

class Tehai
{
protected:
	Tile tiles[14]; //0-12 = è”vA13 = ©–Ì”v
	
public:

	Tehai(){}
	~Tehai(){}

	void SetTile(unsigned int num, unsigned int index) { tiles[index].SetTileNum(num); }
	Tile& GetTile(unsigned int num) { return tiles[num]; }
};



class DefaultTehai : public Tehai
{
private:
	unsigned int tehai_count = 14;

	DefaultNakiFace* compFace[4] = { nullptr };
	unsigned int naki_count = 0;

public:
	void Naki(DefaultNakiFace face);

	DefaultTehai() {}
	~DefaultTehai() {}
};
