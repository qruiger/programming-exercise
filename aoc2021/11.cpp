#include <bits/stdc++.h>
using namespace std;

bool all_flashing(vector<vector<pair<int, int>>>& input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[0].size(); j++) {
      if (input[i][j].first != -1 && input[i][j].first != 0) {
        return false;
      }
    }
  }
  return true;
}

int get_total_flashes(int row,
                      int col,
                      vector<vector<pair<int, int>>>& input,
                      int size) {
  input[row][col].second = 1;
  vector<pair<int, int>> indices = {{row, col - 1},     {row, col + 1},
                                    {row + 1, col},     {row - 1, col},
                                    {row - 1, col - 1}, {row - 1, col + 1},
                                    {row + 1, col - 1}, {row + 1, col + 1}};
  for (auto it : indices) {
    if (input[it.first][it.second].first != -1 &&
        input[it.first][it.second].first != 0) {
      if (input[it.first][it.second].first == 9) {
        input[it.first][it.second].first = 0;
      } else {
        input[it.first][it.second].first++;
      }
      if (input[it.first][it.second].first == 0 &&
          input[it.first][it.second].second == 0) {
        size = get_total_flashes(it.first, it.second, input, ++size);
      }
    }
  }
  return size;
}

pair<int, int> solve(vector<vector<pair<int, int>>> input) {
  pair<int, int> ans(0, 0);
  int step = 1;
  while (1) {
    vector<pair<int, int>> nine_pos;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        input[i][j].second = 0;
        if (input[i][j].first == 9) {
          nine_pos.push_back(make_pair(i, j));
          input[i][j].first = 0;
        } else if (input[i][j].first != -1) {
          input[i][j].first++;
        }
      }
    }
    for (auto it : nine_pos) {
      int total_flashes = get_total_flashes(it.first, it.second, input, 1);
      if (step <= 100) {
        ans.first += total_flashes;
      }
    }
    if (all_flashing(input)) {
      ans.second = step;
      break;
    }
    step++;
  }
  return ans;
}

void populate_vector(vector<pair<int, int>>& vec, int size, int value) {
  for (int i = 0; i < size; i++) {
    vec.push_back(make_pair(value, -1));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<vector<pair<int, int>>> input;
  vector<pair<int, int>> row;
  ifstream fin;
  fin.open("11.in");
  int counter = 0;
  while (fin) {
    string line;
    getline(fin, line);
    if (line != "") {
      if (input.size() == 0) {
        populate_vector(row, line.length() + 2, -1);
        input.push_back(row);
        row.clear();
      }
      row.push_back(make_pair(-1, 0));
      for (int i = 0; i < line.length(); i++) {
        row.push_back(make_pair(int(line[i]) - '0', 0));
      }
      row.push_back(make_pair(-1, 0));
      input.push_back(row);
      row.clear();
    }
  }
  populate_vector(row, input[0].size(), -1);
  input.push_back(row);
  pair<int, int> ans = solve(input);
  cout << "part_one = " << ans.first << endl;
  cout << "part_two = " << ans.second << endl;
  return 0;
}