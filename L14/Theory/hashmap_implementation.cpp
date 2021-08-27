//Theory terms
// Size-> no of keys in the hashmap
//Bucket cnt-> no of buckets in the hashmap(basically size of our outer vector)
//Load factor-> size/bucket cnt
//max load factor-> 1.0
// so whenever size become equal to bucket cnt then our hashmap changes the bucket count to prime no just greater than or = 2*(pre bucket count)
// eg-> 2,then 5,then 11, then 23 and so on 
// as we decrease max load factor, collisions will be less as size must dec and thus there are less elements
//Morever as load factor decreases, our bucket count have to be doubled various times and thus hash fn have to change everytime 
// and all keys have to be reorderd!!!
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
// hash fn for string to int
class mapStoi{
    vector<list<pair<const string,int>>> v;
    int n,sz; //bucket cnt
    double lf,mx_lf; //load factor and max load factor 
    int hash(string s){
        int p=257,ans=0;
        for(int i=s.size()-1;i>=0;i--){
            int curr = int(s[i]);
            ans= (ans*p + curr)%n;
        }
        return ans;
    }
    int rehash(){
        // get smallest prime >=2*n
        vector<list<pair<const string,int>>> v2(2*n);
        n*=2;
        looper(i,0,n/2){
            for(auto p:v[i]){
                v2[hash(p.ff)].pb(p);
            }
        }
        v=v2;
        lf= sz/(double)n;

    }
    public:
    mapStoi(){
        v.resize(1);
        sz=0;
        n=1;lf=0.0;mx_lf=1.0;
    }
    void erase(string s){
        int id= hash(s);
        for(auto it=v[id].begin();it!= v[id].end();++it){
            if(it->ff==s){
                v[id].erase(it);
                sz--;
                break;
            }
        }
        return;
    }
    int &operator[](string s){
        int id=hash(s);
        for(auto &p : v[id]){
            if(p.ff==s){
                return p.ss;
            }
        }
        v[id].pb({s,0});
        sz++;
        lf=(sz)/(double)n;
        if(lf<=mx_lf){
            return v[id].back().ss;
        }
        rehash();
        return find(s)->ss;
        
    }
    list<pair<string,int>>::iterator find(string s){
        int id= hash(s);
        for(auto it=v[id].begin();it!= v[id].end();++it){
            if(it->ff==s){
                return it;
            }
        }
        return v.back().end();
    }
    int count(string s){
        int id= hash(s);
        for(auto it=v[id].begin();it!= v[id].end();++it){
            if(it->ff==s){
                return 1;
            }
        }
        return 0;
    }
    int size(){
        return sz;
    }
    int bucket_cnt(){
        return n;
    }
    int insert(pair<string,int> p){
        string s=p.ff;
        int val= p.ss;
        int id=hash(s);
        for(auto &p : v[id]){
            if(p.ff==s){
                p.ss=val;
                return ;
            }
        }
        v[id].pb({s,0});
        sz++;
        lf=(sz)/(double)n;
        if(lf>mx_lf){
            rehash();
            // return v[id].back().ss;
        }
    }
};
int32_t main(){
    mapStoi m;
    int n=10;
    looper(i,1,n+1){
        string s;
        s+= (char)('a' + i);
        m[s]=i;
        cout<<m.bucket_cnt()<<space<<m.size()<<endl;
    }
    cout<<m["d"]<<endl;
    cout<<m.count("d")<<endl;
    m.erase("d");
    cout<<m["d"]<<endl;
    cout<<m.count("d")<<endl;
    m.insert({"dh",1});
    // unordered map overview
    unordered_map<int,int> map_;
    map_.insert({1,1});
    map_[5]=2;
    cout<<map_[10]<<endl;
    if(map_.count(10)){
        cout<<"10 is present"<<endl;
    }
    auto it= map_.find(10);
    if(it!=map_.end()){
        it->ss=10;
    }
    cout<<map_[10]<<endl;
    // functions in map
    cout<<map_.size()<<space<<map_.bucket_count()<<space<<map_.max_load_factor(); 
    // we can even change the default max lf
    map_.max_load_factor(0.25);
    cout<<map_.max_load_factor()<<endl;
    // if we know how many keys we have to add in our map, we can reserve space for that
    map_.reserve(1024);
    cout<<map_.bucket_count()<<endl; //will give prime no just greater than 1024;
    // this bucket cnt depends on max load factor we set to take care of collissions
    // if u want to set bucket size by yourself , u can use rehash fn
    map_.rehash(1000);
    cout<<map_.bucket_count()<<endl; // will find no close to set bucket cnt which is prime


    return 0;
}
// lly we have unordered set, here instead of storing key value pair, we store only value, 
// here instead of hashing key, we hash the value itself 
//------------------
// we cant have unordered_map<pii,int> as its hash fn is not defined in c++, but we can use map for that
// as map is implemented entirely diff using self balancing binary search tree
