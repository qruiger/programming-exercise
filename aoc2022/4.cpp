#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string s, char delimitter) {
  vector<string> result;
  for (int i = 0; i < s.length();) {
    string temp = "";
    bool flag = false;
    while (s[i] != delimitter && i < s.length()) {
      flag = true;
      temp += s[i++];
    }
    if (!flag) i++;
    else result.push_back(temp);
  }
  return result;
}

vector<pair<int, int>> get_times (string range) {
  vector<pair<int, int>> times;
  vector<string> sections = split(range, ',');
  vector<string> section_a = split(sections[0], '-');
  vector<string> section_b = split(sections[1], '-');
  times.push_back(make_pair(stoi(section_a[0]), stoi(section_a[1])));
  times.push_back(make_pair(stoi(section_b[0]), stoi(section_b[1])));
  return times;
}

int part_one(vector<string> input) {
  int ans = 0;
  for (auto it : input) {
    vector<pair<int, int>> times = get_times(it);
    if (((times[0].first <= times[1].first) && (times[0].second >= times[1].second)) ||
        ((times[0].first >= times[1].first) && (times[0].second <= times[1].second))) {
      ans++;
    }
  }
  return ans;
}

int part_two(vector<string> input) {
  int ans = 0;
  for (auto it : input) {
    vector<pair<int, int>> times = get_times(it);
    sort(
      times.begin(),
      times.end(),
      [](auto &a, auto &b) { return a.first < b.first; });
    if (times[1].first <= times[0].second) {
      ans++;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("4.in");
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