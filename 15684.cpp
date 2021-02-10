#include <iostream>
#include <vector>
using namespace std;

int ladder[100][100]; // 2차원 배열
int n, m, h; // 세로선, 가로선, 가로선 개수

// 1개 세로선 검사
int start(int c) { // c 번째 세로선에서 사다리 타기 시작
	int r = 1; // 1 번째 가로선(맨 위)에서 시작

	while (r <= h) { // h = 마지막 가로선
		if (ladder[r][c] == 1) {
			c += 1; // 오른쪽으로 이동
		}
		else if (ladder[r][c] == 2) {
			c -= 1; // 왼쪽으로 이동
		}
		r += 1; // 아래로 내려가기
	}
	return c; // 최종 도착 위치
}

// 모든 세로선 검사
bool simulation() {
	for (int i = 1; i <= n; i++) {
		int ret = start(i);
		if (ret != i)
			return false;
	}
	return true;
}

int main() {
	// 입력
	cin >> n >> m >> h;
	// 기존 사다리 저장
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x][y] = 1;
		ladder[x][y + 1] = 2;
	}

	vector<pair<int, int>> v; // 가로선을 놓을 수 있는 좌표 저장
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (ladder[i][j] != 0)
				continue;
			if (ladder[i][j + 1] != 0)
				continue;
			v.push_back(make_pair(i, j));
		}
	}

	int garo = -1; // 출력 값

	if (simulation()) { // 검사 시작
		cout << 0 << '\n';
		return 0;
	}

	int len = v.size();
	for (int i = 0; i < len; i++) {
		int x1 = v[i].first;
		int y1 = v[i].second;
		if (ladder[x1][y1] != 0 || ladder[x1][y1 + 1] != 0)
			continue;
		// 가로선 놓기
		ladder[x1][y1] = 1;
		ladder[x1][y1 + 1] = 2;

		if (simulation()) { // 가로선 1개 놓고 검사
			if (garo == -1 || garo > 1) {
				garo = 1; // 가로선 = 1
			}
		}

		for (int j = i + 1; j < len; j++) {
			int x2 = v[j].first;
			int y2 = v[j].second;
			if (ladder[x2][y2] != 0 || ladder[x2][y2 + 1] != 0)
				continue;
			// 가로선 놓기
			ladder[x2][y2] = 1;
			ladder[x2][y2 + 1] = 2;

			if (simulation()) { // 가로선 2개 놓고 검사
				if (garo == -1 || garo > 2) {
					garo = 2; // 가로선 = 2
				}
			}

			for (int k = j + 1; k < len; k++) {
				int x3 = v[k].first;
				int y3 = v[k].second;
				if (ladder[x3][y3] != 0 || ladder[x3][y3 + 1] != 0)
					continue;
				// 가로선 놓기
				ladder[x3][y3] = 1;
				ladder[x3][y3 + 1] = 2;

				if (simulation()) { // 가로선 3개 놓고 검사
					if (garo == -1 || garo > 3) {
						garo = 3; // 가로선 = 3
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

	// 정답 출력
	cout << garo << '\n';

	return 0;
}