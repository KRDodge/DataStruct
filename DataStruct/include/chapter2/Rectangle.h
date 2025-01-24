#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 {

	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(int x, int y, int h, int w);
		~Rectangle();

		int GetHeight();
		int GetWidth();

		bool operator==(const Rectangle& s);
		friend std::ostream& operator<<(std::ostream& os, const Rectangle& s) {
			os << "Rectangle(width: " << s.width << ", height: " << s.height << ")";
			return os;
		}

	private:
		int xLow, yLow, height, width;
		
	};

	void CompareReferenceRectangle();
}
