#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MAXN 10

using namespace std;

typedef vector<int16_t> vi16;

int16_t N, T;
int16_t hate[MAXN + 1];

int32_t divide_teams(vi16& teams, int16_t player){
    if(player > N){
        return(teams.size() == T);
    }

    int32_t answer = 0;
    rep(t, 0, teams.size()){
        if(!(teams[t] & hate[player])){
            teams[t] += 1 << player;
            answer += divide_teams(teams, player + 1);
            teams[t] -= 1 << player;
        }
    }

    if(teams.size() < T){
        teams.push_back(1 << player);
        answer += divide_teams(teams, player + 1);
        teams.pop_back();
    }

    return(answer);
}

int main(){
    int16_t M;
    cin >> N >> T >> M;

    int16_t A, B;
    rep(i, 0, M){
        cin >> A >> B;
        hate[A] += 1 << B;
        hate[B] += 1 << A;
    }

    vi16 teams;
    cout << divide_teams(teams, 1) << endl;
    return(0);
}