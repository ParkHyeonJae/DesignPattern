#include "stdafx.h"
#include "Singleton.hpp"

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