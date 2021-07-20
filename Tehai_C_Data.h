#pragma once
#include "CompressionData.h"
#include "Tile.h"

class Tehai_C_Data
{
private:
	CompressionData Manzu_C_data;
	CompressionData Pinzu_C_data;
	CompressionData Souzu_C_data;
	CompressionData Zihai_C_data;

	CompressionData& CheckType(Tile& num)
	{
		if (num.GetTileNum() < 9)
		{
			return Manzu_C_data;
		}
		else if (num.GetTileNum() < 18)
		{
			return Pinzu_C_data;
		}
		else if (num.GetTileNum() < 27)
		{
			return Souzu_C_data;
		}
		else if (num.GetTileNum() < 34)
		{
			return Zihai_C_data;
		}
		else
		{
			CompressionData* _null = nullptr; //Error
			return *_null;
		}
	}

public:
	Tehai_C_Data() : Manzu_C_data(), Pinzu_C_data(), Souzu_C_data(), Zihai_C_data()
	{

	}
	~Tehai_C_Data()
	{

	}

	CompressionData& Get_C_Data(TileType type)
	{
		switch (type)
		{
		case TileType::Manzu:
			return Manzu_C_data;
		case TileType::Pinzu:
			return Pinzu_C_data;
		case TileType::Souzu:
			return Souzu_C_data;
		case TileType::Zihai:
			return Zihai_C_data;
		default:
			CompressionData* _null = nullptr; //Error
			return *_null;
			break;
		}
	}

	C_Data& operator*=(Tile& tile) //”v‚Ì‘}“ü
	{
		return CheckType(tile) *= primeTable[tile.GetTileNum() % 9];
	}
	C_Data& operator/=(Tile& tile) //”v‚Ìíœ
	{
		return CheckType(tile) /= primeTable[tile.GetTileNum() % 9];
	}
	const C_Data& operator%(Tile& tile) //‚»‚Ì”v‚ª‚ ‚é‚©‚Ì˜_—ŽZ(–ß‚è’l‚ÍC_Data)
	{
		return CheckType(tile) % primeTable[tile.GetTileNum() % 9];
	}

	void ExtractHai(Tile& tile) //”v‚ð”²‚«o‚·
	{
		this->operator/=(tile);
	}
	void InsertHai(Tile& tile)  //”v‚ð·‚µž‚Þ
	{
		this->operator*=(tile);
	}
	bool ExistHai(Tile& tile)	//”v‚Ì‘¶Ý”»’è 
	{
		return this->operator%(tile);
	}

	//bool CheckToitsu










};

C_Data ChengePrime(unsigned int num)
{
	return primeTable[num % 9];
}

