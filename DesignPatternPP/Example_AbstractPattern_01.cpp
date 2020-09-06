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

class UI_Factory
{
public:
	virtual IButton* createButton() = 0;

	virtual IScroll* createScroll() = 0;
};

class UI_RectangleFactory : public UI_Factory
{
public:
	IButton* createButton() override
	{
		return new ButtonRectangle();
	}

	IScroll* createScroll() override
	{
		return new ScrollRectangle();
	}
};

class UI_CircleFactory : public UI_Factory
{
public:
	IButton* createButton() override
	{
		return new ButtonCircle();
	}

	IScroll* createScroll() override
	{
		return new ScrollCircle();
	}
};

int main(int argc, char* argv[])
{
	UI_RectangleFactory rectangleFactory;
	UI_CircleFactory circleFactory;

	IButton* rectangleButton = rectangleFactory.createButton();
	rectangleButton->print();
	IScroll* rectangleScroll = rectangleFactory.createScroll();
	rectangleScroll->print();

	cout << endl;

	IButton* circleButton = circleFactory.createButton();
	circleButton->print();
	IScroll* circleScroll = circleFactory.createScroll();
	circleScroll->print();

	delete circleScroll;
	delete circleButton;
	delete rectangleScroll;
	delete rectangleButton;
	return 0;
}