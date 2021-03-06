#include "Triangle.h"

Triangle inputTriangle()
{
	cout << "Введите 3 стороны треугольника: " << endl;
	Triangle t;
	cin >> t.a >> t.b >> t.c;
	return t;
}

string triangleToString(Triangle t)
{
	string s = "Треугольник {"+to_string(t.a)+ ", "+to_string(t.b)+ ", "+to_string(t.c)+" }";
	return s;
}

float getPerimeter(Triangle t)
{
	return t.a + t.b + t.c;
}

float getSquare(Triangle t)
{
	float p = getPerimeter(t) / 2;
	return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

bool equalityTriangle(Triangle t1, Triangle t2)
{
	if (getPerimeter(t1) == getPerimeter(t2) && getSquare(t1) == getSquare(t2)) {
		if (t1.a == t2.a || t1.a == t2.b || t1.a == t2.c) {
			if (t1.b == t2.a || t1.b == t2.b || t1.b == t2.c) {
				if (t1.c == t2.a || t1.c == t2.b || t1.c == t2.c)
					return true;
			}
		}
	}
	else
		return false;
}

void sortTriangles(Triangle arr[], int SIZE)
{
	cout << "Выберите метод сортировки: 1 - по периметру, 2 - по площади" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE - 1; j++) {
				if (getPerimeter(arr[j]) > getPerimeter(arr[j + 1])) {
					swapTriangles(&arr[j], &arr[j + 1]);
				}
			}
		}
		for (int i = 0; i < SIZE; i++) {
			cout << "Периметр " << i << " треугольника = " << getPerimeter(arr[i]) << endl;
		}
	}
	if (x == 2) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE - 1; j++) {
				if (getSquare(arr[j]) > getSquare(arr[j + 1])) {
					swapTriangles(&arr[j], &arr[j + 1]);
				}
			}
		}
		for (int i = 0; i < SIZE; i++) {
			cout << "Площадь " << i << " треугольника = " << getSquare(arr[i]) << endl;
		}
	}
	
}

void swapTriangles(Triangle* x, Triangle* y)
{
	Triangle t = *x;
	*x = *y;
	*y = t;
}