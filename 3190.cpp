#include <iostream>
#include <cstring>
using namespace std;

// 뱀의 머리 정보 저장
int head[100][100];
// 사과 위치 저장
bool apple[100][100];
// 동, 남, 서, 북
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
	int n, k;
	cin >> n >> k;

	while (k--) {
		int row, col;
		cin >> row >> col;
		apple[row - 1][col - 1] = true;
	}

	// -1로 초기화
	memset(head, -1, sizeof(head));

	// 뱀의 시작 위치 : (0, 0)
	int x = 0, y = 0;
	int dir = 0; // 뱀의 시작 방향 : 오른쪽
	int len = 1; // 뱀의 시작 길이 : 1

	head[x][y] = 0;
	
	int l; // 방향 변환 횟수
	cin >> l;
	int now = 0;
	for (int i = 0; i <= l; i++) {
		int t = 10000; // 최대값으로 초기화
		char ch;
		if (i < l) {
			cin >> t >> ch;
		}
		while (now < t) {
			now++;
			x += dx[dir];
			y += dy[dir];
			// 벽이랑 충돌하는 경우
			if (x < 0 || x >= n || y < 0 || y >= n) {
				cout << now << '\n';
				return 0;
			}
			// 사과로 이동할 경우
			if (apple[x][y]) {
				apple[x][y] = false;
				len += 1;
			}
			// 자기 자신과 충돌하는 경우
			// 이동하려는 칸이 전에 머리가 방문했던 곳이면서 
			// 뱀의 현재 머리 위치와 이동하려는 위치의 길이차가 
			// 몸통의 길이보다 작거나 같다면 종료
			if ((head[x][y] != -1) && (now - head[x][y] <= len)) {
				cout << now << '\n';
				return 0;
			}
			head[x][y] = now;
		}
		
		if (ch == 'L') 
			dir = (dir + 3) % 4;
		else
			dir = (dir + 1) % 4;
	}
	return 0;
}
