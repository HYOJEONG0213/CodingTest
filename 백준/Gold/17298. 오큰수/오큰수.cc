#include <bits/stdc++.h>
using namespace std;

int N, a[10000004], ret[10000004];
stack <int> stk;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < N; i++){
        cin >> a[i];
    
        while(stk.size() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    for(int i = 0; i < N; i++)
        cout << ret[i] << " ";
}