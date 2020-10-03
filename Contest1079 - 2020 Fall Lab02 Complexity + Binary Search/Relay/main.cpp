#include <iostream>

using namespace std;
int find(int left , int right);
bool check(int gap[] , int n , int diff , int Center);
void start(int gap[] , int n , int m , int L);

int main()
{
    int n = 0;  //the number of trees
    int m = 0;  //the number of freshmen
    int L = 0;  //the position of the finish line.
    cin >> n >> m >> L;
    int nums[n+1];
    int temp = 0 ;
    while(temp != n){
        cin >> nums[temp];

        if(temp == n-1){
            nums[temp+1] = L;
        }

        temp++;
    }

    int gap[n];
    temp = 0;

    while(temp != n){
        if(temp != n-1){
            gap[temp] = nums[temp+1] - nums[temp];
//            cout<<gap[temp];
        }
        else{
            gap[temp] = L - nums[temp];
//            cout<<gap[temp];
        }
        temp++;
    }
    start(nums , n+1 , m , L);

}

int find(int left , int right){
    int Center = (left + right+1)/2;
    return Center;
}


bool check(int nums[] , int n , int diff , int Center){
    int temp = 1;
    int tempdiff = 0;
    int last = 0;
    while(temp != n){

        if(nums[temp] -last < Center){
            tempdiff++;
        }
        else{
            last = nums[temp-1];
        }
        temp++;
    }
    if(tempdiff <= diff){
        return true;
    }
    else{
        return false;
    }
}

void start(int nums[] , int n , int m , int L){
    int left = 0;
    int right = L;
    int Max = 0;
    while(left <= right){
        Max = find(left , right);
        if(check(nums , n , n-m-1 , Max)){
            left = Max;
        }
        else{
            right = Max - 1;
        }
    }
    cout<<left;
}








