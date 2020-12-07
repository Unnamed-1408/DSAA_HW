#include <iostream>

using namespace std;

struct HeapStruct{
    int num = 0;
    int *heap = new int[300000];
};
void Insert_min(int X, HeapStruct* H);
void displace_top_min(int X, HeapStruct* H);
int Delete_min(HeapStruct* H);




int main()
{
    HeapStruct *a = new HeapStruct;
    int N = 0;
    cin >> N;
    while(N--){
        a->num = 0;
        int T = 0;
        cin >> T;
        for(int i = 0; i < T; i++){
            int b = 0;
            cin >> b;
            Insert_min(b,a);
        }
        long long total = 0;

        while(a->num != 1){
            int b = Delete_min(a) + Delete_min(a);
            total += b;
            Insert_min(b,a);
        }
        cout << total << endl;
    }
}

void Insert_min(int X, HeapStruct* H){
    int i;

    for( i = ++H->num; H->heap[i/2] > X; i/=2){
        H->heap[i] = H->heap[i/2];
    }
    H->heap[i] = X;
}

void displace_top_min(int X, HeapStruct* H){ //min
    int i;

    for(i = 1; H->heap[2 * i] < X || H->heap[2 * i + 1] < X; ){
        int abc = H->num;
        if(2*i > H->num && 2*i +1 > H->num){
            break;
        }
        if(2 * i + 1 <= H->num){
            if(H->heap[2 * i] < H->heap[2 * i +1]){
                H->heap[i] = H->heap[2 * i];
                i*=2;
            }
            else{
                H->heap[i] = H->heap[2 * i +1];
                i = 2*i +1;
            }
        }
        else{
            H->heap[i] = H->heap[2*i];
            i*=2;
        }
        if(i > H->num){
            break;
        }
    }
    if(H->num == 0){
        H->num++;
    }
    H->heap[i] = X;
/*
    if(H->heap[2 * i] < H->heap[2 * i +1]){
        H->heap[2 * i] = X;
    }
    else{
        H->heap[2 * i +1] = X;
    }
*/
}

int Delete_min(HeapStruct* H){
    int i , Child ;
    int min , last;

    min = H->heap[1];
    last = H->heap[H->num--];

    for(i = 1; i*2 <=H->num; i = Child){

        Child = i*2;

        if(Child != H->num && H->heap[Child +1] < H->heap[Child])
            Child++;
        if(last > H->heap[Child])
            H->heap[i] = H->heap[Child];
        else {
            break;
        }
    }
    H->heap[ i ] = last;
//    cout << min << endl;
    return min;
}
