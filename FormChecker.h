#pragma once
#include "MarjongChecker.h"
#include <vector>

template <class _Ty>
class FormChecker
{
private:
    
protected:
    std::vector<_Ty> form_list;
    bool enable_type[4] = { false };

public:

    FormChecker(){}

    bool virtual CreateFormList(MarjongChecker checkData) = 0;
};
