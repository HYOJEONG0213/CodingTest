#include <bits/stdc++.h>
using namespace std;

int R, C, M, ret, visited[104][104];

struct{
	int r, c, s, d, z;
	bool isDie;
} sh[10004];

void show(){
	for(int i = 0 ; i < M; i++){
		if(sh[i].isDie == true) continue;
		cout << sh[i].r << " " << sh[i].c << "방향 : " << sh[i].d << "\n";
	}
	cout << "\n\n";
}


void move(){
	for(int idx = 0; idx < M ; idx++){
		if(sh[idx].isDie == true) continue;
		
		int r = sh[idx].r, c = sh[idx].c, s = sh[idx].s, d = sh[idx].d;
		
		if(d == 2 || d == 3){
			//왼쪽으로 가는거면 일단 0에 위치시키기 
			if(d == 3){
				if(c-s > 0){
					sh[idx].c = c-s;
					continue;
				}
				s = s - c;
				c = 0;
				sh[idx].d ^= 1;
			}
			
			//시작점을 C-1로 맞춰버려~  
			int cnt = ((C-1) - c);
			if(cnt > s){
				sh[idx].c = c + s;
				continue;
			}
			c = C-1;
			s = s - cnt;
			
			int temp = s / (C-1);
			cnt = s % (C-1);
			//cout << "*"<< cnt << "\n";
			if(temp % 2 == 1){
				sh[idx].c = cnt;
				//sh[idx].d ^= 1;
			}
			
			else{
				sh[idx].c = C-1 - cnt;
				sh[idx].d ^= 1;
			}
			
		}
		
		else if(d == 0 || d == 1){
			//위쪽으로 가는거면 일단 0에 위치시키기 
			if(d == 0){
				if(r-s > 0){
					sh[idx].r = r-s;
					continue;
				}
				s = s - r;
				r = 0;
				sh[idx].d ^= 1;
			}
			
			//시작점을 R-1로 맞춰버려~  
			int cnt = ((R-1) - r);
			if(cnt > s){
				sh[idx].r = r + s;
				continue;
			}
			r = R-1;
			s = s - cnt;
			
			int temp = s / (R-1);
			cnt = s % (R-1);
			//cout << "*"<< cnt << "\n";
			if(temp % 2 == 1){
				sh[idx].r = cnt;
				//sh[idx].d ^= 1;
			}
			
			else{
				sh[idx].r = R-1 - cnt;
				sh[idx].d ^= 1;
				
			}
				
		}
	}
	//show();
}

void eat(){
	for(int i = 0; i < M; i++){
		if(sh[i].isDie == true) continue;
		
		int r = sh[i].r, c = sh[i].c, z = sh[i].z;
		if(visited[r][c] == -1)
			visited[r][c] = i;
		else{
			if(sh[visited[r][c]].z > z){
				sh[i].isDie = true;
				//cout << i <<"번째 상어 잡아먹힘\n";
			}
			else{
				sh[visited[r][c]].isDie = true;
				//cout << visited[r][c] <<"번째 상어 잡아먹힘hihi\n";
				visited[r][c] = i;
			}
		}	
	}
	
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> R >> C >> M;
	memset(visited, -1, sizeof(visited));
	for(int i = 0 ; i < M ; i++){
		cin >> sh[i].r >> sh[i].c >> sh[i].s >> sh[i].d >> sh[i].z;
		sh[i].r--;
		sh[i].c--;
		sh[i].d--;
		sh[i].isDie = false;
		visited[sh[i].r][sh[i].c] = i;
	}
	
	for(int t = 0; t < C; t++){
		for(int i = 0; i < R; i++){
			if(visited[i][t] != -1){
				int idx = visited[i][t];
				//cout << idx << "** \n";
				ret += sh[idx].z;
				sh[idx].isDie = true;
				break;
			}
		}
		//cout << "탐색끝";
		
		memset(visited, -1, sizeof(visited));
		move();
		eat();
		//show();
	}
	
	cout << ret;
}