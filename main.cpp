#include <stdio.h>
#include "DefaultFormChecker.h"
#include "Tehai.h"

int main()
{
	unsigned int num_list[14] =
	{
		0,0,0,1,2,3,4,5,6,7,8,8,8,NullTile
	};

	DefaultTehai tehai;

	for (int i = 0; i < 14; i++)
	{
		tehai.SetTile(i, num_list[i]);
	}

	DefaultFormChecker dfc;
	dfc.CreateFormList(tehai);

	return 0;
}