#include <iostream>

using namespace std;
int *A = new int[20000000];
int front_ptr = 0;
int back_ptr = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--){
        char a;
        cin >> a;
        if(a == 'E'){
            cin >> A[front_ptr];
            front_ptr++;
        }
        else if(a == 'D'){
            if(front_ptr > back_ptr)
                back_ptr++;
        }
        else if(a == 'A'){
            printf("%d\n",A[back_ptr]);
        }
    }

    while(back_ptr < front_ptr){
        printf("%d ",A[back_ptr]);
        back_ptr++;
    }
}

/*
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
struct queue
{

    int *data = new int[20000000];
    int rear, front;
    void initial()
    {
        rear = 0;
        front = 0;
        memset(data, 0, 20000000);
    }
    void enqueue(int x)
    {
        if (rear >= 20000000)
        {
            return;
        }
        else
        {
            data[rear] = x;
            rear++;
        }
    }
    void dequeue()
    {
        if (rear == front)
        {
            return;
        }
        else
        {
            front++;
        }
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int fron()
    {

        return data[front];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    queue in;
    in.initial();
    for (int i = 0; i < n; i++)
    {
        char operation;
        cin>>operation;
        if (operation == 'E')
        {
            int x;
           cin>>x;
            in.enqueue(x);
        }
        else if (operation == 'D')
        {
            in.dequeue();
        }
        else if (operation == 'A')
        {
            printf("%d\n", in.fron());
        }
    }

        while (in.front != in.rear)
        {
            printf("%d ", in.fron());
            in.dequeue();
        }


    return 0;
}
 */
