#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; // 세로, 가로
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 2가지
			if (i + 3 < n) {
				int cnt = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
				if (ans < cnt) ans = cnt;
			}
			if (j + 3 < m) {
				int cnt = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
				if (ans < cnt) ans = cnt;
			}

			// 1가지
			if (i + 1 < n && j + 1 < m) {
				int cnt = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (ans < cnt) ans = cnt;
			}

			// 8가지
			if (i + 2 < n && j + 1 < m) {
				int cnt = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
				if (ans < cnt) ans = cnt;
				int cnt2 = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i][j + 1];
				if (ans < cnt2) ans = cnt2;
				int cnt3 = a[i + 2][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < cnt3) ans = cnt3;
				int cnt4 = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < cnt4) ans = cnt4;

				int cnt5 = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < cnt5) ans = cnt5;
				int cnt6 = a[i + 1][j] + a[i + 2][j] + a[i][j + 1] + a[i + 1][j + 1];
				if (ans < cnt6) ans = cnt6;

				int cnt7 = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j + 1];
				if (ans < cnt7) ans = cnt7;
				int cnt8 = a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < cnt8) ans = cnt8;
			}
			if (i + 1 < n && j + 2 < m) {
				int cnt = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j];
				if (ans < cnt) ans = cnt;
				int cnt2 = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
				if (ans < cnt2) ans = cnt2;
				int cnt3 = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < cnt3) ans = cnt3;
				int cnt4 = a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < cnt4) ans = cnt4;
				int cnt5 = a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1] + a[i][j + 1];
				if (ans < cnt5) ans = cnt5;
				int cnt6 = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < cnt6) ans = cnt6;
				int cnt7 = a[i + 1][j + 2] + a[i + 1][j] + a[i + 1][j + 1] + a[i][j + 1];
				if (ans < cnt7) ans = cnt7;
				int cnt8 = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i][j + 2];
				if (ans < cnt8) ans = cnt8;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}