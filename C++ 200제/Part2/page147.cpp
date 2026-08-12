#include <bits/stdc++.h>
using namespace std;

int f(vector <string> *p){
	if(p->empty()){
		return 0;
	}
	else{
		return sizeof(p);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector <string> v;
	v.push_back("Rabbit");
	v.push_back("Bunny");
	v.push_back("Cat");
	v.push_back("Kitty");
	
	cout << f(&v) << " " << sizeof(v);
 }
