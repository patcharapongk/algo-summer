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
    // {1};
    // {1, 1, 1, 1, 1};
    // {1, 1, 2, 2, 2, 2};
    {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
//   0  1  2  3  4  5  6  7  8  9  0  1  2

Pair solve(int left, int right) {
    if (left > right) return {-1, -1};
    if (left == right) return {1, v[left]};
    auto nextPos_it = upper_bound(v.begin(), v.end(), v[left]);
    int nextPos = nextPos_it - v.begin();
    if (nextPos == right) return {nextPos - left, v[left]};
    return max(solve(left, nextPos), solve(nextPos, right));
}

int main() {
    print_vec(v);
    Pair result = solve(0, v.size() - 1);
    printf("Mode: %d | Freq %d\n", result.second, result.first);
}
