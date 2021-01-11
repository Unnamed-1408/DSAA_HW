#include <iostream>

#pragma GCC optimize(2)

using namespace std;

struct Node{
    int value;
    Node *pre = nullptr;
    Node *Next = nullptr;
};

Node *cursor;
int *dp = new int[1000001];
int *sum = new int[1000001];

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    Node *head = new Node;
    cursor = head;
    int n = 0;
    cin >> n;
    while(n--){
        char tmp ;
        cin >> tmp;
        if(tmp == 'I'){
            Node *tmp_a = new Node;
            if(cursor->Next)
                cursor->Next->pre = tmp_a;
            tmp_a->pre = cursor;
            tmp_a->Next = cursor->Next;
            cursor->Next = tmp_a;
            int ab;
            cin >> ab;
            tmp_a->value = ab;
            cursor = cursor->Next;
        }
        if(tmp == 'L'){
            if(cursor->pre){
                cursor = cursor->pre;
            }
        }
        if(tmp == 'R'){
            if(cursor->Next){
                cursor = cursor->Next;
            }
        }
        if(tmp == 'D'){
            Node *temp;
            temp = cursor->Next;
            if(temp && cursor->pre){
                cursor = cursor->pre;
                if(temp != nullptr)
                    temp->pre = cursor;
                delete cursor->Next;
                cursor->Next = temp;
            }
            else if(temp == nullptr && cursor->pre != nullptr){
                cursor = cursor->pre;
                delete cursor->Next;
                cursor->Next = nullptr;
            }
        }
        if(tmp == 'Q'){
            int move;
            cin >> move;
            int max = 0;
            int go = 0;
            Node *temp = head->Next;
            for(int i = 0; i < move; i++){
                go += temp->value;
                temp = temp->Next;
                max = (max > go) ? max : go;
            }
            cout << max << endl;
        }
//        Node *abc = head->Next;
//        while(abc != nullptr){
//            cout << abc->value << " ";
//            abc = abc->Next;
//        }
//        cout << endl;
    }
    return 0;
}
