#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

struct number{
    int len,a[20];}L,R;
bool bz[10];
int nxt[10]={2,2,3,5,5,7,7,2,0,0};
int pri[11]={0,2,3,5,7,11,13,17,19,23,29};
bool operator < (number a,number b){
    if (a.len!=b.len)return a.len<b.len;
    ROF(i,a.len,1)
    if (a.a[i]!=b.a[i])return a.a[i]<b.a[i];
    return 1;
}

void getClosestNumber(LL x,number &a){
    a.len=0;
    while(x){
        a.a[++a.len]=x%10;
        x/=10;
    }
}

void init(number &a){
    int w=0;
    ROF(i,a.len,1)
    if (!bz[a.a[i]]){w=i;break;}
    if (w){
        if (a.a[w]>7){
            FOR(i,1,w)a.a[i]=0;
            a.a[w+1]++;
            if (w==a.len)a.a[++a.len]=1;
            init(a);
            return;
        }
        a.a[w]=nxt[a.a[w]];
        FOR(i,1,w-1)a.a[i]=2;
    }
}

number getnxt(number a){
    int w=a.len+1;
    FOR(i,1,a.len)
    if (a.a[i]!=7){w=i;break;}
    a.len=max(a.len,w);
    FOR(i,1,w)a.a[i]=nxt[a.a[i]];
    return a;
}

LL quickmi(LL x,LL tim,LL mo){
    LL ans=1;
    while(tim){
        if (tim%2)ans=ans*x%mo;
        x=x*x%mo;
        tim/=2;
    }
    return ans;
}

bool check(LL x,LL p,LL t,LL mo){
    x=quickmi(x,p,mo);
    if (x==mo-1||x==1)return 1;
    FOR(i,1,t){
        if (x==1)return 0; 
        x=x*x%mo;
        if (x==mo-1)return 1;
    }
    return 0;
}

bool millerRabin(number a){
    LL x=0;
    ROF(i,a.len,1)x=x*10+a.a[i];
    LL p=x-1;
    int t=0;
    while(p%2==0){p/=2;t++;}
    FOR(i,1,10){
        if (x==pri[i])return 1;
        if (!check(pri[i],p,t,x))return 0;
    }
    return 1;
}

int main(){
    LL l,r;
    cin >> l >> r;
    getClosestNumber(l,L);
    getClosestNumber(r,R);
    bz[2]=bz[3]=bz[5]=bz[7]=1;
    init(L);
    int ans=0;
    while(L<R){
        if (millerRabin(L)){
            ans++;
            ROF(i,L.len,1);
        }
        L=getnxt(L);
    }
    cout << ans << endl;
    return 0;
}