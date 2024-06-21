#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

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
Vector score = 
    //{1,2,9,8}
{9,8,7,3,2,1};
//  9 9 1 1 1 1 9 9
//    {9,9,1,1,1,1,9,9}
// {9,8,7,3,2,1}
Vector used(score.size(), -1);

int max3(int a, int b, int c) {
    return max(a, max(b,c));
}

int solve(int dae_score, int left, int right) {
    printf("dae_score: %d, left: %d, right: %d ", dae_score, left, right);
    printf(" | ");
    print_vec(score, left, right);
    if (left > right) return -1;
    if (left == right) return score[left];
    if (right - left == 1) return dae_score + max(score[left], score[right]);
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

