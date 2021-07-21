#include "DefaultFormChecker.h"

unsigned int DefaultFormChecker::SetKoutsuList(DefaultForm&& res_form, MarjongChecker&& res_check, DefaultForm form, MarjongChecker check)
{
    res_form = form;
    res_check = check;

    for (unsigned int i = 0; i < 4; i++)
    {
        if (res_check.CheckType((TileType)i) != 1)
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                if (res_check.CheckKoutsu(j))
                {
                    res_check.ExtractHai(j);
                    res_check.ExtractHai(j);
                    res_check.ExtractHai(j);

                    res_form.comp_face.push_back(DefaultCompleteFace(DefaultCompleteFaceType::Koutsu, j));
                }
            }
        }
    }
}
unsigned int DefaultFormChecker::SetSyuntsuFrontList(DefaultForm&& res_form, MarjongChecker&& res_check, DefaultForm form, MarjongChecker check)
{
    res_form = form;
    res_check = check;

    for (unsigned int i = 0; i < 4; i++)
    {
        if (check.CheckType((TileType)i) != 1)
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                if (check.CheckSyuntsu(j))
                {
                    check.ExtractHai(j);
                    check.ExtractHai(j + 1);
                    check.ExtractHai(j + 2);

                    res_form.comp_face.push_back(DefaultCompleteFace(DefaultCompleteFaceType::Syuntsu, j));
                }
            }
        }
    }
}
unsigned int DefaultFormChecker::SetSyuntsuBackList(DefaultForm&& res_form, MarjongChecker&& res_check, DefaultForm form, MarjongChecker check)
{
    res_form = form;
    res_check = check;

    for (unsigned int i = 0; i < 3; i++)
    {
        if (check.CheckType((TileType)i) != 1)
        {
            for (unsigned int j = 6; 0 < j; j--)
            {
                if (check.CheckSyuntsu(j))
                {
                    check.ExtractHai(j);
                    check.ExtractHai(j - 1);
                    check.ExtractHai(j - 2);
                }
            }
        }
    }
}

unsigned int DefaultFormChecker::SetToitsuList(DefaultForm&& res_form, MarjongChecker&& res_check, DefaultForm form, MarjongChecker check)
{
    res_form = form;
    res_check = check;

    for (unsigned int i = 0; i < 4; i++)
    {
        if (check.CheckType((TileType)i) != 1)
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                if (check.CheckToitsu(j))
                {
                    check.ExtractHai(j);
                    check.ExtractHai(j);
                }
            }
        }
    }
}
unsigned int DefaultFormChecker::SetTartsuFrontList(DefaultForm&& res_form, MarjongChecker&& res_check, DefaultForm form, MarjongChecker check)
{
    res_form = form;
    res_check = check;

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
                if (check.CheckTartsu(start_num, patarn_num))
                {
                    check.ExtractHai(start_num);
                    check.ExtractHai(start_num + patarn_num + 1);
                }
            }
        }
    }
}
unsigned int DefaultFormChecker::SetTartsuBackList(DefaultForm&& res_form, MarjongChecker&& res_check, DefaultForm form, MarjongChecker check)
{
    res_form = form;
    res_check = check;

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
                if (check.CheckTartsu(start_num, patarn_num))
                {
                    check.ExtractHai(start_num);
                    check.ExtractHai(start_num + patarn_num + 1);
                }
            }
        }
    }
}

bool DefaultFormChecker::CreateFormList(MarjongChecker checkData)
{
	MarjongChecker data = checkData;

	enable_type[0] = data.CheckType(TileType::Manzu);
	enable_type[1] = data.CheckType(TileType::Pinzu);
	enable_type[2] = data.CheckType(TileType::Souzu);
	enable_type[3] = data.CheckType(TileType::Zihai);

	//“ª‚ª‚ ‚é‚Æ‰¼’è‚µ‚½ê‡‚Ìˆ—

	form_list.size();

	Tile tile;
	for (int i = 0; i < 33; i++)
	{
		tile.SetTileNum(i);
		if (data.CheckToitsu(tile)) //“ªi‘ÎŽqj‚ª‚ ‚é
		{
			for (unsigned int i = 0; i < 33; i++)
			{
                

				//SetKoutsuList()
					//SyuntsuFront()
						//Toitsu()
							//TartsuFront()
								//Set()
								 
							//TartsuBack()
								//Set()
								 
						//TartsuFront()
							//Toitsu()
								//Set()
								
						//TartsuBack()
							//Toitsu()
								//Set()

					//SyuntsuBack()
						//Toitsu()
							//TartsuFront()
								//Set()
							 
							//TartsuBack()
								//Set()
								
						//TartsuFront()
							//Toitsu()
								//Set()
								
						//TartsuBack()
							//Toitsu()
								//Set()


				//SyuntsuFront()
					//Koutsu()			
						//Toitsu()
							//TartsuFront()
							//TartsuBack()
						//TartsuFront()
								//Toitsu()
						//TartsuBack()
							//Toitsu()


				//SyuntsuBack()
					//Koutsu()
						//Toitsu()
							//TartsuFront()
							//TartsuBack()
						//TartsuFront()
								//Toitsu()
						//TartsuBack()
							//Toitsu()
			}
		}
	}


	//“ª‚ª–³‚¢‚Æ‰¼’è‚µ‚½ê‡‚Ìˆ—


}