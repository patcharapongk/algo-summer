#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

void print_vec(Vector &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void print_vec(Vector &v, int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print_matrix(Matrix &m) {
    for (int i = 0; i < m.size(); ++i) {
        print_vec(m[i]);
    }
}

Vector score =
    // {1, 2};
    // {1, 2, 9, 8};
    {1, 2, 9, 8, 7, 3};
// {1, 2, 9, 8, 1, 2, 9, 8};
// {9, 8, 7, 3, 2, 1};
//  9 9 1 1 1 1 9 9
//    {9,9,1,1,1,1,9,9}
// {9,8,7,3,2,1}
int N = score.size();
Matrix memo(N, Vector(N, -1));

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
    cout << solve(0, score.size() - 1) << endl;
    print_matrix(memo);
}
