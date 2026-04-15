#include <bits/stdc++.h>
using namespace std;

string s;
stack <char> stk1;
stack <char> stk2;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        cin >> s;
        stk1 = {};
        stk2 = {};
        bool flag = true;    //여러 규칙들에 위반 안한경우 : true 
        bool flag2 = false;    //모음이 한번도 안나오는 경우 : false
        
        if(s == "end") exit(0);
        
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                if(stk1.size() && stk1.top() == c) {
                    if(c == 'e' || c == 'o') continue;
                    else {
                        //cout <<"test1\n";
                         flag = false;
                         break;                     
                     }
                }
                stk1.push(c);
                stk2 = {};
                flag2 = true;
            }
            else{
                if(stk2.size() && stk2.top() == c){
                    flag = false;
                    //cout <<"test2\n";
                    break;
                    
                }
                stk2.push(c);
                stk1 = {};
            }
            
            if(stk1.size() == 3 || stk2.size() == 3){
                flag = false;
                //cout <<"test3\n";
                break;
                
            }
        }
        
        if(flag == false || flag2 == false) cout << "<" << s << "> " << "is not acceptable.\n";
        else cout << "<" << s << "> " << "is acceptable.\n";
    }

}