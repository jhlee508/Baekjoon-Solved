#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char cave[101][101];
bool crash[101][101]; 
int dx[] = { 0, 0, 1, -1 }; // 세로방향(행) 이동
int dy[] = { 1, -1, 0, 0 }; // 가로방향(열) 이동
int r, c; // 동굴의 크기(r행 c열)
vector<pair<int, int>> cluster;

void dfs(int x, int y) {
	if (cave[x][y] == '.')
		return;
	if (crash[x][y])
		return;
	crash[x][y] = true;
	cluster.push_back(make_pair(x, y));
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < r && 0 <= ny && ny < c) {
			dfs(nx, ny);
		}
	}
}

void Crashdown() {
	memset(crash, false, sizeof(crash));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// 미네랄이 없을 경우
			if (cave[i][j] == '.')
				continue;
			// 이미 떨어진 경우
			if (crash[i][j])
				continue;
			// 클러스터 만들기
			cluster.clear();
			dfs(i, j);
			vector<int> low(c, -1); // 클러스터의 가장 아래 위치
			for (auto &p : cluster) {
				low[p.second] = max(low[p.second], p.first);
				cave[p.first][p.second] = '.';
			}
			
			int level = c; // 떨어지는 칸의 갯수
			for (int i, j = 0; j < c; j++) {
				if (low[j] == -1)
					continue;
				for (i = low[j]; i < r && cave[i][j] == '.'; i++);
				level = min(level, i - 1 - low[j]);
			}
			for (auto &p : cluster) {
				p.first += level;
				cave[p.first][p.second] = 'x';
				crash[p.first][p.second] = true;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> cave[i];
	}

	int n; // 막대 던진 횟수(1~100)
	cin >> n;

	for (int i = 0; i < n; i++) {
		int height; // 막대를 던진 높이
		cin >> height;
		height = r - height;

		// 왼쪽에서 던질 때
		if (i % 2 == 0) {
			for (int col = 0; col <  c; col++) {
				if (cave[height][col] == 'x') {
					cave[height][col] = '.';
					break;
				}
			}
		}

		// 오른쪽에서 던질 때
		else {
			for (int col = c - 1; col >= 0; col--) {
				if (cave[height][col] == 'x') {
					cave[height][col] = '.';
					break;
				}
			}
		}

		Crashdown();
	}

	for (int i = 0; i < r; i++) {
		cout << cave[i] << '\n';
	}
}