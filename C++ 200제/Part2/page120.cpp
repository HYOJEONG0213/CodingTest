#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "rabbit is so cuuuute and it is funny.";
	int idx = a.find("cuuuute");
	if(idx == -1){
		cout << "cuuuute없음";
	} 
	else{
		cout << idx << " 위치에 존재하네유 \n"; 
	}
}
