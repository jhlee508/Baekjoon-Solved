#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// 북 동 남 서 (0 1 2 3)
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1};

// location
int loc[55][55];

int main() {

	// 입력
	int n, m;
	cin >> n >> m;
	int x, y, dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> loc[i][j];
		
	// 구현
	int cnt = 0;
	// loc[x][y] == 0 : 청소하지 않은 공간
	// loc[x][y] == 1 : 벽
	// loc[x][y] == 2 : 청소한 공간

	while (true) {
		// 1 : 현재 위치 청소한다. 다시 청소해도 상관없다.
		if (loc[x][y] == 0) 
			loc[x][y] = 2;
		
		// 2-c, 2-d : 네 방향 모두 청소가 되어있거나 벽일 경우
		if (loc[x + 1][y] != 0 && loc[x - 1][y] != 0 && loc[x][y - 1] != 0 && loc[x][y + 1] != 0) {
			// 2-d : 뒤쪽 방향일 경우 -> 작동을 멈춘다.
			if (loc[x - dx[dir]][y - dy[dir]] == 1) {
				break;
			}
			// 2-c : 방향을 유지한 채 한 칸 후진한다.
			else {
				x = x - dx[dir];
				y = y - dy[dir];
			}
		}

		// 2-a, 2-b
		else {
			// 2-a, 2-b : 왼쪽 방향으로 회전한다.
			if (dir == 0)
				dir = 3;
			else if (dir == 1)
				dir = 0;
			else if (dir == 2)
				dir = 1;
			else
				dir = 2;

			// 2-a : 청소할 공간이 있다면 이동한다.
			if (loc[x + dx[dir]][y + dy[dir]] == 0) {
				x = x + dx[dir];
				y = y + dy[dir];
			}
		}
	}

	// 출력
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