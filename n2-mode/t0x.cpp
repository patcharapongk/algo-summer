#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef map<int, int> Map;
typedef pair<int, int> Pair;

Vector v =
    {1, 1, 2, 5, 5};

void print_vec(Vector &v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int max3(int a, int b, int c) { return max(a, max(b, c)); }

// inclusive
Pair find_mode(int left, int right) {
    Map map;
    for (int i = left; i <= right; ++i) {
        map[v[i]]++;
    }

    auto maxEntry = std::max_element(
        map.begin(), map.end(),
        [](const Pair &a, const Pair &b) { return a.second < b.second; });

    return {maxEntry->first, maxEntry->second};
}

Pair solve(int left, int right) {
    if (v.size() == 0) return {-1, -1};
    if (left == right)
        return {v[left], 1};

    int half = left + (right - left) / 2;

    Pair p1 = solve(left, half);
    Pair p2 = solve(half + 1, right);

    int mid_mode = v[half];
    int mid_mode_count = 1;
    int h1 = half - 1;
    int h2 = half + 1;

    while (left <= h1 && v[h1] == mid_mode) --h1;
    while (right >= h1 && v[h2] == mid_mode) ++h2;

    mid_mode_count = h2 - h1 - 1;
    int max_count = max3(p1.second, p2.second, mid_mode_count);
    if (max_count == p1.second)
        return {p1.first, p1.second};
    if (max_count == p2.second)
        return {p2.first, p2.second};
    return {mid_mode, mid_mode_count};
}

int main() {
    print_vec(v);
    Pair p = solve(0, v.size() - 1);
    printf("val %d count %d\n", p.first, p.second);
}
