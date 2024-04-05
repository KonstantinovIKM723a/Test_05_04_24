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

    int n, k = 0;

    cout << "Введіть значення змінної n: ";
    cin >> n;

    int* x = new int[n];

    srand(time(NULL));
     
    for (int i = 0; i < n; i++) x[i] = rand() % 19 - 9;
}