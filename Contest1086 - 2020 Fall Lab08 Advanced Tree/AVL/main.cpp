#include <iostream>

using namespace std;

struct AVLNode {
    int value;
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    int height = 0;       //树高
    int subTreeSize = 1;//以当前节点为根节点的子树大小
};
typedef AVLNode* AVLTree; /* AVL树类型 */


AVLTree findMin(AVLTree Tree) {  //找到树中最小元素
    if (Tree->left)
        return findMin(Tree->left);
    else
        return Tree;
}

AVLTree findMax(AVLTree Tree) {  //找到树中最大元素
    if (Tree->right)
        return findMin(Tree->left);
    else
        return Tree;
}


int getHeight(AVLTree Tree) { //得到树高
    if (Tree == nullptr){
        return 0;
    }
    return max(getHeight(Tree->left), getHeight(Tree->right)) + 1;
}

int getSubTreeSize(AVLNode* T){
    int cnt = 0;
    if(T->left != nullptr){
        cnt +=T->left->subTreeSize + 1;
    }
    else{
        cnt = 1;
    }
    if(T->right != nullptr){
        cnt += T->right->subTreeSize;
    }
    return cnt;
}


void InitializerTree(AVLTree T, int value){
    T->value = value;
}

AVLTree LL_Rotation(AVLTree T){
    AVLTree tmp = T->left;
    AVLTree tmp_Y = nullptr;
    if(tmp != nullptr){
        tmp_Y = T->left->right;
        tmp->right = T;
    }
    T->left = tmp_Y;
    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    tmp->height = max(getHeight(tmp->left), T->height) + 1;
    tmp->subTreeSize = T->subTreeSize;
    T->subTreeSize = getSubTreeSize(T);
    return tmp;
}

AVLTree RR_Rotation(AVLTree T){
    AVLTree tmp = T->right;
    AVLTree tmp_Y = nullptr;
    if(tmp != nullptr){
        tmp_Y = T->right->left;
        tmp->left = T;
    }
    T->right = tmp_Y;
    T->height = max(getHeight(T->right), getHeight(T->left)) + 1;
    tmp->height = max(getHeight(tmp->right), T->height) + 1;
    tmp->subTreeSize = T->subTreeSize;
    T->subTreeSize = getSubTreeSize(T);
    return tmp;
}

AVLTree LR_Rotation(AVLTree T){
    T->left = RR_Rotation(T->left);
    return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree T) { //RL旋转
    T->right = LL_Rotation(T->right);
    return RR_Rotation(T);
}

AVLTree InsertNode(AVLTree T, int value){
    if (!T){
        T = new AVLNode;
        InitializerTree(T,value);
    }
    else{
        T->subTreeSize++;

    if(T->value > value){
        if(T->right != nullptr){
            InsertNode(T->right, value);
        }
        else{
            AVLNode *to_insert = new AVLNode;
            to_insert->value = value;
            T->right = to_insert;
        }

        if (getHeight(T->left) - getHeight(T->right) == 2){//若平衡被破坏
            if (value < T->left->value)//判断是进行RR旋转还是RL旋转
                T = LL_Rotation(T);
            else
                T = LR_Rotation(T);
        }
    }
    else if(T->value < value){
        if(T->left != nullptr){
            InsertNode(T->left, value);
        }
        else{
            AVLNode *to_insert = new AVLNode;
            to_insert->value = value;
            T->left = to_insert;
        }

        if (getHeight(T->left) - getHeight(T->right) == -2){//若平衡被破坏
            if (value > T->right->value){  //判断是进行LL旋转还是LR旋转
                T = RR_Rotation(T);
            }
            else{
                T = RL_Rotation(T);
            }
        }
    }

    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    }
    return T;
}


AVLTree deleteOldNode(AVLTree Tree, int value) { //删除节点
    AVLTree tmp;
    if (!Tree)
        printf("not find\n");
    else {
        if (value < Tree->value) {//往左,删除节点后可能导致右子树失去平衡
            Tree->subTreeSize--;  //则以该节点为根节点子树大小减一
            Tree->left = deleteOldNode(Tree->left, value);
            if (getHeight(Tree->left) - getHeight(Tree->right) == -2) {//若平衡被破坏
                tmp = Tree->right;
                if (getHeight(tmp->left)> getHeight(tmp->right))//判断是进行RR旋转还是RL旋转
                    Tree = RL_Rotation(Tree);  //若左子树高度大于右子树则做RL旋转
                else
                    Tree = RR_Rotation(Tree);  //否则做RR旋转
            }
        }
        else if (value > Tree->value) {//往右，删除节点后可能导致左子树失去平衡
            Tree->right = deleteOldNode(Tree->right, value);
            Tree->subTreeSize--;
            if (getHeight(Tree->left) - getHeight(Tree->right) == 2) {//若平衡被破坏
                tmp = Tree->left;
                if (getHeight(tmp->left) > getHeight(tmp->right))  //判断是进行LL旋转还是LR旋转
                    Tree = LL_Rotation(Tree);//原理同上
                else
                    Tree = LR_Rotation(Tree);
            }
        }
        else {//找到要删除节点
            if (Tree->left && Tree->right) {  //若节点左右儿子均存在
                if (getHeight(Tree->left) > getHeight(Tree->right)) { //为尽量使得树平衡，判断去寻找左子树的最大值还是右子树的最小值
                    tmp = findMax(Tree->left);	//找到左子树中最大元素
                    Tree->value = tmp->value;  //与要删除节点互换位置
                    Tree->subTreeSize--;  //更新子树大小
                    Tree->left= deleteOldNode(Tree->left, Tree->value);
                }
                else {
                    tmp = findMin(Tree->right);  //找到右子树中最小元素
                    Tree->value = tmp->value;  //与要删除节点互换位置
                    Tree->subTreeSize--;  //更新子树大小
                    Tree->right = deleteOldNode(Tree->right, Tree->value); //到右子树中将相应位置删除
                }
            }
            else { //有一个或无儿子
                tmp = Tree;
                if (!Tree->left)       //只有右儿子或无子结点
                    Tree = Tree->right;
                else                   // 只有左儿子
                    Tree = Tree->left;
                delete tmp;
            }
        }
    }
    return Tree;
}


int findKth(AVLTree T, int index){
    if(T->left != nullptr){
        int sub = T->left->subTreeSize + 1;
        if(sub == index){
            return T->value;
        }
        else if(sub > index){
            return findKth(T->left, index);
        }
        else if(sub < index){
            return findKth(T->right, index - sub);
        }
    }
    else {
            if (index == 1)
                return T->value;
            else
                return findKth(T->right, index - 1);
        }
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int m = 0;
    int k = 0;
    cin >> m >> k;
    int *list = new int[m];
    for(int i = 0; i < m; i++){
        cin >> list[i];
    }
    AVLTree Head = new AVLNode;
    InitializerTree(Head, list[0]);

    for(int i = 1; i < k ; i++){
        InsertNode(Head, list[i]);
    }

    int index = 0;
    cin >> index;
    printf("%d\n",findKth(Head, k - index + 1));
    for(int i = 1; i < m-k+1; i++){
        cin >> index;
        Head = deleteOldNode(Head, list[i-1]);
        Head = InsertNode(Head, list[i+k-1]);
        printf("%d\n",findKth(Head, k - index + 1));
//        cout << findKth(Head, k - index + 1) << endl;
    }
}
