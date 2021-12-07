#include <bits/stdc++.h>
#define LL int long long
using namespace std;

LL binary_to_decimal(string binary) {
  LL ans = 0;
  for (LL i = 0; i < binary.length(); i++) {
    ans += binary[i] == '1' ? 1 << (binary.length() - i - 1) : 0;
  }
  return ans;
}

LL part_one(vector<string> input) {
  string gamma_rate_binary = "";
  for (LL col = 0; col < input[0].size(); col++) {
    LL one = 0, zero = 0;
    for (LL row = 0; row < input.size(); row++) {
      if (input[row][col] == '1') {
        one++;
      } else {
        zero++;
      }
      LL majority = (input.size() / 2) + 1;
      if (one == majority || zero == majority) {
        break;
      }
    }
    gamma_rate_binary += one > zero ? '1' : '0';
  }
  LL gamma_rate = binary_to_decimal(gamma_rate_binary);
  LL epsilon_rate = ~gamma_rate & ((1 << gamma_rate_binary.length()) - 1);
  return gamma_rate * epsilon_rate;
}

vector<string> get_numbers(vector<string> input,
                           LL position,
                           char tie_breaker,
                           char significance) {
  vector<string> one, zero;
  for (LL row = 0; row < input.size(); row++) {
    if (input[row][position] == '1') {
      one.push_back(input[row]);
    } else {
      zero.push_back(input[row]);
    }
  }
  if (one.size() == zero.size()) {
    return tie_breaker == '1' ? one : zero;
  }
  if (significance == 'm') {
    return one.size() > zero.size() ? one : zero;
  }
  if (significance == 'l') {
    return one.size() < zero.size() ? one : zero;
  }
}

LL solver(vector<string> input,
          LL n,
          LL position,
          char tie_breaker,
          char significance) {
  if (input.size() == 1) {
    return binary_to_decimal(input[0]);
  }
  vector<string> numbers =
      get_numbers(input, position, tie_breaker, significance);
  return solver(numbers, n, ++position, tie_breaker, significance);
}

LL part_two(vector<string> input) {
  return solver(input, input.size(), 0, '1', 'm') *
         solver(input, input.size(), 0, '0', 'l');
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<string> input;
  ifstream fin;
  fin.open("3.in");
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();
  cout << "part_one = " << part_one(input) << endl;
  cout << "part_two = " << part_two(input) << endl;
  return 0;
}