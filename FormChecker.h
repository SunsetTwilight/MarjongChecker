#pragma once
#include "MarjongChecker.h"

class FormChecker :
    public MarjongChecker
{
    bool Tenpai;

public:
    bool virtual Check() = 0;
};

class DefaultForm : public FormChecker
{

};

class SevenToitsuForm : public FormChecker
{

};
