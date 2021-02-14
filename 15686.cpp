#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int map[51][51];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

// 두 점 사이의 거리를 측정하는 함수
int distance(pair<int, int> loc1, pair<int, int> loc2) {
	int dist = 
		abs(loc1.first - loc2.first)
		+ abs(loc1.second - loc2.second);

	return dist;
}

int main() {
	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	// 치킨집과 집의 좌표 구하기
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

	// 순열을 통해 모든 조합 구하기
	vector<int> p(chicken.size(), 0); // 치킨집의 개수 만큼의 길이를 가진 벡터 생성, 0으로 초기화

	for (int i = 0; i < m; i++)
		p[i] = 1; // 선택할 치킨집의 개수인 M개를 1로 설정

	sort(p.begin(), p.end());

	int total_distance = -1;

	// 순열
	do {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			vector<int> dists; 
			for (int j = 0; j < chicken.size(); j++) {
				if (p[j] == 0) continue; // 0인 경우는 패스

				// 1인 경우
				int dist = distance(chicken[j], house[i]); // 거리 측정
				dists.push_back(dist);
			}
			sum += *min_element(dists.begin(), dists.end()); // 측정한 치킨거리의 최솟값 저장
		}
		
		if (total_distance == -1 || total_distance > sum) 
			total_distance = sum;

	} while (next_permutation(p.begin(), p.end()));
	
	// 정답 출력
	cout << total_distance << '\n';

 	return 0;
}