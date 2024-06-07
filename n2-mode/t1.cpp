#include <iostream>
#include <map>
#include <vector>

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

Pair move_mid(int half) {
  int mid_entry = v[half];
  int half1, half2 = half;
  while (v[half2] == mid_entry) {
    ++half2;
  }
  while (v[half1] == mid_entry) {
    --half1;
  }
  return {half1, half2};
}


int solve() {
  int left = 0;
  int half = v.size() / 2;
  int right = v.size() - 1;
  
  int half1 = move_mid(half).first;
  int half2 = move_mid(half).second;

  Pair p1 = find_mode(left, half1);
  Pair p2 = find_mode(half1, half2);
  Pair p3 = find_mode(half2, right);
  return max3(p1.second,p2.second,p3.second); 
}


int main() {
  solve();
}
