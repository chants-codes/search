#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

struct prime{
    int number;
    int step;
    prime(int _number=0,int _step=0):number(_number),step(_step){}
};

int vis[1100];
int p[1100];
int start;
int endd;
int total;
int ans;

bool isprime(int a){
    if(a<=1) return 0;
    if(a==2) return 1;
    for(int i=2;i<=a/2;i++){
        if(a%i==0) return 0;
    }
    return 1;
}

bool check(int a,int b){
    int t=0;
    for(int i=1;i<=4;i++){
        if(t>1) return 0;
        if(a%10!=b%10) t++;
            a=a/10;
            b=b/10;
    }
    if(t==0) return 0;
    if(t==1) return 1;
}

void bfs(int beginn){
    memset(vis,0,sizeof(vis));
    queue<prime>que;
    while(!que.empty()) que.pop();
    for(int i=1;i<total;i++){
        if(p[i]==beginn){
            vis[i]=1;
            break;
        }
    }
    que.push(prime(beginn,0));
    prime tmp;
    while(!que.empty()){
        tmp=que.front();
        if(tmp.number==endd){
            ans=tmp.step;
            break;
        }
        que.pop();
        for(int i=1;i<total;i++){
            if(check(p[i],tmp.number)&&vis[i]==0){
                vis[i]=1;
                que.push(prime(p[i],tmp.step+1));
            }
        }
    }
}

int main(){
    total=1;
    for(int i=1000;i<=9999;i++){
        if(isprime(i)){
            p[total]=i;
            //cout<<total<<" "<<i<<endl;
            total++;
        }
    }
    int n;
    cin>>n;
    while(n--){
        cin>>start>>endd;
        ans=-1;
        bfs(start);
        if(ans==-1) cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}

