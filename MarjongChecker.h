#pragma once
#include <memory>
#include <iostream>

#include "Tehai_C_Data.h"

class MarjongChecker //麻雀の判定の基底クラス
{
private:
	Tehai_C_Data data;

public:
	
	bool CheckHai(Tile& tile);
	bool CheckToitsu(Tile& tile);
	bool CheckTartsu(Tile& tile, unsigned int patarn); //(num) を先頭として考える (patarn) はターツの並び順 (0 = 連番,1 = 1つ飛ばし)
	bool CheckKoutsu(Tile& tile);
	bool CheckSyuntsu(Tile& tile); //(num) を先頭として考える
	bool CheckKantsu(Tile& tile);

	bool CheckHai(unsigned int& num);
	bool CheckToitsu(unsigned int& num);
	bool CheckTartsu(unsigned int& num, unsigned int& patarn); //(num) を先頭として考える (patarn) はターツの並び順 (0 = 連番,1 = 1つ飛ばし)
	bool CheckKoutsu(unsigned int& num);
	bool CheckSyuntsu(unsigned int& num); //(num) を先頭として考える
	bool CheckKantsu(unsigned int& num);

	bool CheckHai(const unsigned int& num);
	bool CheckToitsu(const unsigned int& num);
	bool CheckTartsu(const unsigned int& num, unsigned int& patarn); //(num) を先頭として考える (patarn) はターツの並び順 (0 = 連番,1 = 1つ飛ばし)
	bool CheckKoutsu(const unsigned int& num);
	bool CheckSyuntsu(const unsigned int& num); //(num) を先頭として考える
	bool CheckKantsu(const unsigned int& num);


	bool CheckType(TileType type);

	bool InsertHai(Tile& tile);
	bool InsertHai(unsigned int& tile);
	bool InsertHai(const unsigned int& num);
	
	bool ExtractHai(Tile& tile);
	bool ExtractHai(unsigned int& tile);
	bool ExtractHai(const unsigned int& num);

	MarjongChecker() : data() {}
	virtual ~MarjongChecker() {}

	void Set_TehaiData(/*手牌の配列*/) {}
	Tehai_C_Data& GetData() { return data; }
};

