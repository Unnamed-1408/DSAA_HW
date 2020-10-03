#include <iostream>

using namespace std;
inline int find(int num[] , int left, int right , int target);
inline long long findall(int num[] , int left , int right , int found);
long long start(int num[] , int n , int S);

int main()
{
    int n = 0;
    int S = 0;
    cin >> n >> S;

    int num[n];
    int temp = 0;

    while(temp != n){
         cin >>num[temp] ;
        temp++;
    }

    cout<<start(num , n ,S)<<endl;

}

inline int find(int num[] , int left, int right , int target){

    int Center = (left + right)/2;

    if(left == right){
        if(num[left] != target){
            return -1;
        }
        else{
            return left;
        }
    }
    if(num[Center] > target){
        return find(num , left ,Center,target);
    }
    if(num[Center] < target){
        return find(num , Center+1 , right , target);
    }
    if(num[Center] == target){
        return Center;
    }
}

inline long long findall(int num[] , int left , int right , int found){
    long long temp = 1;
    int ptr = 1;
    while(num[found+ptr] == num[found] && found+ptr != right){
        temp++;
        ptr++;
    }
    ptr = 1;
    while(num[found-ptr] == num[found] && found-ptr != left){
        temp++;
        ptr++;
    }
    return temp;
}

long long start(int num[] , int n , int S){

    int Aptr = 0;
    int Bptr = n-1;
    long long total = 0;

    while(Aptr != n){

            Bptr = n-1;
            if(3*num[Aptr] > S)
                break;

        while(S - num[Aptr] - num[Bptr] <= num[Bptr] && Bptr - Aptr >= 2){

            if(num[Aptr] == num[Bptr] && 3*num[Aptr] == S){
                total += (Bptr - Aptr - 1)*(Bptr - Aptr)/2;
                break;
            }

            if(3*num[Bptr] < S){
                break;
            }

             long long now = find(num , Aptr+1 , Bptr-1 , S-num[Aptr]-num[Bptr]);
             if(now == -1){
                 Bptr--;
             }
             else{
                 total+=findall(num , Aptr , Bptr , now);
//                 cout<<total;
                 Bptr--;
             }
        }
        Aptr++;
    }
    return total;
}








