//由于我不会独立封装含有数组的函数
//所以没有把逆康托展开写成一个函数
//于是我直接在bfs里面逆展开了QAQ
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int q[10]={0,40320,5040,720,120,24,6,2,1,1};

struct point{
    int cantt;
    string ans;
    int vis;
}vis[362888];

int cant(int a,int b,int c,int d,int e,int f,int g,int h,int i){
    int p[10];p[0]=0;
    p[1]=a;p[2]=b;p[3]=c;
    p[4]=d;p[5]=e;p[6]=f;
    p[7]=g;p[8]=h;p[9]=i;
    for(int n=1;n<=9;n++){
        int countt=0;
        for(int m=n+1;m<=9;m++){
            if(p[n]>p[m]) countt++;
        }
        p[0]+=countt*q[n];
    }
    return p[0];
}

void bfs(){
    queue<point> que;
    while(!que.empty()) que.pop();
    vis[0].cantt=0;//逆向bfs，把终点加入队列
    que.push(vis[0]);
    vis[0].vis=1;
    while(!que.empty()){
        point tmp=que.front();
        que.pop();
        int h[10];
        h[0]=tmp.cantt;
        //h[0]储存康托展开得到的值
        //下方逆康拓展开代码{
        for(int n=1;n<=9;n++){
            h[n]=h[0]/q[n];
            h[0]=h[0]-h[n]*q[n];
        }//上面代码得到逆康拓展开的序列，放在h数组里面
        //然后用下面代码进一步处理得到原始序列
        int check[10]={0};
        int p[10]={0};
        for(int n=1;n<=9;n++){
            int countt=0;
            for(int m=1;m<=9;m++){
                if(check[m]==0){
                    countt++;
                }
                if(countt==h[n]+1){
                    p[n]=m;
                    check[m]=1;
                    break;
                }
            }
        }//得到8数码的数组形式,存放在p数组里面
        //上方逆康托展开代码}
        if(p[1]==9){
            point t;
            t.cantt=cant(p[4],p[2],p[3],p[1],p[5],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'d';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[2],p[1],p[3],p[4],p[5],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'r';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[2]==9){
            point t;
            t.cantt=cant(p[2],p[1],p[3],p[4],p[5],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'l';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[3],p[2],p[4],p[5],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'r';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[5],p[3],p[4],p[2],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'d';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[3]==9){
            point t;
            t.cantt=cant(p[1],p[3],p[2],p[4],p[5],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'l';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[6],p[4],p[5],p[3],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'d';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[4]==9){
            point t;
            t.cantt=cant(p[4],p[2],p[3],p[1],p[5],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'u';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[5],p[4],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'r';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[7],p[5],p[6],p[4],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'d';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[5]==9){
            point t;
            t.cantt=cant(p[1],p[5],p[3],p[4],p[2],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'u';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[5],p[4],p[6],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'l';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[6],p[5],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'r';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[8],p[6],p[7],p[5],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'d';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[6]==9){
            point t;
            t.cantt=cant(p[1],p[2],p[6],p[4],p[5],p[3],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'u';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[6],p[5],p[7],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'l';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[5],p[9],p[7],p[8],p[6]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'d';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[7]==9){
            point t;
            t.cantt=cant(p[1],p[2],p[3],p[7],p[5],p[6],p[4],p[8],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'u';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[5],p[6],p[8],p[7],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'r';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[8]==9){
            point t;
            t.cantt=cant(p[1],p[2],p[3],p[4],p[8],p[6],p[7],p[5],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'u';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[5],p[6],p[8],p[7],p[9]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'l';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[5],p[6],p[7],p[9],p[8]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'r';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
        if(p[9]==9){
            point t;
            t.cantt=cant(p[1],p[2],p[3],p[4],p[5],p[9],p[7],p[8],p[6]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'u';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
            t.cantt=cant(p[1],p[2],p[3],p[4],p[5],p[6],p[7],p[9],p[8]);
            if(vis[t.cantt].vis==0){
                t.ans=tmp.ans+'l';
                que.push(t);
                vis[t.cantt].ans=t.ans;
                vis[t.cantt].vis=1;
            }
        }
    }
}

int main(){
    for(int i=1;i<=362880;i++){
        vis[i].ans='S';
        vis[i].cantt=-1;
        vis[i].vis=0;
    }//初始化
    bfs();//逆向打表
    string p;
    while(cin>>p[0]>>p[1]>>p[2]>>p[3]>>p[4]>>p[5]>>p[6]>>p[7]>>p[8]){
        int start[10];
        int k=1;
        for(int i=0;i<9;i++){
            if(p[i]>='1'&&p[i]<='8') {start[k]=int(p[i]-48);k++;}
            else if(p[i]=='x') {start[k]=9;k++;}
        }//q数组里面存放了输入的数据，从1到9
        int number=cant(start[1],start[2],start[3],start[4],start[5],start[6],start[7],start[8],start[9]);
        if(vis[number].ans=="S") cout<<"unsolvable"<<endl;
        else{//我一开始是用正向方法写的，但是TLE了，所以用逆向打表的方法
	//这里bfs内部没有改，所以输出会相反
            for(int i=vis[number].ans.length();i>=0;i--){
                if(vis[number].ans[i]=='l') cout<<'r';
                if(vis[number].ans[i]=='r') cout<<'l';
                if(vis[number].ans[i]=='u') cout<<'d';
                if(vis[number].ans[i]=='d') cout<<'u';
            }
            cout<<endl;
        }
    }
    return 0;
}