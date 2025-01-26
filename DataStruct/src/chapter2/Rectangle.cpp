#include "chapter2/Rectangle.h"


namespace Chapter2
{
	Rectangle::Rectangle()
	{
	}

	Rectangle::Rectangle(int x, int y, int h, int w) 
		: xLow(x), yLow(y), height(h), width(w)
	{
	}

	Rectangle::~Rectangle()
	{
	}

	int Rectangle::GetHeight()
	{
		return height;
	}

	int Rectangle::GetWidth()
	{
		return width;
	}

	bool Rectangle::operator==(const Rectangle& s)
	{
		if (this == &s)
			return true;

		if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))
			return true;
		else 
			return false;
	}

	bool Rectangle::operator<(const Rectangle& s)
	{
		return height * width < s.height * s.width;
	}

	void CompareReferenceRectangle()
	{
		Rectangle r(0, 0, 100, 100);
		Rectangle s(100,100,50,50);
		Rectangle* t = &s;

		//if (r.GetHeight() * r.GetWidth() > t->GetHeight() * t->GetWidth())
		if(s < r)
			cout << "r";
		else
			cout << "s";

		cout << "has greater area" << endl;
	}

	MyRectangle::MyRectangle(int x, int y, int h, int w)
		: Rectangle(x,y,h,w)
	{
	}
	MyRectangle::~MyRectangle()
	{
	}

	int MyRectangle::GetCircumfrence()
	{
		return 2*GetHeight() + 2*GetWidth();
	}

	void MyRectangle::SetColor(int _r, int _g, int _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}

	void GetMyRectangleCircumfrence()
	{
		MyRectangle r(0, 0, 100, 200);
		//cin >> &r;
		cout << &r << endl;
		cout << r.GetCircumfrence() << endl;
	}
}
