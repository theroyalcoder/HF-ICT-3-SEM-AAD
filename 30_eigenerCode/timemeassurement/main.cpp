#include <iostream>
#include <ctime>
using namespace std;

int main()   {
    clock_t start, stop;

    start = clock();
    //Code
    stop = clock();

    double time = (double) (stop-start) /CLOCKS_PER_SEC;

    cout << time;
    return 0;
}
