#pragma once
typedef unsigned long long int C_Data;

class CompressionData
{
private:
	C_Data data;

public:
	CompressionData();

	C_Data& operator*=(const C_Data d); //�v�̑}��
	C_Data& operator/=(const C_Data d); //�v�̍폜

	const C_Data& operator%(const C_Data d); //���̔v�����邩�̘_���Z(�߂�l��C_Data)

	bool operator==(const C_Data d);
	bool operator!=(const C_Data d);
};

