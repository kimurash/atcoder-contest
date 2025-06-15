// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    string S;
    cin >> S;

    stack<char> st;

    for(char c : S){
        if(st.empty()){
            st.push(c);
        }else{
            char top = st.top();
            if(top == '(' && c == ')'){
                st.pop();
            } else if(top == '[' && c == ']'){
                st.pop();
            } else if(top == '<' && c == '>'){
                st.pop();
            } else {
                st.push(c);
            }
        }
    }

    if(st.empty()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return(0);
}
