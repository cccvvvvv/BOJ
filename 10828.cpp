#include <iostream>
#include <string>
using namespace std;


class _stack {
public:
	int st[10005];
	int size = 0, capa = 10005;

	inline void _push(int x) {
		st[size++] = x;
		capa--;
	}
	inline void _empty() {
		if (size == 0)  cout << 1 << '\n'; 
		else cout << 0 << '\n';
	}

	inline void _top() {
		if (size == 0) cout << -1 << '\n';
		else cout << st[size - 1] << '\n';
	}

	inline void _size() {
		cout << size << '\n';
	}
	inline void _pop() {
		if(size == 0) cout << -1 << '\n';
		else cout << st[--size] << '\n';
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, a = 0; _stack s;
	string ord;
	cin >> N;
	while (N--) {
		cin >> ord;
		if (ord == "push") { cin >> a;  s._push(a); continue; }
		if (ord == "pop") { s._pop(); continue; }
		if (ord == "size") { s._size(); continue; }
		if (ord == "top") { s._top(); continue; }
		if (ord == "empty") { s._empty(); continue; }
	}
}
