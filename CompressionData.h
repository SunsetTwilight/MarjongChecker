#pragma once
typedef unsigned long long int C_Data;

class CompressionData
{
private:
	C_Data data;

public:
	CompressionData();

	C_Data& operator*=(const C_Data d); //牌の挿入
	C_Data& operator/=(const C_Data d); //牌の削除

	const C_Data& operator%(const C_Data d); //その牌があるかの論理算(戻り値はC_Data)

	bool operator==(const C_Data d);
	bool operator!=(const C_Data d);
};

