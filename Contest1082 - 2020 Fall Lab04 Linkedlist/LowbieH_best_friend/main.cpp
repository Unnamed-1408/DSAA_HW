#include <iostream>

struct HeapStruct{
    int num = 0;
    int *heap = new int[300000];
};

using namespace std;
void Insert_min(int X, HeapStruct* H);
int Delete_min(HeapStruct* H);
void Insert_max(int X, HeapStruct* H);
int Delete_max(HeapStruct* H);
void displace_top_min(int X, HeapStruct* H);
void displace_top_max(int X, HeapStruct* H);



int main()
{
    int count_num = 0;
    cin >> count_num;
    while(count_num != 0){
    HeapStruct *Down_max = new HeapStruct;
    HeapStruct *Up_min = new HeapStruct;
    Down_max->heap[0] = 300001;
    int count = 0;
    cin >> count;
    int temp = 0;
    while(temp != count){

        int temp_int = 0;
        cin >> temp_int;

        if(temp % 2 == 0){
//            Up_min->num++;
            Insert_min(temp_int,Up_min);
            temp_int = Up_min->heap[1];
//            cout << Down_max->heap[1] << endl;
            displace_top_max(temp_int,Down_max);
            cout << Down_max->heap[1] << ' ';
        }
        else{
            Insert_max(temp_int,Down_max);
            temp_int = Down_max->heap[1];
            displace_top_min(temp_int,Up_min);
        }

/*        for(int b = 0;b < 6;b++){
            cout << Down_max->heap[b] <<' ';
        }
        cout << "num" << Down_max->num;
        cout << endl;
        for(int b = 0; b<6;b++){
            cout << Up_min->heap[b] << ' ';
        }
        cout << "num" << Up_min->num;
        cout << endl;*/
//        cout << Down_max->num;
//            cout << Down_max->heap[1] << endl;

        /*
        Insert_min(temp_int , Small);

        if(Small->num > Large->num+1){
            Insert_max(Delete_min(Small) , Large);
        }

        while(Small->heap[1] < Large->heap[1]){
            int temp_a,temp_b;
            temp_a = Delete_min(Small);
            temp_b = Delete_max(Large);
            Insert_min(temp_b,Small);
            Insert_max(temp_a,Large);
        }

        if(temp % 2 == 0){
            cout << Small->heap[1] << " ";
        }
        temp++;*/
    temp++;

    }
        cout << endl;
        delete  Up_min,Down_max;
        count_num--;
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

void displace_top_max(int X, HeapStruct* H){ //min
    int i;

    for(i = 1; H->heap[2 * i] > X || H->heap[2 * i + 1] > X; ){
        if(2*i > H->num && 2*i +1> H->num){
            break;
        }
        if(2 * i + 1 <= H->num){
            if(H->heap[2 * i] > H->heap[2 * i +1]){
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


void Insert_max(int X, HeapStruct* H){
    int i;

    for( i = ++H->num; H->heap[i/2] < X; i/=2){
        H->heap[i] = H->heap[i/2];
//        cout << i;
    }
    H->heap[i] = X;
}


int Delete_max(HeapStruct* H){
    int i , Child ;
    int max , last;

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

