#include <bits/stdc++.h>
using namespace std;

int N, M, H, visited[35][35], a, b, ret = 987654321;

bool check(){
    //1부터 시작하는 이유 : start - 1을 하는데 0으로 시작하면 -1 배열로 시작함 ㅜㅜ 
    for(int i = 1; i <= N; i++){
        int start = i;
        for(int j = 1; j <= H; j++){
            if(visited[j][start-1] == 1)
                start--;
            else if(visited[j][start] == 1)
                start++;
        }
        
       // cout << "hi" << start << " " << i << "\n";
        if(i != start)
            return false;
    }
    
    return true;
}

void go(int here, int cnt){
    if(cnt > 3 || cnt >= ret) {
        return;
    }
    //현재상태의 사다리가 사다리 성공하나 확인하기 
    if(check()) {
        ret = min(cnt, ret);
        return; 
    }
    //사다리 새로 추가하기
    //여기서도 범위를 잘 보기,.. H는 들어가고, 세로선 개수는 안들어가넹 
    for(int i = here; i <= H; i++){
        for(int j = 1; j < N; j++){
            if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;
            
            visited[i][j] = 1;
            go(i, cnt+1);
            visited[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        visited[a][b] = 1;
    }
    
    go(1, 0);    //1로 시작하는 이유? visited[i][j-1]하면은 -1번째 배열이 나오게 됨 
    cout << ((ret == 987654321) ? -1 : ret); 
}