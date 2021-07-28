#pragma once
#include "MarjongChecker.h"
#include <vector>

template <class _Ty>
class FormChecker
{
private:
    
protected:
    std::vector<_Ty> form_list;
   
public:

    FormChecker() {} 
    ~FormChecker() {}

   bool virtual CreateFormList(Tehai checkData) = 0;
};
