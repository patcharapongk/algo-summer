#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef map<int, int> Map;
typedef pair<int, int> Pair;

Vector v =
    {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};

/* --- solve1 : Divide by half, fix the comquer part --- */
int max3(int a, int b, int c) { return max(a, max(b, c)); }
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

Pair solve1(int left, int right) {
    if (v.size() == 0) return {-1, -1};
    if (left == right)
        return {v[left], 1};

    int half = left + (right - left) / 2;

    // Divide by half
    Pair p1 = solve1(left, half);
    Pair p2 = solve1(half + 1, right);

    // Conquer and fix the boundaries
    int mid_mode = v[half];
    int mid_mode_count = 1;
    if (half + 1 < right && v[half] == v[half + 1]) {
        int h1 = half;
        int h2 = half + 1;
        while (h1 >= 0 && v[h1] == v[half])
            --h1;
        while (h2 < v.size() && v[h2] == v[half])
            ++h2;
        mid_mode_count = h2 - h1 - 1;
    }
    int max_count = max3(p1.second, p2.second, mid_mode_count);
    if (max_count == p1.second)
        return {p1.first, p1.second};
    if (max_count == p2.second)
        return {p2.first, p2.second};
    return {mid_mode, mid_mode_count};
}

/* --- solve22 : Divide by half, mid, right           --- */
Pair move_mid(int left, int half, int right) {
    int mid_entry = v[half];
    int half1 = half, half2 = half;
    while (half1 >= left && v[half1] == mid_entry) {
        --half1;
    }
    while (half2 <= right && v[half2] == mid_entry) {
        ++half2;
    }
    return {half1 + 1, half2 - 1};
}

Pair solve2(int left, int right) {
    if (left > right) return {-1, -1};
    if (left == right) return {v[left], 1};
    int half = left + (right - left) / 2;

    // Divide into left, half, mid
    Pair halves = move_mid(left, half, right);
    int half1 = halves.first;
    int half2 = halves.second;

    Pair p1 = solve2(left, half1 - 1);
    Pair p2 = {v[half], half2 - half1 + 1};
    Pair p3 = solve2(half2 + 1, right);

    // Conquer
    int max_count = max3(p1.second, p2.second, p3.second);
    if (max_count == p1.second) return {p1.first, p1.second};
    if (max_count == p2.second) return {p2.first, p2.second};
    return {p3.first, p3.second};
}

/* --- solve3 : Divide into ranges of each value    --- */
Pair maxOrEqual(const Pair &p1, const Pair &p2) {
    if (p1.second >= p2.second) {
        return p1;
    }
    return p2;
}

Pair solve3(int left, int right) {
    if (left > right) return {-1, -1};
    if (left == right) return {v[left], 1};
    auto nextPos_it = upper_bound(v.begin(), v.end(), v[left]);
    int nextPos = nextPos_it - v.begin();
    if (nextPos == right) return {v[left], nextPos - left};
    return maxOrEqual(solve3(left, nextPos), solve3(nextPos, right));
}
