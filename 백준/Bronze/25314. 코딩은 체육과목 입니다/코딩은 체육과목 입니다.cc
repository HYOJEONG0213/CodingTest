#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while(N > 0){
		cout << "long ";
		N -= 4;
	}
	cout << "int";
}