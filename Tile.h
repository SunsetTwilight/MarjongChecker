#pragma once
#include <iostream>

enum class TileType
{
	Manzu,
	Pinzu,
	Souzu,
	Zihai
};

constexpr unsigned int NullTile = 34;

struct Tile
{
private:
	unsigned int tile_num;

public:
	unsigned int& GetTileNum();
	void SetTileNum(unsigned int num);
	void ChangeTable(Tile& tile);

	Tile();
	Tile(unsigned int& num);
	Tile(const unsigned int& num);
	//Tile(const Tile&) {};

	void operator=(Tile) = delete;
	void operator=(Tile&) = delete;
	void operator=(const Tile&) = delete;

	const unsigned int operator+(const unsigned int num);
	const unsigned int operator-(const unsigned int num);
};

//inline unsigned int operator+(Tile& tile, const unsigned int num) { return tile.GetTileNum() + num; }
//inline unsigned int operator-(Tile& tile, const unsigned int num) { return tile.GetTileNum() + num; }