#include <iostream>
#include <ctime>
using namespace std;

int main()   {
    int n;
    clock_t start, stop;

    start = clock();
    for(int i= 0; i < 100000; i++) {
        for(int j= 0; j < i; j++)   {
            if(j != 0)   {
                //useless mathematical operation
                n += i%j;
            }
        }
    }

    stop = clock();

    double time = (double) (stop-start) /CLOCKS_PER_SEC;

    cout << time;
    return 0;
}
