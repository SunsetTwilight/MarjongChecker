#include "CompressionData.h"

CompressionData::CompressionData() { data = 1; }

unsigned long long int& CompressionData::operator*=(const unsigned long long int d) { return data *= d; } //�v�̑}��
unsigned long long int& CompressionData::operator/=(const unsigned long long int d) { return data /= d; } //�v�̍폜

const unsigned long long int& CompressionData::operator%(const unsigned long long int d) { return data % d; } //���̔v�����邩�̘_���Z(�߂�l��C_Data)

bool CompressionData::operator==(const unsigned long long int d) { return data == d; }
bool CompressionData::operator!=(const unsigned long long int d) { return data != d; }