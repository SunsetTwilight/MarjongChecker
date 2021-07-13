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

	C_Data& operator*=(Tile& tile) //牌の挿入
	{
		return CheckType(tile) *= primeTable[tile.GetTileNum() % 9];
	}
	C_Data& operator/=(Tile& tile) //牌の削除
	{
		return CheckType(tile) /= primeTable[tile.GetTileNum() % 9];
	}
	const C_Data& operator%(Tile& tile) //その牌があるかの論理算(戻り値はC_Data)
	{
		return CheckType(tile) % primeTable[tile.GetTileNum() % 9];
	}

	void ExtractHai(Tile& tile) //牌を抜き出す
	{
		this->operator/=(tile);
	}
	void InsertHai(Tile& tile)  //牌を差し込む
	{
		this->operator*=(tile);
	}
	bool ExistHai(Tile& tile)	//牌の存在判定 
	{
		return this->operator%(tile);
	}
};

C_Data ChengePrime(unsigned int num)
{
	return primeTable[num % 9];
}

