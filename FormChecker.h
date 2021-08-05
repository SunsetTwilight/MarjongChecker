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

   unsigned int GetSize() { return (unsigned int)form_list.size(); }

   _Ty& Get(unsigned int& num) { return form_list[num]; }
   _Ty& Get(const unsigned int& num) { return form_list[num]; }

   _Ty* GetAddress(unsigned int& num) { return &form_list[num]; }
   _Ty* GetAddress(const unsigned int& num) { return &form_list[num]; }
};
