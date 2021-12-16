#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define LL unsigned long long int
using namespace std;

LL solve(vector<int> timers, int total_days) {
  LL ans = 0;
  LL tracker[9] = {0};
  for (int i = 0; i < timers.size(); i++) {
    tracker[timers[i]]++;
  }
  while (total_days--) {
    LL new_spawns = tracker[0];
    for (int j = 0; j < 8; j++) {
      tracker[j] = tracker[j + 1];
    }
    tracker[6] += new_spawns;
    tracker[8] = new_spawns;
  }
  for (int i = 0; i < 9; i++) {
    ans += tracker[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  vector<int> timers;
  string line;
  fin.open("6.in");
  getline(fin, line);
  split(input, line, boost::is_any_of(","));
  for (int i = 0; i < input.size(); i++) {
    timers.push_back(stoi(input[i]));
  }
  cout << "part_one = " << solve(timers, 80) << endl;
  cout << "part_two = " << solve(timers, 256) << endl;
  return 0;
}