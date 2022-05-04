#include <bits/stdc++.h>
using namespace std
node findNext(node p)
{
    if (p->ltag == 0)
        return p->llink;
    if (p->rtag == 0)
        return p->rlink;
    while (p->rtag == 1)
    {
        if (p->rlink == NULL)
        {
            printf("NO pre");
            return NULL;
        }
        p = p->rlink;
    }
    return p->rlink;
}