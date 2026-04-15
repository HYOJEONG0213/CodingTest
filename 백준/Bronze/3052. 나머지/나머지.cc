#include <bits/stdc++.h>
using namespace std;

int a;
map <int,int> mp;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 10; i++){
		cin >> a;
		mp[a%42]++;
	}
	cout << mp.size();
}