#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

Vector score;
Matrix memo;

int max3(int a, int b, int c) { return max(a, max(b, c)); }

int solve(int left, int right) {
    if (memo[left][right] != -1) return memo[left][right];
    if (left >= right)
        return 0;
    if (left + 1 == right)
        return max(score[left], score[right]);
    int s1 = max(score[left], score[left + 1]) + solve(left + 2, right);
    int s2 = max(score[left], score[right]) + solve(left + 1, right - 1);
    int s3 = max(score[right - 1], score[right]) + solve(left, right - 2);
    memo[left][right] = max3(s1, s2, s3);
    return memo[left][right];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        score.push_back(x);
    }
    memo.resize(n, Vector(n, -1));
    cout << solve(0, score.size() - 1) << endl;
}
