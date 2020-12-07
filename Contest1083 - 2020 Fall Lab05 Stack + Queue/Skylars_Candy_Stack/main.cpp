#include <iostream>
#include <string>
using namespace std;

struct stack {
    int ptr = -1;
    int* sta = new int[3 * 100000];
};

void push(stack* a, int b);
void pop(stack* a);
int* length = new int[3 * 100000+1];


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    stack* A = new stack[100];
    int max = 0;
    string temp = "";
    cin >> temp;

    while (temp != "nsdd") {

        if (temp == "put-in") {
            int in_to = 0;
            cin >> in_to;
            length[in_to]++;
            push(&A[length[in_to]],in_to);

            if (length[in_to] > max){
                max = length[in_to];
            }

        }

        else if(temp == "eat" && max == 0){
            printf("pa\n");
        }

        else if (temp == "eat") {
            pop(&A[max]);
            if (A[max].ptr == -1) {
                max--;
            }
        }

        cin >> temp;
    }
}

void push(stack* a, int b) {
    a->sta[++a->ptr] = b;
}

void pop(stack* a) {
    length[a->sta[a->ptr]]--;
    printf("%d\n",a->sta[a->ptr]);
    a->ptr--;
}
