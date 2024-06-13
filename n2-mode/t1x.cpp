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

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

Vector v =
    {};
// {1};
// {0, 1, 1, 1, 1};
// {1, 1, 1, 1};
// {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};

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

Pair solve(int left, int right) {
    if (left > right) return {-1, -1};
    if (left == right) return {v[left], 1};
    int half = left + (right - left) / 2;

    Pair halves = move_mid(left, half, right);
    int half1 = halves.first;
    int half2 = halves.second;

    Pair p1 = solve(left, half1 - 1);
    Pair p2 = {v[half], half2 - half1 + 1};
    Pair p3 = solve(half2 + 1, right);

    int max_count = max3(p1.second, p2.second, p3.second);
    if (max_count == p1.second) return {p1.first, p1.second};
    if (max_count == p2.second) return {p2.first, p2.second};
    return {p3.first, p3.second};
}

int main() {
    print_vec(v);
    Pair result = solve(0, v.size() - 1);
    cout << "Mode: " << result.first << ", Frequency: " << result.second << endl;
}
