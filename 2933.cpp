#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char cave[101][101];
bool crash[101][101]; 
int dx[] = { 0, 0, 1, -1 }; // ���ι���(��) �̵�
int dy[] = { 1, -1, 0, 0 }; // ���ι���(��) �̵�
int r, c; // ������ ũ��(r�� c��)
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
			// �̳׶��� ���� ���
			if (cave[i][j] == '.')
				continue;
			// �̹� ������ ���
			if (crash[i][j])
				continue;
			// Ŭ������ �����
			cluster.clear();
			dfs(i, j);
			vector<int> low(c, -1); // Ŭ�������� ���� �Ʒ� ��ġ
			for (auto &p : cluster) {
				low[p.second] = max(low[p.second], p.first);
				cave[p.first][p.second] = '.';
			}
			
			int level = c; // �������� ĭ�� ����
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

	int n; // ���� ���� Ƚ��(1~100)
	cin >> n;

	for (int i = 0; i < n; i++) {
		int height; // ���븦 ���� ����
		cin >> height;
		height = r - height;

		// ���ʿ��� ���� ��
		if (i % 2 == 0) {
			for (int col = 0; col <  c; col++) {
				if (cave[height][col] == 'x') {
					cave[height][col] = '.';
					break;
				}
			}
		}

		// �����ʿ��� ���� ��
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