#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

Vector v = {0, 1, 2, 3};

int main() {
    auto it1 = v.end();
    auto it2 = upper_bound(v.begin(), v.end(), 3);
    auto it3 = upper_bound(v.begin(), v.end(), 4);
    printf("it1, it2, it3 %d, %d, %d\n", it1, it2, it3);

    auto b = v.begin();

    int d1 = it1 - b;
    int d2 = it2 - b;
    int d3 = it3 - b;
    printf("d1, d2, d3 %d, %d, %d\n", d1, d2, d3);
}