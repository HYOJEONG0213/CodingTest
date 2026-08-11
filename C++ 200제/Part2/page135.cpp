#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "rabbits are so cuuuute and they are funny.\n";
	int idx = a.find("cuuuute");
	a.replace(idx, 7, "cute");

	cout << a;
}


