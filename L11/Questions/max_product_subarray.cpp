// https://www.geeksforgeeks.org/maximum-product-subarray/
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
// we split the array about zero and then take corresponding max product of all array ka max
class Max_product_subarray{
    int max_prod_without_0(vi &a){
        int n=a.size();
        if(n==1 & a[0]<0){
            return a[0];
        }
        int min_positive_prod=1,max_neg_prod=INT_MIN,prefix_prod=1,ans=0; // ans is 0 coz we have zeroes in our array so 0 can be achieved anytime
        looper(i,0,n){
            prefix_prod*=a[i];
            if(prefix_prod<0 & max_neg_prod!=INT_MIN){
                ans= max(ans,prefix_prod/max_neg_prod);
            }
            if(prefix_prod>0 & min_positive_prod!=INT_MIN){
                ans= max(ans,prefix_prod/min_positive_prod);
            }
            if(prefix_prod<0){
                max_neg_prod= max(max_neg_prod,prefix_prod);
            }
            if(prefix_prod>=0){
                min_positive_prod= min(min_positive_prod,prefix_prod);
            }
        }
        return ans;
    }
    public:
    int max_product(vi &a){
        vi v;
        int n=a.size();
        int ans= INT_MIN;
        looper(i,0,n){
            if(a[i]!=0){
                v.pb(a[i]);
            }else{
                if(ans<0) ans=0; //now we found a zero so min prod can be zero only and not any negative value
                if(v.size()){
                    ans= max(ans,max_prod_without_0(v));

                }
                v.clear();
            }
        }
        if(v.size()){
            ans= max(ans,max_prod_without_0(v));
        }
        v.clear();
        return ans;
    }

};
int32_t main(){
    int n;cin>>n;
    vi arr;
    looper(i,0,n){
        int x;cin>>x;arr.pb(x);
    }
    Max_product_subarray obje;
    int result = obje.max_product(arr);
    cout<<result<<endl;
    return 0;
}