#include "stdafx.h"
#include "Singleton.hpp"

/*

FlyWeight 패턴
오브젝트를 특정 클래스 안에 캐싱해둬서
다음번에 관련 오브젝트를 사용할 때 캐싱된 데이터를 그대로 가져다
쓸 수 있게 한 구조

디자인 패턴이라는 건 유용한 방법을 참고하여 모두가 이해하고 유지 보수 할 수 있는 코드를 위하여
존재하는 것이기 때문에 시중에 나와있는 구조대로 설계하여 제작할 필요가 없다.
어려운 코드는 결국 자기자랑만 하게되는 꼴

*/

class Item
{
public:
	virtual void operation() = 0;
};

class Potion : public Item
{
public:
	void operation() override
	{
		cout << "Potion Test" << endl;
	}
};

class Axe : public Item
{
public:
	void operation() override
	{
		cout << "Axe Test" << endl;
	}
};


class Map : public Item
{
public:
	void operation() override
	{
		cout << "Map Test" << endl;
	}
};

class ItemFactory : public Singleton<ItemFactory>
{
public:
	~ItemFactory() {}

public:

	template<typename T1>
	Item* GetItem(int key)
	{
		if (mList.find(key) == mList.end())
		{
			mList[key] = new T1();
		}

		return mList[key];
	}

private:
	map<int, Item*> mList;
};

int main()
{
	ItemFactory factory;
	Item* potion = factory.GetItem<Potion>(5);
	Item* axe = factory.GetItem<Axe>(2);
	Item* map = factory.GetItem<Map>(3);

	potion->operation();
	axe->operation();
	map->operation();
	return 0;
}