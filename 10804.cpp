#include <iostream>
using namespace std;

int temp, ar[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };


void rev(int s, int e) {
	if (s >= e) return;
	else {
		temp = ar[s];
		ar[s] = ar[e];
		ar[e] = temp;
		return rev(s + 1, e - 1);
	}
}

void myPrint() {
	for (int i = 0; i < 20; i++) {
		cout << ar[i] << " ";
	}
	cout << '\n';
}

int main(void) {
	int s, e;
	for (int i = 0; i < 10; i++) {
		cin >> s >> e;
		rev(--s, --e);
	}
	myPrint();
}
