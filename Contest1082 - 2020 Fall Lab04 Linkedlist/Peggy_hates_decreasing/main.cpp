#include <iostream>

using namespace std;
void calculating_b(int *Linked_list, int *pre, int*next, int num, int *record);
void out(int *a , int length);
void output(int *a, int length , int *next);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int count = 0;
    cin >> count;
    while(count--){
    int num = 0;
    cin >> num;
    int temp = 1;

    int Linked_list[num+1];
    int pre[num+1];
    int next[num+1];
    int record[num+1];
    while(temp != num+1){
        cin >> Linked_list[temp];
        pre[temp] = temp-1;
        next[temp] = temp+1;
        temp++;
    }
    next[0] = 1;
    pre[0] = 0;
    calculating_b(Linked_list, pre, next, num, record);
    output(Linked_list , num , next);
    }
}

void calculating(int *Linked_list, int *pre, int *next, int num, int *record){
    int ptr = 0;
    int front_ptr = 0;

    while(ptr <= num  && next[ptr] < num){
        out(next,num+1);

        if(Linked_list[next[ptr]] > Linked_list[next[next[ptr]]]){
            front_ptr = ptr;
            ptr = next[next[ptr]];

            while(ptr <= num  && (Linked_list[ptr] < Linked_list[pre[ptr]] || Linked_list[ptr] > Linked_list[next[ptr]])){
                ptr = next[ptr];
            }

            if(Linked_list[ptr] > Linked_list[pre[ptr]]){
                next[front_ptr] = ptr;
                pre[ptr] = front_ptr;
            }

            if(ptr == num+1){
                break;
            }

            ptr = pre[pre[ptr]];

            if(ptr < 0){
                ptr = 0;
            }
        }
        else{
            ptr = next[ptr];
        }
    }
    out(next,num+1);
}


void calculating_b(int *Linked_list, int *pre, int *next, int num, int *record){
    int ptr = 1;
    int front_ptr = 0;

    while(1){
//        out(next,num+1);
        if(num ==1)
            break;
        if(ptr == num+1)
            break;
        if(Linked_list[ptr] > Linked_list[next[ptr]]){

            front_ptr = pre[ptr];

            while(ptr != num+1 && ((next[ptr] != num+1 &&Linked_list[ptr] > Linked_list[next[ptr]]) || Linked_list[ptr] < Linked_list[pre[ptr]] || (next[ptr] != num+1 && next[next[ptr]] != num+1 &&Linked_list[next[ptr]] > Linked_list[next[next[ptr]]]))){
                ptr = next[ptr];
            }

            next[front_ptr] = ptr;
            pre[ptr] = front_ptr;

            if(ptr == num+1 || next[ptr] == num+1){
                break;
            }
            ptr = pre[ptr];

        }
        else{
            ptr = next[ptr];
        }

    }
//    out(next,num+1);
}





void output(int *a, int length , int *next){
    int temp = 0;
    int tempa = 0;
    while((temp = next[temp]) != length+1){
//        if(a[temp] > tempa)
            cout << a[temp] << ' ';
        tempa = a[temp];
    }
    cout << endl;

}







void out(int *a , int length){
    int temp = 0;
    int tempa = 0;
    while(temp != length){

//       if(tempa < a[temp])
           cout << a[temp] << " ";

       tempa = a[temp];
       temp++;
    }
    cout << endl;
}

























