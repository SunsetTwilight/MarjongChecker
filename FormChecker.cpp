#include "FormChecker.h"

bool DefaultForm::Check(MarjongChecker checkData)
{
	MarjongChecker data = checkData;

	bool enable_type[4] = { false };

	enable_type[0] = data.CheckType(TileType::Manzu);
	enable_type[1] = data.CheckType(TileType::Pinzu);
	enable_type[2] = data.CheckType(TileType::Souzu);
	enable_type[3] = data.CheckType(TileType::Zihai);

	//雀頭があると仮定した場合の処理

	Tile tile;
	for (int i = 0; i < 33; i++)
	{
		tile.SetTileNum(i);
		if (data.CheckToitsu(tile)) //雀頭（対子）がある
		{
			for (unsigned int i = 0; i < 33; i++)
			{
				//Koutsu()
					//SyuntsuFront()
						//Toitsu()
							//TartsuFront()
							//TartsuBack()
						//TartsuFront()
								//Toitsu()
						//TartsuBack()
							//Toitsu()
							
					//SyuntsuBack()
						//Toitsu()
							//TartsuFront()
							//TartsuBack()
						//TartsuFront()
								//Toitsu()
						//TartsuBack()
							//Toitsu()
							 
							
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


	//雀頭が無いと仮定した場合の処理


}