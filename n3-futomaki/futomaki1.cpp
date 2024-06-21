#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

Vector score;
Vector used;

int solve(int dae_score, int left, int right) {
    if (left > right) return -1;
    if (left == right) return score[left];
    if (right - left == 1) return dae_score + max(score[left], score[right]);
    // left left
    int left_left = solve(dae_score + score[left], left+2, right);
    // left right
    int left_right = solve(dae_score + score[left], left+1, right-1);
    // right left
    int right_left = solve(dae_score + score[right], left+1, right-1);
    // right right
    int right_right = solve(dae_score + score[right], left, right-2);
    return max(max(left_left, left_right), max(right_left, right_right));
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        score.push_back(x);
        used.push_back(-1);
    } 
    cout << solve(0, 0, score.size()-1) << endl;
}

