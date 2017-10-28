/*
HF-ICT, Programmieren C++
Algorithmen und Datenstrukturen
Arbeitsblatt Rekursion
19-Sep-2017, David Herzig (dave.herzig@gmail.com)
*/

#include <iostream>
#include <limits.h>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;

/* AUFGABE 1, Fakultaet
Welches ist die groesste Zahl, fuer welche die Fakultaet mit C++
berechnet werden kann (falls der Datentyp long long verwendet wird.)?
*/
unsigned long long fakRE(long long n) {
    if(n <= 1) return 1;
    return n * fakRE(n -1);
}

/* AUFGABE 2, Fibonacci Rekursiv (inkl Performance Messung!)
*/
int fibRe(int n) {
    if (n == 1 || n == 0) return n;
    return fibRe(n -1) + fibRe(n -2);
}

/* AUFGABE 3, Fibonacci Iterativ (inkl Performance Messung!)
*/
int fibIt(int n) {
    if (n == 1 || n == 0) return n;

    int first(0), second(1), tmp(0);

    for(int i= 2; i <= n; i++) {
        tmp = first + second;
        swap(first, second);
        second = tmp;
    }


    return tmp;
}

/* AUFGABE 4, Fibonacci Rekursiv mit Verbesserung*/
int fibReImp(int n) {
    if (n == 1 || n == 0) return n;
    static map<int, int> fibo;

    if (fibo.find(n - 1)->first != 0) {
        return fibo[n-1] + fibReImp(n -2);

    } else if (fibo.find(n - 2)->first != 0) {
        return fibo[n-2] + fibReImp(n -2);

    } else {
        return fibReImp(n -1) + fibReImp(n -2);
    }
}

/* AUFGABE 5, Exponentiation Rekursiv
*/
double power(double x, int n) {
/*
//   Pontenzfunktion Iterativ
    double sum = 0;

    if (n == 0) return x;
    if (n == 1) return x;

    if (n < 0) {
        for (int i = n; i < 0; --i) {
            double tmp2 = 0;
            tmp2 = x * x;
            sum += tmp2;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            double tmp2 = 0;
            tmp2 = x * x;
            sum += tmp2;
        }
    }
    return sum;
*/
//    Potenzialfunktion rekursiv
int count = 0;
    if (n == 0) return 1;
    if (n == 1) return x;
//    x = 2
//    n = 15

//    Überprüfen, ob n gerade oder ungerade ist
    while (count < 100) {
        count++;
        if (n % 2 == 0) {
//        gerade
            return power(x, n/2) * power(x, n/2);
        } else {
//        ungerade
            n--;
            return power(x, n/2) * power(x, n/2) * x;
        }
    }

    return -999;
}

int main(int argc, char **argv) {
    //Test Aufgabe 1
    //cout << fakRE(50) << endl;

    // Test Aufgabe 2

    clock_t start, stop;

    start = clock();
    cout << fibRe(40) << endl;
    stop = clock();

    double time = (double) (stop-start) /CLOCKS_PER_SEC;
    cout << time << endl;

  if (fibRe(1) == 1 && fibRe(3) == 2 && fibRe(8) == 21) {
    cout << "Aufgabe 2 ist richtig" << endl;
  } else {
    cout << "Aufgabe 2 ist falsch" << endl;
  }

  // Test Aufgabe 3
    start = 0;
    stop = 0;

    start = clock();
    fibIt(10);
    stop = clock();

    time = (double) (stop-start) /CLOCKS_PER_SEC;
    cout << fibIt(10) << endl;
    cout << time << endl;

  if (fibIt(1) == 1 && fibIt(3) == 2 && fibIt(8) == 21) {
    cout << "Aufgabe 3 ist richtig" << endl;
  } else {
    cout << "Aufgabe 3 ist falsch" << endl;
  }


    // Test Aufgabe 4
    if (fibReImp(1) == 1 && fibReImp(3) == 2 && fibReImp(8) == 21) {
        cout << "Aufgabe 4 ist richtig" << endl;
    } else {
        cout << "Aufgabe 4 ist falsch" << endl;
    }

    // Test Aufgabe 5
    if (power(2, 2) == 4 && power(2, 0) == 1 && power(3, 3) == 27) {
        cout << "Aufgabe 5 ist richtig" << endl;
    } else {
        cout << "Aufgabe 5 ist falsch" << endl;
    }

    return 0;
}
