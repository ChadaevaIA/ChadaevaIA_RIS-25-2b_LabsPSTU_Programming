#include <iostream>
#include <clocale>
using namespace std;

const int m = 10;     
int A[m], B[m], C[m];  
int aTop = 0, bTop = 0, cTop = 0; 

void print()
{
    int height = aTop;
    if (bTop > height)
    {
        height = bTop;
    }
    if (cTop > height) 
    {
        height = cTop;
    }

    cout << endl << "--------------------------------" << endl;

    for (int i = height - 1; i >= 0; i--)
    {
        // Колонка A
        if (i < aTop)
            cout << "  " << A[i] << "  ";
        else
            cout << "     ";

        // Колонка B
        if (i < bTop)
            cout << "  " << B[i] << "  ";
        else
            cout << "     ";

        // Колонка C
        if (i < cTop)
            cout << "  " << C[i] << "  ";
        else
            cout << "     ";

        cout << endl;
    }

    cout << "  A    B    C" << endl;
    cout << "--------------------------------" << endl << endl;
}



void moveDisk(int from, int to)
{
    int disk;

    // снимаем диск
    if (from == 1) 
        disk = A[--aTop];
    if (from == 2) 
        disk = B[--bTop];
    if (from == 3) 
        disk = C[--cTop];

    // кладём диск
    if (to == 1) 
        A[aTop++] = disk;
    if (to == 2) 
        B[bTop++] = disk;
    if (to == 3) 
        C[cTop++] = disk;
}

void hanoi(int n, int from, int to, int temp)
{
    if (n <= 0) return;

    hanoi(n - 1, from, temp, to);

    cout << "Перемещаем диск со стержня " << from << " на стержень " << to << "\n";
    moveDisk(from, to);
    print();

    hanoi(n - 1, temp, to, from);
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество дисков: ";
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        A[aTop++] = i;
    }

    print();
    hanoi(n, 1, 3, 2);

    return 0;
}
