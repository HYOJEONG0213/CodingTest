#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "rabbits are so cuuuute and they are funny.\n";
	string b = "cuuuute";
	int idx = a.find(b);
	a.erase(idx, b.size());

	cout << a;
}


