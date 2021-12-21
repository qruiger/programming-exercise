#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> get_adjacent_indices(int row,
                                            int col,
                                            int row_len,
                                            int col_len) {
  row_len--;
  col_len--;
  vector<pair<int, int>> indices;
  if (row == 0 && col == 0) {
    indices = {{row + 1, col}, {row, col + 1}};
  } else if (row == row_len && col == 0) {
    indices = {{row - 1, col}, {row, col + 1}};
  } else if (row == 0 && col == col_len) {
    indices = {{row, col - 1}, {row + 1, col}};
  } else if (row == row_len && col == col_len) {
    indices = {{row - 1, col}, {row, col - 1}};
  } else if (row == 0) {
    indices = {{row, col - 1}, {row, col + 1}, {row + 1, col}};
  } else if (row == row_len) {
    indices = {{row, col - 1}, {row, col + 1}, {row - 1, col}};
  } else if (col == 0) {
    indices = {{row - 1, col}, {row + 1, col}, {row, col + 1}};
  } else if (col == col_len) {
    indices = {{row - 1, col}, {row + 1, col}, {row, col - 1}};
  } else {
    indices = {{row, col - 1}, {row, col + 1}, {row + 1, col}, {row - 1, col}};
  }
  return indices;
}

bool are_all_lesser(int value, vector<int> adjacent) {
  for (int i = 0; i < adjacent.size(); i++) {
    if (adjacent[i] <= value) {
      return false;
    }
  }
  return true;
}

int get_basin_size(int row,
                   int col,
                   vector<vector<pair<int, int>>>& input,
                   int size) {
  vector<pair<int, int>> indices =
      get_adjacent_indices(row, col, input.size(), input[row].size());
  for (auto it : indices) {
    if (input[it.first][it.second].second == 0 &&
        input[it.first][it.second].first != 9) {
      input[it.first][it.second].second = 1;
      size = get_basin_size(it.first, it.second, input, ++size);
    }
  }
  return size;
}

pair<int, int> solve(vector<vector<pair<int, int>>> input) {
  pair<int, int> ans(0, 0);
  vector<pair<int, int>> low_points;
  vector<int> basins;
  for (int row = 0; row < input.size(); row++) {
    for (int col = 0; col < input[row].size(); col++) {
      vector<pair<int, int>> indices =
          get_adjacent_indices(row, col, input.size(), input[row].size());
      vector<int> values;
      for (auto it : indices) {
        values.push_back(input[it.first][it.second].first);
      }
      if (are_all_lesser(input[row][col].first, values)) {
        input[row][col].second = 1;
        low_points.push_back(make_pair(row, col));
        ans.first += input[row][col].first + 1;
      }
    }
  }
  for (int i = 0; i < low_points.size(); i++) {
    int basin_size =
        get_basin_size(low_points[i].first, low_points[i].second, input, 1);
    basins.push_back(basin_size);
  }
  sort(basins.begin(), basins.end(), greater<int>());
  ans.second = basins[0] * basins[1] * basins[2];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<vector<pair<int, int>>> input;
  ifstream fin;
  fin.open("9.in");
  while (fin) {
    string line;
    getline(fin, line);
    if (line != "") {
      vector<pair<int, int>> row;
      for (int i = 0; i < line.length(); i++) {
        row.push_back(make_pair(int(line[i]) - '0', 0));
      }
      input.push_back(row);
    }
  }
  pair<int, int> ans = solve(input);
  cout << "part_one = " << ans.first << endl;
  cout << "part_two = " << ans.second << endl;
  return 0;
}