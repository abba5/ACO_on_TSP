#include <bits/stdc++.h>
#define int long long int
#define error cout << "here\n";exit(0)
using namespace std;

int dp[18][262144+1];
int n, q;
int dis[105][105];

int cou_for_die;
int call_dp;

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

int f(int cur, int bit_arr){

    if(dp[cur][bit_arr] != -1){
        return dp[cur][bit_arr];
    }

    if(bit_arr == 0){
        return dis[0][cur];
    }else{
        
        int temp = INT_MAX;

        for(int i = 0; i < n; ++i){
            if(bit_arr & (1 << i)){
                temp = min(temp, dis[cur][i] + f(i, bit_arr ^ (1 << i)));
            }
        }

        return dp[cur][bit_arr] = temp;
    }

}

int32_t main(){

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);

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
    cout << f(0, bit_arr ^ 1) << '\n';


    return 0;
}