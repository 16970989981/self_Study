
typedef int KEY_TYPE;


#define RBTREE_ENTRY(name, type)
    struct name{
        struct type *right;
        struct type *left;
        struct type *parent;
        unsigned char color;
    }

typedef struct _rbtree_node {  //红黑树节点定义
    KEY_TYPE key;
    void *value;

#if 1

    struct _rbtree_node *right; //右子树
    struct _rbtree_node *left; //左子树
    struct _rbtree_node *parent; //指向父节点（便于插入后红黑树调整）
    
    unsigned char color;  //红黑节点


#else
        RBTREE_ENTRY(, _rbtree_node) node;

#endif
} retree_node;


typedef struct _rbtree { //红黑树定义

    struct _rbtree_node *root; //根节点
    struct _rbtree_node *nil;
} rbtree;


//红黑树左旋
void rbtree_left_rotate(rbtree *T, rbtree_node *x) {

    rbtree_node *y = x->right;
//1
    x->right = y->left;
    if(y->left != T->nil) {y->left->parent =x;}
//2
    y->parent = x->parent;
    if(x->parent == T->nil){
        T->root = y; 
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
//3
    y->left = x;
    x->parent =y;
}

//红黑树右旋
void rbtree_right_rotate(rbtree *T, rbtree_node *y) {

    rbtree_node *x = y->left;
//1
    y->left = x->right;
    if(x->right != T->nil) {x->right->parent = y;}y
//2
    x->parent = y->parent;
    if(y->parent == T->nil){
        T->root = x; 
    } else if(y == y->parent->left){
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
//3
    x->right = y;
    y->parent = x;
}