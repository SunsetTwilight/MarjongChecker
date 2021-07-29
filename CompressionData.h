#pragma once

class CompressionData
{
private:
	unsigned long long int data;

public:
	CompressionData();

	unsigned long long int& operator*=(const unsigned long long int d); //”v‚Ì‘}“ü
	unsigned long long int& operator/=(const unsigned long long int d); //”v‚Ìíœ

	const unsigned long long int& operator%(const unsigned long long int d); //‚»‚Ì”v‚ª‚ ‚é‚©‚Ì˜_—Z(–ß‚è’l‚ÍC_Data)

	bool operator==(const unsigned long long int d);
	bool operator!=(const unsigned long long int d);
};

