// Lab_06_3_rec.cpp
// Половінко Софія 
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (Рекурсивний спосіб).
// Варіант 13

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Звичайна рекурсивна функція створення масиву
void CreateRec(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i < size)
    {
        a[i] = Low + rand() % (High - Low + 1);
        CreateRec(a, size, Low, High, i + 1);
    }
}

// Шаблонна рекурсивна функція створення масиву
template <typename T>
void CreateRec(T* a, const int size, const T Low, const T High, int i = 0)
{
    if (i < size)
    {
        a[i] = Low + static_cast<T>(rand()) / RAND_MAX * (High - Low);
        CreateRec(a, size, Low, High, i + 1);
    }
}

// Звичайна рекурсивна функція виведення масиву
void PrintRec(const int* a, const int size, int i = 0)
{
    if (i < size)
    {
        cout << setw(6) << a[i];
        PrintRec(a, size, i + 1);
    }
    else
        cout << endl;
}

// Шаблонна рекурсивна функція виведення масиву
template <typename T>
void PrintRec(const T* a, const int size, int i = 0)
{
    if (i < size)
    {
        cout << setw(8) << setprecision(2) << fixed << a[i];
        PrintRec(a, size, i + 1);
    }
    else
        cout << endl;
}

// Звичайна рекурсивна функція перевірки впорядкованості за незростанням
bool IsNonIncreasingRec(const int* a, const int size, int i = 0)
{
    if (i >= size - 1)
        return true;
    if (a[i] < a[i + 1])
        return false;
    return IsNonIncreasingRec(a, size, i + 1);
}

// Шаблонна рекурсивна функція перевірки впорядкованості за незростанням
template <typename T>
bool IsNonIncreasingRec(const T* a, const int size, int i = 0)
{
    if (i >= size - 1)
        return true;
    if (a[i] < a[i + 1])
        return false;
    return IsNonIncreasingRec<T>(a, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 5;

    // 1. Тест зі звичайною рекурсивною функцією (int)
    int a[n] = { 50, 40, 30, 30, 10 }; // Впорядкований за незростанням
    cout << "Masiv int a (Recursive):" << endl;
    PrintRec(a, n);
    if (IsNonIncreasingRec(a, n))
        cout << "Masiv 'a' vporyadkovanyi za nezrostannyam (YES)" << endl;
    else
        cout << "Masiv 'a' NE vporyadkovanyi za nezrostannyam (NO)" << endl;

    cout << endl;

    // 2. Тест із шаблонною рекурсивною функцією (double)
    double b[n] = { 10.0, 9.5, 9.6, 5.1, 1.0 }; // Не впорядкований (9.5 < 9.6)
    cout << "Masiv double b (Recursive):" << endl;
    PrintRec(b, n);
    if (IsNonIncreasingRec<double>(b, n))
        cout << "Masiv 'b' vporyadkovanyi za nezrostannyam (YES)" << endl;
    else
        cout << "Masiv 'b' NE vporyadkovanyi za nezrostannyam (NO)" << endl;

    return 0;
}