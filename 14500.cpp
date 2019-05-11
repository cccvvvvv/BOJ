#include <iostream>
using namespace std;

int N, M, sum, result, map[503][503];

void _set() {
	(sum > result) ? (result = sum) : 0;
	sum = 0;
}

//1
inline void t1_1(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
	_set();
}
inline void t1_2(int i, int j) {
	sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
	_set();
}
//2
inline void t2_1(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
	_set();
}
//3
inline void t3_1(int i, int j) {
	sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
	_set();
}
inline void t3_2(int i, int j) {
	sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
	_set();
}
inline void t3_3(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
	_set();
}
inline void t3_4(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
	_set();
}
inline void t3_5(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 2][j + 1];
	_set();
}
inline void t3_6(int i, int j) {
	sum = map[i][j] + map[i - 1][j] + map[i - 2][j] + map[i - 2][j + 1];
	_set();
}
inline void t3_7(int i, int j) {
	sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
	_set();
}
inline void t3_8(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
	_set();
}

//4
inline void t4_1(int i, int j) {
	sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
	_set();
}
inline void t4_2(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2];
	_set();
}
inline void t4_3(int i, int j) {
	sum = map[i][j] + map[i - 1][j] + map[i - 1][j + 1] + map[i - 2][j + 1];
	_set();
}
inline void t4_4(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
	_set();
}
//5
inline void t5_1(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
	_set();
}
inline void t5_2(int i, int j) {
	sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
	_set();
}
inline void t5_3(int i, int j) {
	sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
	_set();
}
inline void t5_4(int i, int j) {
	sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
	_set();
}

int main() {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				//1
				if (j + 3 <= M) t1_1(i, j);
				if (i + 3 <= N) t1_2(i, j);
				//2
				if (i + 1 <= N && j + 1 <= M)t2_1(i, j);
				//3
				if (i + 2 <= N && j + 1 <= M)t3_1(i, j);
				if (i + 1 <= N && j + 2 <= M)t3_2(i, j);
				if (i + 2 <= N && j + 1 <= M)t3_3(i, j);
				if (i - 1 >= 1 && j + 2 <= M)t3_4(i, j);
				if (i - 2 >= 1 && j + 1 <= M)t3_5(i, j);
				if (i - 2 >= 1 && j + 1 <= M)t3_6(i, j);
				if (i + 1 <= N && j + 2 <= M)t3_7(i, j);
				if (i + 1 <= N && j + 2 <= M)t3_8(i, j);
				//4
				if (i + 2 <= N && j + 1 <= M)t4_1(i, j);
				if (i - 1 >= 1 && j + 2 <= M)t4_2(i, j);
				if (i - 2 >= 1 && j + 1 <= M)t4_3(i, j);
				if (i + 1 <= N && j + 2 <= M)t4_4(i, j);
				//5
				if (i + 1 <= N && j + 2 <= M)t5_1(i, j);
				if (i + 2 <= N && j - 1 >= 1)t5_2(i, j);
				if (i - 1 >= 1 && j + 2 <= M)t5_3(i, j);
				if (i + 2 <= N && j + 1 <= M)t5_4(i, j);
			}
		}
		cout << result << '\n';
}
