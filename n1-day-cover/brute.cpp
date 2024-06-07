#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

Vector selected(4);

void print_vector(Vector &v) {
  for (auto x : v) cout << x << " ";
  cout << endl;
}

void brute(int num) {
  if (num == 4) {
    print_vector(selected);
    return;
  }
  selected[num] = 1;
  brute(num+1);
  selected[num] = 0;
  brute(num+1);
}

int main() {
  brute(0);
  return 0;
}
