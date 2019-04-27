#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define inf 0x3f3f3f3f
int n,m;//行和列
bool vis[15][15];
char grid[15][15];//草坪，存图的地方
int casee=0;//第几次测试样例
int ans;

struct node{
    int x,y,depth;
};//分别储存横坐标，纵坐标，还有当前的时间
vector<node> grass;

bool check(int x,int y){
    if (!vis[x][y]&&grid[x][y]=='#'&&x>=0&&x<n&&y>=0&&y<m)
    return true;
    else
    return false;
}//判断这个点是否可以走，注意这里的判断方式是只判断正确的，这个值得学习

bool judge(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='#'&&!vis[i][j])
            return false;
        }
    }
    return true;
}//判断是否有些草坪没有被烧起来，因为可能会有多个草坪。个人感觉只有数据小的时候可以这样

void init(){
    grass.clear();
    memset(vis,false,sizeof vis);
}//初始化

//所谓的两个点bfs，其实就是在初始化的时候放入两个点就可以了，其他和平常的bfs几乎都一样
int bfs(node n1,node n2){
    queue<node> q;
    memset(vis,false,sizeof vis);
    while (!q.empty()) q.pop();
    q.push(n1);
    q.push(n2);
    int depthest=0;//将要输出的时间值
    while(!q.empty()){
        node now=q.front();
        q.pop();
        if(vis[now.x][now.y]) continue;//节省时间，注意这句话的使用方式!
        vis[now.x][now.y]=true;//出队列才会给判断vis
        depthest=now.depth;//更新时间
        if(check(now.x-1,now.y)){
            node nxt=now;
            nxt.x--;
            nxt.depth++;
            q.push(nxt);
        }//这些if可以更改一下，用kuangbin的函数
        if(check(now.x+1,now.y)){
            node nxt=now;
            nxt.x++;
            nxt.depth++;
            q.push(nxt);
        }
        if(check(now.x,now.y-1)){
            node nxt=now;
            nxt.y--;
            nxt.depth++;
            q.push(nxt);
        }
        if(check(now.x,now.y+1)){
            node nxt=now;
            nxt.y++;
            nxt.depth++;
            q.push(nxt);
        }
    }
    return depthest;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        ans=inf;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%s",grid[i]);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='#'){
                    node g;
                    g.x=i;
                    g.y=j;
                    g.depth=0;
                    grass.push_back(g);
                }
            }
        }
        for(int i=0;i<grass.size();++i){
            for(int j=i;j<grass.size();++j){
                grass[i].depth=0;//由于在遍历中会存在depth变化，
                grass[j].depth=0;//所以要在遍历途中初始化
                int temp=min(bfs(grass[i],grass[j]),ans);
                if(judge()) ans=min(ans,temp);//判断是否烧过所有草坪
            }
        }//双重循环遍历每个草坪暴力求最小值
        printf("Case %d: ",++casee);
        if(ans==inf) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
