#include <iostream>

using namespace std;

struct Node{
    int num;
    Node *Next;
};

int main()
{
    int count = 0;
    cin >> count;
    while(count != 0){
    int much = 0;
    int gap = 0;
    cin >> much >> gap;
    int temp = 0;
    Node *last;
    while(temp != much){
        Node *p = new Node;
        p->num = temp+1;
        if(temp == 0){
            (*p).Next = p;
        }
        else {
            (*p).Next = (*last).Next;
            (*last).Next = p;
        }
        last = p;
        temp++;
    }

    last=last->Next;
//    cout << "out";
    int origin_gap = gap-1;
    gap = gap-1;

    while(much >0){
//        if(origin_gap % much != 0){
//            gap = origin_gap % much;
//            gap--;
//        }
        if(gap != 0){
        int count = 0;
        while (count < gap-1) {
            last = last->Next;
            count++;
        }
        cout << last->Next->num << " ";
//        int tempa = last->Next->num;
        last->Next = last->Next->Next;
        last = last->Next;
        }
        else{
            cout << last->num << " ";
            last = last->Next;
        }
        much--;
    }
    cout << endl;
    count--;
    }
}
