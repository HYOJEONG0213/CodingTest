#include <bits/stdc++.h>
using namespace std;

namespace Test{
	int Plus(int x, int y){
		return x + y;
	}
}

using namespace Test;
using V = vector<int>;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	V v;
	v.push_back(1);
	v.push_back(2);
	
	cout << v[0] << " " << v[1] << "\n";
	cout << Plus(v[0], v[1]);
}
