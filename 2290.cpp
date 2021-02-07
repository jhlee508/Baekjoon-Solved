#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*  숫자별 선의 위치

 0123
0 00
11  2
21  2
3 33
44  5
54  5
6 66

*/
int num[10][7] = {
	{ 1,1,1,0,1,1,1 }, // 0
	{ 0,0,1,0,0,1,0 }, // 1
	{ 1,0,1,1,1,0,1 }, // 2
	{ 1,0,1,1,0,1,1 }, // 3
	{ 0,1,1,1,0,1,0 }, // 4
	{ 1,1,0,1,0,1,1 }, // 5 
	{ 1,1,0,1,1,1,1 }, // 6
	{ 1,0,1,0,0,1,0 }, // 7
	{ 1,1,1,1,1,1,1 }, // 8
	{ 1,1,1,1,0,1,1 }  // 9
};



int main() {
	int s; // 크기
	string n; // 수
	
	cin >> s >> n;
	int len = n.length();

	// 5번 반복
	for (int i = 0; i < 5; i++) {
		if (i == 0 || i == 2 || i == 4) {
			for (int j = 0; j < len; j++) {
				int number = n[j] - '0'; // 문자를 정수로
				if (j != 0) {
					cout << ' ';
				}
				cout << ' ';
				if ((i == 0 && num[number][0]) || (i == 2 && num[number][3]) || (i == 4 && num[number][6])) {
					for (int k = 0; k < s; k++) {
						cout << '-';
					}
				}
				else {
					for (int k = 0; k < s; k++) {
						cout << ' ';
					}
				}
				cout << ' ';
			}
			cout << '\n';
		}
		else {
			for (int l = 0; l < s; l++) { // s번 반복
				for (int j = 0; j < len; j++) {
					int number = n[j] - '0';
					if (j != 0) {
						cout << ' ';
					}
					if ((i == 1 && num[number][1]) || (i == 3 && num[number][4])) {
						cout << '|';
					}
					else {
						cout << ' ';
					}
					for (int k = 0; k < s; k++) {
						cout << ' ';
					}
					if ((i == 1 && num[number][2]) || (i == 3 && num[number][5])) {
						cout << '|';
					}
					else {
						cout << ' ';
					}
				}
				cout << '\n';
			}
		}
	}
	return 0;
}


/* 입출력 예제

2 1234567890

      --   --        --   --   --   --   --   --  
   |    |    | |  | |    |       | |  | |  | |  | 
   |    |    | |  | |    |       | |  | |  | |  | 
      --   --   --   --   --        --   --       
   | |       |    |    | |  |    | |  |    | |  | 
   | |       |    |    | |  |    | |  |    | |  | 
      --   --        --   --        --   --   --  


*/