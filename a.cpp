#include<iostream>
#include<cstring>
using namespace std;

int n,k;
char mapp[10][10];
int vis[10][10];
int ans;

int check(int x,int y){
    if(vis[x][y]==1) return 0;
    for(int i=1;i<=n;i++){
        if(mapp[x][i]=='#'&&vis[x][i]==1) return 0;
        if(mapp[i][y]=='#'&&vis[i][y]==1) return 0;
    }
    return 1;
}

void dfs(int hang,int total){
    if(total==0){
        ans++;
        return;
    }
    if(hang>n) return;
    for(int i=1;i<=n;i++){
        if(mapp[hang][i]=='#'&&check(hang,i)){
            vis[hang][i]=1;
            dfs(hang+1,total-1);
            vis[hang][i]=0;
        }
    }
    dfs(hang+1,total);
}

int main(){
    while(cin>>n>>k){
        if(n==-1&&k==-1) break;
        memset(mapp,'.',sizeof(mapp));
        memset(vis,0,sizeof(vis));
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mapp[i][j];
            }
        }
        dfs(1,k);
        cout<<ans<<endl;
    }
    return 0;
}

