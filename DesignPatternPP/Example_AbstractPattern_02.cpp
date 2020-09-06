#include "stdafx.h"

class IButton
{
public:
	virtual void print() = 0;
};
class IScroll
{
public:
	virtual void print() = 0;
};

class ButtonRectangle : public IButton
{
	void print() override
	{
		cout << "Rectangle Button" << endl;
	}
};
class ButtonCircle : public IButton
{
	void print() override
	{
		cout << "Circle Button" << endl;
	}
};

class ScrollRectangle : public IScroll
{
public:
	void print() override
	{
		cout << "Rectangle Scroll" << endl;
	}
};

class ScrollCircle : public IScroll
{
public:
	void print() override
	{
		cout << "Circle Scroll" << endl;
	}
};

template<typename T>
class UI_Factory
{
public:
	virtual T* createUI() = 0;
};

template<typename T1, typename T2>
class UI_ConcreteFactory : public UI_Factory<T1>
{
public:
	T1* createUI() override
	{
		return new T2();
	}
};
int main(int argc, char* argv[])
{

	UI_ConcreteFactory<IButton, ButtonRectangle> mButtonRectangleFactory;
	UI_ConcreteFactory<IScroll, ScrollRectangle> mScrollRectangleFactory;
	
	UI_ConcreteFactory<IButton, ButtonCircle> mButtonCircleFactory;
	UI_ConcreteFactory<IScroll, ScrollCircle> mScrollCircleFactory;


	IButton* rectangleButton = mButtonRectangleFactory.createUI();
	IScroll* rectangleScroll = mScrollRectangleFactory.createUI();

	rectangleButton->print();
	rectangleScroll->print();

	IButton* circleButton = mButtonCircleFactory.createUI();
	IScroll* circleScroll = mScrollCircleFactory.createUI();

	circleButton->print();
	circleScroll->print();

	delete circleScroll;
	delete circleButton;
	delete rectangleScroll;
	delete rectangleButton;

	return 0;
}