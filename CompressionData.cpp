#include "CompressionData.h"

CompressionData::CompressionData() { data = 1; }

C_Data& CompressionData::operator*=(const C_Data d) { return data *= d; } //”v‚Ì‘}“ü
C_Data& CompressionData::operator/=(const C_Data d) { return data /= d; } //”v‚Ìíœ

const C_Data& CompressionData::operator%(const C_Data d) { return data % d; } //‚»‚Ì”v‚ª‚ ‚é‚©‚Ì˜_—Z(–ß‚è’l‚ÍC_Data)

bool CompressionData::operator==(const C_Data d) { return data == d; }
bool CompressionData::operator!=(const C_Data d) { return data != d; }