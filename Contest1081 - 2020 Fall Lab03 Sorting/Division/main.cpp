#include <iostream>


using namespace std;
void in(long long list[] , long long output[] , int num , int m);

void Qsort(long long list[],long long num);
void Merge(long long lista[] , long long listb[] , long long left ,long long Center ,long long right);
void Mergesort(long long list[]  ,long long temp[], long long left ,long long right);
long long* Start(long long list[],long long num);



int main()
{
    int num = 0;
    int m = 0;
    cin >> num >> m;
    int temp = 0;
    long long list[num] ;
    long long output[num];

    while(temp != num){
        cin >> list[temp];
        temp++;
    }
    in(list , output , num , m);
}


void in(long long list[] , long long output[] , int num , int m){
    int temp = num - 1;
    int ptr = num - 1;

    while(ptr != -1){

        temp = ptr;
        if(ptr != num-1){
            output[ptr] = output[ptr+1] + list[ptr];
        }
        else{
            output[ptr] = list[ptr];
        }
        ptr--;
    }

//    sort(output+1,output+num);
    Qsort(output , num-1);

    long long total = 0;
    int numptr = 0;
    while(numptr != m-1){
        total += output[num-1-numptr];
        numptr++;
    }
//    total += output[num-1];
    total += output[0];
    cout << total << endl;
}

void Qsort(long long list[], long long num){
    Start(list , num);
}

long long* Start(long long list[],long long num){
    long long temp[num];
    Mergesort(list,temp,1,num);
    return list;
}

void Mergesort(long long list[] , long long temp[],long long left ,long long right){

     long long Center = (left+right)/2;

     if(left < right){

        Mergesort(list ,temp, left ,Center);
        Mergesort(list ,temp, Center+1 ,right);
        Merge(list , temp ,left ,Center ,right);

     }

}

void Merge(long long list[] , long long temp[] , long long left ,long long Center ,long long right){
    long long Aptr = left;
    long long Bptr = Center+1;
    long long Cptr = left;
    while(Cptr != right+1){
        if(Aptr != Center+1 && Bptr != right +1){
            if(list[Aptr] < list[Bptr]){
                temp[Cptr] = list[Aptr];
                Cptr ++;
                Aptr ++;
            }
            else{
                temp[Cptr] = list[Bptr];
                Cptr ++;
                Bptr ++;
            }
       }

        else if(Aptr == Center +1){
            temp[Cptr] = list[Bptr];
            Cptr ++;
            Bptr ++;
        }
        else if(Bptr == right+1){
            temp[Cptr] = list[Aptr];
            Cptr ++;
            Aptr ++;
        }
    }
        int tempnum = left;
        while(tempnum != right+1){
            list[tempnum] = temp[tempnum];
//            cout<<list[tempnum]<<endl;
            tempnum++;
        }
}



