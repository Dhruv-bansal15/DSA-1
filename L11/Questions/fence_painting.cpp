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
int32_t main(){
    tester{
        int n,m;cin>>n>>m;
        vi a,b,c;
        looper(i,0,n){
            int x;cin>>x;
            a.pb(x);
        }
        looper(i,0,n){
            int x;cin>>x;
            b.pb(x);
        }
        looper(i,0,m){
            int x;cin>>x;
            c.pb(x);
        }
        vector<vi> required_(n+1);
        int cnt=0;
        looper(i,0,n){
            if(a[i]!=b[i]){
                required_[b[i]].pb(i);cnt++;
            }
        }
        int extra_paint_candidate=-1;
        if(required_[c[n-1]].size()){
            extra_paint_candidate= required_[c[n-1]][0];
        }else{
            looper(i,0,n){
                if(b[i]==c[n-1]){
                    extra_paint_candidate=i;
                    break;
                }
            }
        }
        if(extra_paint_candidate==-1){
            cout<<"NO"<<endl;
            continue;
        }
        // if(required_[c[n-1]].empty()){
        //     required_[c[n-1]].pb(extra_paint_candidate);cnt++;
        // }
        vi ans;
        looper(i,0,m){
            if(required_[c[i]].size()){
                ans.pb(required_[c[i]].back() + 1),required_[c[i]].pop_back(),cnt--;
            }else{
                ans.pb(extra_paint_candidate + 1);
            }
        }
        if(cnt){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i:ans){
                cout<<i<<space;
            }
            cout<<endl;
        }
    }   
    return 0;
}