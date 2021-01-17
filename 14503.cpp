#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// �� �� �� �� (0 1 2 3)
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1};

// location
int loc[55][55];

int main() {

	// �Է�
	int n, m;
	cin >> n >> m;
	int x, y, dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> loc[i][j];
		
	// ����
	int cnt = 0;
	// loc[x][y] == 0 : û������ ���� ����
	// loc[x][y] == 1 : ��
	// loc[x][y] == 2 : û���� ����

	while (true) {
		// 1 : ���� ��ġ û���Ѵ�. �ٽ� û���ص� �������.
		if (loc[x][y] == 0) 
			loc[x][y] = 2;
		
		// 2-c, 2-d : �� ���� ��� û�Ұ� �Ǿ��ְų� ���� ���
		if (loc[x + 1][y] != 0 && loc[x - 1][y] != 0 && loc[x][y - 1] != 0 && loc[x][y + 1] != 0) {
			// 2-d : ���� ������ ��� -> �۵��� �����.
			if (loc[x - dx[dir]][y - dy[dir]] == 1) {
				break;
			}
			// 2-c : ������ ������ ä �� ĭ �����Ѵ�.
			else {
				x = x - dx[dir];
				y = y - dy[dir];
			}
		}

		// 2-a, 2-b
		else {
			// 2-a, 2-b : ���� �������� ȸ���Ѵ�.
			if (dir == 0)
				dir = 3;
			else if (dir == 1)
				dir = 0;
			else if (dir == 2)
				dir = 1;
			else
				dir = 2;

			// 2-a : û���� ������ �ִٸ� �̵��Ѵ�.
			if (loc[x + dx[dir]][y + dy[dir]] == 0) {
				x = x + dx[dir];
				y = y + dy[dir];
			}
		}
	}

	// ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (loc[i][j] == 2) {
				cnt += 1;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}