#include<cstring>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

int a,b,c;
int v[111][111];

struct node{
    int x;
    int y;
    int step;
    string s;
};

int bfs(){
    queue<node>Q;
    int l=1;
    node p,q;
    p.x=0;
    p.y=0;
    p.step=0;
    p.s+='0';
    Q.push(p);
    v[0][0]=1;
    while(!Q.empty()){
        p=Q.front();
        Q.pop();
        //printf("%d %d  %d  ",p.x,p.y,p.step);
        //cout<<p.s<<endl;
        if(p.x==c||p.y==c){//�ж���ȷ����ʼ���
            cout<<p.step<<endl;
            for(int i=0; p.s[i]!='\0'; i++){//�ڽṹ�����棬ʹ���ַ���������·��
                if(p.s[i]=='1') printf("FILL(1)\n");//һһ��Ӧ�������ע��forѭ���ķ���
                if(p.s[i]=='2') printf("DROP(1)\n");
                if(p.s[i]=='3') printf("POUR(1,2)\n");
                if(p.s[i]=='4') printf("FILL(2)\n");
                if(p.s[i]=='5') printf("DROP(2)\n");
                if(p.s[i]=='6') printf("POUR(2,1)\n");
            }
            return 1;
        }
        else{
            int xx=a,yy=b;
            q.x=p.x+(xx-p.x);//��1����,��Ϊ1
            q.y=p.y;
            q.s=p.s+'1';
            q.step=p.step+1;
            if(v[q.x][q.y]==0){
                v[q.x][q.y]=1;
                Q.push(q);
            }
            q.x=0;//��1����,��Ϊ2
            q.y=p.y;
            q.s=p.s+'2';
            q.step=p.step+1;
            if(v[q.x][q.y]==0){
                v[q.x][q.y]=1;
                Q.push(q);
            }
            if(p.x>=(yy-p.y)){//��1����2,��Ϊ3
                q.x=p.x-(yy-p.y);
                q.y=p.y+(yy-p.y);
                q.step=p.step+1;
                q.s=p.s+'3';
                if(v[q.x][q.y]==0){
                    v[q.x][q.y]=1;
                    Q.push(q);
                }
            }
            if(p.x<yy-p.y){//��1����2,��Ϊ3
                q.x=0;
                q.y=p.y+p.x;
                q.step=p.step+1;
                q.s=p.s+'3';
                if(v[q.x][q.y]==0){
                    v[q.x][q.y]=1;
                    Q.push(q);
                }
            }
            q.x=p.x;//��2����,��Ϊ4
            q.y=p.y+(yy-p.y);
            q.s=p.s+'4';
            q.step=p.step+1;
            if(v[q.x][q.y]==0){
                v[q.x][q.y]=1;
                Q.push(q);
            }
            q.x=p.x;//��2����,��Ϊ5
            q.y=0;
            q.s=p.s+'5';
            q.step=p.step+1;
            if(v[q.x][q.y]==0){
                v[q.x][q.y]=1;
                Q.push(q);
            }
            if(p.y>=(xx-p.x)){//��2����1,��Ϊ6
                q.x=p.x+(xx-p.x);
                q.y=p.y-(xx-p.x);
                q.s=p.s+'6';
                q.step=p.step+1;
                if(v[q.x][q.y]==0){
                    v[q.x][q.y]=1;
                    Q.push(q);
                }
            }
            else if(p.y<xx-p.x){
                q.x=p.x+p.y;
                q.y=0;
                q.s=p.s+'6';
                q.step=p.step+1;
                if(v[q.x][q.y]==0){
                    v[q.x][q.y]=1;
                    Q.push(q);
                }
            }
        }
    }
    return 0;
}

int main(){
    while(~scanf("%d %d %d",&a,&b,&c)){
        memset(v,0,sizeof(v));
        int sum=bfs();
        if(sum==0) printf("impossible\n");
    }
    return 0;
}
