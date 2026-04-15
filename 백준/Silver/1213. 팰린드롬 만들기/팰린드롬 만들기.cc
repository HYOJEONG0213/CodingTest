#include <bits/stdc++.h>
using namespace std;

string s, ret;
char mid;
int cnt[200], flag;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> s;
    for (char a : s) cnt[a]++;
    
    for(int i = 'Z'; i >= 'A'; i--){
        if(cnt[i] == 0) continue;
        
        if(cnt[i] & 1){
             flag ++;
             mid = char (i);
             cnt[i] --;
        }
   
        if(flag == 2) {
            cout << "I'm Sorry Hansoo";
            exit(0);
        }
   
    
        for(int j = 0; j < cnt[i]; j += 2){
            ret = char(i) + ret; // 무한 입력받게 만들음 얘가
            //찾았다 무한입력의 원인ㅋㅋㅋ cnt를 최대 26으로 해서 그럼
            //cnt는 알파벳 자체가 들어있기 때문에 A~Z 범위임 ㄷㄷ 
            ret += char(i);
        }
    }
    
    if(mid){
        ret.insert(ret.begin() + ret.size() / 2, mid);
    }
    
    cout << ret;
    
 
}