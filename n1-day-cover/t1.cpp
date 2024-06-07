#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

std::bitset<1000> days_covered;

void print_vector(Vector &v) {
  for (auto x : v) cout << x << " ";
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
bitset<1000> target;

// return 0 if not covered
int check_days_covered(int nisit_id_bound) {
  bitset<1000> days_covered;
  days_covered.set();
  days_covered <<= 1000 - n;
  for (int nisit_id = 0; nisit_id < nisit_id_bound; ++nisit_id) {
    if (selected[nisit_id] == 1) {
      for (int i = 0; i < n; ++i) {
        days_covered |= M[nisit_id][i]; 
      }
    }
  }
  int result =  (days_covered == target);
  if (result) cout << "FOUND" << endl;
  return result;
}

int count_nisit() {
  int count = 0;
  for (int i = 0; i < m; ++i) {
    if (selected[i] == 1) ++count;
  }
  return count;
}

int brute(int nisit_id) {
  if (nisit_id == m) {
    return -1;
  }
  print_vector(selected);
  int result = check_days_covered(nisit_id);
  if (result == 1) {
    cout << "FOUND2" << endl;
    return count_nisit();
  }
  selected[nisit_id] = 1;
  brute(nisit_id + 1);
  selected[nisit_id] = 0;
  brute(nisit_id + 1);
}

// careful day--
int main() {
  cin >> n >> m;
  M.resize(m, Vector(n, 0));
  selected.resize(m);
  days_covered.set();
  for (int nisit_id = 0; nisit_id < m; ++nisit_id) {
    int k, day;
    cin >> k;
    for (int day_count = 0; day_count < k; ++day_count) {
      cin >> day;
      --day;
      M[nisit_id][day] = 1;
    }
  }
  cout << brute(0) << endl;
}
