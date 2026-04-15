#include <bits/stdc++.h>
using namespace std;

int N, ret;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        stack <char> stk;
        cin >> s;
        
        for (char a : s){
            if(stk.size() && stk.top() == a) stk.pop();
            else stk.push(a);
        }
        
        if(stk.size() == 0) ret++;
    }    

    cout << ret;    
}