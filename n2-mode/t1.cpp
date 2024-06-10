#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> Vector;
typedef map<int, int> Map;
typedef pair<int, int> Pair;

int max3(int a, int b, int c) {
  return max(a, max(b,c));
}


Vector v = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};


// inclusive
Pair find_mode(int left, int right) {
  Map map;
  for (int i = left; i <= right; ++i) {
    map[v[i]]++;
  }
  for (auto it : map) {
    cout << it.first << " " << it.second << endl;
  }

  auto maxEntry = std::max_element(
      map.begin(), map.end(),
      [](const Pair& a, const Pair& b) { return a.second < b.second; });

  return {maxEntry->first, maxEntry->second};
}

Pair move_mid(int left, int half, int right) {
  int mid_entry = v[half];
  int half1, half2 = half;
  if (v[left] == v[half]) {}
  if (v[half] == v[right]) {}
  while (v[half2] == mid_entry) {
    ++half2;
  }
  while (v[half1] == mid_entry) {
    --half1;
  }
  return {half1, half2};
}


Pair solve(int left, int right) {
  if (v.size() == 0) return {-1, -1};
  if (left == right) return {v[left], 1};
  int half = left + (right-left) / 2;
  
  Pair halves = move_mid(half);
  int half1 = halves.first;
  int half2 = halves.second;

  Pair p1 = solve(left, half1);
  Pair p2 = solve(half1, half2);
  Pair p3 = solve(half2, right);

  int max_count = max3(p1.second, p2.second, p3.second);
  if (max_count == p1.second) return {p1.first, p1.second};
  if (max_count == p2.second) return {p2.first, p2.second};
  return {p3.first, p3.second};
}
 


int main() {
  solve(0, v.size() - 1);
}
