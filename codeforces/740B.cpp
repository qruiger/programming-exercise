#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int a_val;
    cin >> a_val;
    a.push_back(a_val);
  }
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int sum = 0;
    for (int j = l; j <= r; j++) {
      sum += a[j];
    }
    if (sum > 0) {
      ans.push_back(sum);
    }
  }
  int final_ans = 0;
  for (auto it : ans) {
    final_ans += it;
  }
  cout << final_ans;
  return 0;
}
