#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

void print_vector(Vector &v) {
  for (auto x : v)
    cout << x << " ";
  cout << endl;
}
void print_matrix(Matrix &m) {
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[0].size(); ++j) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

int n, m;
Matrix M;
Vector selected;
int min_result = 1e9;
bitset<1000> target;
bitset<1000> days_covered;

// return 0 if not covered
int check_days_covered(int nisit_id_bound) {
  days_covered.set();
  days_covered <<= n;
  for (int nisit_id = 0; nisit_id < nisit_id_bound; ++nisit_id) {
    if (selected[nisit_id] == 1) {
      for (int i = 0; i < n; ++i) {
        if (M[nisit_id][i] == 1)
          days_covered |= (1 << i);
      }
    }
  }
  int result = (days_covered == target);
  return result;
}

int count_nisit() {
return count(selected.begin(), selected.end(), 1);;
}

void brute(int nisit_id) {
  if (count_nisit() >= min_result) {
    return;
  }
  if (nisit_id == m) {
    if (check_days_covered(nisit_id) == 1) {
      min_result = std::min(min_result, count_nisit());
    }
    return;
  }
  selected[nisit_id] = 1;
  brute(nisit_id + 1);
  selected[nisit_id] = 0;
  brute(nisit_id + 1);
}

// careful day--
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  M.resize(m, Vector(n, 0));
  target.set();

  selected.resize(m);
  for (int nisit_id = 0; nisit_id < m; ++nisit_id) {
    int k, day;
    cin >> k;
    for (int day_count = 0; day_count < k; ++day_count) {
      cin >> day;
      --day;
      M[nisit_id][day] = 1;
    }
  }
  brute(0);
  cout << min_result << endl;
  return 0;
}
