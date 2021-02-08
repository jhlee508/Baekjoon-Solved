#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; // ������ ���� ����
int map[10][10]; // ���� ����
int virus_map[10][10]; // ���̷��� �̵� ����

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			virus_map[i][j] = map[i][j];
			if (virus_map[i][j] == 2) { // ��� ���̷����� ��ġ�� bfs ������
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (virus_map[nx][ny] == 0) { // �� ĭ�� ��쿡�� �̵� ����
					virus_map[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int numofSafezone = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus_map[i][j] == 0) {
				numofSafezone++;
			}
		}
	}

	return numofSafezone;
}

int main() {	
	// �Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int max_safezone = 0; // ���� ������ �ִ� ũ��

	// ���� Ž��
	for (int a1 = 0; a1 < n; a1++) {
		for (int a2 = 0; a2 < m; a2++) {
			if (map[a1][a2] != 0)
				continue;
			for (int b1 = 0; b1 < n; b1++) {
				for (int b2 = 0; b2 < m; b2++) {
					if (map[b1][b2] != 0)
						continue;
					for (int c1 = 0; c1 < n; c1++) {
						for (int c2 = 0; c2 < m; c2++) {
							if (map[c1][c2] != 0)
								continue;
							if (a1 == b1 && a2 == b2)
								continue;
							if (a1 == c1 && a2 == c2)
								continue;
							if (b1 == c1 && b2 == c2)
								continue;
							// �� 3�� �����
							map[a1][a2] = 1;
							map[b1][b2] = 1;
							map[c1][c2] = 1;

							// bfs�� ���� ���� ���� ���� ���ϱ�
							int numofSafezone = bfs();

							// �ִ� ���� ���� ���� ���ϱ�
							if (max_safezone < numofSafezone)
								max_safezone = numofSafezone;

							// ������� �ǵ�����
							map[a1][a2] = 0;
							map[b1][b2] = 0;
							map[c1][c2] = 0;
						}
					}
				}
			}
		}
	}
	cout << max_safezone << '\n';
	
	return 0;
}
