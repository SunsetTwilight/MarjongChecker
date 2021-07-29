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

	unsigned long long int& operator*=(Tile& tile); //”v‚Ì‘}“ü
	unsigned long long int& operator/=(Tile& tile); //”v‚Ìíœ	
	const unsigned long long int& operator%(Tile& tile); //‚»‚Ì”v‚ª‚ ‚é‚©‚Ì˜_—Z(–ß‚è’l‚ÍC_Data)	

	void ExtractHai(Tile& tile); //”v‚ğ”²‚«o‚·		
	void InsertHai(Tile& tile);  //”v‚ğ·‚µ‚Ş
	bool ExistHai(Tile& tile);	//”v‚Ì‘¶İ”»’è 		
};

