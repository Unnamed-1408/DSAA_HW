#include <iostream>
#include <algorithm>

using namespace std;
void in(long long list[] , long long output[] , int num , int m);

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

    sort(output+1,output+num);

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
