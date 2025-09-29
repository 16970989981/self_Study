 
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

void rbtree_insert_fixup(rbtree *T, rbtree_node *z) {
    
    //z == RED

    while(z->parent->color == "RED") {
        if(z->parent = z->parent->parent->left) {
            rbtree_node *y = z->parent->parent->right;

            if(y->color == "RED") {

                z->parent->color = "BLACK";
                y->color = "BLACK";
                z->parent->parnt->color = "RED";

                z = z->parent->parent; //z == RED
            } else { // y->color = BLACK
                
                if(z == z->parent->right) {
                    
                    z = z->parent;
                    rbtree_left_rotate(T, z);
                }

                    z->parent->color = "BLACK";
                    z->parent->parent->color = "RED";

                    rbtree_right_rotate(T, z->parent->parent);

                }
                    
                    

            }   
        }
}

void rbtree_insert(rbtree *T, rbtree_node *z) {

    rbtree_node *y = T->nil;
    rbtree_node *x = T->root;

    //遍历树
    while(x != T->nil)
    {
        if(z->key < x->key) { x = x->left; }
        else if(z->key > x->key) { x = x->right; }
        else { return ; } //相等的情况看业务场景
    }

    if(y == T->nil) { T->root = z; }
    else {
        if(y->key > z->key) { y->left = z; }
        else { y->right = z; }
    }

    z->parent = y;

    z->left = T->nil;
    z->right = T->nil;
    z->color = "RED";

    rbtree_insert_fixup(T, z);
}