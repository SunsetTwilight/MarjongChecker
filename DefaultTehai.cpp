#include "DefaultTehai.h"

void DefaultTehai::Naki(DefaultNakiFace face)
{
	if (naki_count < 4)
	{
		switch (face.type)
		{
		case DefaultNakiFaceType::Koutsu:

			break;
		case DefaultNakiFaceType::Syuntsu:

			break;
		default:
			break;
		}

		for (unsigned int i = 0; i < tehai_count; i++)
		{
			if (face.num)
				tiles[i].SetTileNum(NullTile);
		}



		tehai_count -= 3;
		compFace[naki_count] = new DefaultNakiFace(face);
		naki_count++;
	}
}
