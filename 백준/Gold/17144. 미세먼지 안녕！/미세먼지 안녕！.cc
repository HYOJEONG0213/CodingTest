#include <bits/stdc++.h>
using namespace std;

int R, C, T, a[54][54], aa[54][54], ret;
int dy1[4]={0, -1, 0, 1}, dx1[4]={1,0,-1,0};
int dy2[4]={0,1,0,-1}, dx2[4]={1,0,-1,0};
vector <pair <int, int>> v1, v2;
bool flag = true;

void mise(){
	memset(aa, 0, sizeof(aa));
	queue <pair<int,int>> q;
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			//청소기 부분과 미세먼지 0인부분 안하게 하기 
			if(a[i][j] == -1 || a[i][j] == 0) continue;
			q.push({i, j});
		}
	}
	
	while(q.size()){
		int y, x;
		tie(y, x) = q.front(); q.pop();
		
		int spread = a[y][x] / 5;
		
		for(int i = 0; i < 4; i++){
			int ny = dy1[i] + y;
			int nx = dx1[i] + x;
			if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;	

			if(a[ny][nx]==-1) continue;
			
			aa[ny][nx] += spread;
			a[y][x] -= spread;
		}
	}
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			a[i][j] += aa[i][j];
		}
	}
} 

vector <pair<int,int>> chung(int y, int x, int dy[4], int dx[4]){
	vector <pair<int, int>> v;
	int cnt = 0;
	while(true){
		int ny = y + dy[cnt], nx = x + dx[cnt];
		if(ny < 0 || nx < 0 || ny >= R || nx >= C){
			cnt++;
			ny = y + dy[cnt];
			nx = x + dx[cnt]; 
		}
		if(a[ny][nx] == -1) break;
		y = ny, x = nx;
		v.push_back({ny, nx});
	}
	
	
	return v;
}

void wind(vector <pair<int,int>> v){
	for(int i = v.size() -1; i > 0; i--){
		int ny, nx, py, px;
		tie(ny, nx) = v[i];
		tie(py, px) = v[i-1];
		a[ny][nx] = a[py][px];
	}
	a[v[0].first][v[0].second] = 0;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	

	cin >> R >> C >> T;
	//입력 및 청소기 바람 구역 v1, v2에 뽑기 
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> a[i][j];
			if(a[i][j]==-1){
				if(flag == true){
					v1 = chung(i, j, dy1, dx1);
					flag = false;
				}
				else{
					v2 = chung(i, j, dy2, dx2);
				}
			}
		}
	}
	
	
	while(T--){		
		//미세먼지 전파부터 
		mise();
		wind(v1);
		wind(v2);
		

//		cout << "\n";
//		for(int i = 0; i < R; i++){
//			for(int j = 0; j < C; j++){
//				cout << a[i][j] << " ";
//			}
//			cout << "\n";
//		}

		
	}
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(a[i][j]==-1) continue;
			ret += a[i][j];
		}
	}
	
	cout << ret;
}