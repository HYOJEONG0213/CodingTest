#include <bits/stdc++.h>
using namespace std;

string s, temp; 

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	cin >> s;
	temp = s;

	reverse(temp.begin(), temp.end());
		
	if(s == temp){
		cout << 1;	
		exit(0);
	}
	cout << 0;
}