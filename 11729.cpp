#include <iostream>
using namespace std;


void hanoi(int n, int from, int to, int by) {
	if (n == 1) {
		cout << from << " " << to << '\n';
		return;
	}
	else {
		hanoi(n - 1, from, by, to);
		cout << from << " " << to << '\n';
		hanoi(n - 1, by, to, from);
	}
}


int main(void) {
	int N;
	cin >> N;
	cout << (1 << N) - 1 << '\n';
	hanoi(N, 1, 3, 2);

}
