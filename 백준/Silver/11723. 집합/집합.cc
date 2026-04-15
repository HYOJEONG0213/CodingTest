#include <bits/stdc++.h>
using namespace std;

int M, num, i;
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	while(M--){
		cin >> s;
		if (s[0]=='a'&&s[1]=='d'){
			cin >> i;
			num |= (1 << i);
		}
		else if (s[0]=='a'&&s[1]=='l'){
			num = (1 << 21) - 1;
		}
		else if (s[0]=='r'){
			cin >> i;
			num &= ~ (1 << i);
		}
		else if (s[0]=='c'){
			cin >> i;
			int temp = 1 << i;
			if(num & temp) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s[0]=='t'){
			cin >> i;
			num ^= (1 << i);
		}
		else if (s[0]=='e'){
			num = 0;
		}
	}
}