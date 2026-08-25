#include <bits/stdc++.h>
#include <atomic>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	atomic <int> a(10), b(20), c(20);
	atomic_exchange(&a, c.load());
	atomic_exchange(&c, 55);
	cout << a << " " << b << " " << c;
}
