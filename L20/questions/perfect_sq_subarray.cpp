// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003381cb
// the max sum of subarray possible is (10**5)*(100) = 10**7 so it means for a perfect sq sqrt(10**7) ~ 3162 
// this means sum of any subarray can be at max equal to sq of 3162
// if we check for all values in [0,3162] if that sq sum exist 
// it will take 3200*n time = 3.2 * 10**8
// #include <bits/stdc++.h>
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
int zero;
vi sq;
void pre(){
    looper(i,0,5001){
        sq.pb(i*i);
    }
}
int32_t main(){
    int *cnt = new int[20000001];
    looper(i,0,20000001){
        cnt[i]=0;
    }   
    pre();
    tester{
        int n;cin>>n;
        zero = 100*n;
        int sz = 200*n + 1;
        cnt[zero]++;
        int curr=0;
        int ans=0;
        vi arr(n);
        looper(i,0,n){
            int x;cin>>x;
            curr+=x;arr[i]=curr;
            for(int num:sq){
                if(num>100*n)
                    break;
                int id= curr-num+zero;
                if(id>=0 && id<sz){
                    ans+= cnt[id];
                }
            }
            cnt[zero + curr]++;
        }
        looper(i,0,n){
            cnt[zero + arr[i]]=0;
        }
        cnt[zero]=0;
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
    return 0;
}