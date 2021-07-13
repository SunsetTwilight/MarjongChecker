#pragma once
#include <iostream>

enum class TileType
{
	Manzu,
	Pinzu,
	Souzu,
	Zihai
};


struct Tile
{
private:
	unsigned int tile_num;

public:

	unsigned int& GetTileNum() { return tile_num; }
	void SetTileNum(unsigned int num) { tile_num = num; }

	void ChangeTable(Tile& tile) { std::swap(tile_num, tile.GetTileNum()); }

	Tile() :tile_num(34) {};
	Tile(const Tile&) {};

	void operator=(Tile) = delete;
	void operator=(Tile&) = delete;
	void operator=(const Tile&) = delete;

	Tile(unsigned int num) : tile_num(num) {}
	Tile(unsigned int& num) : tile_num(num) {}
	Tile(const unsigned int& num) : tile_num(num) {}

};

unsigned int operator+(Tile& tile, const unsigned int num) { return tile.GetTileNum() + num; }
unsigned int operator-(Tile& tile, const unsigned int num) { return tile.GetTileNum() + num; }