// #include <bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_long longEGER.
 * The function accepts following parameters:
 *  1. long longEGER n
 *  2. LONG_long longEGER_ARRAY c
 */

long long getWays(long long n, vector<long> c) {
    vector<long long>dp(n+1, 0);
    long long m = c.size();
    long long sum = 0;
    for(long long i = 0 ; i<= n;i++){
        sum = 0;
        if(i == 0){
            dp[i] = 1;
        }
        else {
            for(long long j = 0; j<m; j++){
                long long val = (i - c[j] < 0 ? 0 : dp[i - c[j]]);
                sum += val;
            }
            dp[i] = sum;   
        }
    }
    for(auto x:dp){
        cout<<x<<" ";
    }
    return dp[n];
}

int main() {
    long long n,m;
    cin>>n>>m;
    vector<long>coins;
    for(long long i=1;i<=m;i++){
        long long x;
        cin>>x;
        coins.push_back(x);
    }
    getWays(n, coins);
}
