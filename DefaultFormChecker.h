#pragma once
#include "FormChecker.h"

#include <vector>
#include "DefaultCompleteFace.h"
#include "DefaultMissingFace.h"


struct DefaultForm
{
    std::vector<DefaultCompleteFace> comp_face;
    std::vector<DefaultMissingFace> one_miss_face;

    std::vector<Tile> remainder_tile;
};

class DefaultFormChecker : public FormChecker<DefaultForm>
{
private:
    unsigned int SetKoutsuList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check);
    unsigned int SetSyuntsuFrontList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check);
    unsigned int SetSyuntsuBackList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check);
    unsigned int SetToitsuList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check);
    unsigned int SetTartsuFrontList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check);
    unsigned int SetTartsuBackList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check);

    void SetFormList(DefaultForm& res_form, MarjongChecker& res_check);

    std::vector<DefaultForm> curFormList;

public:
    bool CreateFormList(Tehai tehai);

    DefaultFormChecker() {}
    ~DefaultFormChecker() {}
};

