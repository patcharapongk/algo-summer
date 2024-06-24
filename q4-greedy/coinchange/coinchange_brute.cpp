#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

int coins_count, target;
Vector coins;

int call_count = 0;
int solve(int idx, int acc) {
    call_count++;
    if (acc >= target) return 0;
    if (idx == -1) return target + 1;
    return min(solve(idx - 1, acc), 1 + solve(idx, acc + coins[idx]));
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
    cout << solve() << endl;
    cout << "called : " << call_count << endl;
}