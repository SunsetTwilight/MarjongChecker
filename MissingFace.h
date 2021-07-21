#pragma once



template <class _Ty>
class MissingFace
{
public:
    _Ty type;
    unsigned int num;

    MissingFace(_Ty type, unsigned int num) : type(type), num(num) {}
};

