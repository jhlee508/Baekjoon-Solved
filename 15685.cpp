#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ������ �����ϴ� �ͺ��ٴ� ������ �����Ͽ� �װ����� ��ǥ�� �����ϸ� �ξ� ȿ�������� ���� ����

bool loc[101][101]; // x, y ��ǥ ��� 0 ~ 100
// ��, ��, ��, ��
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// �巡�� Ŀ���� �̵������� ��� ����س��� �Լ�
vector<int> dragon_curve(int x, int y, int d, int g) {
	vector<int> ret = { d }; // 0����
	// g������� ���
	for (int i = 1; i <= g; i++) {
		vector<int> temp(ret); // �� ���� ����
		reverse(temp.begin(), temp.end()); // ������ ���ݴ�� ��ȯ
		for (int &t : temp) {
			t = (t + 1) % 4; // ������ �ݽð� �������� 90�� ȸ��
		}
		ret.insert(ret.end(), temp.begin(), temp.end());
	}
	return ret;
}

int main() {
	int n; // �巡�� Ŀ���� ����
	cin >> n;

	while (n--) {
		int x, y, d, g; // ���� ��ǥ, ���� ����, ����
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
			// 4���� ��ǥ�� ��� TRUE�� ���
			if (loc[i][j] && loc[i + 1][j] && loc[i][j + 1] && loc[i + 1][j + 1]) {
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}