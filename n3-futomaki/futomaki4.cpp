#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

Vector score;
Vector used;

int max3(int a, int b, int c) { return max(a, max(b, c)); }

int solve(int left, int right) {
  if (left >= right)
    return 0;
  if (left + 1 == right)
    return max(score[left], score[right]);
  int b1 = max(score[left], score[left + 1]) + solve(left + 2, right);
  int b2 = max(score[left], score[right]) + solve(left + 1, right - 1);
  int b3 = max(score[right - 1], score[right]) + solve(left, right - 2);
  return max3(b1, b2, b3);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    score.push_back(x);
    used.push_back(-1);
  }
  cout << solve(0, score.size() - 1) << endl;
}
