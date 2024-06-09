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

int check_all_days_cov() {
    for (auto x : days_to_cov) {
        if (x == 0) return 0;
    }
    return 1;
}

// add nisit to the day coverage
void check_nisit_data(Vector &ans) {
    int nisit_count = 0;
    reset_vec(days_to_cov);
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == 1) {
            nisit_count++;
            for (int x : nisit_map[i]) {
                days_to_cov[x - 1] += 1;
            }
        }
    }
    if (check_all_days_cov() == 1) least_ppl = min(least_ppl, nisit_count);
}

void brute(Vector &ans, int nisit_count, int idx) {
    if (nisit_count > least_ppl) return;
    if (idx == ans.size()) {
        check_nisit_data(ans);
        return;
    }
    ans[idx] = 0;
    brute(ans, nisit_count, idx + 1);
    ans[idx] = 1;
    brute(ans, nisit_count + 1, idx + 1);
}

void get_inputs() {
    cin >> n >> m;
    days_to_cov.resize(n, 0);  // Initialize with zeros
    for (int i = 0; i < m; ++i) {
        int day;
        cin >> day;
        for (int k = 0; k < day; ++k) {
            int free_day;
            cin >> free_day;
            nisit_map[i].push_back(free_day);
        }
    }
}

int main() {
    get_inputs();
    Vector ans(m);
    brute(ans, 0, 0);
    cout << least_ppl << endl;
    return 0;
}
