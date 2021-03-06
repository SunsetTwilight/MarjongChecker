#pragma once
#include "CompressionData.h"
#include "Tile.h"

#include "PrimeTable.h"

class Tehai_C_Data
{
private:
	CompressionData Manzu_C_data;
	CompressionData Pinzu_C_data;
	CompressionData Souzu_C_data;
	CompressionData Zihai_C_data;

	CompressionData& CheckType(Tile& num);

public:
	Tehai_C_Data();
	~Tehai_C_Data();

	CompressionData& Get_C_Data(TileType type);

	unsigned long long int& operator*=(Tile& tile); //牌の挿入
	unsigned long long int& operator/=(Tile& tile); //牌の削除	
	const unsigned long long int& operator%(Tile& tile); //その牌があるかの論理算(戻り値はC_Data)	

	void ExtractHai(Tile& tile); //牌を抜き出す		
	void InsertHai(Tile& tile);  //牌を差し込む
	bool ExistHai(Tile& tile);	//牌の存在判定 		
};

