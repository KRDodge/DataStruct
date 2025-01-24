#include "chapter2/Rectangle.h"


namespace Chapter2
{
	Rectangle::Rectangle()
	{
	}

	Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0) 
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

	void CompareReferenceRectangle()
	{
		Rectangle r, s;
		Rectangle* t = &s;

		if (r.GetHeight() * r.GetWidth() > t->GetHeight() * t->GetWidth())
			cout << "r";
		else
			cout << "s";

		cout << "has greater area" << endl;
	}
}
