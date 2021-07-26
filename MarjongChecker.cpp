#include "MarjongChecker.h"



bool MarjongChecker::CheckHai(Tile& tile)
{
	if (data.ExistHai(tile)) return true;
	else return false;
}

bool MarjongChecker::CheckToitsu(Tile& tile)
{
	for (int i = 0; i < 2; i++)
	{
		if (CheckHai(tile))
		{
			for (int k = 0; k < i; k++)
			{
				data.ExtractHai(tile);
			}
		}
		else return false;
	}
	for (int i = 0; i < 2; i++)
	{
		data.InsertHai(tile);
	}
	return true;
}

bool MarjongChecker::CheckTartsu(Tile& tile, unsigned int patarn) //(num) を先頭として考える (patarn) はターツの並び順 (0 = 連番,1 = 1つ飛ばし)
{
	if (26 < tile.GetTileNum()) return false;
	switch (patarn)
	{
	case 0:
		if (((tile.GetTileNum() + 1) % 9) == 0) return false;//(num) が( 8, 17, 26)
		if (CheckHai(tile) && CheckHai(tile + 1)) return true;
		else return false;
	case 1:
		if (((tile.GetTileNum() + 2) % 9) == 0) return false;//(num) が( 7, 16, 25)
		if (CheckHai(tile) && CheckHai(tile + 2)) return true;
		else return false;
	default:
		return false;
	}
}

bool MarjongChecker::CheckKoutsu(Tile& tile)
{
	for (int i = 0; i < 3; i++)
	{
		if (CheckHai(tile))
		{
			for (int k = 0; k < i; k++)
			{
				data.ExtractHai(tile);
			}
		}
		else return false;
	}
	for (int i = 0; i < 3; i++)
	{
		data.InsertHai(tile);
	}
	return true;
}

bool MarjongChecker::CheckSyuntsu(Tile& tile) //(num) を先頭として考える
{
	if (26 < tile.GetTileNum()) return false;
	if (((tile.GetTileNum() + 2) % 9) == 0) return false;//(num) が( 7, 16, 25)
	if (CheckHai(tile) && CheckHai(tile + 1) && CheckHai(tile + 2)) return true;
	else return false;
}

bool MarjongChecker::CheckKantsu(Tile& tile)
{
	for (int i = 0; i < 4; i++)
	{
		if (CheckHai(tile))
		{
			for (int k = 0; k < i; k++)
			{
				data.ExtractHai(tile);
			}
		}
		else return false;
	}
	for (int i = 0; i < 4; i++)
	{
		data.InsertHai(tile);
	}
	return true;
}

bool MarjongChecker::CheckHai(unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckHai(tile);
}

bool MarjongChecker::CheckToitsu(unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckToitsu(tile);
}
bool MarjongChecker::CheckTartsu(unsigned int& num, unsigned int& patarn)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckTartsu(tile, patarn);
}
bool MarjongChecker::CheckKoutsu(unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckKoutsu(tile);
}
bool MarjongChecker::CheckSyuntsu(unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckSyuntsu(tile);
}
bool MarjongChecker::CheckKantsu(unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckKantsu(tile);
}


bool MarjongChecker::CheckHai(const unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckHai(tile);
}

bool MarjongChecker::CheckToitsu(const unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckToitsu(tile);
}
bool MarjongChecker::CheckTartsu(const unsigned int& num, unsigned int& patarn)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckTartsu(tile, patarn);
}
bool MarjongChecker::CheckKoutsu(const unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckKoutsu(tile);
}
bool MarjongChecker::CheckSyuntsu(const unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckSyuntsu(tile);
}
bool MarjongChecker::CheckKantsu(const unsigned int& num)
{
	Tile tile = {};
	tile.SetTileNum(num);
	return CheckKantsu(tile);
}


bool MarjongChecker::CheckType(TileType type)
{

	 if(data.Get_C_Data(type) == 1);

	return true;
}

bool MarjongChecker::InsertHai(Tile& tile)
{
	for (int i = 0; i < 4; i++)
	{
		if (CheckHai(tile))
		{
			data.ExtractHai(tile);
		}
		else
		{
			for (int k = (i - 1); 0 < k; k--)
			{
				data.InsertHai(tile);
			}
			data.InsertHai(tile);

			return true;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		data.InsertHai(tile);
	}
	return false;
}
bool MarjongChecker::ExtractHai(Tile& tile)
{
	if (CheckHai(tile))
	{
		data.ExtractHai(tile);
		return true;
	}
	return false;
}

bool MarjongChecker::InsertHai(unsigned int& num)
{
	Tile tile(num);
	InsertHai(tile);
}

bool MarjongChecker::ExtractHai(unsigned int& num)
{
	Tile tile(num);
	ExtractHai(tile);
}

bool MarjongChecker::InsertHai(const unsigned int& num)
{
	Tile tile(num);
	InsertHai(tile);
}

bool MarjongChecker::ExtractHai(const unsigned int& num)
{
	Tile tile(num);
	ExtractHai(tile);
}