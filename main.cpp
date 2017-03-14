#include <iostream>

using namespace std;

struct Tree
{
    int x;
    Tree* l;
    Tree* r;
    int hight;
    Tree ( int x ): x(x)
    {
        this-> l = NULL;
        this-> r = NULL;
        this-> hight = 1;
    };
    Tree& dell (Tree& a)
    {
        if (a.l)
            dell ( *(a.l) );
        if (a.r)
            dell ( *(a.r) );
        delete l, r, x, hight;
    }
    ~Tree (){
    dell ( *l );
    dell ( *r );
    delete l, r, x, hight;
    }
};
class bstree
{
public:
    unsigned char height(Tree* x) // ��������� ������, ����� �������� � ������� �����������
    {
        return x?x->hight:0;
    }
    int bfactor ( Tree* x )//�������� ������� ��� �����
    {
        return height( x->r ) - height( x->l );
    }
    void fixheight(Tree* p)//�������� ������ �� ������� � ������ ������
    {
        unsigned char hl = height(p->l);
        unsigned char hr = height(p->r);
        p->hight = (hl>hr?hl:hr)+1;
    }
    Tree* rotateright (Tree* x)//������ �������
    {
        Tree* q = x->l;
        x->l = q->r;
        q->r = x;
        fixheight(x);
        fixheight(q);
        return q;
    }
    Tree* rotateleft (Tree* x)//����� �������
    {
        Tree* q = x->l;
        x->r = q->l;
        q->l = x;
        fixheight(x);
        fixheight(q);
        return q;
    }
    Tree* add(Tree* p, int k) // ������� ����� k � ������ � ������ p
    {
        if( !p ) return new Tree (k);
        if( k<p->x )
            p->l = add(p->l,k);
        else
            p->r = add(p->r,k);
        return balance(p);
    }
    Tree* find1 (int k, Tree* a)//����� �������� ����� ���� �
    {
      if ( k > a->x )
        a->r?find1 ( k, a->r ): a = NULL;
      if ( k < a->x )
        a->l?find1 ( k, a->l ): a = NULL;
      return a;
    }
    Tree* balance(Tree* p) // ������������ ���� p
    {
        fixheight(p);
        if( bfactor(p)==2 )
        {
            if( bfactor(p->r) < 0 )
                p->r = rotateright(p->r);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->l) > 0  )
			p->l = rotateleft(p->l);
            return rotateright(p);
        }
        return p; // ������������ �� �����
    }
};
int main()
{
    int x = 5;
    Tree s (x);
    return 0;
}
