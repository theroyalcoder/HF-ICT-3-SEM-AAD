#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

class MergeSort {
public:
  virtual void sort(vector<int> & data);
};

int main(int argc, char **argv) {

  vector<int> data;
  for (int i=0; i<10; ++i) {
    data.push_back(rand()%1000);
    data.push_back(i);
  }

  //print(data);
  MergeSort *s = new MergeSort();
  clock_t start, stop;
  start = clock();
  s->sort(data);
  stop = clock();
  cout << (double)(stop-start)/CLOCKS_PER_SEC << endl;
  //print(data);

  return 0;
}
