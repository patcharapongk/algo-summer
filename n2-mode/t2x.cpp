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
    {1, 1, 2, 2, 2, 2};
// {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
//   0  1  2  3  4  5  6  7  8  9  0  1  2

int MODE = INT_MIN;
int FREQ = -1;

void solve(int left, int right) {
    auto nextPos_it = upper_bound(v.begin(), v.end(), v[left]);
    int nextPos = nextPos_it - v.begin();
    printf("nextPos, left, right %d %d %d \n", nextPos, left, right);
    if (nextPos_it == v.end()) return;
    if (nextPos - left > FREQ) {
        MODE = v[nextPos];
        FREQ = nextPos - left;
        cout << "M:F " << MODE << " " << FREQ << endl;
    }
    solve(nextPos, right);
}

int main() {
    print_vec(v);
    solve(0, v.size() - 1);
    cout << "Mode: " << MODE << ", Frequency: " << FREQ << endl;
}
