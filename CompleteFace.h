#pragma once



template <class _Ty>
class CompleteFace
{
public:
    _Ty type;
    unsigned int num;

    CompleteFace(_Ty type, unsigned int num) : type(type), num(num) {}
};

