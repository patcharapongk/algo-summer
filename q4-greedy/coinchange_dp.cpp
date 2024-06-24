#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

void print_vector(Vector &v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}
void print_matrix(Matrix &m) {
    for (int i = 0; i < m.size(); ++i)
        print_vector(m[i]);
}
int coins_count, target;
Vector coins;
Matrix memo;

int call_count = 0;
int solve(int idx, int acc) {
    call_count++;
    if (acc >= target) return 0;
    if (idx == -1) return target + 1;
    if (memo[idx][acc] != -1) return memo[idx][acc];
    memo[idx][acc] = min(solve(idx - 1, acc), 1 + solve(idx, acc + coins[idx]));
    return memo[idx][acc];
}
int solve() {
    return solve(coins_count - 1, 0);
}
int main() {
    cin >> coins_count >> target;
    int coin;
    for (int i = 0; i < coins_count; ++i) {
        cin >> coin;
        coins.push_back(coin);
    }
    memo.resize(coins_count, Vector(target + 1, -1));

    cout << solve() << endl;
    print_matrix(memo);
    cout << "called : " << call_count << endl;
}