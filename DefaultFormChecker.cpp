#include "DefaultFormChecker.h"
#include "Tehai.h"

unsigned int DefaultFormChecker::SetKoutsuList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check)
{
    unsigned int count = 0;

    res_form = std::move(form);
    res_check = std::move(check);

    for (unsigned int i = 0; i < 4; i++)
    {
        if (res_check.CheckType((TileType)i))
        {
            if (i == 4)
            {
                for (unsigned int j = 0; j < 7; j++)
                {
                    if (res_check.CheckKoutsu(i * 9 + j))
                    {
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j);

                        res_form.comp_face.push_back(DefaultCompleteFace(DefaultCompleteFaceType::Koutsu, i * 9 + j));
                        count++;
                    }
                }
            }
            else
            {
                for (unsigned int j = 0; j < 9; j++)
                {
                    if (res_check.CheckKoutsu(i * 9 + j))
                    {
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j);

                        res_form.comp_face.push_back(DefaultCompleteFace(DefaultCompleteFaceType::Koutsu, i * 9 + j));
                        count++;
                    }
                }
            }
        }
    }

    return count;
}
unsigned int DefaultFormChecker::SetSyuntsuFrontList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check)
{
    unsigned int count = 0;

    res_form = std::move(form);
    res_check = std::move(check);

    for (unsigned int i = 0; i < 4; i++)
    {
        if (res_check.CheckType((TileType)i))
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                if (res_check.CheckSyuntsu(i * 9 + j))
                {
                    res_check.ExtractHai(i * 9 + j);
                    res_check.ExtractHai(i * 9 + j + 1);
                    res_check.ExtractHai(i * 9 + j + 2);

                    res_form.comp_face.push_back(DefaultCompleteFace(DefaultCompleteFaceType::Syuntsu, i * 9 + j));
                    j--;
                    count++;
                }
            }
        }
    }
    return count;

}
unsigned int DefaultFormChecker::SetSyuntsuBackList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check)
{
    unsigned int count = 0;

    res_form = std::move(form);
    res_check = std::move(check);

    for (unsigned int i = 0; i < 3; i++)
    {
        if (res_check.CheckType((TileType)i))
        {
            for (unsigned int j = 6; 0 < j; j--)
            {
                if (res_check.CheckSyuntsu(i * 9 + j))
                {
                    res_check.ExtractHai(i * 9 + j);
                    res_check.ExtractHai(i * 9 + j + 1);
                    res_check.ExtractHai(i * 9 + j + 2);

                    res_form.comp_face.push_back(DefaultCompleteFace(DefaultCompleteFaceType::Syuntsu, i * 9 + j));
                    j++;
                    count++;
                }
            }
        }
    }

    return count;
}

