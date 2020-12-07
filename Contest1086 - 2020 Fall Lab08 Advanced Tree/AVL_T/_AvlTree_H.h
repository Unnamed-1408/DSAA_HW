#ifndef _AVLTREE_H_H
#define _AVLTREE_H_H

struct AvlNode;
typedef struct AvlNode *Position ;
typedef struct AvlNode *AvlTree ;

AvlTree MakeEmpty( AvlTree T);
Position Find(int X, AvlTree T);
Position FindMin( AvlTree T);
Position FIndMax( AvlTree T);
AvlTree Insert( int X, AvlTree T);
AvlTree Delete( int X, AvlTree T);
int Retrieve( Position P );
static Position SingleRoateWithLeft(Position K2);
static Position DoubleRoateWithLeft(Position K3);
static Position SingleRoateWithRight(Position K2);
static Position DoubleRoateWithRight(Position K3);
int Height(AvlTree Tree);

#endif // _AVLTREE_H_H
