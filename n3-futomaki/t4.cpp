#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

void print_vec(Vector &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void print_vec(Vector &v, int left, int right) {
  for (int i = left; i <= right; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
Vector score =
    // {1, 2};
    // {1, 2, 9, 8};
    {1, 2, 9, 8, 7, 3};
// {9, 8, 7, 3, 2, 1};
//  9 9 1 1 1 1 9 9
//    {9,9,1,1,1,1,9,9}
// {9,8,7,3,2,1}
Vector used(score.size(), -1);

int max3(int a, int b, int c) { return max(a, max(b, c)); }

int solve(int left, int right) {
  printf(" left: %d, right: %d ", left, right);
  printf(" | ");
  print_vec(score, left, right);
  if (left >= right)
    return 0;
  if (left + 1 == right)
    return max(score[left], score[right]);
  int b1 = max(score[left], score[left + 1]) + solve(left + 2, right);
  int b2 = max(score[left], score[right]) + solve(left + 1, right - 1);
  int b3 = max(score[right - 1], score[right]) + solve(left, right - 2);
  return max3(b1, b2, b3);
}

int main() { cout << solve(0, score.size() - 1) << endl; }
