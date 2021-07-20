#pragma once
typedef unsigned long long int C_Data;
unsigned primeTable[]{ 2,3,5,7,11,13,17,23,29 };

class CompressionData
{
private:
	C_Data data;

public:
	CompressionData() { data = 1; }

	C_Data& operator*=(const C_Data d) { return data *= d; } //�v�̑}��
	C_Data& operator/=(const C_Data d) { return data /= d; } //�v�̍폜

	const C_Data& operator%(const C_Data d) { return data % d; } //���̔v�����邩�̘_���Z(�߂�l��C_Data)

	bool operator==(const C_Data d) { return data == d; }
	bool operator!=(const C_Data d) { return data != d; }
};

