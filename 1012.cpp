#include <iostream>
#include <queue>
using namespace std;

class pos {
public:
	int x, y;
	pos(int ax, int ay) :x(ax), y(ay) {};
};

int T, N, M, K, X, Y, num, map[52][52];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[52][52];
queue<pos> q;

void my_init() {
	num = 0;
	for (register int i = 0; i < 52; i++) {
		for (register int j = 0; j < 52; j++) {
			visit[i][j] = false; map[i][j] = 0;
		}
	}
}

void sol() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				++num;
				visit[i][j] = true;
				q.push(pos(i, j));
				while (!q.empty()) {
					int qsize = q.size();
					for (int k = 0; k < qsize; k++) {
						pos fr = q.front();
						q.pop();
						for (int l = 0; l < 4; l++) {
							int tx = fr.x + dx[l];
							int ty = fr.y + dy[l];

							if (tx < 0 || tx >= N || ty < 0 || ty >= M) continue;
							if (visit[tx][ty] || map[tx][ty] == 0) continue;

							visit[tx][ty] = true;
							q.push(pos(tx, ty));
						}
					}
				}

			}
		}
	}
	cout << num << '\n';
}

int main(void) {
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		while (K--) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}
		sol();
		my_init();
	}
}
