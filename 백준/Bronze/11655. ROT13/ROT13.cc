#include <bits/stdc++.h>
using namespace std;

string s, ret;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getline(cin, s);
    for(char c : s){
        if(islower(c)){
            if (c+13 > 'z') ret += (c-13);
            else ret += c + 13;
        }
        else if(isupper(c)){
            if (c+13 > 'Z') ret += (c-13);
            else ret += c + 13;
        }
        else
            ret += c;
    }
    
    cout << ret;
    
    
    
    
}