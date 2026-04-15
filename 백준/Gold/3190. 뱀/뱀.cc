#include <bits/stdc++.h>
using namespace std;

int N, K, a, b, visited[104][104], x, ret, L, dir;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
char c;
queue <pair<int, char>> lotate;
queue <pair<int,int>> q;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> K;
	for(int i = 0; i < K; i++){
		cin >> a >> b;
		a--; b--;
		visited[a][b] = 10;
	}
	cin >> L;
	for(int i =0; i <L; i++){
		cin >> x >> c;
		lotate.push({x, c});
	}
	
	q.push({0,0});
	//움직이기
	while(1){
		bool flag = false;
		//y, x : 뱀의 머리 부분  
		int y = q.back().first;
		int x = q.back().second;
		//cout << y << " " << x <<"\n";
		
		
		//뱀 회전  
		if(ret == lotate.front().first){		
			//cout << ret << "\n\n";
			if(lotate.front().second == 'L')
				dir = (dir+3)%4;
			else
				dir = (dir+1)%4;
			
			lotate.pop();
			
			//cout << "&&" << dir << "\n";
		}
		
		//뱀 움직이기  
		ret++;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny < 0 || nx < 0 || ny >= N || nx >= N) break;
		if(visited[ny][nx]==1) {
			//cout << "*"<< dir << ": "<< ny << " " << nx <<"\n";
			break;
		}
		
		//사과가 있는 자리라면  
		if(visited[ny][nx]==10) 
			flag = true;
			
		//방문 처리하고, 몸길이 증가  
		visited[ny][nx] = 1;
		q.push({ny,nx});
		
		//사과를 먹지 않았다면 이동(제거) 
		if(flag == false){
			auto temp = q.front();
			visited[temp.first][temp.second] = 0;
			q.pop();
		}
		
		
	} 
	
	cout << ret;
}