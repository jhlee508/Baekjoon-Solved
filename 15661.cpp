#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int s[21][21];

int go(int index, vector<int> &first, vector<int> &second) {
	if (index == n) {
		if (first.size() == 0) return -1;
		if (second.size() == 0) return -1;
		int temp1 = 0;
		int temp2 = 0;
		for (int i = 0; i<first.size(); i++) {
			for (int j = 0; j<first.size(); j++) {
				if (i == j) continue;
				temp1 += s[first[i]][first[j]];
			}
		}
		for (int i = 0; i<second.size(); i++) {
			for (int j = 0; j<second.size(); j++) {
				if (i == j) continue;
				temp2 += s[second[i]][second[j]];
			}
		}
		return abs(temp1 - temp2);
	}
	int ans = -1;
	first.push_back(index);
	int temp1 = go(index + 1, first, second);
	if (ans == -1 || (temp1 != -1 && ans > temp1)) {
		ans = temp1;
	}
	first.pop_back();

	second.push_back(index);
	int temp2 = go(index + 1, first, second);
	if (ans == -1 || (temp2 != -1 && ans > temp2)) {
		ans = temp2;
	}
	second.pop_back();

	return ans;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	vector<int> first, second;

	go(0, first, second);

	cout << go(0, first, second) << '\n';

	return 0;
}