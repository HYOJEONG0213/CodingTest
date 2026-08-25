#include <bits/stdc++.h>
#include <atomic>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	atomic <int> a(10);
	a.fetch_add(5);
	cout << a.load() << "\n";
	a.fetch_sub(10);
	cout << a.load() << "\n";
}
