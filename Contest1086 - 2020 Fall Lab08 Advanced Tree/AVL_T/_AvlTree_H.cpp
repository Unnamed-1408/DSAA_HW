#include <iostream>
#include "_AvlTree_H.h"

using namespace std;

struct AvlNode{
    int Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
    bool exist = true;   //惰性删除
};

AvlTree Insert(int X, AvlTree T){
    if(T == nullptr){
        T = new AvlNode;
        T->Element = X;
        T->Height = 0;
        T->Left = T->Right = nullptr;
    }
    else if( X < T->Element){
        T->Left = Insert(X, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2){
            if(X < T->Left->Element){
                T = SingleRoateWithLeft( T );
            }
            else {
                T = DoubleRoateWithLeft( T );
            }
        }
    }
    else if(X > T->Element){
        T->Right = Insert(X, T->Right);
        if(Height(T->Right) - Height(T->Left) == 2){
            if(X > T->Right->Element){
                T = SingleRoateWithRight( T );
            }
            else {
                T = DoubleRoateWithRight( T );
            }
        }
    }

    T->Height = max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}




static Position  SingleRoateWithLeft(Position K2){
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = max(Height(K2->Left), Height(K2->Right)) +1;

    K1->Height = max(Height(K1->Left), Height(K1->Right)) +1;

    return K1;
}

static Position DoubleRoateWithLeft(Position K3){
    K3->Left = SingleRoateWithRight(K3->Left);
    return SingleRoateWithLeft(K3);
}

static Position  SingleRoateWithRight(Position K2){
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = max(Height(K2->Left), Height(K2->Right)) +1;

    K1->Height = max(Height(K1->Left), Height(K1->Right)) +1;

    return K1;
}

static Position DoubleRoateWithRight(Position K3){
    K3->Right = SingleRoateWithLeft(K3->Right);
    return SingleRoateWithRight(K3);
}

int Height(AvlTree Tree) { //得到树高
    if (!Tree)return 0;
    return max(Height(Tree->Left), Height(Tree->Right)) + 1;
}
