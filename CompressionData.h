#pragma once

class CompressionData
{
private:
	unsigned long long int data;

public:
	CompressionData();

	unsigned long long int& operator*=(const unsigned long long int d); //牌の挿入
	unsigned long long int& operator/=(const unsigned long long int d); //牌の削除

	const unsigned long long int& operator%(const unsigned long long int d); //その牌があるかの論理算(戻り値はC_Data)

	bool operator==(const unsigned long long int d);
	bool operator!=(const unsigned long long int d);
};

