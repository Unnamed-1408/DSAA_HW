#include <iostream>
#include <algorithm>

using namespace std;
bool check(long long list[] , long long n , long long mid , long long K , long long M);
void find(long long list[] , long long left , long long Max , long long n , long long K , long long M);

int main()
{
    int count = 0;
    cin >> count;

    while(count !=0){
    long long n = 0;
    long long K = 0;
    long long M = 0;
    cin >> n >> K >> M;
    long long temp = 0;
    long long Max = 0;
    long long list[n];

    while(temp != n){
        cin >> list[temp];

        if(Max < list[temp]){
            Max = list[temp];
        }
        temp++;
    }
    find(list , 0 , Max , n , K, M);

    count--;
    }
}

void find(long long list[] , long long left , long long Max , long long n , long long K , long long M){

    long long right = Max;

    while(left < right){

        long long Center = (left + right+1)/2;

        if(check(list , n , Center , K , M)){
            left = Center;
        }//small
        else{
            right = Center-1;
        }
    }
    cout << left << endl;
}

bool check(long long list[] , long long n , long long mid , long long K , long long M){
    long long Aptr = 0;
    long long Bptr = 0;
    long long count = 0;
    long long sum = 0;

    while(Aptr <= n){

        while(Bptr <=n && count < K){
            if(list[Bptr] >=mid){
                count++;
            }
            Bptr++;
        }

        if(count == K){
            sum+=n-Bptr+1;
        }

        if(list[Aptr] >= mid){
            count--;
        }
        Aptr++;
    }

    return (sum>=M);
}











