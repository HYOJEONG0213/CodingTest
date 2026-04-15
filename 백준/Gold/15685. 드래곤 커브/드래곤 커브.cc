#include <bits/stdc++.h>
using namespace std;

string s;
vector <string> dr;
int N, x, y, g, d, ret, visited[104][104];
int dy[4] = {0,-1,0,1}, dx[4] = {1,0,-1,0};

void show(){
	int dir = 0;
	for(int i = 0 ; i < dr[dir].size(); i++ ){
		cout << dr[dir][i] ;
	}
	cout << "\n";
}

void makeCurv(){
	for(int i = 0; i < 4; i++){
		s = "";
		int dir = i;
		s += dir +'0';
		dir = (dir + 1) % 4;
		s += dir + '0';
		
		for(int j = 2; j <= 10; j++){
			for(int k = s.size()-1; k >= 0; k--){
				dir = s[k] - '0';
				dir = (dir + 1) % 4;
				s += dir +'0';
			}
		}
		dr.push_back(s);
	}
	//show();
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	makeCurv();
	cin >> N;
	for(int i =0; i < N; i++){
		cin >> x >> y >> d >> g;
		visited[y][x] = 1;
		for(int j = 0; j < (1<<g); j++){
			int dir = dr[d][j] - '0';
			y = y + dy[dir];
			x = x + dx[dir];
			visited[y][x] = 1;
			//드래곤커브는 격자밖으로 벗어나지 않으므로 조건부 생략 
		}
	}
	
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(visited[i][j] && visited[i+1][j] && visited[i][j+1] &&  visited[i+1][j+1]) {
				ret++;
				//cout << i << j << "\n";
			}

		}
	}
	
	cout << ret;
}