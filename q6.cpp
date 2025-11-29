#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class PriorityQueue{
    vector<T> h; bool isMax;
    bool compare(const T& a,const T& b) const { return isMax? a>b : a<b; }
    void heapifyUp(int i){
        while(i>0){
            int p=(i-1)/2;
            if(compare(h[i],h[p])){ swap(h[i],h[p]); i=p; } else break;
        }
    }
    void heapifyDown(int i){
        int n=h.size();
        while(true){
            int l=2*i+1, r=2*i+2, ext=i;
            if(l<n && compare(h[l],h[ext])) ext=l;
            if(r<n && compare(h[r],h[ext])) ext=r;
            if(ext==i) break;
            swap(h[i],h[ext]); i=ext;
        }
    }
public:
    PriorityQueue(bool maxHeap=true):isMax(maxHeap){}
    void push(const T& val){ h.push_back(val); heapifyUp(h.size()-1); }
    T top() const{ return h.front(); }
    void pop(){ h[0]=h.back(); h.pop_back(); if(!h.empty()) heapifyDown(0); }
    bool empty() const{ return h.empty(); }
    int size() const{ return h.size(); }
};
int main(){
    PriorityQueue<int> pq(true);
    pq.push(5); pq.push(2); pq.push(8); pq.push(4);
    while(!pq.empty()){ cout<<pq.top()<<" "; pq.pop(); }
    cout<<endl;
    PriorityQueue<int> pq2(false);
    pq2.push(5); pq2.push(2); pq2.push(8); pq2.push(4);
    while(!pq2.empty()){ cout<<pq2.top()<<" "; pq2.pop(); }
}
