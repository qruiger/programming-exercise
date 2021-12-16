#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

int part_one(vector<int> pos) {
  sort(pos.begin(), pos.end());
  int median = pos[pos.size() / 2];
  int ans = 0;
  for (int i = 0; i < pos.size(); i++) {
    ans += abs(pos[i] - median);
  }
  return ans;
}

int part_two(vector<int> pos) {
  float sum = 0, mean;
  for (int i = 0; i < pos.size(); i++) {
    sum += pos[i];
  }
  mean = round(sum / pos.size());
  int total_fuel = INT_MAX;
  for (int x = mean - 2; x <= mean + 2; x++) {
    int possible_total_fuel = 0;
    for (int i = 0; i < pos.size(); i++) {
      int distance = abs(pos[i] - x);
      possible_total_fuel += (distance * (distance + 1)) / 2;
    }
    total_fuel = min(possible_total_fuel, total_fuel);
  }
  return total_fuel;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  vector<int> pos;
  string line;
  fin.open("7.in");
  getline(fin, line);
  split(input, line, boost::is_any_of(","));
  for (int i = 0; i < input.size(); i++) {
    pos.push_back(stoi(input[i]));
  }
  cout << "part_one = " << part_one(pos) << endl;
  cout << "part_two = " << part_two(pos) << endl;
  return 0;
}