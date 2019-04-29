#include<iostream>
#include<queue>
using namespace std;
int n;
long long bfs(){
     queue<long long> p;
     while(!p.empty()) p.pop();
     p.push(1);//把1放入队列
     while(1){
        long long sum=p.front();
        if(sum%n==0) return sum;
        p.pop();
        p.push(10*sum);
        p.push(10*sum+1);
        //上两句把所有包含1和0的各个十进制数全部放到队列里面了
     }
}
int main(){
    while(cin>>n,n) cout<<bfs()<<endl;
    return 0;
}
