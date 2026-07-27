#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void solve() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int m;
    cin >> m;

    string time;
    char sign;
    int offset;

    for (int i = 0; i < m; ++i) {
      cin >> time >> sign >> offset;
      if (sign == '-') offset = -offset;

      int h, min;
      char colon;
      istringstream iss(time);
      iss >> h >> colon >> min;

      int total = h * 60 + min + offset * 60;
      total = (total % 1440 + 1440) % 1440;

      h = total / 60;
      min = total % 60;

      cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0')
           << min << "\n";
    }
  }
}

int main() {
  solve();
  return 0;
}
