#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// 시계방향 회전
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int n, m;

void check(vector<vector<int>> &office, vector<vector<int>> &v, int x, int y, int dir) {
	int i = x;
	int j = y;
	while (0 <= i && i < n && 0 <= j && j < m) {
		if (office[i][j] == 6)
			break;
		v[i][j] = office[x][y]; // 감시 영역 표시
		i += dx[dir];
		j += dy[dir];
	}
}

int surveil(vector<vector<int>> &office, vector<tuple<int, int, int>> &cctv, int index, vector<int> dirs) {
	if (cctv.size() == index) {
		vector<vector<int>> v(office);
		for (int i = 0; i < cctv.size(); i++) {
			int type, x, y;
			tie(type, x, y) = cctv[i];
			if (type == 1) {
				check(office, v, x, y, dirs[i]);
			}
			else if (type == 2) {
				check(office, v, x, y, dirs[i]);
				check(office, v, x, y, (dirs[i] + 2) % 4);
			}
			else if (type == 3) {
				check(office, v, x, y, dirs[i]);
				check(office, v, x, y, (dirs[i] + 1) % 4);
			}
			else if (type == 4) {
				check(office, v, x, y, dirs[i]);
				check(office, v, x, y, (dirs[i] + 1) % 4);
				check(office, v, x, y, (dirs[i] + 2) % 4);
			}
			else if (type == 5) {
				check(office, v, x, y, dirs[i]);
				check(office, v, x, y, (dirs[i] + 1) % 4);
				check(office, v, x, y, (dirs[i] + 2) % 4);
				check(office, v, x, y, (dirs[i] + 3) % 4);
			}
		}
		int numofBlindspot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 0) {
					numofBlindspot++;
				}
			}
		}
		return numofBlindspot;
	}
	int ans = 100; // 최대 개수 64

	// cctv 방향 결정(0, 90, 180, 270 회전)
	for (int i = 0; i < 4; i++) {
		dirs[index] = i;
		int temp = surveil(office, cctv, index + 1, dirs);
		if (ans > temp) {
			ans = temp;
		}
	}

	return ans;
}

int main() {
	// 입력
	cin >> n >> m;
	
	vector<vector<int>> office(n, vector<int>(m));
	vector<tuple<int, int, int>> cctv; // cctv의 종류 + 위치(x, y)
	vector<int> dirs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5) {
				cctv.emplace_back(office[i][j], i, j);
				dirs.push_back(0);
			}
		}
	}

	int min_Blindspot = surveil(office, cctv, 0, dirs); 

	cout << min_Blindspot << '\n';
	return 0;
}