#pragma once

class CompressionData
{
private:
	unsigned long long int data;

public:
	CompressionData();

	unsigned long long int& operator*=(const unsigned long long int d); //�v�̑}��
	unsigned long long int& operator/=(const unsigned long long int d); //�v�̍폜

	const unsigned long long int& operator%(const unsigned long long int d); //���̔v�����邩�̘_���Z(�߂�l��C_Data)

	bool operator==(const unsigned long long int d);
	bool operator!=(const unsigned long long int d);
};

