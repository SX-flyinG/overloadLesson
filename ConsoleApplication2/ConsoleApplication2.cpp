#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void PrintInfo() {
		cout << "X: " << this->x << " Y: " << this->y << endl;
	}

	Point operator+(const Point& other) {
		return Point(this->x + other.x, this->y + other.y);
	}

	Point operator-() {
		return Point(-this->x , -this->y);
	}

	Point operator++() {
		return Point(++this->x, ++this->y);
	}



	friend Point operator-(const Point& other  , const Point& current);
};

Point operator- (const Point& other, const Point& current) {
	return Point(other.x - current.x, other.y - current.y );
}

int main()
{
	Point obj = Point(1, 2);
	Point obj2 = Point(23, 25);

	Point obj3 = obj + obj2;

	Point obj4 = obj - obj3;

	obj.PrintInfo();
	obj2.PrintInfo();
	obj3.PrintInfo();
	obj4.PrintInfo();

	obj = -obj;
	obj.PrintInfo();
	obj = ++obj;
	obj.PrintInfo();
}