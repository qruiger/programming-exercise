#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int x, y, v;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> v;
      if (v == 1) {
        y = i;
        x = j;
      }
    }
  }
  cout << abs(y - 2) + abs(x - 2) << endl;
  return 0;
}
