#pragma once
#include "Tehai.h"

#include "DefaultFormChecker.h"
#include "DefaultCompleteFace.h"

class DefaultTehai : public Tehai
{
private:
	unsigned int tehai_count = 14;

	DefaultNakiFace* compFace[4] = { nullptr };
	unsigned int naki_count = 0;

public:
	void Naki(DefaultNakiFace face);

	DefaultTehai() {}
	~DefaultTehai() {}
};