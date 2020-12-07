#include <iostream>

using namespace std;

typedef struct AVLNode* Position;
typedef Position AVLTree; /* AVL树类型 */
AVLNode *Nearest;
int Sum = 0;
struct AVLNode {
    int value;
    AVLTree left;
    AVLTree right;
    int height;       //树高
    int subTreeSize;//以当前节点为根节点的子树大小
};

Position findMin(AVLTree Tree) {  //找到树中最小元素
    if (Tree->left)
        return findMin(Tree->left);
    else
        return Tree;
}
Position findMax(AVLTree Tree) {  //找到树中最大元素
    if (Tree->right)
        return findMin(Tree->left);
    else
        return Tree;
}
int getHeight(AVLTree Tree) { //得到树高
    if (!Tree)return 0;
    return max(getHeight(Tree->left), getHeight(Tree->right)) + 1;
}
int getSubTreeSize(AVLTree Tree) {
    int cnt = 0;
    if (Tree->left)
        cnt = Tree->left->subTreeSize + 1;
    else cnt = 1;
    if (Tree->right)
        cnt += Tree->right->subTreeSize;
    return cnt;
}
AVLTree LL_Rotation(AVLTree Tree) { //LL旋转
    AVLTree tmp = Tree->left;
    Tree->left = tmp->right;
    tmp->right = Tree;
    Tree->height = max(getHeight(Tree->left), getHeight(Tree->right)) + 1;
    tmp->height = max(getHeight(tmp->left), Tree->height) + 1;
    tmp->subTreeSize = Tree->subTreeSize;
    Tree->subTreeSize = getSubTreeSize(Tree);
    return tmp;
}
AVLTree RR_Rotation(AVLTree Tree) {  //RR旋转
    AVLTree tmp = Tree->right;
    Tree->right = tmp->left;
    tmp->left = Tree;
    Tree->height = max(getHeight(Tree->left), getHeight(Tree->right)) + 1;
    tmp->height = max(getHeight(tmp->right), Tree->height) + 1;
    tmp->subTreeSize = Tree->subTreeSize;
    Tree->subTreeSize = getSubTreeSize(Tree);
    return tmp;
}
AVLTree LR_Rotation(AVLTree Tree){  //LR旋转
    Tree->left = RR_Rotation(Tree->left);
    return LL_Rotation(Tree);
}
AVLTree RL_Rotation(AVLTree Tree) { //RL旋转
    Tree->right = LL_Rotation(Tree->right);
    return RR_Rotation(Tree);
}
AVLTree addNewNode(AVLTree Tree, int value){
    if (!Tree) {
        Tree = (AVLTree)malloc(sizeof(struct AVLNode));
        Tree->value = value;
        Tree->height = 0;
        Tree->left = Tree->right = NULL;
        Tree->subTreeSize = 1;
    }
    else if (value < Tree->value) { //左子树中
        Tree->left = addNewNode(Tree->left, value);
        Tree->subTreeSize++;
        if (getHeight(Tree->left) - getHeight(Tree->right) == 2)//若平衡被破坏
            if (value < Tree->left->value)  //判断是进行LL旋转还是LR旋转
                Tree = LL_Rotation(Tree);
            else
                Tree = LR_Rotation(Tree);
    }
    else if (value > Tree->value) {//又子树中
        Tree->right = addNewNode(Tree->right, value);
        Tree->subTreeSize++;
        if (getHeight(Tree->left) - getHeight(Tree->right) == -2)//若平衡被破坏
            if (value > Tree->right->value)//判断是进行RR旋转还是RL旋转
                Tree = RR_Rotation(Tree);
            else
                Tree = RL_Rotation(Tree);
    }
    //更新树高
    Tree->height = max(getHeight(Tree->left), getHeight(Tree->right)) + 1;
    return Tree;
}
AVLTree deleteOldNode(AVLTree Tree, int value) { //删除节点
    Position tmp;
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
                free(tmp);
            }
        }
    }
    return Tree;
}
AVLTree createTree(int a[], int n) {
    if (!n)return NULL;
    AVLTree Tree = NULL;
    for (int i = 0; i < n; i++)
        Tree = addNewNode(Tree, a[i]);
    return Tree;
}
int findKth(AVLTree Tree, int k) {//寻找第k小的数
    if (k > Tree->subTreeSize)
        return -1;
    if (!Tree->left && !Tree->right)return Tree->value;
    if (Tree->left) {
        int now = Tree->left->subTreeSize + 1;
        if (now == k)return Tree->value;
        else if (now > k)
            return findKth(Tree->left, k);
        if (Tree->right)
            return findKth(Tree->right, k - now);
    }
    else {
        if (k == 1)
            return Tree->value;
        else
            return findKth(Tree->right, k - 1);
    }
}

