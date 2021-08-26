// given two arrays X and Y, u have to choose two indices i and j such that expression
// abs(X[j]-X[i]) + Y[i] + Y[j] is max
// given only X is sorted 
//assuming i<j, given expression turns to X[j] + Y[j] + Y[i] - X[i]
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
//take Y as P
pii get_ans(vi x,vi p,int n){
    int max_diff = p[0] - x[0],max_id = 0,max_ans= INT_MIN;
    pii ans={-1,-1};
    looper(j,1,n){
        int curr_sum = p[j] + x[j];
        if(curr_sum + max_diff>max_ans){
            max_ans= curr_sum + max_diff;ans={max_id,j};

        }
        if(p[j]-x[j]>max_diff){
            max_diff = p[j]-x[j];max_id=j;
        }
    }
    return ans;
}
int32_t main(){
    int n;cin>>n;
    vi x,p;
    looper(i,0,n){
        int y;cin>>y;x.pb(y);
    }
    looper(i,0,n){
        int y;cin>>y;p.pb(y);
    }
    pii ans=get_ans(x,p,n);
    cout<<ans.first<<space<<ans.second<<endl;
    return 0;
}