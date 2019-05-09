#include <iostream>
#include <queue>
using namespace std;


int N, K, cnt, ar[100001];
bool visit[100001];
queue<int> q;

int main(void) {
	cin >> N >> K;
	if (N == K) { cout << 0 << '\n'; return 0; }
	
	visit[N] = true;
	q.push(N);
	while (!q.empty()) {
		int qsize = q.size();
		cnt++;
		for (int i = 0; i < qsize; i++) {
			int tp = q.front();
			q.pop();
			
			for (int j = 0; j < 3; j++) {
				if (tp - 1 == K || tp + 1 == K || 2 * tp == K) { cout << cnt << '\n'; return 0; }
				if (tp - 1 >= 0 && !visit[tp - 1]) { visit[tp - 1] = true; q.push(tp - 1); }
				if (tp + 1 <= 100000 && !visit[tp + 1]) { visit[tp + 1] = true; q.push(tp + 1); }
				if (2 * tp <= 100000 && !visit[2 * tp]) { visit[2 * tp] = true; q.push(2 * tp); }
			}
		}
	}

}
