#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

//两次bfs。先对火bfs，记录火烧到这些位置的最短时间
//然后对人bfs，通过比较时间来判断人可不可以逃脱迷宫
//听说这种方法在网络流里面经常使用，注意了
char mapp[1005][1005];
int timee[1005][1005];
//储存火烧到某个格子的最短时间
int vis[1005][1005];
//储存某个格子是否被人走过的信息
int h,l;
int ans;

struct point{
    int h;
    int l;
    int step;
    point(int _h=0,int _l=0,int _step=0):h(_h),l(_l),step(_step){}
};

bool check(int h1,int l1){
    if(mapp[h1][l1]=='#') return false;//墙
    if(timee[h1][l1]<0x3f3f3f3f) return false;
    //上句判断是否曾经走过
    //注意bfs特点，曾经走过的点时间肯定更短
    return true;
}//给火使用的，判断是否可走

bool check2(int h1,int l1,int p){
    if(mapp[h1][l1]=='#') return false;
    if(mapp[h1][l1]=='F') return false;
    if(timee[h1][l1]<=p) return false;//判断时间
    if(vis[h1][l1]==1) return false;//判断是否曾经走过
    return true;
}//给人使用的，判断是否可走

void bfs(int h1,int l1){
    vis[h1][l1]=1;
    queue<point> b;
    while(!b.empty()) b.pop();
    b.push(point(h1,l1,0));
    while(!b.empty()){
        point t=b.front();
        b.pop();
        if(t.h==1||t.l==1||t.h==h||t.l==l){
            ans=t.step+1;//判断人是否可以逃出迷宫
            break;
        }
        if(check2(t.h+1,t.l,t.step+1)){
            b.push(point(t.h+1,t.l,t.step+1));
                            vis[t.h+1][t.l]=1;
        }
        if(check2(t.h-1,t.l,t.step+1)){
            b.push(point(t.h-1,t.l,t.step+1));
                            vis[t.h-1][t.l]=1;
        }
        if(check2(t.h,t.l-1,t.step+1)){
            b.push(point(t.h,t.l-1,t.step+1));
                            vis[t.h][t.l-1]=1;
        }
        if(check2(t.h,t.l+1,t.step+1)){
            b.push(point(t.h,t.l+1,t.step+1));
                            vis[t.h][t.l+1]=1;
        }
    }//人在当前位置无路可走的时候
     //不要退出循环，因为队列里面还可能有其他元素
     //应当等它自行退出
}//事实证明，开数组做for和用4个if效率差不多的

int main(){
    ios_base::sync_with_stdio(0);
    //上面这句可以关掉流同步，加快数据读入
    //开这个就最好不要同时使用cin和scanf了
    int T;
    cin>>T;
    while(T--){
        ans=-1;
        cin>>h>>l;
        memset(timee,0x3f3f3f3f,sizeof(timee));
        memset(mapp,'#',sizeof(mapp));
        memset(vis,0,sizeof(vis));
        queue<point> a;
        while(!a.empty()) a.pop();
        int h0,l0;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                cin>>mapp[i][j];
                if(mapp[i][j]=='F') a.push(point(i,j,0));
                if(mapp[i][j]=='J') {h0=i;l0=j;}//记录人的位置
            }
        }//在读入数据的时候就把火放入队列，省的再去处理
        while(!a.empty()){
            point tmp=a.front();
            a.pop();
            if(check(tmp.h+1,tmp.l)){
                timee[tmp.h+1][tmp.l]=tmp.step+1;
                a.push(point(tmp.h+1,tmp.l,tmp.step+1));
            }
            if(check(tmp.h-1,tmp.l)){
                timee[tmp.h-1][tmp.l]=tmp.step+1;
                a.push(point(tmp.h-1,tmp.l,tmp.step+1));
            }
            if(check(tmp.h,tmp.l+1)){
                timee[tmp.h][tmp.l+1]=tmp.step+1;
                a.push(point(tmp.h,tmp.l+1,tmp.step+1));
            }
            if(check(tmp.h,tmp.l-1)){
                timee[tmp.h][tmp.l-1]=tmp.step+1;
                a.push(point(tmp.h,tmp.l-1,tmp.step+1));
            }
        }//上方对火bfs，记录时间信息
        bfs(h0,l0);//对人bfs，找出答案
        if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}

