#pragma once
typedef unsigned long long int C_Data;
unsigned primeTable[]{ 2,3,5,7,11,13,17,23,29 };

class CompressionData
{
private:
	C_Data data;

public:
	CompressionData() { data = 1; }

	C_Data& operator*=(const C_Data d) { return data *= d; } //”v‚Ì‘}“ü
	C_Data& operator/=(const C_Data d) { return data /= d; } //”v‚Ìíœ

	const C_Data& operator%(const C_Data d) { return data % d; } //‚»‚Ì”v‚ª‚ ‚é‚©‚Ì˜_—Z(–ß‚è’l‚ÍC_Data)

	bool operator==(const C_Data d) { return data == d; }
	bool operator!=(const C_Data d) { return data != d; }
};

