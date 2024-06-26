#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef map<int, int> Map;
typedef pair<int, int> Pair;

Vector v;

void print_vec(const Vector &v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

/* --- solve1 : Divide by half, fix the conquer part --- */
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
    int h1 = half, h2 = half;

    while (h1 >= left && v[h1] == mid_mode) --h1;
    while (h2 <= right && v[h2] == mid_mode) ++h2;

    mid_mode_count = h2 - h1 - 1;

    int max_count = max3(p1.second, mid_mode_count, p2.second);
    if (max_count == p1.second)
        return {p1.first, p1.second};
    if (max_count == mid_mode_count)
        return {mid_mode, mid_mode_count};
    return {p2.first, p2.second};
}

/* --- solve2 : Divide by half, mid, right           --- */
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

/* --- Testing Function --- */
void run_tests() {
    vector<Vector> test_cases = {
        {},                                 // 1 Empty vector
        {1},                                // 2 Single element
        {1, 1, 1, 1, 1},                    // 3 All elements the same
        {1, 2},                             // 4 Two different elements
        {2, 2, 2, 2, 2, 3, 3, 3, 3},        // 5 Two different elements with more duplicates
        {1, 2, 3, 4, 5},                    // 6 Increasing sequence
        {1, 1, 2, 5, 5},                    // 7 NEW
        {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3},  // 8 Mixed elements
        {-3, -2, -1, 0, 1, 2, 3},           // 9 Vector with negative numbers
        {1, 1, 2, 3, 3, 4, 5, 5, 6}         // 10 Vector with duplicates and unique elements
    };

    vector<Pair> expected_results = {
        {-1, -1},  // 1 Empty vector
        {1, 1},    // 2 Single element
        {1, 5},    // 3 All elements the same
        {1, 1},    // 4 Two different elements
        {2, 5},    // 5 Two different elements with more duplicates
        {1, 1},    // 6 Increasing sequence
        {1, 2},    // 7 NEW
        {2, 4},    // 8 Mixed elements
        {-3, 1},   // 9 Vector with negative numbers
        {1, 2}     // 10 Vector with duplicates and unique elements
    };

    for (size_t i = 0; i < test_cases.size(); ++i) {
        v = test_cases[i];
        cout << "Testing vector: ";
        print_vec(v);

        Pair result1 = solve1(0, v.size() - 1);
        Pair result2 = solve2(0, v.size() - 1);
        Pair result3 = solve3(0, v.size() - 1);

        // cout << "Expected - Mode: " << expected_results[i].first << ", Frequency: " << expected_results[i].second << endl;
        // cout << "solve1 - Mode: " << result1.first << ", Frequency: " << result1.second << endl;
        // cout << "solve2 - Mode: " << result2.first << ", Frequency: " << result2.second << endl;
        // cout << "solve3 - Mode: " << result3.first << ", Frequency: " << result3.second << endl;

        if (result1 != expected_results[i]) {
            cout << ">> solve1 failed for test case " << i + 1 << endl;
        }
        if (result2 != expected_results[i]) {
            cout << ">> solve2 failed for test case " << i + 1 << endl;
        }
        if (result3 != expected_results[i]) {
            cout << ">> solve3 failed for test case " << i + 1 << endl;
        }

        cout << "----------------------------------------" << endl;
    }
}

int main() {
    run_tests();
    return 0;
}
