#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "123456789abcdefgh";
	string b = "Hello Wolrd !";
	int c[10] = {1,2,3,4,5,6,7,8,9,10};
	
	
	// ---------- a ------------- 
	random_shuffle(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << ", ";
	}
	cout << "\n";
	
	
	// ---------- b ------------- 
	random_shuffle(b.begin(), b.end());
	for(int i = 0; i < b.size(); i++){
		cout << b[i] << ", ";
	}
	cout << "\n";
	
	
	// ---------- c ------------- 
	random_shuffle(c, c+4);
	for(auto i : c){
		cout << i << ", ";
	}
	cout << "\n";
}
