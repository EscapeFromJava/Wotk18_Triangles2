#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Triangle {
	float a, b, c;
};

Triangle inputTriangle();
string triangleToString(Triangle t);
float getPerimeter(Triangle t);
float getSquare(Triangle t);
bool equalityTriangle(Triangle t1, Triangle t2);
void sortTriangles(Triangle arr[], int SIZE);
void swapTriangles(Triangle* x, Triangle* y);