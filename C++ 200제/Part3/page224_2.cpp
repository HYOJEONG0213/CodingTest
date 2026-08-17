#include <bits/stdc++.h>
using namespace std;

static class Test1{
public:
	int sum(const int x, const int y) const{
		return x+y;
	}
} test;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << test.sum(10,3);
}
