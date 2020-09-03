#include "stdafx.h"

class Noodles
{
private:
	virtual void Additive() = 0;

	void PutWater() { cout << "pour some water" << endl; }
	void Boil() { cout << "Boiling Water" << endl; }
	void Enjoy() { cout << "Delicious" << endl; }
	void Waiting() { cout << "Waiting " << waitMinuate << " minuate" << endl; }
protected:
	int waitMinuate;
public:
	void Process()
	{
		PutWater();
		Boil();
		Additive();
		Waiting();
		Enjoy();
	}
};


class ShinNoodles : public Noodles
{
private:
	void Additive() sealed override
	{
		cout << "Addition Additive" << endl;
		cout << "Addition Ramen powder Soup" << endl;
	}
public:
	ShinNoodles(int waitMinuate)
	{
		this->waitMinuate = waitMinuate;
	}
};

class BuldakFriedNoodles : public Noodles
{
private:
	void Additive() sealed override
	{
		cout << "Addition Additive" << endl;
		cout << "Addition liquid Soup" << endl;
	}
public:
	BuldakFriedNoodles(int waitMinuate)
	{
		this->waitMinuate = waitMinuate;
	}
};

int main(int argc, char* argv)
{

	Noodles* noodles = new ShinNoodles(3);
	noodles->Process();
	cout << endl;
	noodles = new BuldakFriedNoodles(4);
	noodles->Process();

	delete noodles;
	return 0;
}