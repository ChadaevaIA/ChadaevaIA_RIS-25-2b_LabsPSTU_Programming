#include <iostream>
#include <stdarg.h>
#include <math.h>
using namespace std;

int Circle(int n, double R, double x0, double y0, ...) {
    va_list args;
    va_start(args, y0);

    int count = 0;

    for (int i = 0; i < n; i++) {
        double x = va_arg(args, double);
        double y = va_arg(args, double);

        double distance = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));

        if (distance <= R) { 
            count++;
        }
    }

    va_end(args);
    return count;
}

int main() {

    setlocale(LC_ALL, "ru");
    double x0 = 0.0, y0 = 0.0;

    cout << "Точек внутри (3 точки): "
        << Circle(3, 5.0, x0, y0,
            1.0, 2.0,
            3.0, 4.0,
            -1.0, 1.0)
        << endl;

    cout << "Точек внутри (9 точек): "
        << Circle(9, 10.0, x0, y0,
            1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
            -3, -4, -1, -2, 0, 0)
        << endl;

    cout << "Точек внутри (11 точек): "
        << Circle(11, 7.0, x0, y0,
            1, 1, 2, 3, -3, 4, 6, 2, -5, -1,
            0, 6, 1, -6, 2, -1, -2, -2, 0, 0)
        << endl;

    return 0;
}