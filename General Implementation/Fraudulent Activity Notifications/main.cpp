#include<iostream>
using namespace std;
int a[200000],p[250],n,d;
int median(){
    int sum=0,sum2=0;for(int i=0;i<250;i++)sum+=p[i];
    for(int i=0;i<250;i++){
        sum2+=p[i];
        if(sum2*2>sum){return i*2;}
        if(sum2*2==sum){
            for(int j=i+1;j<250;j++){
                sum2+=p[j];
                if(sum2*2>sum){return i+j;}
            }
        }
    }
    return 250;
}
int main(){
    cin>>n>>d;int cnt=0;for(int i=0;i<n;i++){cin>>a[i];if(i<d)p[a[i]]++;}
    for(int i=d;i<n;i++){
        int W=median();//cout<<W<<endl;
        if(W<=a[i])cnt++;
        p[a[i]]++;p[a[i-d]]--;
    }
    cout<<cnt<<endl;
    return 0;
}
