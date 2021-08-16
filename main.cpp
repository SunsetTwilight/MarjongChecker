#include <stdio.h>
#include "MarjongChecker.h"
#include "DefaultTehai.h"


template<class _Ty>
class Memory
{



public:
	Memory();
	~Memory();

	void push_back(_Ty ty);

};

template<class _Ty>
class TenpaiChecker //’®”vAndŒü’®”
{
private:

protected:
	struct CheckAndMati
	{
		_Ty* pointer;
		bool tenpai;
		bool agari;

		std::vector<Tile> effectiveness_hai;

		CheckAndMati(_Ty* ty) pointer(ty), tenpai(false), agari(false) {}
	};

	std::vector<CheckAndMati> tenpai_list;

public:
	virtual void Check(_Ty* checker) = 0;

};

class DefaultTenpaiChecker : public TenpaiChecker<DefaultForm>
{
private:

public:
	void Check(DefaultForm* checker)
	{
		CheckAndMati tm(checker);
		if (checker->comp_face.size() == 4)
		{
			if (checker->one_miss_face.size() == 1)
			{
				if (checker->one_miss_face[0].type == DefaultMissingFaceForm::Toitsu)
				{
					tm.agari = true;
					
					tenpai_list.push_back(tm);
					return;
				}
			}
			//‘Ò‚¿‚ª‰½‚©‚Ìˆ—
			for (int i = 0; i < checker->remainder_tile.size(); i++)
			{
				tm.effectiveness_hai.push_back(checker->remainder_tile[i]);
			}
			tm.tenpai = true;
			tenpai_list.push_back(tm);

			return;
		}
		else if (checker->comp_face.size() == 3)
		{
			for (int i = 0; i < checker->one_miss_face.size(); i++)
			{
				if (checker->one_miss_face[i].type == DefaultMissingFaceForm::Toitsu)
				{

				}
			}
		}
		
	}

};




#include "YakuChecker.h"

template<class _TyForm, class _TyPoint>
class Checker
{
protected:
	_TyForm  form_checker;
	_TyPoint point_checker;
	std::vector<YakuChecker> yaku_list;

public:

	Checker(){}
	~Checker(){}

	virtual void Check() = 0;

	template<class _Ty>
	void SetYaku()
	{
		_Ty ty;
		YakuChecker yc = static_cast<YakuChecker>(ty);
		yaku_list.push_back(yc);
	}
};

class DefaultChecker : public Checker<DefaultFormChecker, DefaultTenpaiChecker>
{

public:
	void Check(Tehai& tehai)
	{
		form_checker.CreateFormList(tehai);
		for (unsigned int i = 0; i < form_checker.GetSize(); i++)
		{
			point_checker.Check(form_checker.GetAddress(i));
		}
		for (unsigned int i = 0; i < yaku_list.size(); i++)
		{

		}
	}
};

int main()
{
	unsigned int num_list[14] =
	{
		0,0,0,1,1,1,2,2,2,3,3,3,4,24
	};

	DefaultTehai tehai;

	for (int i = 0; i < 14; i++)
	{
		tehai.SetTile(i, num_list[i]);
	}

	DefaultFormChecker dfc;




	{
		dfc.CreateFormList(tehai);


		
		/////////

	}
	/*std::vector<DefaultForm> list = dfc.GetList();
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
	}*/
	return 0;
}