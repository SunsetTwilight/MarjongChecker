#include "Tehai_C_Data.h"

CompressionData& Tehai_C_Data::CheckType(Tile& num)
{
	if (num.GetTileNum() < 9)
	{
		return Manzu_C_data;
	}
	else if (num.GetTileNum() < 18)
	{
		return Pinzu_C_data;
	}
	else if (num.GetTileNum() < 27)
	{
		return Souzu_C_data;
	}
	else if (num.GetTileNum() < 34)
	{
		return Zihai_C_data;
	}
	else
	{
		CompressionData* _null = nullptr; //Error
		return *_null;
	}
}

Tehai_C_Data::Tehai_C_Data() : Manzu_C_data(), Pinzu_C_data(), Souzu_C_data(), Zihai_C_data()
{

}
Tehai_C_Data::~Tehai_C_Data()
{

}

CompressionData& Tehai_C_Data::Get_C_Data(TileType type)
{
	switch (type)
	{
	case TileType::Manzu:
		return Manzu_C_data;
	case TileType::Pinzu:
		return Pinzu_C_data;
	case TileType::Souzu:
		return Souzu_C_data;
	case TileType::Zihai:
		return Zihai_C_data;
	default:
		CompressionData _null; //Error
		return _null;
		break;
	}
}

unsigned long long int& Tehai_C_Data::operator*=(Tile& tile) //�v�̑}��
{
	return CheckType(tile) *= PrimeTable::GetPrimeNumber(tile.GetTileNum() % 9);
}
unsigned long long int& Tehai_C_Data::operator/=(Tile& tile) //�v�̍폜
{
	return CheckType(tile) /= PrimeTable::GetPrimeNumber(tile.GetTileNum() % 9);
}
const unsigned long long int& Tehai_C_Data::operator%(Tile& tile) //���̔v�����邩�̘_���Z(�߂�l��C_Data)
{
	return CheckType(tile) % PrimeTable::GetPrimeNumber(tile.GetTileNum() % 9);
}

void Tehai_C_Data::ExtractHai(Tile& tile) //�v�𔲂��o��
{
	this->operator/=(tile);
}
void Tehai_C_Data::InsertHai(Tile& tile)  //�v����������
{
	this->operator*=(tile);
}
bool Tehai_C_Data::ExistHai(Tile& tile)	//�v�̑��ݔ��� 
{
	bool a = !(bool)this->operator%(tile);

	return a;
}