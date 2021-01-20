#include <iostream>
#include <cstring>
using namespace std;

// ���� �Ӹ� ���� ����
int head[100][100];
// ��� ��ġ ����
bool apple[100][100];
// ��, ��, ��, ��
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

	// -1�� �ʱ�ȭ
	memset(head, -1, sizeof(head));

	// ���� ���� ��ġ : (0, 0)
	int x = 0, y = 0;
	int dir = 0; // ���� ���� ���� : ������
	int len = 1; // ���� ���� ���� : 1

	head[x][y] = 0;
	
	int l; // ���� ��ȯ Ƚ��
	cin >> l;
	int now = 0;
	for (int i = 0; i <= l; i++) {
		int t = 10000; // �ִ밪���� �ʱ�ȭ
		char ch;
		if (i < l) {
			cin >> t >> ch;
		}
		while (now < t) {
			now++;
			x += dx[dir];
			y += dy[dir];
			// ���̶� �浹�ϴ� ���
			if (x < 0 || x >= n || y < 0 || y >= n) {
				cout << now << '\n';
				return 0;
			}
			// ����� �̵��� ���
			if (apple[x][y]) {
				apple[x][y] = false;
				len += 1;
			}
			// �ڱ� �ڽŰ� �浹�ϴ� ���
			// �̵��Ϸ��� ĭ�� ���� �Ӹ��� �湮�ߴ� ���̸鼭 
			// ���� ���� �Ӹ� ��ġ�� �̵��Ϸ��� ��ġ�� �������� 
			// ������ ���̺��� �۰ų� ���ٸ� ����
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
