#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

pair<string, string> split_input(string input_line) {
  string splitter = " | ", signal, output;
  pair<string, string> result("", "");
  int splitter_pos = input_line.find(splitter);
  for (int i = 0; i < input_line.length(); i++) {
    if (i < splitter_pos) {
      result.first += input_line[i];
    } else if (i > (splitter_pos + splitter.length() - 1)) {
      result.second += input_line[i];
    }
  }
  return result;
}

int part_one(vector<string> input) {
  int ans = 0;
  int digit_count[] = {2, 4, 3, 7};
  for (int i = 0; i < input.size(); i++) {
    pair<string, string> result = split_input(input[i]);
    vector<string> signal, output;
    split(signal, result.first, boost::is_any_of(" "));
    split(output, result.second, boost::is_any_of(" "));
    for (int i = 0; i < output.size(); i++) {
      for (int j = 0; j < 4; j++) {
        if (output[i].size() == digit_count[j]) {
          ans++;
          break;
        }
      }
    }
  }
  return ans;
}

int part_two(vector<string> input) {
  int ans = 0;
  for (int i = 0; i < input.size(); i++) {
    unordered_map<int, int> digit_count;
    unordered_map<string, int> mapping;
    vector<string> number(10);
    vector<string> signal, output;
    digit_count[2] = 1;
    digit_count[4] = 4;
    digit_count[3] = 7;
    digit_count[7] = 8;
    pair<string, string> result = split_input(input[i]);
    split(signal, result.first, boost::is_any_of(" "));
    split(output, result.second, boost::is_any_of(" "));
    for (int i = 0; i < signal.size(); i++) {
      if (digit_count[signal[i].size()]) {
        number[digit_count[signal[i].size()]] = signal[i];
      }
    }
    for (int i = 0; i < signal.size(); i++) {
      if (signal[i].size() == 6 && number[6] == "") {
        for (int j = 0; j < number[7].size(); j++) {
          if (signal[i].find(number[7][j]) == -1) {
            number[6] = signal[i];
            break;
          }
        }
      }
    }
    for (int i = 0; i < signal.size(); i++) {
      if (signal[i].size() == 5 && number[5] == "") {
        int flag = 0;
        for (int j = 0; j < signal[i].size(); j++) {
          if (number[6].find(signal[i][j]) == -1) {
            flag = 1;
            break;
          }
        }
        if (!flag) {
          number[5] = signal[i];
        }
      }
    }
    char diff;
    for (int i = 0; i < number[7].size(); i++) {
      if (number[5].find(number[7][i]) == -1) {
        diff = number[7][i];
      }
    }
    number[9] = diff + number[5];
    for (int i = 0; i < signal.size(); i++) {
      if (signal[i].size() == 6 && signal[i] != number[6] &&
          signal[i] != number[9]) {
        number[0] = signal[i];
      }
    }
    for (int i = 0; i < signal.size(); i++) {
      if (signal[i].size() == 5 && signal[i] != number[5]) {
        if (signal[i].find(number[1][0]) != -1 &&
            signal[i].find(number[1][1]) != -1) {
          number[3] = signal[i];
        } else {
          number[2] = signal[i];
        }
      }
    }
    for (int i = 0; i <= 9; i++) {
      sort(number[i].begin(), number[i].end());
      mapping[number[i]] = i;
    }
    int current_ans = 0;
    for (int i = 0; i < output.size(); i++) {
      sort(output[i].begin(), output[i].end());
      current_ans = (current_ans * 10) + mapping[output[i]];
    }
    ans += current_ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin;
  vector<string> input;
  fin.open("8.in");
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