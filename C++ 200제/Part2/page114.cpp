#include <bits/stdc++.h>
using namespace std;

string ret1, ret2, ret3;
int visited[14];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "123456789abcdefgh";
	string b = "Hello Wolrd !";
	int c[10] = {1,2,3,4,5,6,7,8,9,10};
	
	
	// ---------- a ------------- 
	srand(static_cast<unsigned int> (time(NULL)));
	int cnt = a.size();
	for(int i = 0; i < cnt; i++){
		int idx = rand()%a.size();
		ret1 += a[idx];
		a.erase(idx, 1);
	}
	for(int i = 0; i < ret1.size(); i++){
		cout << ret1[i] << ", ";
	}
	cout << "\n";
	
	
	// ---------- b ------------- 
	cnt = b.size();
	for(int i = 0; i < cnt; i++){
		int idx = rand()%b.size();
		ret2 += b[idx];
		b.erase(idx, 1);
	}
	for(int i = 0; i < ret2.size(); i++){
		cout << ret2[i] << ", ";
	}
	cout << "\n";
	
	
	// ---------- c ------------- 
	cnt = sizeof(c)/sizeof(c[0]);
	int i = 0;
	while(i < cnt){
		int idx = rand()%cnt;
		if(visited[idx]==1) continue;
		visited[idx] = 1;
		ret3 += c[idx]+'0';
		i++;
	}
	for(int i = 0; i < ret3.size(); i++){
		cout << ret3[i] << ", ";
	}
	cout << "\n";
}
