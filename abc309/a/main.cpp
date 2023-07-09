// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

int main(){
    int16_t A, B;
    cin >> A >> B;

    if(A % 3 == 0){
        cout << "No" << endl;
    } else{
        if(A + 1 == B){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
}