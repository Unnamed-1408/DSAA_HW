#include <iostream>

using namespace std;
void Delete(int ptr , int *pre , int *next);
long long calculate(int ptr , int *pre , int *next , int *num , int K , int length);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--){
    int length = 0, K=0;
    cin >> length >> K;
    int num[length+1];
    int Linked_list[length+1];
    int pre[length+1];
    int next[length+1];

    int temp = 1;
    while(temp != length+1){
        cin >> num[temp];//记录值
        Linked_list[num[temp]] = temp;//将输入顺序记录下来,Linked_list[]即为记录顺序，下标为值，pos即为链表
        pre[temp] = temp - 1;
        next[temp] = temp + 1;
        temp++;
    }

    temp = 1;
    long long ans = 0;
    while(temp != length+1){
        int ptr = Linked_list[temp]; //顺序
        ans += (calculate(ptr , pre , next , num , K , length)%1000000007) * (temp%1000000007);
        Delete(ptr , pre , next);
        temp++;
    }
    ans = ans % 1000000007;
    cout << ans << endl;
    }
    return 0;
}

long long calculate(int ptr , int *pre , int *next , int *num , int K , int length){
    int pre_ptr = 0;
    int next_ptr = 0;
    long long *A = new long long[K+1];
    long long B[K+1];
    long long *max_a = new long long[K+1];
    long long max_b[K+1];

    for(int i = 0; i<=K;i++){
        A[i] = 0;
        B[i] = 0;
        max_a[i] = 0;
        max_b[i] = 0;
    }

    int temp_a = ptr;
    int temp_b = ptr;

    while(pre_ptr <= K-1 && temp_a){

        A[++pre_ptr] = temp_a - pre[temp_a];

        if(num[temp_a] > max_a[pre_ptr-1]){
            max_a[pre_ptr] = num[temp_a];
        }
        else{
            max_a[pre_ptr] = max_a[pre_ptr-1];
        }

        temp_a = pre[temp_a];
    }

    while(next_ptr <= K-1 && temp_b <= length){
        B[++next_ptr] = next[temp_b] - temp_b;

        if(num[temp_b] > max_b[next_ptr-1]){
            max_b[next_ptr] = num[temp_b];
        }
        else{
            max_b[next_ptr] = max_b[next_ptr-1];
        }
//        cout << max_b[next_ptr] << endl;
        temp_b = next[temp_b];
    }

    long long ans = 0;
    for(int i = 1; i<= pre_ptr; i++){
        if(K-i+1 >= 1 && K-i+1 <= next_ptr ){
            int max = 0;
            max = (max_a[i] > max_b[K-i+1]) ? max_a[i] : max_b[K-i+1];
//            cout << max << endl;
            ans += A[i] * B[K-i+1] * max;
        }
    }
//    cout << ans << endl;
//    cout << endl;
    delete [] A,max_a;
    return ans;
}


void Delete(int ptr , int *pre , int *next){
    pre[next[ptr]] = pre[ptr];
    next[pre[ptr]] = next[ptr];
}

















