#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool check(vector<int> &map, int l) {
	int n = map.size();
	vector<bool> hill(n, false);
	for (int i = 1; i < n; i++) {
		// ���� ���� �߻�
		if (map[i - 1] != map[i]) {
			int diff = abs(map[i - 1] - map[i]);

			// �������� 1�� ���� ���
			if (diff > 1)
				return false;
			 
			if (map[i - 1] < map[i]) {
				for (int j = 1; j <= l; j++) {
					// ������ ���� ���
					if (i - j < 0) {
						return false;
					}
					// ���� ������ ĭ�� ���̰� ���� �ʰų�, L�� ���ӵ��� ���� ���
					if (map[i - 1] != map[i - j]) {
						return false;
					}
					// ���θ� ���� ���� �� ���� ���
					if (hill[i - j]) {
						return false;
					}
					hill[i - j] = true;
				}
			}

			else { // map[i - 1] > map[i]
				for (int j = 0; j < l; j++) {
					// ������ ���� ���
					if (i + j >= n) {
						return false;
					}
					// ���� ������ ĭ�� ���̰� ���� �ʰų�, L�� ���ӵ��� ���� ���
					if (map[i] != map[i + j]) {
						return false;
					}
					// ���θ� ���� ���� �� ���� ���
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

	// n * n ũ���� 2���� ���� ���� 
	vector<vector<int>> map(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int ans = 0;

	// �� check
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			row.push_back(map[i][j]);
		}
		if (check(row, l))
			ans++;
	}

	// �� check
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