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


enum class DefaultNakiFaceType
{
    Koutsu,
    Syuntsu,
    MinKan,
    DaiMinKan,
    AnnKan,
};

class DefaultNakiFace : public CompleteFace<DefaultNakiFaceType>
{

public:
    DefaultNakiFace(DefaultNakiFaceType type, unsigned int num) : CompleteFace(type, num)
    {

    }
};
