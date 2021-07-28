#include "DefaultFormChecker.h"
#include "Tehai.h"

unsigned int DefaultFormChecker::SetKoutsuList(DefaultForm& res_form, MarjongChecker& res_check, DefaultForm form, MarjongChecker check)
{
    unsigned int count = 0;

    res_form = std::move(form);
    res_check = std::move(check);

    for (unsigned int i = 0; i < 4; i++)
    {
        if (res_check.CheckType((TileType)i) != 1)
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
        if (check.CheckType((TileType)i) != 1)
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                if (check.CheckSyuntsu(i * 9 + j))
                {
                    check.ExtractHai(i * 9 + j);
                    check.ExtractHai(i * 9 + j + 1);
                    check.ExtractHai(i * 9 + j + 2);

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
        if (check.CheckType((TileType)i) != 1)
        {
            for (unsigned int j = 6; 0 < j; j--)
            {
                if (check.CheckSyuntsu(i * 9 + j))
                {
                    check.ExtractHai(i * 9 + j);
                    check.ExtractHai(i * 9 + j - 1);
                    check.ExtractHai(i * 9 + j - 2);

                    res_form.comp_face.push_back(DefaultCompleteFace(DefaultCompleteFaceType::Syuntsu, i * 9 + j - 2));
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
        if (check.CheckType((TileType)i) != 1)
        {
            if (i == 4)
            {
                for (unsigned int j = 0; j < 7; j++)
                {
                    if (check.CheckToitsu(i * 9 + j))
                    {
                        check.ExtractHai(i * 9 + j);
                        check.ExtractHai(i * 9 + j);

                        res_form.one_miss_face.push_back(DefaultMissingFace(MissingFaceForm::Toitsu, i * 9 + j));
                        count++;
                    }
                }
            }
            else
            {
                for (unsigned int j = 0; j < 9; j++)
                {
                    if (check.CheckToitsu(i * 9 + j))
                    {
                        check.ExtractHai(i * 9 + j);
                        check.ExtractHai(i * 9 + j);

                        res_form.one_miss_face.push_back(DefaultMissingFace(MissingFaceForm::Toitsu, i * 9 + j));
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
        if (check.CheckType((TileType)i) != 1)
        {
            unsigned int start_num = 0;
            unsigned int patarn_num = 0;

            for (unsigned int j = 0; j < 15; j++)
            {
                start_num = j / 8;
                patarn_num = j % 2;
                if (check.CheckTartsu(i * 9 + start_num, patarn_num))
                {
                    check.ExtractHai(i * 9 + start_num);
                    check.ExtractHai(i * 9 + start_num + patarn_num + 1);

                    res_form.one_miss_face.push_back(DefaultMissingFace((MissingFaceForm)(patarn_num + 1), i * 9 + j));
                    j--;
                    count++;
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
        if (check.CheckType((TileType)i) != 1)
        {
            unsigned int start_num = 0;
            unsigned int patarn_num = 0;

            for (int j = 14; 0 <= j; j--)
            {
                start_num = j / 8;
                patarn_num = j % 2;
                if (check.CheckTartsu(i * 9 + start_num, patarn_num))
                {
                    check.ExtractHai(i * 9 + start_num);
                    check.ExtractHai(i * 9 + start_num + patarn_num + 1);

                    res_form.one_miss_face.push_back(DefaultMissingFace((MissingFaceForm)(patarn_num + 1), i * 9 + j));
                    j++;
                    count++;
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
        if (check.CheckType((TileType)i) != 1)
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                check.CheckHai((i * 9) + j);
                form.remainder_tile.push_back((i * 9) + j);
            }
        }
    }

    curFormList.push_back(form);
}

bool DefaultFormChecker::CreateFormList(Tehai tehai)
{
    curFormList.clear();
    MarjongChecker data;
    data.Set_TehaiData(tehai);

	//雀頭があると仮定した場合の処理

	Tile tile;
    for (int i = 0; i < 33; i++)
    {
        tile.SetTileNum(i);
        if (data.CheckToitsu(tile)) //雀頭（対子）がある
        {
            MarjongChecker checker = data;
            DefaultForm form = {};

            checker.ExtractHai(i);
            checker.ExtractHai(i);
            form.one_miss_face.push_back(DefaultMissingFace(MissingFaceForm::Toitsu, i));

            DefaultForm f00;
            MarjongChecker c00;
            SetKoutsuList(f00, c00, form, checker);
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
            SetSyuntsuFrontList(f00, c00, form, checker);
            {
                DefaultForm f01;
                MarjongChecker c01;
                SetKoutsuList(f01, c01, f00, c00);
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
            SetSyuntsuBackList(f00, c00, form, checker);
            {
                DefaultForm f01;
                MarjongChecker c01;
                SetKoutsuList(f01, c01, f00, c00);
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

        {
            MarjongChecker checker = data;
            DefaultForm form = {};

            DefaultForm f00;
            MarjongChecker c00;
            SetKoutsuList(f00, c00, form, checker);
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
            SetSyuntsuFrontList(f00, c00, form, checker);
            {
                DefaultForm f01;
                MarjongChecker c01;
                SetKoutsuList(f01, c01, f00, c00);
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
            SetSyuntsuBackList(f00, c00, form, checker);
            {
                DefaultForm f01;
                MarjongChecker c01;
                SetKoutsuList(f01, c01, f00, c00);
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
    }

	//雀頭が無いと仮定した場合の処理


    return true;
}