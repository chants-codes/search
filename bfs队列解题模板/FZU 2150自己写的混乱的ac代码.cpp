#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int h,l;
char mapp[15][15];
int vis[15][15];
int judge[15][15];
int ans;

struct point{
    int h;
    int l;
    int step;
    point(int _h=0,int _l=0,int _step=0):h(_h),l(_l),step(_step){}
};

void bfs(int h1,int l1){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=l;j++){
            if(mapp[i][j]=='#'&&judge[i][j]==0){
                memset(vis,0,sizeof(vis));
                queue<point> que;
                while(!que.empty()) que.pop();
                que.push(point(h1,l1,0));
                que.push(point(i,j,0));
                int stepp=-1;
                while(!que.empty()){
                    point tmp=que.front();
                    que.pop();
                    if(vis[tmp.h][tmp.l]==1) continue;
                    stepp=max(tmp.step,stepp);
                    vis[tmp.h][tmp.l]=1;
                    if(mapp[tmp.h-1][tmp.l]=='#'&&vis[tmp.h-1][tmp.l]==0) que.push(point(tmp.h-1,tmp.l,tmp.step+1));
                    if(mapp[tmp.h+1][tmp.l]=='#'&&vis[tmp.h+1][tmp.l]==0) que.push(point(tmp.h+1,tmp.l,tmp.step+1));
                    if(mapp[tmp.h][tmp.l-1]=='#'&&vis[tmp.h][tmp.l-1]==0) que.push(point(tmp.h,tmp.l-1,tmp.step+1));
                    if(mapp[tmp.h][tmp.l+1]=='#'&&vis[tmp.h][tmp.l+1]==0) que.push(point(tmp.h,tmp.l+1,tmp.step+1));
                }
                int t=1;
                for(int x=1;x<=h;x++){
                    for(int y=1;y<=l;y++){
                        if(mapp[x][y]=='#'&&vis[x][y]==0) t=0;
                    }
                    if(!t) break;
                }
                if(t) ans=min(ans,stepp);
            }
        }
    }
    judge[h1][l1]=1;
}

int main(){
    int T;
    cin>>T;
    int casee=0;
    while(T--){
        cin>>h>>l;
        ans=0x3f3f3f;
        memset(mapp,'.',sizeof(mapp));
        memset(judge,0,sizeof(judge));
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                cin>>mapp[i][j];
            }
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                if(mapp[i][j]=='#') bfs(i,j);
            }
        }
        cout<<"Case "<<++casee<<": ";
        if(ans!=0x3f3f3f) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
