#include<iostream>
#include<cstring>
using namespace std;

int n,m;
char mapp[105][105];
int vis[105][105];

void dfs(int h,int l){
    vis[h][l]=1;
    for(int i=h-1;i<=h+1;i++){
        for(int j=l-1;j<=l+1;j++){
            if(mapp[i][j]=='@'&&vis[i][j]==0) dfs(i,j);
        }
    }
}

int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        memset(mapp,'*',sizeof(mapp));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mapp[i][j];
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mapp[i][j]=='@'&&vis[i][j]==0){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

