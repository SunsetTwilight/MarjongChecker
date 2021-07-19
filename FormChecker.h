#pragma once
#include "MarjongChecker.h"

enum class MentsuType
{
    Tartsu,
    Toitsu,
    Koutsu,
    Syuntsu
};

struct Mentsu
{
    MentsuType type;
    int num;

    Mentsu(MentsuType type, unsigned int num) : type(type), num(num) {}
};




class FormChecker : public MarjongChecker
{
    bool Tenpai;

public:

    FormChecker(){}

    bool virtual Check() = 0;
};

class DefaultForm : public FormChecker
{
public:
    bool Check();
};

class SevenToitsuForm : public FormChecker
{

};
