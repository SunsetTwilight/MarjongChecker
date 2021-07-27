#pragma once
#include "MarjongChecker.h"
#include <vector>

template <typename _Ty>
class FormChecker
{
private:
    
protected:
    std::vector<_Ty> form_list;
    bool enable_type[4] = { false };

public:

    FormChecker(){}
    ~FormChecker(){}

   // bool virtual CreateFormList(Tehai checkData) = 0;
};
