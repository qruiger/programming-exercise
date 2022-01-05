#include <bits/stdc++.h>
#define LL int long long
#define NMAX 200000
#define M 998244353
using namespace std;

void calculate_factorial(vector<int>& factorial) {
  factorial[0] = 1;
  for (LL i = 1; i <= NMAX; i++) {
    factorial[i] = (factorial[i - 1] * i) % M;
  }
}

// http://www.doc.ic.ac.uk/~mrh/330tutor/ch03.html
// https://www.geeksforgeeks.org/modular-division/
LL gcd_extended(LL a, LL b, LL *x, LL *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  LL x1, y1;
  LL gcd = gcd_extended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

LL mod_inverse(LL b, LL m) {
  LL x, y;
  LL g = gcd_extended(b, m, &x, &y);
  if (g != 1)
    return -1;
  return (x % m + m) % m;
}

LL modular_division(LL a, LL b, LL m) {
  a = a % m;
  LL inv = mod_inverse(b, m);
  return (inv * a) % m;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  vector<int> factorial(NMAX);
  calculate_factorial(factorial);
  while (t--) {
    int n, max_val = -1, smax_val = -1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > max_val) {
        smax_val = max_val;
        max_val = a[i];
      } else if (a[i] > smax_val && a[i] != max_val) {
        smax_val = a[i];
      }
    }
    int max_count = count(a.begin(), a.end(), max_val);
    int smax_count = count(a.begin(), a.end(), smax_val);
    if (max_count > 1) {
      /**
       * 1 3 3 will reduce to 0 1 1
       * there will never be any !nice permutations, so answer will be total perm = n!
       */
      cout << factorial[n] << endl;
    } else if ((max_val - smax_val) > 1) {
      /**
       * 1 2 3 will always end up in something like 0 0 1 in second-last step
       * so there are no nice permutations
       */
      cout << 0 << endl;
    } else {
      /**
       * max_val - smax_val == 1
       * 2 2 3 is !nice
       * 2 3 2 is nice
       * thus, we need to find, n! - total(!nice)
       * !nice is basically when there are no (max_val - 1) values to the right of max_val
       * consider, 1 1 3 4 4 4 5 2 3 1 1
       * treat 4 4 4 5 as one entity
       * so, !nice arrangements = nCsmax_count+1 * smax_count! * rem_count! = [n! / (smax_count + 1)]
       * smax_count! because, max position is fixed and you have to only arrange the smax values
       * rem_count = n - smax_count - 1, which is for arranging elements other than max and smax
      */
      LL not_nice_perms = modular_division(factorial[n], smax_count + 1, M);
      cout << (factorial[n] - not_nice_perms + M) % M << endl;
    }
  }
  return 0;
}