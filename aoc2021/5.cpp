#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

int get_ans(vector<vector<int>>& plot) {
  int ans = 0;
  for (int x = 0; x < plot.size(); x++) {
    for (int y = 0; y < plot[x].size(); y++) {
      if (plot[x][y] >= 2) {
        ans++;
      }
    }
  }
  return ans;
}

void plotter (
    vector<vector<int>>& plot,
    pair<int, int>& line_start,
    pair<int, int>& line_end,
    char change
  ) {
  int co_ordinate_start, co_ordinate_end;
  if (change == 'x') {
    co_ordinate_start = min(line_start.first, line_end.first);
    co_ordinate_end = co_ordinate_start == line_start.first ? line_end.first : line_start.first;
  } else if (change == 'y') {
    co_ordinate_start = min(line_start.second, line_end.second);
    co_ordinate_end = co_ordinate_start == line_start.second ? line_end.second : line_start.second;
  }
  for (int i = co_ordinate_start; i <= co_ordinate_end; i++) {
    if (change == 'x') {
      plot[line_start.second][i]++;
    } else {
      plot[i][line_start.first]++;
    }
  }
}

int part_one(vector<pair<pair<int, int>, pair<int, int>>> line_co_ordinates) {
  vector<vector<int>> plot(1001, vector<int>(1001));
  for (int i = 0; i < line_co_ordinates.size(); i++) {
    pair<int, int> line_start = line_co_ordinates[i].first;
    pair<int, int> line_end = line_co_ordinates[i].second;
    if (line_start.first == line_end.first) {
      plotter(plot, line_start, line_end, 'y');
    } else if (line_start.second == line_end.second) {
      plotter(plot, line_start, line_end, 'x');
    }
  }
  return get_ans(plot);
}

int part_two(vector<pair<pair<int, int>, pair<int, int>>> line_co_ordinates) {
  vector<vector<int>> plot(1001, vector<int>(1001));
  for (int i = 0; i < line_co_ordinates.size(); i++) {
    pair<int, int> line_start = line_co_ordinates[i].first;
    pair<int, int> line_end = line_co_ordinates[i].second;
    if (line_start.first == line_end.first) {
      plotter(plot, line_start, line_end, 'y');
    } else if (line_start.second == line_end.second) {
      plotter(plot, line_start, line_end, 'x');
    } else {
      int x_start = min(line_start.first, line_end.first);
      int y_start = x_start == line_start.first ? line_start.second : line_end.second;
      int x_end = x_start == line_start.first ? line_end.first : line_start.first;
      int y_end = y_start == line_start.second ? line_end.second : line_start.second;
      int y = y_start;
      for (int x = x_start; x <= x_end; x++) {
        plot[y][x]++;
        if (y > y_end) {
          y--;
        } else {
          y++;
        }
      }
    }
  }
  return get_ans(plot);
}

pair<pair<int, int>, pair<int, int>> get_line_co_ordinates(string line) {
  pair<pair<int, int>, pair<int, int>> line_co_ordinates;
  vector<string> start_co_ordinates, end_co_ordinates;
  string splitter = " -> ", start, end;
  int splitter_pos = line.find(splitter);
  for (int i = 0; i < line.length(); i++) {
    if (i < splitter_pos) {
      start += line[i];
    } else if (i > (splitter_pos + splitter.length() - 1)) {
      end += line[i];
    }
  }
  split(start_co_ordinates, start, boost::is_any_of(","));
  split(end_co_ordinates, end, boost::is_any_of(","));
  line_co_ordinates =
      make_pair(make_pair(stoi(start_co_ordinates[0]), stoi(start_co_ordinates[1])),
                make_pair(stoi(end_co_ordinates[0]), stoi(end_co_ordinates[1])));
  return line_co_ordinates;
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<pair<pair<int, int>, pair<int, int>>> line_co_ordinates;
  ifstream fin;
  fin.open("5.in");
  while (fin) {
    string line;
    getline(fin, line);
    if (line != "") {
      line_co_ordinates.push_back(get_line_co_ordinates(line));
    }
  }
  cout << "part_one = " << part_one(line_co_ordinates) << endl;
  cout << "part_two = " << part_two(line_co_ordinates) << endl;
  return 0;
}