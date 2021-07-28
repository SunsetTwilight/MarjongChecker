#pragma once
typedef unsigned long long int C_Data;

class CompressionData
{
private:
	C_Data data;

public:
	CompressionData();

	C_Data& operator*=(const C_Data d); //”v‚Ì‘}“ü
	C_Data& operator/=(const C_Data d); //”v‚Ìíœ

	const C_Data& operator%(const C_Data d); //‚»‚Ì”v‚ª‚ ‚é‚©‚Ì˜_—Z(–ß‚è’l‚ÍC_Data)

	bool operator==(const C_Data d);
	bool operator!=(const C_Data d);
};

