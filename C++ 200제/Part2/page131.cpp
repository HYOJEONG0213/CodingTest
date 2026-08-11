#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "rabbits are so cuuuute and they are funny.\n";
	string b = "";
	b = move(a);
	cout << a << "\n";
	cout << b;
	
	vector <int> v1 = {1,2,3,4,5};
	vector <int> v2 = move(v1);
	
	cout << v1.size() << " " << v2.size() ;

}


