#include <iostream>
#define ull unsigned long long
using namespace std;

void sol(ull a, ull b) {
	if (a == b) {
		cout << 0 << '\n' << '\n';
		return;
	}
	int len = b - a - 1;
	cout << len << '\n';
	for (int i = 1; i <= len; i++) {
		cout << a + i << " ";
	}
	cout << '\n';
}

int main(void) {
	ull A, B;
	cin >> A >> B;
	(A > B) ? sol(B, A) : sol(A, B);
}
