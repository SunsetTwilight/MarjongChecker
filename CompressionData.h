#pragma once
typedef unsigned long long int C_Data;
unsigned primeTable[]{ 2,3,5,7,11,13,17,23,29 };

class CompressionData
{
private:
	C_Data data;

public:
	CompressionData() { data = 1; }

	C_Data& operator*=(const C_Data d) { return data *= d; } //牌の挿入
	C_Data& operator/=(const C_Data d) { return data /= d; } //牌の削除

	const C_Data& operator%(const C_Data d) { return data % d; } //その牌があるかの論理算(戻り値はC_Data)
};

