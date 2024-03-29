#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
    struct node *next[26];//接收的态
    struct node *par;     //父亲节点
    struct node *fail;    //失败节点
    char inputchar;
    int patterTag;//是否为可接收态
    int patterNo; //接收态对应的可接受模式
} * Tree, TreeNode;

char pattern[4][30]{"nihao", "hao", "hs", "hsr"};

/**
申请新的节点，并进行初始化
*/
TreeNode *getNewNode() {
    int i;
    TreeNode *tnode = new TreeNode();
    tnode->fail = NULL;
    tnode->par = NULL;
    tnode->patterTag = 0;
    for (i = 0; i < 26; i++) tnode->next[i] = NULL;
    return tnode;
}

/**
将Trie树中，root节点的分支节点，放入队列
*/
int nodeToQueue(Tree root, queue<Tree> &myqueue) {
    int i;
    for (i = 0; i < 26; i++) {
        if (root->next[i] != NULL) myqueue.push(root->next[i]);
    }
    return 0;
}

/**
建立trie树
*/
Tree buildingTree() {
    int i, j;
    Tree root = getNewNode();
    Tree tmp1{NULL}, tmp2{NULL};
    for (i = 0; i < 4; i++) {
        tmp1 = root;
        for (j = 0; j < strlen(pattern[i]); j++)///对每个模式进行处理
        {
            if (tmp1->next[pattern[i][j] - 'a'] ==
                NULL)///是否已经有分支，Trie共用节点
            {
                tmp2 = getNewNode();
                tmp2->inputchar = pattern[i][j];
                tmp2->par = tmp1;
                tmp1->next[pattern[i][j] - 'a'] = tmp2;
                tmp1 = tmp2;
            } else
                tmp1 = tmp1->next[pattern[i][j] - 'a'];
        }
        tmp1->patterTag = 1;
        tmp1->patterNo = i;
    }
    return root;
}

/**
建立失败指针
*/
int buildingFailPath(Tree root) {
    int i;
    char inputchar;
    queue<Tree> myqueue;
    root->fail = root;
    for (i = 0; i < 26; i++)///对root下面的第二层进行特殊处理
    {
        if (root->next[i] != NULL) {
            nodeToQueue(root->next[i], myqueue);
            root->next[i]->fail = root;
        }
    }

    Tree tmp = NULL, par = NULL;
    while (!myqueue.empty()) {
        tmp = myqueue.front();
        myqueue.pop();
        nodeToQueue(tmp, myqueue);

        inputchar = tmp->inputchar;
        par = tmp->par;

        while (true) {
            if (par->fail->next[inputchar - 'a'] != NULL) {
                tmp->fail = par->fail->next[inputchar - 'a'];
                break;
            } else {
                if (par->fail == root) {
                    tmp->fail = root;
                    break;
                } else
                    par = par->fail->par;
            }
        }
    }
    return 0;
}

/**
进行多模式搜索，即搜寻AC自动机
*/
int searchAC(Tree root, char *str, int len) {
    TreeNode *tmp = root;
    int i = 0;
    while (i < len) {
        int pos = str[i] - 'a';
        if (tmp->next[pos] != NULL) {
            tmp = tmp->next[pos];
            if (tmp->patterTag == 1)///如果为接收态
            {
                cout << i - strlen(pattern[tmp->patterNo]) + 1 << '\t'
                     << tmp->patterNo << '\t' << pattern[tmp->patterNo] << endl;
            }
            i++;
        } else {
            if (tmp == root)
                i++;
            else {
                tmp = tmp->fail;
                if (tmp->patterTag == 1)//如果为接收态
                    cout << i - strlen(pattern[tmp->patterNo]) + 1 << '\t'
                         << tmp->patterNo << '\t' << pattern[tmp->patterNo]
                         << endl;
            }
        }
    }
    while (tmp != root) {
        tmp = tmp->fail;
        if (tmp->patterTag == 1)
            cout << i - strlen(pattern[tmp->patterNo]) + 1 << '\t'
                 << tmp->patterNo << '\t' << pattern[tmp->patterNo] << endl;
    }
    return 0;
}

/**
释放内存，DFS
*/
int destory(Tree tree) {
    if (tree == NULL) return 0;
    queue<Tree> myqueue;
    TreeNode *tmp = NULL;

    myqueue.push(tree);
    tree = NULL;
    while (!myqueue.empty()) {
        tmp = myqueue.front();
        myqueue.pop();
        for (int i = 0; i < 26; i++) {
            if (tmp->next[i] != NULL) myqueue.push(tmp->next[i]);
        }
        free(tmp);
    }
    return 0;
}
