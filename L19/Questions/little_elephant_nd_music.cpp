// https://www.codechef.com/problems/LEMUSIC
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
// product is max when small is multiplied with small and large with large 
int32_t main(){
    tester{
        int n;cin>>n;
        map<int,vi> m;
        looper(i,0,n){
            int b,l;cin>>b>>l;
            m[b].pb(l);
        }
        vi small;
        int rest_sum=0;
        for(auto p:m){
            vi v = p.ss;
            sort(all(v));
            small.pb(v[0]);
            looper(i,1,v.size()){
                rest_sum+= v[i];
            }
        }
        small.pb(-1);
        sort(all(small));
        int cnt=0;
        looper(i,1,small.size()){
            cnt+= i*small[i];
        }
        cnt+= rest_sum*(m.size());
        cout<<cnt<<endl; 
    }
    return 0;
}