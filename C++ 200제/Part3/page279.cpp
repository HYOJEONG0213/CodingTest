#include <bits/stdc++.h>
#include <atomic>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	atomic <int> a;
	a.store(10);
	a = 10;
	cout << a.load() << " " << a;
}
