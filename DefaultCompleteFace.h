#pragma once
#include "CompleteFace.h"

enum class DefaultCompleteFaceType
{
    Koutsu,
    Syuntsu
};

class DefaultCompleteFace : public CompleteFace<DefaultCompleteFaceType>
{

public:
    DefaultCompleteFace(DefaultCompleteFaceType type, unsigned int num) : CompleteFace(type, num)
    {

    }
};

