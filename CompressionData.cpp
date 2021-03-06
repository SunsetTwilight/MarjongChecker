#include "CompressionData.h"

CompressionData::CompressionData() { data = 1; }

unsigned long long int& CompressionData::operator*=(const unsigned long long int d) { return data *= d; } //牌の挿入
unsigned long long int& CompressionData::operator/=(const unsigned long long int d) { return data /= d; } //牌の削除

const unsigned long long int& CompressionData::operator%(const unsigned long long int d) { return data % d; } //その牌があるかの論理算(戻り値はC_Data)

bool CompressionData::operator==(const unsigned long long int d) { return data == d; }
bool CompressionData::operator!=(const unsigned long long int d) { return data != d; }