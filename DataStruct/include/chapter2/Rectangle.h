#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 {

	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(int x = 0, int y = 0, int h = 0, int w = 0);
		~Rectangle();

		int GetHeight();
		int GetWidth();

		bool operator==(const Rectangle& s);
		bool operator<(const Rectangle& s);
		friend std::ostream& operator<<(std::ostream& os, const Rectangle& s) {
			os << "Rectangle(width: " << s.width << ", height: " << s.height << ")";
			return os;
		}

	private:
		int xLow, yLow, height, width;
		
	};

	class MyRectangle : Rectangle
	{
	public:
		MyRectangle(int x = 0, int y = 0, int h = 0, int w = 0);
		~MyRectangle();

		int GetCircumfrence();

		void SetColor(int r = 0, int g = 0, int b = 0);

		//friend ostream& operator<<(ostream& os, const MyRectangle& s)
		//{
		//	os << "Rectangle(color: " << s.r << s.g << s.b << ")" << endl;
		//	return os;
		//}
		//friend istream& operator>>(istream& is, MyRectangle& s)
		//{
		//	is >> s.r >> s.g >> s.b;
		//	return is;
		//}
	private:
		int r, g, b;
	};

	void CompareReferenceRectangle();
	void GetMyRectangleCircumfrence();
}
