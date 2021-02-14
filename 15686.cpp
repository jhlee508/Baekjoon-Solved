#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int map[51][51];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

// �� �� ������ �Ÿ��� �����ϴ� �Լ�
int distance(pair<int, int> loc1, pair<int, int> loc2) {
	int dist = 
		abs(loc1.first - loc2.first)
		+ abs(loc1.second - loc2.second);

	return dist;
}

int main() {
	// �Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	// ġŲ���� ���� ��ǥ ���ϱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}

	// ������ ���� ��� ���� ���ϱ�
	vector<int> p(chicken.size(), 0); // ġŲ���� ���� ��ŭ�� ���̸� ���� ���� ����, 0���� �ʱ�ȭ

	for (int i = 0; i < m; i++)
		p[i] = 1; // ������ ġŲ���� ������ M���� 1�� ����

	sort(p.begin(), p.end());

	int total_distance = -1;

	// ����
	do {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			vector<int> dists; 
			for (int j = 0; j < chicken.size(); j++) {
				if (p[j] == 0) continue; // 0�� ���� �н�

				// 1�� ���
				int dist = distance(chicken[j], house[i]); // �Ÿ� ����
				dists.push_back(dist);
			}
			sum += *min_element(dists.begin(), dists.end()); // ������ ġŲ�Ÿ��� �ּڰ� ����
		}
		
		if (total_distance == -1 || total_distance > sum) 
			total_distance = sum;

	} while (next_permutation(p.begin(), p.end()));
	
	// ���� ���
	cout << total_distance << '\n';

 	return 0;
}