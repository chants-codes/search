#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int vis[100005];//使用vis数组可以大大提高bfs效率
struct line{
    int number;
    int step;
};
int start;
int endd;
int ans;

void bfs(int beginn,int ennd){
    memset(vis,0,sizeof(vis));
    queue<line>a;
    while(!a.empty()) a.pop();
    line tmp;
    tmp.number=beginn;
    tmp.step=0;
    a.push(tmp);
    vis[tmp.number]=1;
    while(!a.empty()){
        tmp=a.front();
        a.pop();
        if(tmp.number==endd){
            ans=tmp.step;
            break;
        }
        if(tmp.number-1>=0&&vis[tmp.number-1]==0){
            line tmp1;
            tmp1.number=tmp.number-1;
            tmp1.step=tmp.step+1;
            a.push(tmp1);
            vis[tmp1.number]=1;
        }
        if(tmp.number+1<=100000&&vis[tmp.number+1]==0){
            line tmp1;
            tmp1.number=tmp.number+1;
            tmp1.step=tmp.step+1;
            a.push(tmp1);
            vis[tmp1.number]=1;
        }
        if(tmp.number*2<=100000&&vis[tmp.number*2]==0){
            line tmp1;
            tmp1.number=tmp.number*2;
            tmp1.step=tmp.step+1;
            a.push(tmp1);
            vis[tmp1.number]=1;
        }
    }//注意bfs的vis数组使用时只需要判断走过，不需要回溯
}

int main(){
    while(cin>>start>>endd){
        bfs(start,endd);
        cout<<ans<<endl;
    }
    return 0;
}
