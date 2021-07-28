#include "Tile.h"

unsigned int& Tile::GetTileNum()
{
	return tile_num;
}

void Tile::SetTileNum(unsigned int num)
{
	tile_num = num;
}

void Tile::ChangeTable(Tile& tile)
{
	std::swap(tile_num, tile.GetTileNum());
}

Tile::Tile() :tile_num(NullTile) {}
Tile::Tile(unsigned int& num) : tile_num(num) {}
Tile::Tile(const unsigned int& num) : tile_num(num) {}

const unsigned int Tile::operator+(const unsigned int num) { return GetTileNum() + num; }
const unsigned int Tile::operator-(const unsigned int num) { return GetTileNum() + num; }

