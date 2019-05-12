//遇见起点和终点只有一个
//且都告诉你坐标的题目
//可以double bfs
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int vis[2][305][305];
//感觉双向bfs主要是在vis数组上下功夫
//我这里把走的步数存到vis里面了
//如果要开结构体数组会炸空间
int L;
int ans;

struct point{
    int h;
    int l;
    int judge;
    int step;
    point(int _h=0,int _l=0,int _judge=0,int _step=0):h(_h),l(_l),judge(_judge),step(_step){}
};

bool check(point t){
    if(t.h<0||t.l<0||t.h>=L||t.l>=L) return false;
    if(vis[t.judge][t.h][t.l]!=0) return false;
    return true;
}

void bfs(int h1,int l1,int h2,int l2){
    queue<point> que;
    while(!que.empty()) que.pop();
    que.push(point(h1,l1,0,1));
    vis[0][h1][l1]=1;
    que.push(point(h2,l2,1,1));
    vis[1][h2][l2]=1;
    while(!que.empty()){
        point tmp=que.front();
        //cout<<tmp.h<<" "<<tmp.l<<" "<<tmp.judge<<" "<<tmp.step<<endl;
        que.pop();
        if(vis[0][tmp.h][tmp.l]!=0&&vis[1][tmp.h][tmp.l]!=0){
            ans=vis[0][tmp.h][tmp.l]+vis[1][tmp.h][tmp.l]-2;
            return ;
        }//注意退出循环的方式，输出很重要
        tmp.h++;tmp.l+=2;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
        tmp.h--;tmp.l-=2;
        tmp.h++;tmp.l-=2;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
        tmp.h--;tmp.l+=2;
        tmp.h--;tmp.l+=2;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
        tmp.h++;tmp.l-=2;
        tmp.h--;tmp.l-=2;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
        tmp.h++;tmp.l+=2;
        tmp.h+=2;tmp.l++;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
        tmp.h-=2;tmp.l--;
        tmp.h+=2;tmp.l--;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
        tmp.h-=2;tmp.l++;
        tmp.h-=2;tmp.l++;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
        tmp.h+=2;tmp.l--;
        tmp.h-=2;tmp.l--;
        if(check(tmp)){
            vis[tmp.judge][tmp.h][tmp.l]=tmp.step+1;
            que.push(point(tmp.h,tmp.l,tmp.judge,tmp.step+1));
        }
    }
    return ;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        ans=0;
        cin>>L;
        int h1,l1,h2,l2;
        cin>>h1>>l1>>h2>>l2;
        bfs(h1,l1,h2,l2);
        cout<<ans<<endl;
    }
    return 0;
}
