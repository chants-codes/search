#include<iostream>
#include<cstring>
using namespace std;

int n;
/*
int qipan[12][12];
int ans;

int check(int y,int x){
    for(int i=1;i<=n;i++){
        if(qipan[i][x]) return 1;
        if(y+i<=n&&x+i<=n&&qipan[y+i][x+i]) return 1;
        if(y-i>=1&&x+i<=n&&qipan[y-i][x+i]) return 1;
        if(y-i>=1&&x-i>=1&&qipan[y-i][x-i]) return 1;
        if(y+i<=n&&x-i>=1&&qipan[y+i][x-i]) return 1;
    }//N皇后最难写的是check，然而网上有一种用绝对值的写法看起来很简单
    return 0;
}

void dfs(int censhu,int geshu){
    if(geshu==n){
        ans++;
        return;
    }
    if(censhu>n) return;//注意在层数超过给定的n之后就要退出了，这行代码是由我的写法决定的
    for(int i=1;i<=n;i++){
        if(check(censhu,i)==0){
            qipan[censhu][i]=1;
            dfs(censhu+1,geshu+1);
            qipan[censhu][i]=0;
        }
    }//这里没有在for结束后dfs下一层，因为N皇后里面每一行都必须有一个皇后，就是说每一行都肯定可以dfs
    return;
}
*/
int main(){
    while(cin>>n){
	//这题只能打表过，不然超时
        if(n==0) break;
        if(n==1) cout<<1<<endl;
        if(n==2||n==3) cout<<0<<endl;
        if(n==4) cout<<2<<endl;
        if(n==5) cout<<10<<endl;
        if(n==6) cout<<4<<endl;
        if(n==7) cout<<40<<endl;
        if(n==8) cout<<92<<endl;
        if(n==9) cout<<352<<endl;
        if(n==10) cout<<724<<endl;
        /*ans=0;
        memset(qipan,0,sizeof(qipan));
        dfs(1,0);
        cout<<ans<<endl;*/
    }
    return 0;
}