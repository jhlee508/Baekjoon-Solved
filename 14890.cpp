#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool check(vector<int> &map, int l) {
	int n = map.size();
	vector<bool> hill(n, false);
	for (int i = 1; i < n; i++) {
		// 높이 차이 발생
		if (map[i - 1] != map[i]) {
			int diff = abs(map[i - 1] - map[i]);

			// 높이차가 1이 넘을 경우
			if (diff > 1)
				return false;
			 
			if (map[i - 1] < map[i]) {
				for (int j = 1; j <= l; j++) {
					// 경사로의 범위 벗어남
					if (i - j < 0) {
						return false;
					}
					// 낮은 지점의 칸의 높이가 같지 않거나, L개 연속되지 않은 경우
					if (map[i - 1] != map[i - j]) {
						return false;
					}
					// 경사로를 높은 곳에 또 놓는 경우
					if (hill[i - j]) {
						return false;
					}
					hill[i - j] = true;
				}
			}

			else { // map[i - 1] > map[i]
				for (int j = 0; j < l; j++) {
					// 경사로의 범위 벗어남
					if (i + j >= n) {
						return false;
					}
					// 낮은 지점의 칸의 높이가 같지 않거나, L개 연속되지 않은 경우
					if (map[i] != map[i + j]) {
						return false;
					}
					// 경사로를 높은 곳에 또 놓는 경우
					if (hill[i + j]) {
						return false;
					}
					hill[i + j] = true;
				}
			}
		}
	}
	return true;
}

int main() {

	int n, l;
	cin >> n >> l;

	// n * n 크기의 2차원 벡터 생성 
	vector<vector<int>> map(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int ans = 0;

	// 행 check
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			row.push_back(map[i][j]);
		}
		if (check(row, l))
			ans++;
	}

	// 열 check
	for (int i = 0; i < n; i++) {
		vector<int> col;
		for (int j = 0; j < n; j++) {
			col.push_back(map[j][i]);
		}
		if (check(col, l))
			ans++;
	}

	cout << ans << '\n';
	return 0;
}