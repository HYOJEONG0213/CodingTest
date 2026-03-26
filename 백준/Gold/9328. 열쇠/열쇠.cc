#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int T, h, w, ret, dy[4] = {-1,0,1,0}, dx[4]={0, 1, 0, -1};
int visited[104][104];
char board[104][104];
string s;
map <char, int> mp;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		mp.clear();
		memset(visited, 0, sizeof(visited));
		memset(board, '.', sizeof(board));
		ret = 0;
		
		cin >> h >> w;
		for(int i = 1; i <= h ; i++){
			cin >> s;
			for(int j = 1; j <= w; j++){
				board[i][j] = s[j-1];
			}
		}
		cin >> s;
		if(s != "0"){
			for(int i = 0; i < s.size(); i++){
				mp[s[i]-'a'+'A']++;
			}
		}
		
		
		queue <pp> q;
		queue <pp> doors[100];
		
		q.push({0, 0});
		visited[0][0] = 1;
		
		while(q.size()){
			auto f = q.front(); q.pop();
			int y = f.first, x = f.second;
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i], nx = x + dx[i];
				if(ny < 0 || nx < 0 || ny > h+1 || nx > w+1) continue;
				if(visited[ny][nx]==1 || board[ny][nx]=='*') continue;
				
				if(board[ny][nx] >= 'a' && board[ny][nx] <= 'z'){
					int temp = board[ny][nx]-'a'+'A';
					mp[temp]++;
					visited[ny][nx] = 1;
					
					while(doors[temp].size()){
						auto f = doors[temp].front(); doors[temp].pop();
						visited[f.first][f.second]=1;
						q.push(f);
					}
					q.push({ny, nx});
				}
				else if(board[ny][nx] >= 'A' && board[ny][nx] <= 'Z'){
					int temp = board[ny][nx];
					if(mp[temp]==0){
						doors[temp].push({ny, nx});
					}
					else{
						q.push({ny, nx});
					}
					visited[ny][nx] = 1;
				}
				else if(board[ny][nx]=='.' || board[ny][nx]=='$'){
					if(board[ny][nx]=='$'){
						ret++;
					}
					visited[ny][nx] = 1;
					q.push({ny, nx});
				}
			}
		}
		
		cout << ret << "\n";
	}
}