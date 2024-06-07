#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef map<int, Vector> Map;

int n;  // days to cover
int m;  // nisit count

Map nisit_map;  // info of free days per nisit

Vector days_to_cov;
int least_ppl = 99999999;

void print_vec(Vector &v) {
    for (const int &x : v)
        cout << x << " ";
    cout << endl;
}
void reset_vec(Vector &v) {
    for (int i = 0; i < v.size(); ++i) {
        v[i] = 0;
    }
}

bool check_all_cov() {
    for (int i = 0; i < n; ++i) {
        if (days_to_cov[i] == 0)
            return false;
    }
    return true;
}
int count_ones(Vector &v) {
    int ones = 0;
    for (auto x : v)
        if (x == 1)
            ones++;
    return ones;
}

void check_nisit_data(Vector &ans) {
    int nisit_count = 0;
    reset_vec(days_to_cov);
    for (int i = 0; i < ans.size(); ++i) {
        // nisit is chosen
        if (ans[i] == 1) {
            nisit_count++;
            for (int x : nisit_map[i]) {
                days_to_cov[x - 1] += 1;
            }
        }
    }
    bool covered_all_days = check_all_cov();
    if (covered_all_days) {
        int ones_count = count_ones(ans);
        if (ones_count < least_ppl) {
            least_ppl = ones_count;
        }
    }
}

void brute(Vector &ans, int n) {
    if (n == ans.size()) {
        // do soemthing
        check_nisit_data(ans);
        return;
    }
    ans[n] = 0;
    brute(ans, n + 1);
    ans[n] = 1;
    brute(ans, n + 1);
}

void get_inputs() {
    cin >> n >> m;
    days_to_cov.resize(n);
    int day;
    for (int i = 0; i < m; ++i) {
        cin >> day;
        int free_day;
        for (int k = 0; k < day; ++k) {
            cin >> free_day;
            nisit_map[i].push_back(free_day);
        }
    }
}

int main() {
    get_inputs();
    Vector ans(m);
    brute(ans, 0);
    cout << least_ppl << endl;
    return 0;
}
