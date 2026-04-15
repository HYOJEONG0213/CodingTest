#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
bool flag = true;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T; 
    for(int i = 0; i < T; i++){
        flag = true;
        cin >> s;
        stack <char> stk;
        for(char c : s){
            if(c == '(') stk.push(c);
            else if(c==')')
               if(stk.size() && stk.top() == '(') stk.pop();
               else {
                    flag = false;
                    break;
               }
        }
        if(stk.size() != 0) flag = false;
        
        if(flag == false) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
}