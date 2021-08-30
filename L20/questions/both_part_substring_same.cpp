// given a string, find the longest substr of even length which has first and second part equal
// we can use hashing here , if hash of two parts of even length substr is equal, there is very low prob that its not our ans
// to reduce the probability of failure we take mod wit prime no (10**9 + 9) and then again take mod wit a no close to 10**9 + 9 
// #include <bits/stdc++.h>
// we gonna use rolling hash function
// where hash[i][j+1] = (31*hash[i][j] + s[j+1])%MOD
#include <iostream>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;
#define int long long 
#define vi vector<int>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define tester int t;cin>>t;while(t--)
#define looper(a,b,c) for(int a=b;a<c;a++)
#define ss second
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int> >
#define mod 1000000007
#define vs vector<string>
#define mp map<int,int>
#define ump unordered_map<int,int>
#define space ' '
#define stc stack<char>
#define sti stack<int>
#define all(arr) arr.begin(),arr.end()
#define looprev(i,a,b) for(int i=a;i>=(b);i--)
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<space;std::cout<<std::endl;
#define si set<int>
int gCd(int a,int b){
    if(b==0)
        return a;
    return gCd(b,a%b);
}
int fact(int n){
    int res=1;
    for(int i=2;i<=n;i++)
        res = (res*i)%mod;
    return res;
}
int nCr(int n,int r){
    return fact(n)/ (fact(r)*fact(n-r));
}
    
bool compare(pair<int,int> &one, pair<int,int> &two){
    return one.second < two.second;
}
int polynomialRollingHash (string const& str)
{
    int p = 31,power_of_p = 1,hash_val = 0;
    for (int i = 0; i < str.length(); i++) {
        hash_val= (hash_val + (str[i] - 'a' + 1) * power_of_p)% mod;
        power_of_p = (power_of_p * p) % mod;
    }
    return hash_val;
}
int32_t main(){
    int n;cin>>n;
    string s;cin>>s;
    vector<vi> hash(n,vi(n));
    int ans = INT_MIN;
    looper(i,0,n){
        for(int j=i+1;j<n;j+=2){
            int mid = (i+j)/2;
            if(hash[i][mid]==hash[mid+1][j]){
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}