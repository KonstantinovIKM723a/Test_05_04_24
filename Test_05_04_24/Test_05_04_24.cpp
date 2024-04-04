#include <iostream>;
#include "windows.h";
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //
    int a = 1;

    int* pa = &a;
    int* pb = &a;

    int m, n, k = 0;

    int* x = new int[n];
    int* y = new int[m];

    srand(time(NULL));

    cout << "Введіть значення змінної a: ";
    cin >> n;

    for (int i = 0; i < n; i++) x[i] = rand() % 19 - 9;
}