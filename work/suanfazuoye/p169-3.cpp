#include <bits/stdc++.h>
using namespace std;
struct ThrTree
{
    ThrTree *llink;
    ThrTree *rlink;
    int ltag;
    int rtag;
};
typedef ThrTree Node;
Node *findPre(ThrTree *t, Node *node)
{
    Node *p = t;
    if (p == NULL)
        return NULL;
    while (p->llink != NULL && p->ltag == 0)
        p = p->llink;
    while (p != NULL)
    {
        if (p->rlink != NULL && p->rtag == 0)
        { //右子树不是线索时
            if (p->rlink == node)
                return p;
            p = p->rlink;
            while (p->llink != NULL && p->ltag == 0)
                p = p->llink; //右子树的左子树
        }
        else//右子树为线索时
        {
            if (p->rlink == node)
                return p;
            p = p->rlink;
        }
    }
}