#include <bits/stdc++.h>
using namespace std;

inline int Max(int x, int y){
	return x > y ? x : y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 5; i++){
		cout << Max(i, i+10) << "\n";
	}
}
