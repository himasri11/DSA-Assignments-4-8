#include <iostream>
using namespace std;

int heapArr[1000];
int sz = 0;

void insertPQ(int x){
    heapArr[sz] = x;
    int i = sz;
    sz++;
    while(i>0){
        int p = (i-1)/2;
        if(heapArr[p] < heapArr[i]){
            int t = heapArr[p];
            heapArr[p] = heapArr[i];
            heapArr[i] = t;
            i = p;
        } else break;
    }
}

int getMax(){
    if(sz==0) return -1;
    return heapArr[0];
}

int deleteMax(){
    if(sz==0) return -1;
    int mx = heapArr[0];
    heapArr[0] = heapArr[sz-1];
    sz--;

    int i = 0;
    while(true){
        int l = 2*i+1;
        int r = 2*i+2;
        int big = i;

        if(l<sz && heapArr[l] > heapArr[big]) big = l;
        if(r<sz && heapArr[r] > heapArr[big]) big = r;

        if(big != i){
            int t = heapArr[i];
            heapArr[i] = heapArr[big];
            heapArr[big] = t;
            i = big;
        } else break;
    }
    return mx;
}

int main(){
    int n,x;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;
        insertPQ(x);
    }

    cout << getMax() << endl;
    cout << deleteMax() << endl;
    cout << getMax() << endl;
}
