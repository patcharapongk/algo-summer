#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef map<int, int> Map;
typedef pair<int, int> Pair;

void print_vec(Vector& v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

Vector v =
    // {};
    // {1, 1, 1, 1, 1};
    // {1, 1, 2, 2, 2, 2};
    {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
//   0  1  2  3  4  5  6  7  8  9  0  1  2

// Pair solve(int left, int right) {
//     printf("l,r %d %d | v[l],v[r] %d %d\n", left, right, v[left], v[right]);
//     auto nextPos_it = upper_bound(v.begin(), v.end(), v[left]);
//     int diff = nextPos_it - (v.begin() + left);
//     if (nextPos_it == v.end()) return {diff, v[right]};
//     Pair next_pair = solve(diff, right);
//     Pair curr_pair = {diff, v[diff]};
//     return max(curr_pair, next_pair);
// }

Pair solve(int left, int right) {
    auto nextPos_it = upper_bound(v.begin(), v.end(), v[left]);
    int nextPos = nextPos_it - v.begin();
    if (nextPos_it == v.end()) return {nextPos - left, v[nextPos]};
}

void solve2(int left, int right) {
    auto nextPos_it = upper_bound(v.begin(), v.end(), v[left]);
    int nextPos = nextPos_it - v.begin();
    if (nextPos_it == v.end()) return;
    for (int i = nextPos; i < right; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    solve2(nextPos, right);
}

int main() {
    print_vec(v);
    // solve2(0, v.size() - 1);
    Pair result = solve(0, v.size() - 1);
    cout << "Mode: " << result.second << ", Frequency: " << result.first << endl;
}