AVLTree Find(AVLTree T, int value){
    if(!T){
        return T;
    }
    if(T->value == value){
        return T;
    }
    if(T->value > value){
        if(abs(Nearest->value - value) < abs(T->value - value)){
            Nearest = T;
        }
        cout << T->value << endl;
        return Find(T->left, value);
    }
    if(T->value < value){
        if(abs(Nearest->value - value) < abs(T->value - value)){
            Nearest = T;
        }
        return Find(T->right, value);
    }
}

AVLTree FindNDelete(AVLTree T, int value){
    if(!T){
    }
    else {
        Nearest = T;
        Find(T, value);
        Sum += abs(Nearest->value - value);
        Position tmp;
        if (Nearest->left && Nearest->right) {  //若节点左右儿子均存在
            if (getHeight(Nearest->left) > getHeight(Nearest->right)) { //为尽量使得树平衡，判断去寻找左子树的最大值还是右子树的最小值
                tmp = findMax(Nearest->left);	//找到左子树中最大元素
                Nearest->value = tmp->value;  //与要删除节点互换位置
                Nearest->subTreeSize--;  //更新子树大小
                Nearest->left= deleteOldNode(Nearest->left, Nearest->value);
            }
            else {
                tmp = findMin(Nearest->right);  //找到右子树中最小元素
                Nearest->value = tmp->value;  //与要删除节点互换位置
                Nearest->subTreeSize--;  //更新子树大小
                Nearest->right = deleteOldNode(Nearest->right, Nearest->value); //到右子树中将相应位置删除
            }
        }
        else { //有一个或无儿子
            tmp = Nearest;
            if (!Nearest->left)       //只有右儿子或无子结点
                Nearest = Nearest->right;
            else                   // 只有左儿子
                Nearest = Nearest->left;
            free(tmp);
        }
    }
    return T;
}



int main()
{
    AVLTree pets = NULL;
    AVLTree adopters = NULL;
    int n = 0;
    cin >> n;
    int total_pets = 0;
    int total_adopters = 0;
    while(n--){
        int a = 0, b= 0;
        cin >> a >> b;
        if(a == 0){
            if(total_adopters != 0){
                adopters = FindNDelete(adopters, b);
                total_adopters--;
            }
            else{
                pets = addNewNode(pets, b);
                total_pets++;
            }
        }
        else if(a == 1){
            if(total_pets != 0){
                pets = FindNDelete(pets, b);
                total_pets--;
            }
            else{
                adopters = addNewNode(adopters, b);
                total_adopters++;
            }
        }
    }
    cout << Sum << endl;
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(0);
//    int m = 0;
//    int k = 0;
//    cin >> m >> k;
//    int *list = new int[m];
//    for(int i = 0; i < m; i++){
//        cin >> list[i];
//    }
//    AVLTree Head = NULL;

//    for(int i = 0; i < k ; i++){
//        Head = addNewNode(Head, list[i]);
//    }

//    int index = 0;
//    cin >> index;
//    printf("%d\n",findKth(Head, index));
//    for(int i = 1; i < m-k+1; i++){
//        cin >> index;
//        Head = deleteOldNode(Head, list[i-1]);
//        Head = addNewNode(Head, list[i+k-1]);
//        printf("%d\n",findKth(Head, index));
////        cout << findKth(Head, k - index + 1) << endl;
//    }
}
