#pragma once
#include "MarjongChecker.h"
#include <vector>

enum class MentsuType
{
    Koutsu,
    Syuntsu
};

struct Mentsu
{
    MentsuType type;
    unsigned int num;

    Mentsu(MentsuType type, unsigned int num) : type(type), num(num) {}
};

struct Toitsu
{
    unsigned int num;

    Toitsu(unsigned int num) : num(num) {}
};

enum class TartsuForm
{
    KanTyan,
    Ryanmen
};

struct Tartsu
{
    TartsuForm form;
    unsigned int num;

    Tartsu(TartsuForm form, unsigned int num) : form(form), num(num) {}
};

class Form
{
    std::vector<Mentsu> mentsus;
};

class FormChecker
{
private:



public:

    FormChecker(){}

    bool virtual Check(MarjongChecker checkData) = 0;
};

class DefaultForm : public FormChecker
{
public:
    bool Check(MarjongChecker checkData);
};

class SevenToitsuForm : public FormChecker
{

};
