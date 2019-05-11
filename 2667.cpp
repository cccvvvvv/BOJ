#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class pos {
public:
	int x, y;
	pos(int ax, int ay) :x(ax), y(ay) { }
};

queue<pos> q;
int N, sum, area, map[26][26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[26][26];
vector<int> v;

void sol() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == false && map[i][j] == 1) {
				sum++; area = 1;
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

							if (tx < 0 || tx >= N || ty < 0 || ty >= N) continue;
							if (visit[tx][ty] || map[tx][ty] == 0) continue;

							area++;
							visit[tx][ty] = true;
							q.push(pos(tx, ty));
						}
					}
				}
				v.push_back(area);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < (int)v.size(); i++) {
	cout << v.at(i) << '\n';
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	sol();
}
