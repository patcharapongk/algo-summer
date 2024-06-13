#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef map<int, int> Map;
typedef pair<int, int> Pair;

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

//          0  1  2  3  4  5  6  7  8  9  0  1
// Vector v = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
//
Vector v = {0, 1, 1, 1, 1, 1};

Pair move_mid(int left, int half, int right) {
    int mid_entry = v[half];
    int half1 = half - 1, half2 = half + 1;
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
    printf("h1 %d | h2 %d\n", half1, half2);
    Pair p1 = solve(left, half1 - 1);
    Pair p2 = {v[half], half2 - half1 + 1};
    Pair p3 = solve(half2 + 1, right);
    printf("c1, c2, c3 %d %d %d \n", p1.second, p2.second, p3.second);
    int max_count = max3(p1.second, p2.second, p3.second);
    if (max_count == p1.second) return {p1.first, p1.second};
    if (max_count == p2.second) return {p2.first, p2.second};
    return {p3.first, p3.second};
}

int main() {
    Pair result = solve(0, v.size() - 1);
    cout << "Mode: " << result.first << ", Frequency: " << result.second << endl;
}
