#include <iostream>
using namespace std;

class dice {
public:
	int u, d, w, e, n, s, x, y;
};

int N, M, x, y, K, ord, map[22][22];
dice myDice;

bool go(int ord) {
	int posX = myDice.x; int posY = myDice.y;
	if (ord == 1) {
		if (posY + 1 >= M) return false;
		++posY; myDice.y++;
		if (map[posX][posY] == 0) {
			map[posX][posY] = myDice.e;
			int temp = myDice.e;
			myDice.e = myDice.u; myDice.u = myDice.w; myDice.w = myDice.d; myDice.d = temp;
		}
		else{
			myDice.e = myDice.u; myDice.u = myDice.w; myDice.w = myDice.d; myDice.d = map[posX][posY];
			map[posX][posY] = 0;
		}
	}
	//West
	else if (ord == 2) {
		if (posY - 1 < 0) return false;
		--posY; myDice.y--;
		if (map[posX][posY] == 0) {
			map[posX][posY] = myDice.w;
			int temp = myDice.w;
			myDice.w = myDice.u; myDice.u = myDice.e; myDice.e = myDice.d; myDice.d = temp;
		}
		else{
			myDice.w = myDice.u; myDice.u = myDice.e; myDice.e = myDice.d; myDice.d = map[posX][posY];
			map[posX][posY] = 0;
		}
	}
	//North
	else if (ord == 3) {
		if (posX - 1 < 0) return false;
		--posX; myDice.x--;
		if (map[posX][posY] == 0) {
			map[posX][posY] = myDice.n;
			int temp = myDice.n;
			myDice.n = myDice.u; myDice.u = myDice.s; myDice.s = myDice.d; myDice.d = temp;
		}
		else {
			myDice.n = myDice.u; myDice.u = myDice.s; myDice.s = myDice.d; myDice.d = map[posX][posY];
			map[posX][posY] = 0;
		}
	}
		//South
		else {
			if (posX + 1 >= N) return false;
			++posX; myDice.x++;
			if (map[posX][posY] == 0) {
				map[posX][posY] = myDice.s;
				int temp = myDice.s;
				myDice.s = myDice.u; myDice.u = myDice.n; myDice.n = myDice.d; myDice.d = temp;
			}
			else {
				myDice.s = myDice.u; myDice.u = myDice.n; myDice.n = myDice.d; myDice.d = map[posX][posY];
				map[posX][posY] = 0;
			}
		}
		return true;
	}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> x >> y >> K;
	myDice.x = x; myDice.y = y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	while (K--) {
		cin >> ord;
		if (go(ord)) cout << myDice.u << '\n';
	}
}
