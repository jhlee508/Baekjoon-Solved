#include <cstdio>
#include <iostream>
using namespace std;

int matrix[20][20]; // ����
int dice[7]; // 1 ~ 6

// �� �� �� ��
// 1  2  3  4
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
	int N, M; // ������ ũ�� : (N, M) 
	int x, y; // ��ǥ ��ġ
	int K; // ����� ��

	// �Է�
	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	while (K--) {
		int t;
		cin >> t;
		t--;
		int nx, ny; 
		nx = x + dx[t]; // �̵��ϴ� ��
		ny = y + dy[t]; // �̵��ϴ� ��

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;

		if (t == 0) { // �� 1
			int temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
		}
		else if (t == 1) { // �� 2
			int temp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
		}
		else if (t == 2) { // �� 3
			int temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}
		else { // �� 4
			int temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}

		x = nx;
		y = ny;

		if (matrix[x][y] == 0) {
			matrix[x][y] = dice[6]; // �ٴ� ��
		}
		else {
			dice[6] = matrix[x][y];
			matrix[x][y] = 0;
		}

		// ���
		cout << dice[1] << '\n'; // �� ��
	} 
	return 0;
}

/* 

�Է� ���� 1

4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

��� ���� 1

0
0
3
0
0
8
6
3

*/