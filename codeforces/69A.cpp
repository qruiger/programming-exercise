#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, a, b, c, sa = 0, sb = 0, sc = 0;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    sa += a;
    sb += b;
    sc += c;
  }
  if (sa == 0 && sb == 0 && sc == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
