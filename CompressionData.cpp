#include "CompressionData.h"

CompressionData::CompressionData() { data = 1; }

C_Data& CompressionData::operator*=(const C_Data d) { return data *= d; } //牌の挿入
C_Data& CompressionData::operator/=(const C_Data d) { return data /= d; } //牌の削除

const C_Data& CompressionData::operator%(const C_Data d) { return data % d; } //その牌があるかの論理算(戻り値はC_Data)

bool CompressionData::operator==(const C_Data d) { return data == d; }
bool CompressionData::operator!=(const C_Data d) { return data != d; }