#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, arr[1005]=  {0}, sum[1005] = {0};
    cin>>n ;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    sort(arr+1, arr+n+1);
    for(int i=1; i<=n; i++)
        sum[i] = sum[i-1]+arr[i];

    int ans=0;
    for(int i=1; i<=n ; i++)
        ans += sum[i];
    cout<<ans;
    return 0;
}