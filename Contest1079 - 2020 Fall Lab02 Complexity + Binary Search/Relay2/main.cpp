#include <iostream>

using namespace std;
int find(int left , int right);
bool check(int nums[] , int Center , int nadd , int many );
void start(int nums[] , int nadd , int L , int m);

int main()
{
    int n = 0;
    int m = 0;
    int L = 0;
    cin >> n >> m >> L;
    int nums[n+1];
    int temp = 0;

    while(temp != n){
        cin >> nums[temp];
        if(temp == n-1){
            nums[temp+1] = L;
        }
        temp++;
    }
    start(nums , n+1 , L , m);
}

int find(int left , int right){
    int Center = (left + right)/2;
    return Center;
}

bool check(int nums[] , int Center , int nadd , int many ){
    int ptr = 0;
    int last = 0;
    int total = 0;
    int man = 0;
    while(ptr != nadd){
        total = nums[ptr] - nums[last];

        if(ptr >= 1){
            if(nums[ptr] - nums[ptr-1] > Center){
                return false;
            }
        }

        if(total > Center){
            total = 0;
            last = ptr-1;
            man++;//ren shu up
            ptr--;
        }

        ptr++;
    }
    man++;
    if(man <= many){
        return true;//ren shu he ge
    }
    else{
        return false;
    }
}

void start(int nums[] , int nadd , int L ,int m){
    int left = 0;
    int right = L;
    int Max = 0;

    while(left <=right){
        Max = find(left , right);
        if(check(nums , Max , nadd  , m)){
            right = Max - 1;
        }
        else{
            left = Max + 1;
        }

    }
    cout<<left<<endl;

}















