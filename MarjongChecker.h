#pragma once
#include <memory>
#include <iostream>

#include "Tehai_C_Data.h"

class MarjongChecker //�����̔���̊��N���X
{
private:
	Tehai_C_Data data;

public:
	
	bool CheckHai(Tile& tile);
	bool CheckToitsu(Tile& tile);
	bool CheckTartsu(Tile& tile, unsigned int patarn); //(num) ��擪�Ƃ��čl���� (patarn) �̓^�[�c�̕��я� (0 = �A��,1 = 1��΂�)
	bool CheckKoutsu(Tile& tile);
	bool CheckSyuntsu(Tile& tile); //(num) ��擪�Ƃ��čl����
	bool CheckKantsu(Tile& tile);

	bool CheckHai(unsigned int& num);
	bool CheckToitsu(unsigned int& num);
	bool CheckTartsu(unsigned int& num, unsigned int& patarn); //(num) ��擪�Ƃ��čl���� (patarn) �̓^�[�c�̕��я� (0 = �A��,1 = 1��΂�)
	bool CheckKoutsu(unsigned int& num);
	bool CheckSyuntsu(unsigned int& num); //(num) ��擪�Ƃ��čl����
	bool CheckKantsu(unsigned int& num);

	bool CheckType(TileType type);

	bool InsertHai(Tile& tile);
	bool InsertHai(unsigned int& tile);
	bool InsertHai(const unsigned int& num);
	
	bool ExtractHai(Tile& tile);
	bool ExtractHai(unsigned int& tile);
	bool ExtractHai(const unsigned int& num);

	MarjongChecker() : data() {}
	virtual ~MarjongChecker() {}

	void Set_TehaiData(/*��v�̔z��*/) {}
	Tehai_C_Data& GetData() { return data; }
};