unsigned int DefaultFormChecker::SetToitsuList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check)
{
    unsigned int count = 0;

    res_form = std::move(form);
    res_check = std::move(check);

    for (unsigned int i = 0; i < 4; i++)
    {
        if (res_check.CheckType((TileType)i))
        {
            if (i == 4)
            {
                for (unsigned int j = 0; j < 7; j++)
                {
                    if (res_check.CheckToitsu(i * 9 + j))
                    {
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j);

                        res_form.one_miss_face.push_back(DefaultMissingFace(DefaultMissingFaceForm::Toitsu, i * 9 + j));
                        count++;
                    }
                }
            }
            else
            {
                for (unsigned int j = 0; j < 9; j++)
                {
                    if (res_check.CheckToitsu(i * 9 + j))
                    {
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j);

                        res_form.one_miss_face.push_back(DefaultMissingFace(DefaultMissingFaceForm::Toitsu, i * 9 + j));
                        count++;
                    }
                }
            }
        }
    }

    return count++;
}
unsigned int DefaultFormChecker::SetTartsuFrontList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check)
{
    unsigned int count = 0;

    res_form = std::move(form);
    res_check = std::move(check);

    for (unsigned int i = 0; i < 3; i++)
    {
        if (res_check.CheckType((TileType)i))
        {
            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    unsigned int num = k;
                    if (res_check.CheckTartsu(i * 9 + j, num))
                    {
                        if (j == 8 && k == 1) continue;
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j + k + 1);

                        res_form.one_miss_face.push_back(DefaultMissingFace((DefaultMissingFaceForm)(k + 1), i * 9 + j));
                        count++;
                    }
                }
            }
        }
    }

    return count;
}
unsigned int DefaultFormChecker::SetTartsuBackList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check)
{
    unsigned int count = 0;

    res_form = std::move(form);
    res_check = std::move(check);

    for (unsigned int i = 0; i < 3; i++)
    {
        if (res_check.CheckType((TileType)i))
        {
            for (int j = 7; 0 <= j; j--)
            {
                for (int k = 1; 0 <= k; k--)
                {
                    unsigned int num = k;
                    if (res_check.CheckTartsu(i * 9 + j, num))
                    {
                        if (j == 8 && k == 1) continue;
                        res_check.ExtractHai(i * 9 + j);
                        res_check.ExtractHai(i * 9 + j + k + 1);

                        res_form.one_miss_face.push_back(DefaultMissingFace((DefaultMissingFaceForm)(k + 1), i * 9 + j));
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

void DefaultFormChecker::SetFormList(DefaultForm& form, MarjongChecker& check)
{
    //残り牌の羅列、セット
    //int num = form.comp_face.size() + form.one_miss_face.size();

    for (unsigned int i = 0; i < 4; i++)
    {
        if (check.CheckType((TileType)i))
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                if (check.CheckHai((i * 9) + j))
                {
                    form.remainder_tile.push_back((i * 9) + j);
                }
            }
        }
    }

    form_list.push_back(form);
}


void DefaultFormChecker::DefaultCreate(DefaultForm form, MarjongChecker check)
{
    DefaultForm f00;
    MarjongChecker c00;
    SetKoutsuList(f00, c00, form, check);
    {
        DefaultForm f01;
        MarjongChecker c01;
        SetSyuntsuFrontList(f01, c01, f00, c00);
        {
            DefaultForm f02;
            MarjongChecker c02;
            SetToitsuList(f02, c02, f01, c01);
            {
                DefaultForm f03;
                MarjongChecker c03;
                SetTartsuFrontList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
                SetTartsuBackList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
            }
            SetTartsuFrontList(f02, c02, f01, c01);
            {
                DefaultForm f03;
                MarjongChecker c03;
                SetToitsuList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
            }
            SetTartsuBackList(f02, c02, f01, c01);
            {
                DefaultForm f03;
                MarjongChecker c03;
                SetToitsuList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
            }
        }
        SetSyuntsuBackList(f01, c01, f00, c00);
        {
            DefaultForm f02;
            MarjongChecker c02;
            SetToitsuList(f02, c02, f01, c01);
            {
                DefaultForm f03;
                MarjongChecker c03;
                SetTartsuFrontList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
                SetTartsuBackList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
            }
            SetTartsuFrontList(f02, c02, f01, c01);
            {
                DefaultForm f03;
                MarjongChecker c03;
                SetToitsuList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
            }
            SetTartsuBackList(f02, c02, f01, c01);
            {
                DefaultForm f03;
                MarjongChecker c03;
                SetToitsuList(f03, c03, f02, c02);
                {
                    SetFormList(f03, c03);
                }
            }
        }
    }
}

bool DefaultFormChecker::CreateFormList(Tehai tehai)
{
    form_list.clear();
    MarjongChecker data;
    data.Set_TehaiData(tehai);	

    for (int i = 0; i < 34; i++)
    {
        //雀頭があると仮定した場合の処理
        MarjongChecker checker;
        checker.Set_TehaiData(tehai);
        DefaultForm form = {};

        if (checker.CheckToitsu(i)) //雀頭（対子）がある
        {
            checker.ExtractHai(i);
            checker.ExtractHai(i);
            form.one_miss_face.push_back(DefaultMissingFace(DefaultMissingFaceForm::Toitsu, i));

            DefaultCreate(form, checker);
        }

        //雀頭が無いと仮定した場合の処理
        checker.Set_TehaiData(tehai);
        DefaultForm form_1 = {};

        if (checker.CheckHai(i))
        {
            checker.ExtractHai(i);
            form_1.remainder_tile.push_back(i);

            DefaultCreate(form_1, checker);
        }
    } 	
    return true;
}