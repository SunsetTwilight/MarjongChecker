#include <stdio.h>
#include "MarjongChecker.h"
#include "DefaultTehai.h"

int main()
{
	unsigned int num_list[14] =
	{
		0,0,0,1,2,3,4,5,6,7,8,8,8,24
	};

	DefaultTehai tehai;

	for (int i = 0; i < 14; i++)
	{
		tehai.SetTile(i, num_list[i]);
	}

	DefaultFormChecker dfc;
	dfc.CreateFormList(tehai);

	std::vector<DefaultForm> list = dfc.GetList();

	for (int i = 0; i < list.size(); i++)
	{
		for (int k = 0; k < list[i].comp_face.size(); k++)
		{
			if (list[i].comp_face[k].type == DefaultCompleteFaceType::Koutsu)
			{
				printf("%d,%d,%d ", list[i].comp_face[k].num, list[i].comp_face[k].num, list[i].comp_face[k].num);
			}
			else if(list[i].comp_face[k].type == DefaultCompleteFaceType::Syuntsu)
			{
				printf("%d,%d,%d ", list[i].comp_face[k].num, list[i].comp_face[k].num + 1, list[i].comp_face[k].num + 2);
			}
			else
			{
				printf("error Mentsu!!!");
			}
		}
		printf("\n");
		for (int k = 0; k < list[i].one_miss_face.size(); k++)
		{
			if (list[i].one_miss_face[k].type == DefaultMissingFaceForm::Toitsu)
			{
				printf("%d,%d  ", list[i].one_miss_face[k].num, list[i].one_miss_face[k].num);
			}
			else if (list[i].one_miss_face[k].type == DefaultMissingFaceForm::Ryanmen)
			{
				printf("%d,%d  ", list[i].one_miss_face[k].num, list[i].one_miss_face[k].num + 1);
			}
			else if (list[i].one_miss_face[k].type == DefaultMissingFaceForm::KanTyan)
			{
				printf("%d,%d  ", list[i].one_miss_face[k].num, list[i].one_miss_face[k].num + 2);
			}
			else
			{
				printf("error Mentsu!!!");
			}
		}
		printf("\n");
		for (int k = 0; k < list[i].remainder_tile.size(); k++)
		{
			printf("%d,",list[i].remainder_tile[k].GetTileNum());
		}
		printf("\n\n");
	}
	return 0;
}