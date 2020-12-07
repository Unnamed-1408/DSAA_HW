#include <iostream>
#include <math.h>

struct HeapStruct{
    long long num = 0;
    long long *heap = new long long[1000005];
};

struct HeapStruct_Min{
    long long num = 0;
    long long *heap = new long long[1005];
};

using namespace std;
void Insert_min(long long X, HeapStruct_Min* H);
long long Delete_min(HeapStruct_Min* H);
void Insert_max(long long X, HeapStruct* H);
long long Delete_max(HeapStruct* H);
long long sum_of_the_digits(long long b);

int main()
{
    long long t = 0;
    long long k = 0;
    long long s = 0;
    cin >> t >> k >> s;
    HeapStruct_Min *min = new HeapStruct_Min;
    HeapStruct *max = new HeapStruct;
    max->heap[0] = 9000000000000000000;
    long long tik = 1;
    for(long long i = 0; i < floor((double)t/(double)100); i++){
        long long tik_2 = 0;
        for(tik_2 = 0; tik_2 <100 && tik + tik_2 <= t; tik_2++){
            long long temp = tik + tik_2 + s + sum_of_the_digits(tik + tik_2 + s);
//            cout << temp << endl;
            if(min->num != k){
                Insert_min(temp,min);
            }
            else{
                Insert_max(temp,max);
                while(min->heap[1] < max->heap[1]){
                    long long tempa = 0;
                    tempa = Delete_min(min);
                    Insert_min(Delete_max(max),min);
                    Insert_max(tempa, max);
                }
            }
//            cout << min->heap[1] << " ";
        }
        tik += 100;
        s = min->heap[1];
//        cout << min->heap[1] << " ";
        printf("%lld ", min->heap[1]);
//        min->num = 0;
//        max->num = 0;
    }
}

long long sum_of_the_digits(long long b){
//    cout << b << endl;
    string a = to_string(b);
    long long total = 0;
    for(long long i = 0; i < a.length(); i++){
        total += a.at(i) - '0';
    }
    return total;
}


void Insert_min(long long X, HeapStruct_Min* H){
    long long i;

    for( i = ++H->num; H->heap[i/2] > X; i/=2){
        H->heap[i] = H->heap[i/2];
    }
    H->heap[i] = X;
}


long long Delete_min(HeapStruct_Min* H){
    long long i , Child ;
    long long min , last;

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


void Insert_max(long long X, HeapStruct* H){
    long long i;

    for( i = ++H->num; H->heap[i/2] < X; i/=2){
        H->heap[i] = H->heap[i/2];
//        cout << i;
    }
    H->heap[i] = X;
}


long long Delete_max(HeapStruct* H){
    long long i , Child ;
    long long max , last;

    max = H->heap[1];
    last = H->heap[H->num--];

    for(i = 1; i*2 <=H->num; i = Child){

        Child = i*2;

        if(Child != H->num && H->heap[Child +1] > H->heap[Child])
            Child++;
        if(last < H->heap[Child])
            H->heap[i] = H->heap[Child];
        else {
            break;
        }
    }
    H->heap[ i ] = last;
    return max;
}

