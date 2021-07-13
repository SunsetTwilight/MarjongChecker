#pragma once
#include "MarjongChecker.h"
#include "FormChecker.h"


class YakuChecker : public MarjongChecker
{
private:

    int Point;
public:

    YakuChecker(int point) : Point(point) {} //�`�������Ɋ֌W�Ȃ���(����F�Ȃ�)

    template <class _Ty>
    YakuChecker(int point) : Point(point) {} //�`�������Ɋ֌W�����(���Ύq�Ȃ�)

    virtual ~YakuChecker(){}

    bool virtual Check() = 0;
};

class Tin_Itsu : public YakuChecker
{
public:

    Tin_Itsu() : YakuChecker(6) {}
    ~Tin_Itsu(){}

    bool Check()
    {
        if (!(GetData().Get_C_Data(TileType::Zihai) % 1)) return false;

        int count = 0;
        if (!(GetData().Get_C_Data(TileType::Manzu) % 1)) count++;
        if (!(GetData().Get_C_Data(TileType::Pinzu) % 1)) count++;
        if (!(GetData().Get_C_Data(TileType::Souzu) % 1)) count++;

        if (count == 1) return true;

        return false;
    }
};

class Hon_Itsu : public YakuChecker
{
public:

    Hon_Itsu() : YakuChecker(3) {}
    ~Hon_Itsu() {}

    bool Check()
    {
        if (!(GetData().Get_C_Data(TileType::Zihai) % 1))
        {
            int count = 0;
            if (!(GetData().Get_C_Data(TileType::Manzu) % 1)) count++;
            if (!(GetData().Get_C_Data(TileType::Pinzu) % 1)) count++;
            if (!(GetData().Get_C_Data(TileType::Souzu) % 1)) count++;

            if (count == 1) return true;
        }
        return false;
    }
};

//�g�������Q�[���̏������̎��Ɂ@Set<Type>()�@����B