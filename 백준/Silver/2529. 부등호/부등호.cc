#include <bits/stdc++.h>
using namespace std;

int k, visited[11];
char operand[11];
vector <string> result;

bool f(char x, char op, char y){
    if(op =='<' && x<y) return true;
    if(op =='>' && x>y) return true;

    return false;
}

void dfs(int idx, string num){
    if(idx == k + 1){
        result.push_back(num);
        return;
    }
    
    for(int i = 0; i <= 9; i++){
        if(visited[i] == 1) continue;

        if(idx==0 || f(num[idx-1], operand[idx-1], i + '0')){
            visited[i] = 1;
            dfs(idx+1, num + to_string(i));
            visited[i] = 0;
        }
        
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); cin.tie(NULL);

    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> operand[i];
    }

    dfs(0, "");

    sort(result.begin(), result.end());
    cout << result[result.size()-1] << "\n" << result[0];
}