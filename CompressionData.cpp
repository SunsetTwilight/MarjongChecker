#include "CompressionData.h"

CompressionData::CompressionData() { data = 1; }

C_Data& CompressionData::operator*=(const C_Data d) { return data *= d; } //�v�̑}��
C_Data& CompressionData::operator/=(const C_Data d) { return data /= d; } //�v�̍폜

const C_Data& CompressionData::operator%(const C_Data d) { return data % d; } //���̔v�����邩�̘_���Z(�߂�l��C_Data)

bool CompressionData::operator==(const C_Data d) { return data == d; }
bool CompressionData::operator!=(const C_Data d) { return data != d; }