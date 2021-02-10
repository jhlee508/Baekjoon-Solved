#include <iostream>
#include <vector>
using namespace std;

int ladder[100][100]; // 2���� �迭
int n, m, h; // ���μ�, ���μ�, ���μ� ����

// 1�� ���μ� �˻�
int start(int c) { // c ��° ���μ����� ��ٸ� Ÿ�� ����
	int r = 1; // 1 ��° ���μ�(�� ��)���� ����

	while (r <= h) { // h = ������ ���μ�
		if (ladder[r][c] == 1) {
			c += 1; // ���������� �̵�
		}
		else if (ladder[r][c] == 2) {
			c -= 1; // �������� �̵�
		}
		r += 1; // �Ʒ��� ��������
	}
	return c; // ���� ���� ��ġ
}

// ��� ���μ� �˻�
bool simulation() {
	for (int i = 1; i <= n; i++) {
		int ret = start(i);
		if (ret != i)
			return false;
	}
	return true;
}

int main() {
	// �Է�
	cin >> n >> m >> h;
	// ���� ��ٸ� ����
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x][y] = 1;
		ladder[x][y + 1] = 2;
	}

	vector<pair<int, int>> v; // ���μ��� ���� �� �ִ� ��ǥ ����
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (ladder[i][j] != 0)
				continue;
			if (ladder[i][j + 1] != 0)
				continue;
			v.push_back(make_pair(i, j));
		}
	}

	int garo = -1; // ��� ��

	if (simulation()) { // �˻� ����
		cout << 0 << '\n';
		return 0;
	}

	int len = v.size();
	for (int i = 0; i < len; i++) {
		int x1 = v[i].first;
		int y1 = v[i].second;
		if (ladder[x1][y1] != 0 || ladder[x1][y1 + 1] != 0)
			continue;
		// ���μ� ����
		ladder[x1][y1] = 1;
		ladder[x1][y1 + 1] = 2;

		if (simulation()) { // ���μ� 1�� ���� �˻�
			if (garo == -1 || garo > 1) {
				garo = 1; // ���μ� = 1
			}
		}

		for (int j = i + 1; j < len; j++) {
			int x2 = v[j].first;
			int y2 = v[j].second;
			if (ladder[x2][y2] != 0 || ladder[x2][y2 + 1] != 0)
				continue;
			// ���μ� ����
			ladder[x2][y2] = 1;
			ladder[x2][y2 + 1] = 2;

			if (simulation()) { // ���μ� 2�� ���� �˻�
				if (garo == -1 || garo > 2) {
					garo = 2; // ���μ� = 2
				}
			}

			for (int k = j + 1; k < len; k++) {
				int x3 = v[k].first;
				int y3 = v[k].second;
				if (ladder[x3][y3] != 0 || ladder[x3][y3 + 1] != 0)
					continue;
				// ���μ� ����
				ladder[x3][y3] = 1;
				ladder[x3][y3 + 1] = 2;

				if (simulation()) { // ���μ� 3�� ���� �˻�
					if (garo == -1 || garo > 3) {
						garo = 3; // ���μ� = 3
					}
				}
				ladder[x3][y3] = 0;
				ladder[x3][y3 + 1] = 0;
			}
			ladder[x2][y2] = 0;
			ladder[x2][y2 + 1] = 0;
		}
		ladder[x1][y1] = 0;
		ladder[x1][y1 + 1] = 0;
	}

	// ���� ���
	cout << garo << '\n';

	return 0;
}