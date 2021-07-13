#pragma once
#include <memory>
#include <iostream>

#include "Tehai_C_Data.h"

class MarjongChecker //麻雀の判定の基底クラス
{
private:
	Tehai_C_Data data;

protected:
	bool CheckHai(unsigned int num);
	bool CheckHai(Tile& tile);
	bool CheckToitsu(Tile& tile);
	bool CheckTartsu(Tile& tile, unsigned int patarn); //(num) を先頭として考える (patarn) はターツの並び順 (0 = 連番,1 = 1つ飛ばし)
	bool CheckKoutsu(Tile& tile);
	bool CheckSyuntsu(Tile& tile); //(num) を先頭として考える
	bool CheckKantsu(Tile& tile);

public:
	MarjongChecker() : data() {}
	virtual ~MarjongChecker() {}

	void Set_TehaiData(/*手牌の配列*/) {}
	Tehai_C_Data& GetData() { return data; }
};

