#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int h,l;
char mapp[205][205];
int vis[205][205];
int check[2][205][205];//存放Y与M到达@点时的时间信息
int ans;

struct point{
    int h;
    int l;
    int step;
    point(int _h=0,int _l=0,int _step=0):h(_h),l(_l),step(_step){}
};

bool judge(int x,int y){
    if(mapp[x][y]=='#'||vis[x][y]==1||mapp[x][y]=='Y'||mapp[x][y]=='M') return false;
    return true;
}//判断一个点是否可以经过

void bfs(int h1,int l1,int h2,int l2){//两个BFS，对Y和M分别求到达@的最快时间
    queue<point> que;
    while(!que.empty()) que.pop();
    que.push(point(h1,l1,0));
    vis[h1][l1]=1;
    while(!que.empty()){
        point tmp=que.front();
        que.pop();
        if(mapp[tmp.h][tmp.l]=='@') check[0][tmp.h][tmp.l]=tmp.step;
        if(judge(tmp.h+1,tmp.l)){
            vis[tmp.h+1][tmp.l]=1;
            que.push(point(tmp.h+1,tmp.l,tmp.step+1));
        }
        if(judge(tmp.h-1,tmp.l)){
            vis[tmp.h-1][tmp.l]=1;
            que.push(point(tmp.h-1,tmp.l,tmp.step+1));
        }
        if(judge(tmp.h,tmp.l+1)){
            vis[tmp.h][tmp.l+1]=1;
            que.push(point(tmp.h,tmp.l+1,tmp.step+1));
        }
        if(judge(tmp.h,tmp.l-1)){
            vis[tmp.h][tmp.l-1]=1;
            que.push(point(tmp.h,tmp.l-1,tmp.step+1));
        }
    }//下面几行是再次初始化代码
    memset(vis,0,sizeof(vis));
    while(!que.empty()) que.pop();
    que.push(point(h2,l2,0));
    vis[h2][l2]=1;
    while(!que.empty()){
        point tmp=que.front();
        que.pop();
        if(mapp[tmp.h][tmp.l]=='@') check[1][tmp.h][tmp.l]=tmp.step;//注意@点也可以被走过
        if(judge(tmp.h+1,tmp.l)){
            vis[tmp.h+1][tmp.l]=1;
            que.push(point(tmp.h+1,tmp.l,tmp.step+1));
        }
        if(judge(tmp.h-1,tmp.l)){
            vis[tmp.h-1][tmp.l]=1;
            que.push(point(tmp.h-1,tmp.l,tmp.step+1));
        }
        if(judge(tmp.h,tmp.l+1)){
            vis[tmp.h][tmp.l+1]=1;
            que.push(point(tmp.h,tmp.l+1,tmp.step+1));
        }
        if(judge(tmp.h,tmp.l-1)){
            vis[tmp.h][tmp.l-1]=1;
            que.push(point(tmp.h,tmp.l-1,tmp.step+1));
        }
    }
}

int main(){
    while(cin>>h>>l){
        int h1,l1,h2,l2;
        memset(check,0,sizeof(check));
        memset(mapp,'#',sizeof(mapp));
        memset(vis,0,sizeof(vis));
        ans=123456789;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                cin>>mapp[i][j];
                if(mapp[i][j]=='Y') {h1=i;l1=j;}
                if(mapp[i][j]=='M') {h2=i;l2=j;}
            }
        }
        bfs(h1,l1,h2,l2);
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                if(mapp[i][j]=='@'&&check[0][i][j]!=0&&check[1][i][j]!=0){
                //注意这里，可能会存在无法到达的@点，比如被#包围的那种，这时要用判断语句区分开来
                    ans=min(ans,check[0][i][j]+check[1][i][j]);
                }
            }
        }
        cout<<ans*11<<endl;
    }
    return 0;
}
