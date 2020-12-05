#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define LL int long long
using namespace std;

LL binary_to_decimal(LL binary) {
  LL exponent = 0, decimal = 0;
  while (binary > 0) {
    decimal += (binary % 10) << exponent++;
    binary /= 10;
  }
  return decimal;
}

pair<LL, LL> part_one(string row, string col) {
  pair<LL, LL> ans;
  boost::replace_all(row, "F", "0");
  boost::replace_all(row, "B", "1");
  boost::replace_all(col, "L", "0");
  boost::replace_all(col, "R", "1");
  ans.first = binary_to_decimal(stoll(row));
  ans.second = binary_to_decimal(stoll(col));
  return ans;
}

LL part_two(vector<LL> seat_ids) {
  sort(seat_ids.begin(), seat_ids.end());
  for (LL i = 1; i < seat_ids.size(); i++) {
    if ((seat_ids[i] - seat_ids[i - 1]) == 2) {
      return (seat_ids[i] - 1);
    }
  }
}

pair<LL, LL> solve(vector<string> input) {
  pair<LL, LL> ans(0, 0);
  vector<LL> seat_ids;
  for (LL i = 0; i < input.size(); i++) {
    string row = input[i].substr(0, 7);
    string col = input[i].substr(7);
    pair<LL, LL> part_one_response = part_one(row, col);
    LL part_one_ans = (part_one_response.first * 8) + part_one_response.second;
    seat_ids.push_back(part_one_ans);
    ans.first = part_one_ans > ans.first ? part_one_ans : ans.first;
  }
  ans.second = part_two(seat_ids);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  fin.open("5.in");
  vector<string> input;
  while (fin) {
    string line;
    getline(fin, line);
    input.push_back(line);
  }
  input.pop_back();

  pair<LL, LL> ans = solve(input);
  cout << "part_one = " << ans.first << endl;
  cout << "part_two = " << ans.second << endl;
  return 0;
}