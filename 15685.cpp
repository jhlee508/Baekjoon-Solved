#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 점들을 구현하는 것보다는 방향을 저장하여 그것으로 좌표를 복원하면 훨씬 효율적으로 구현 가능

bool loc[101][101]; // x, y 좌표 모두 0 ~ 100
// 동, 북, 서, 남
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// 드래곤 커브의 이동방향을 모두 기록해놓는 함수
vector<int> dragon_curve(int x, int y, int d, int g) {
	vector<int> ret = { d }; // 0세대
	// g세대까지 기록
	for (int i = 1; i <= g; i++) {
		vector<int> temp(ret); // 전 세대 복사
		reverse(temp.begin(), temp.end()); // 방향을 정반대로 변환
		for (int &t : temp) {
			t = (t + 1) % 4; // 방향을 반시계 방향으로 90도 회전
		}
		ret.insert(ret.end(), temp.begin(), temp.end());
	}
	return ret;
}

int main() {
	int n; // 드래곤 커브의 개수
	cin >> n;

	while (n--) {
		int x, y, d, g; // 시작 좌표, 시작 방향, 세대
		cin >> x >> y >> d >> g;
		vector<int> dir = dragon_curve(x, y, d, g);
		loc[x][y] = true;
		for (int d : dir) {
			x += dx[d];
			y += dy[d];
			loc[x][y] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			// 4개의 좌표가 모두 TRUE인 경우
			if (loc[i][j] && loc[i + 1][j] && loc[i][j + 1] && loc[i + 1][j + 1]) {
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}