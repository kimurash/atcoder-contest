#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    string S;
    cin >> N >> S;

    stack<char> result;
    int32_t left = 0; // スタックに格納されている'('の数

    rep(i, 0, N){
        char strch = S.at(i);
        if(strch == '('){
            result.push(strch);
            left++;
        } else if(strch == ')' && left > 0){
            char stkch;
            do{
                stkch = result.top();
                result.pop();
            } while(stkch != '(');
            left--;
        } else{
            result.push(strch);
        }
    }

    stack<char> output;
    while(!result.empty()){
        output.push(result.top());
        result.pop();
    }
///*
    while(!output.empty()){
        cout << output.top();
        output.pop();
    }
//*/
    cout << endl;
}