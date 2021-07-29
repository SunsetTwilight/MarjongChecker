#include "CompressionData.h"

CompressionData::CompressionData() { data = 1; }

unsigned long long int& CompressionData::operator*=(const unsigned long long int d) { return data *= d; } //”v‚Ì‘}“ü
unsigned long long int& CompressionData::operator/=(const unsigned long long int d) { return data /= d; } //”v‚Ìíœ

const unsigned long long int& CompressionData::operator%(const unsigned long long int d) { return data % d; } //‚»‚Ì”v‚ª‚ ‚é‚©‚Ì˜_—Z(–ß‚è’l‚ÍC_Data)

bool CompressionData::operator==(const unsigned long long int d) { return data == d; }
bool CompressionData::operator!=(const unsigned long long int d) { return data != d; }