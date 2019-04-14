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
}//N皇后的check会比较麻烦，建议独立写成一个函数。

void dfs(int hang,int total){
    if(total==0){
        ans++;
        return;
    }
    if(hang>n) return;
    for(int i=1;i<=n;i++){//N皇后问题的典型dfs就是遍历棋盘行数。
        if(mapp[hang][i]=='#'&&check(hang,i)){
            vis[hang][i]=1;
            dfs(hang+1,total-1);
            vis[hang][i]=0;
        }
    }
    dfs(hang+1,total);//注意这里，不管怎么样都要dfs下一行。这个是和普通dfs的一个重要区别
}//因为这个题目可能会出现dfs的起点不是第一行的情况，所以要dfs下一行
//而N皇后不一样。因为每一行都会有一个皇后，也就是说dfs的起点肯定是在第一行，所以不需要在for以后dfs下一行。

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
