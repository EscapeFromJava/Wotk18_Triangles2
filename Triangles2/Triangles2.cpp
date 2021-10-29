#include "Triangle.h"
#include <iostream>

const int SIZE = 10;
void test0();
void test1();

int main()
{
    setlocale(LC_ALL, "rus");
    test1();
    return 0;
}

void test0()
{
    Triangle tr1;
    Triangle* pTr = new Triangle;
    tr1 = inputTriangle();
    cout << "Первый треугольник: " << triangleToString(tr1) << endl;
    *pTr = inputTriangle();
    cout << "Второй треугольник: " << triangleToString(*pTr) << endl;
    cout << "Периметр первого треугольника: " << getPerimeter(tr1) << endl;
    cout << "Периметр второго треугольника: " << getPerimeter(*pTr) << endl;
    cout << "Площадь первого треугольника: " << getSquare(tr1) << endl;
    cout << "Площадь второго треугольника: " << getSquare(*pTr) << endl;
    if (equalityTriangle(tr1, *pTr))
        cout << "Равенство выполнено" <<endl;
    else
        cout << "Равенство невыполнено" << endl;

    delete pTr;
}

void test1()
{
    cout << "Сколько требуется ввести треугольников?" << endl;
    int n;
    Triangle arr[SIZE];
    cin >> n;
    for (int i = 0; i < n; i++) {
        arr[i] = inputTriangle();
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (equalityTriangle(arr[i], arr[j]))
                count++;
        }
    }
    cout << "Количество пар равных треугольников = " << count << endl;
    sortTriangles(arr, n);
}