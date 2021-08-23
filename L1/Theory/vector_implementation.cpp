// #include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
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
class custom_vector{
    int *a;
    int sz,cap;
    public:
        custom_vector(){
            a=NULL;sz=0;cap=0;
        }
        void push_back(int num){
            if(sz+1<=cap){
                a[sz]=num;sz++;
            }else{
                int *b;
                if(cap){
                    b= new int[2*cap];
                    cap*=2;
                }else{
                    b=new int [1];cap=1;
                }
                looper(i,0,sz){
                    b[i]=a[i];
                }
                delete[] a;a=b;
                a[sz]=num;sz++;
            }
        }
        int size(){
            return sz;
        }
        int capacity(){
            return cap;
        }
        void pop_back(){
            if(sz) sz--;
        }
        int back(){
            if(sz) return a[sz-1];
        }
        int operator[](int i){
            if(i>=0 & i<sz){
                return a[i];
            }else{
                return -1;
            }
        }
};
int32_t main(){
    custom_vector arr;
    looper(i,0,100){
        arr.push_back(i);
        cout<<arr.size()<<space<<arr.capacity()<<endl;
    }
    cout<<arr[5]<<endl; //through operator overloading, this thing is possible
    return 0;
}