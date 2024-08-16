#include<iostream>
using namespace std;
int main(){
    int n;
    while (cin>>n){
        int arr[3005];
        bool flg=0, check[3005] = {0};
        cin>>arr[0];
        for(int i=1; i<n; i++){
            cin>>arr[i];
            check[(int)abs(arr[i]-arr[i-1])] = 1;
        }
        for(int i=1; i<n; i++)
            if(!check[i]){
                flg=1;
                break;
            }
        if(n==1 || flg==0) cout<<"Jolly\n";
        else cout<<"Not jolly\n";
    }
    return 0;
}