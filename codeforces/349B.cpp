#include <bits/stdc++.h>
using namespace std;

int main () {
  int v, x, min_paint = INT_MAX, min_number = 0;
  vector<int> a;
  cin >> v;
  a.push_back(-1);
  for (int i = 1; i <= 9; i++) {
    cin >> x;
    if (x <= min_paint) {
      min_paint = x;
      min_number = i;
    }
    a.push_back(x);
  }
  int length = v / min_paint;
  if (length == 0) {
    cout << -1;
  } else {
    string greedy(length, min_number + '0');
    int paint_used = length * min_paint;
    for (int x = 0; x < greedy.length(); x++) {
      int current_digit = greedy[x] - '0';
      for (int i = 9; i > current_digit; i--) {
        int updated_paint_used = (a[i] - min_paint) + paint_used;
        if (updated_paint_used <= v) {
          greedy[x] = i + '0';
          paint_used = updated_paint_used;
          break;
        }
      }
    }
    cout << greedy;
  }
  return 0;
}
