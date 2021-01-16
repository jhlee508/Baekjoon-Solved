#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<string> gear(n);
	for (int i = 0; i < n; i++) {
		cin >> gear[i];
	}

	int num;
	cin >> num;
	while (num--) {
		int which_gear, direction;
		cin >> which_gear >> direction;
		which_gear--;

		vector<int> d(n);
		d[which_gear] = direction;

		// 왼쪽 톱니바퀴
		for (int i = which_gear; i > 0; i--) {
			if (gear[i - 1][2] != gear[i][6]) {
				d[i - 1] = -d[i];
			}
			else
				break;
		}

		// 오른쪽 톱니바퀴
		for (int i = which_gear; i < n - 1; i++) {
			if (gear[i][2] != gear[i + 1][6]) {
				d[i + 1] = -d[i];
			}
			else
				break;
		}

		for (int i = 0; i < n; i++) {
			if (d[i] == 0) // 그대로
				continue;
			if (d[i] == 1) { // 시계 방향 회전
				char temp = gear[i][7];
				for (int j = 7; j > 0; j--) {
					gear[i][j] = gear[i][j - 1];
				}
				gear[i][0] = temp;
			}
			else if (d[i] == -1) { // 반시계 방향 회전
				char temp = gear[i][0];
				for (int j = 0; j < 7; j++) {
					gear[i][j] = gear[i][j + 1];
				}
				gear[i][7] = temp;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (gear[i][0] == '1')
			ans++;
	}

	cout << ans << '\n';
	return 0;
}

/*

4
10101111
01111101
11001110
00000010
2
3 -1
1 1

*/