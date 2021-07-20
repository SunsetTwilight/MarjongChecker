#pragma once
#include <memory>
#include <iostream>

#include "Tehai_C_Data.h"

class MarjongChecker //�����̔���̊��N���X
{
private:
	Tehai_C_Data data;

public:
	bool CheckHai(unsigned int num);
	bool CheckHai(Tile& tile);
	bool CheckToitsu(Tile& tile);
	bool CheckTartsu(Tile& tile, unsigned int patarn); //(num) ��擪�Ƃ��čl���� (patarn) �̓^�[�c�̕��я� (0 = �A��,1 = 1��΂�)
	bool CheckKoutsu(Tile& tile);
	bool CheckSyuntsu(Tile& tile); //(num) ��擪�Ƃ��čl����
	bool CheckKantsu(Tile& tile);

	bool CheckType(TileType type);

	bool InsertHai(Tile& tile);
	bool ExtractHai(Tile& tile);


	MarjongChecker() : data() {}
	virtual ~MarjongChecker() {}

	void Set_TehaiData(/*��v�̔z��*/) {}
	Tehai_C_Data& GetData() { return data; }
};

