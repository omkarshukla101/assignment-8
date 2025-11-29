#include <iostream>
using namespace std;
void heapify(int a[], int n, int i, bool asc){
    int e=i,l=2*i+1,r=2*i+2;
    if(asc){
        if(l<n && a[l]>a[e]) e=l;
        if(r<n && a[r]>a[e]) e=r;
    } else {
        if(l<n && a[l]<a[e]) e=l;
        if(r<n && a[r]<a[e]) e=r;
    }
    if(e!=i){
        int t=a[i];
        a[i]=a[e];
        a[e]=t;
        heapify(a,n,e,asc);
    }
}
void heapSort(int a[], int n, bool asc){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i,asc);
    for(int i=n-1;i>0;i--){
        int t=a[0];
        a[0]=a[i];
        a[i]=t;
        heapify(a,i,0,asc);
    }
}
int main(){
    int a[]={5,2,8,4,1,7};
    int n=sizeof(a)/sizeof(a[0]);
    heapSort(a,n,true);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    int b[]={5,2,8,4,1,7};
    heapSort(b,n,false);
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
}
