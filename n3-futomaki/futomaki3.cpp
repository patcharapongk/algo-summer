#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

nt max3(int a, int b, int c) {
    return max(a, max(b,c));
}

int solve(int dae_score, int left, int right) {
   if (left >= right) return dae_score;
    // left left
    int l1 = solve(dae_score + score[left], left+2, right);
    int mid = solve(dae_score + max(score[left],score[right]), left+1, right-1);
    // right right
    int r1 = solve(dae_score + score[right], left, right-2);
    return max3(l1, mid, r1);
}

int main() {
    cout << solve(0, 0, score.size()-1) << endl;
}

