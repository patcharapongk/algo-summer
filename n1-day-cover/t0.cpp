#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

bitset<5> days_covered;

int main() {
  days_covered.set();
  days_covered <<= 5-3;
  cout << days_covered << endl;
  return 0;
}
