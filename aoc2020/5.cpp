#include <bits/stdc++.h>
#define LL int long long
using namespace std;

pair<LL, LL> calculate_range(pair<LL, LL> range, char decider) {
  pair<LL, LL> computed_range = range;
  if (decider == 'F' || decider == 'L') {
    computed_range.second =
        range.second - ((range.second - range.first + 1) / 2);
  } else if (decider == 'B' || decider == 'R') {
    computed_range.first = range.first + ((range.second - range.first + 1) / 2);
  }
  return computed_range;
}

pair<LL, LL> part_one(string row, string col) {
  LL total_row = 127, total_col = 7;
  pair<LL, LL> ans, row_tracker(0, total_row), col_tracker(0, total_col);
  for (LL i = 0; i < row.size(); i++) {
    row_tracker = calculate_range(row_tracker, row[i]);
  }
  for (LL i = 0; i < col.size(); i++) {
    col_tracker = calculate_range(col_tracker, col[i]);
  }
  ans.first = row_tracker.first;
  ans.second = col_tracker.second;
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