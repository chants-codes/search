#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

//����bfs���ȶԻ�bfs����¼���յ���Щλ�õ����ʱ��
//Ȼ�����bfs��ͨ���Ƚ�ʱ�����ж��˿ɲ����������Թ�
//��˵���ַ��������������澭��ʹ�ã�ע����
char mapp[1005][1005];
int timee[1005][1005];
//������յ�ĳ�����ӵ����ʱ��
int vis[1005][1005];
//����ĳ�������Ƿ����߹�����Ϣ
int h,l;
int ans;

struct point{
    int h;
    int l;
    int step;
    point(int _h=0,int _l=0,int _step=0):h(_h),l(_l),step(_step){}
};

bool check(int h1,int l1){
    if(mapp[h1][l1]=='#') return false;//ǽ
    if(timee[h1][l1]<0x3f3f3f3f) return false;
    //�Ͼ��ж��Ƿ������߹�
    //ע��bfs�ص㣬�����߹��ĵ�ʱ��϶�����
    return true;
}//����ʹ�õģ��ж��Ƿ����

bool check2(int h1,int l1,int p){
    if(mapp[h1][l1]=='#') return false;
    if(mapp[h1][l1]=='F') return false;
    if(timee[h1][l1]<=p) return false;//�ж�ʱ��
    if(vis[h1][l1]==1) return false;//�ж��Ƿ������߹�
    return true;
}//����ʹ�õģ��ж��Ƿ����

void bfs(int h1,int l1){
    vis[h1][l1]=1;
    queue<point> b;
    while(!b.empty()) b.pop();
    b.push(point(h1,l1,0));
    while(!b.empty()){
        point t=b.front();
        b.pop();
        if(t.h==1||t.l==1||t.h==h||t.l==l){
            ans=t.step+1;//�ж����Ƿ�����ӳ��Թ�
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
    }//���ڵ�ǰλ����·���ߵ�ʱ��
     //��Ҫ�˳�ѭ������Ϊ�������滹����������Ԫ��
     //Ӧ�����������˳�
}//��ʵ֤������������for����4��ifЧ�ʲ���

int main(){
    ios_base::sync_with_stdio(0);
    //���������Թص���ͬ�����ӿ����ݶ���
    //���������ò�Ҫͬʱʹ��cin��scanf��
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
                if(mapp[i][j]=='J') {h0=i;l0=j;}//��¼�˵�λ��
            }
        }//�ڶ������ݵ�ʱ��Ͱѻ������У�ʡ����ȥ����
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
        }//�Ϸ��Ի�bfs����¼ʱ����Ϣ
        bfs(h0,l0);//����bfs���ҳ���
        if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}

