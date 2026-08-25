#include <bits/stdc++.h>
#include <atomic>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	atomic <int> a(10);
	int num = 20;
	bool bChange = a.compare_exchange_weak(num, 30);
	cout << a << " " << num << " "<< bChange << "\n";
	
	a.store(20);
	num = 20;
	bChange = a.compare_exchange_weak(num, 40);
	cout << a << " " << num << " "<< bChange << "\n";
}
