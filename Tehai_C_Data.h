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

	C_Data& operator*=(Tile& tile); //�v�̑}��
	C_Data& operator/=(Tile& tile); //�v�̍폜	
	const C_Data& operator%(Tile& tile); //���̔v�����邩�̘_���Z(�߂�l��C_Data)	

	void ExtractHai(Tile& tile); //�v�𔲂��o��		
	void InsertHai(Tile& tile);  //�v����������
	bool ExistHai(Tile& tile);	//�v�̑��ݔ��� 		
};

