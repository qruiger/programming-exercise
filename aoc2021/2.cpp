#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define LL int long long
using namespace std;

LL part_one(vector<string> commands) {
  LL x = 0, y = 0;
  for (LL i = 0; i < commands.size(); i++) {
    vector<string> command;
    split(command, commands[i], boost::is_any_of(" "));
    string command_type = command[0];
    LL units = stoll(command[1]);
    if (command_type == "forward") {
      x += units;
    } else if (command_type == "down") {
      y += units;
    } else if (command_type == "up") {
      y -= units;
    }
  }
  return x * y;
}

LL part_two(vector<string> commands) {
  LL x = 0, y = 0, aim = 0;
  for (LL i = 0; i < commands.size(); i++) {
    vector<string> command;
    split(command, commands[i], boost::is_any_of(" "));
    string command_type = command[0];
    LL units = stoll(command[1]);
    if (command_type == "forward") {
      x += units;
      y += aim * units;
    } else if (command_type == "down") {
      aim += units;
    } else if (command_type == "up") {
      aim -= units;
    }
  }
  return x * y;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("2.in");
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
