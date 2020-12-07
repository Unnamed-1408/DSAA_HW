#include <iostream>
#include <math.h>

struct HeapStruct{
    int num = 0;
    int *heap = new int[300000]();
};
void Insert_max(int X, HeapStruct* H);
int search(int index, HeapStruct* H);
using namespace std;

int *juan = new int[100005]();

int main()
{	int T = 0;
    scanf("%d",&T);
    while(T--){
        int n = 0;
        HeapStruct *a = new HeapStruct;
        scanf("%d\n" , &n);
        a->heap[0] = 100005;
        juan[100005] = 1000000005;
        for(int i = 1; i <= n ; i++){
            scanf("%d", &juan[i]);
            Insert_max(i , a);
        }
        int to_search = 0;
        scanf("%d", &to_search);
        int now = search(to_search, a);
        printf("%d %d\n",(int)log2(now) + 1,now - (int)pow(2, (int)log2(now)) + 1);
        delete a;
        delete juan;
        juan =  new int[100005]();
    }
}

void Insert_max(int X, HeapStruct* H){
    int i;

    for( i = ++H->num; juan[H->heap[i/2]] < juan[X]; i/=2){
        H->heap[i] = H->heap[i/2];
    }
    H->heap[i] = X;
}

int search(int index, HeapStruct* H){
    int i = 1;

    while(1){

        if(H->heap[i] == index){
            return i;
        }
        i++;
    }

}
//int Delete_max(HeapStruct* H){
//    int i , Child ;
//    int max , last;

//    max = H->heap[1];
//    last = H->heap[H->num--];

//    for(i = 1; i*2 <=H->num; i = Child){

//        Child = i*2;

//        if(Child != H->num && H->heap[Child +1] > H->heap[Child])
//            Child++;
//        if(last < H->heap[Child])
//            H->heap[i] = H->heap[Child];
//        else {
//            break;
//        }
//    }
//    H->heap[ i ] = last;
//    return max;
//}
