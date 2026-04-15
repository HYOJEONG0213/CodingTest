#include <bits/stdc++.h>
using namespace std;

string s;
bool flag;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        getline(cin, s);
        if(s == ".") break;
        
        stack <char> stk;
        flag = true;
        for(char c : s){
            if (c=='[')
                stk.push(c);
            else if (c=='(')
                stk.push(c);
            else if (c==']'){
                if (stk.empty() || stk.top() != '['){
                    flag = false; 
                    break;
                }
                else
                    stk.pop();
            }
            else if (c==')'){
                if (stk.empty() || stk.top() != '('){
                    flag = false; 
                    break;
                }
                else
                    stk.pop();
            }
        }
        if(stk.size()) flag = false;
        
        if(flag == false) cout << "no" << "\n";
        else cout << "yes" << "\n";
    }
}