#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

double term(double x, int n) {
    if (n == 0) 
    {
        return 1;
    }
    return term(x, n - 1) * (2 * x) / n;
}

double sumN(double x, int n) {
    if (n == 0) 
    {
        return 1;
    }
    return sumN(x, n - 1) + term(x, n);
}

double sumEps(double x, double eps, int n = 0) {
    double t = term(x, n);
    if (fabs(t) < eps) 
    {
        return 0;
    }
    return t + sumEps(x, eps, n + 1);
}

int main() {
    setlocale(LC_ALL, "RU");
    const double eps = 10e-7;
    double a = 0.1, b = 1.0;
    int k = 10;           
    double step = (b - a) / k;

    int n = 20;         

    for (double x = a; x <= b; x += step) {
        double sN = sumN(x, n);
        double sE = sumEps(x, eps);
        double Y = exp(2 * x);

        cout << "x = " << x << endl;
        cout << "sN (n=20) = " << sN << endl;
        cout << "sN  = " << sE << endl;
        cout << "Funcion Y   = " << Y << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
