#include <bits/stdc++.h>
#define int long long int
#define error cout << "here\n";exit(0)
using namespace std;

struct DATA
{
    int value = -1;
    std::vector<int> v;
}dp[18][262144+1];

int n, q;
int dis[105][105];


void fill(int n){

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dis[i][j] = i == j ? 0 : INT_MAX;
}

void print(int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <n; ++j)
            cout << dis[i][j] << " \n"[j == n-1];
}

void print(std::vector<int> &v){
    for(int &i: v)
        cout << i+1 << ' ';
    cout << '\n';
}


DATA f(int cur, int bit_arr){

    if(dp[cur][bit_arr].value != -1){
        return dp[cur][bit_arr];
    }

    if(bit_arr == 0){
        DATA temp = {dis[0][cur], {cur}};
        return temp;
    }else{
        
        DATA min_ans = {INT_MAX, {}};

        for(int i = 0; i < n; ++i){
            if(bit_arr & (1 << i)){

                DATA temp = f(i, bit_arr ^ (1 << i));
                temp.value += dis[i][cur];

                if(min_ans.value > temp.value){
                    min_ans = temp;
                    min_ans.v.push_back(cur);
                }
            }
        }

        return dp[cur][bit_arr] = min_ans;
    }

}

int32_t main(){

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    q = ((n)*(n-1)) >> 1;

    fill(n);

    for(int i = 0; i < q; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        dis[u][v] = w;
        dis[v][u] = w;
    }

    int bit_arr = 0;
    bit_arr = (1 << n) - 1;

    DATA min_cost = f(0, bit_arr ^ 1);

    cout << min_cost.value << '\n';

    for(auto i: min_cost.v){
        cout << i + 1<< ' ';
    }
    cout << '\n';
    return 0;
}