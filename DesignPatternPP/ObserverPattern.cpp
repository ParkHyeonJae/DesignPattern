#include <iostream>
#include <vector>

/*
* 
* Observer Pattern (������ ����)
* ��ü�� ���º�ȭ�� �����ϴ� �����ڵ��� ���������� ����� ��ü�� ��Ͻ��Ѽ�,
* ���� ��ȭ�� ���� ������ �޼��� ���� ���� �� ������������ �����ϵ��� ���ִ� ����
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
		std::cout << "�۸�" << std::endl;
	}
};

class CatObserver : public Observer
{
public:
	void notify() override
	{
		std::cout << "�߿�" << std::endl;
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