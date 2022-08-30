#include <iostream>
#include <vector>

/*
* 
* Observer Pattern (옵저버 패턴)
* 객체의 상태변화를 관찰하는 관찰자들인 옵저버들의 목록을 객체에 등록시켜서,
* 상태 변화가 생길 때마다 메서드 등을 통해 각 옵저버들한테 통지하도록 해주는 패턴
* 
*/

class Observer abstract
{
public:
	virtual void notify() = 0;
};

class DogObserver : public Observer
{
public:
	void notify() override
	{
		std::cout << "멍멍" << std::endl;
	}
};

class CatObserver : public Observer
{
public:
	void notify() override
	{
		std::cout << "야옹" << std::endl;
	}
};


class Subject
{
public:
	void registerObserver(std::shared_ptr<Observer>&& observer)
	{
		_observerCollection.emplace_back(observer);
	}

	void unregisterObserver(std::shared_ptr<Observer>&& observer)
	{
		auto iter = std::find(_observerCollection.begin(), _observerCollection.end(), observer);
		if (iter != _observerCollection.end()) 
		{
			_observerCollection.erase(iter);
		}
	}

	void notifyObservers()
	{
		for (auto& observer : _observerCollection)
		{
			observer->notify();
		}
	}

private:
	std::vector<std::shared_ptr<Observer>> _observerCollection;
};

int main(void)
{
	Subject newEvent;

	auto dogObserver = std::make_shared<DogObserver>();
	auto catObserver = std::make_shared<CatObserver>();

	newEvent.registerObserver(dogObserver);
	newEvent.registerObserver(catObserver);

	newEvent.notifyObservers();

	newEvent.unregisterObserver(catObserver);
	newEvent.notifyObservers();

	return 0;
}