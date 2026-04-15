#include <bits/stdc++.h>
using namespace std;

int board[6][20] = {
	{0, 2, 8, 6, 1, 5, 7, 3, 51, 31, 41, 21, 50, 30, 40, 20, 52, 32, 42, 22},
	{10, 12, 18, 16, 11, 15, 17, 13, 56, 26, 46, 36, 57, 27, 47, 37, 58, 28, 48, 38},
	{20, 22, 28, 26, 21, 25, 27, 23, 0, 40, 18, 58, 3, 43, 15, 55, 6, 46, 12, 52},
	{30, 32, 38, 36, 31, 35, 37, 33, 8, 50, 10, 48, 5, 53, 13, 45, 2, 56, 16, 42},
	{40, 42, 48, 46, 41, 45, 47, 43, 6, 30, 16, 28, 7, 33, 17, 25, 8, 36, 18, 22},
	{50, 52, 58, 56, 51, 55, 57, 53, 2, 20, 12, 38, 1, 23, 11, 35, 0, 26, 10, 32}
};
int T, n, node[66];
char s1, s2;

map <char, int> mp;
char dir[6] = {'U', 'D', 'L', 'R', 'F', 'B'};
char color[6] = {'w', 'y', 'g', 'b', 'r', 'o'};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	
	for(int i = 0; i < 6; i++){
		mp[dir[i]] = i;
	}
	
	while(T--){
		//초기화 필요 
		 for(int i = 0; i < 60; i++){
		 	node[i] = i/10;	//node[5] = 0 번째 색이다!  
		 }
		 
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> s1 >> s2;
			int idx = mp[s1];
			int a, b;
			if(s2 == '+'){
				a = 3, b = 1; 
			}
			else{
				a = 1, b = 3;
			}
			
			for(int j = 0; j < 20; j+=4){
				int temp = node[board[idx][j]];
				node[board[idx][j]] = node[board[idx][j+a]];
				node[board[idx][j+a]] = node[board[idx][j+2]];
				node[board[idx][j+2]] = node[board[idx][j+b]];
				node[board[idx][j+b]] = temp;
			}
		}
		
		for(int i = 0; i <= 8; i++){
			cout << color[node[i]] ;
			if(i%10 == 2 || i%10 == 5 || i%10 == 8) cout <<"\n";
		}
	}
	
}