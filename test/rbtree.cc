#include <iostream>
#include <algorithm>
#include <string>

#include <cassert>

using namespace std;


namespace rbtree {


template <typename T>
class RBTree {

    enum Color {
        RED = 0,
        BLACK = 1
    };

    struct Node_;
    using Node = Node_*;
    static constexpr Node NIL = nullptr;

    struct Node_ {
        T val;
        Node p, l, r;
        Color c;
        int size;


        Node_(): p(NIL), l(NIL), r(NIL), c(BLACK), size(0) {}
        Node_(const T& v): val(v), p(NIL), 
            l(NIL), r(NIL), c(BLACK), size(1) {}
        Node_(const T& v, Node par): val(v), p(par), 
            l(NIL), r(NIL), c(RED), size(1) {}
        // Node_(Node par)   // Dummy node
        // : p(par), l(NIL), r(NIL), c(BLACK), size(0) {}
        ~Node_() {
            if (l)
                delete l;
            if (r)
                delete r;
        }

        inline Node G() const {
            return (p ? (p->p) : NIL);
        }
        Node U() const {
            Node g = G();
            if (!g)
                return NIL;
            return ((p == g->l) ? g->r : g->l);
        }
        Node S() const {
            if (!p)
                return NIL;
            return ((p->l == this) ? p->r : p->l);
        }
        inline bool IsLeft() const {
            return (p ? (p->l == this) : false);
        }
        inline bool IsRight() const {
            return (p ? (p->r == this) : false);
        }
        Node Min() const {
            return (l ? l->Min() : (Node)this);
        }
        Node Max() const {
            return (r ? r->Max() : (Node)this);
        }
        Node Successor() const {
            if (r)
                return r->Min();
            if (IsLeft())
                return p;
            Node cur = (Node)this;
            while (cur->IsRight())
                cur = cur->p;
            return cur->p;
        }
        Node Predecessor() const {
            if (l)
                return l->Max();
            if (IsRight())
                return p;
            Node cur = (Node)this;
            while (cur->IsLeft())
                cur = cur->p;
            return cur->p;
        }
        void Update() {
            size = 1;
            if (l)
                size += l->size;
            if (r)
                size += r->size;
        }
        void UpdateToRoot() {
            Node cur = this;
            while (cur) {
                cur->Update();
                cur = cur->p;
            }
        }

        friend std::ostream& operator<<(std::ostream& out, const Node_& node) {
            out << "Node(";
            out << "v=" << node.val;
            out << ", n=" << node.size;
            out << ", " << ((node.c == RED) ? "RED" : "BLK");
            out << ")";
            return out;
        }
    };

    class Iter {
    public:
        Iter() : node(NIL) {}
        Iter(Node node_) : node(node_) {}

        inline const T& operator*() const {
            return node->val;
        }
        inline bool operator==(const Iter& other) const {
            return node == other.node;
        }
        inline bool operator!=(const Iter& other) const {
            return node != other.node;
        }
        Iter& operator++() {
            if (node)
                node = node->Successor();
            return (*this);
        }
        Iter operator++(int) {
            Iter tmp(*this);
            operator++();
            return tmp;
        }
        Iter& operator--() {
            if (node)
                node = node->Predecessor();
            return (*this);
        }
        Iter operator--(int) {
            Iter tmp(*this);
            operator--();
            return tmp;
        }

    private:
        Node node;
    };
    const Iter NIL_ITER;

public:

    RBTree() {}
    ~RBTree() {
        if (root)
            delete root;
    }

    inline bool Empty() const {
        return (root == NIL);
    }
    inline Iter Begin() const {
        return (root ? Iter(root->Min()) : NIL_ITER);
    }
    inline Iter End() const {
        return NIL_ITER;
    }
    inline int Size() const {
        return (root ? root->size : 0);
    }

    Iter Insert(const T& v) {
        if (!root) {
            root = new Node_(v);
            return Iter(root);
        }
        else
            return Iter(Insert(root, v));
    }

    Iter FindKth(int k) const {
        Node x = root;
        while (x) {
            int cnt = (x->l ? x->l->size : 0);
            if (k == cnt) 
                break;
            else if (k < cnt) 
                x = x->l;
            else {
                k -= cnt+1;
                x = x->r;
            }
        }
        return Iter(x);
    }

    Iter Find(const T& v) const {
        return Iter(Find(root, v));
    }

    bool Has(const T& v) const {
        return Find(root, v) != NIL;
    }

    void Delete(const T& v) {
        Node del = Find(root, v);
        if (!del)
            return;
        Delete(del);
    }
    
    void CheckValid() const {
        if (root) {
            assert(root->c == BLACK);
            CheckValidInternal(root);
        }
    }

    void Debug() const {
        cout << "DBG" << endl;
        Debug(root, "", 0);
        cout << endl;
        // CheckValid();
    }

private:
    inline bool IsBlack(Node x) {
        return !x || (x->c == BLACK);
    }

    void Rotate(Node x) {
        Node p = x->p;
        Node b;
        if (x->IsLeft()) {
            p->l = b = x->r;
            x->r = p;
        }
        else {
            p->r = b = x->l;
            x->l = p;
        }
        x->p = p->p;
        p->p = x;
        if (b)
            b->p = p;
        if (x->p) {
            if (x->p->l == p) 
                x->p->l = x;
            else 
                x->p->r = x;
        }
        else
            root = x;
        p->Update();
        x->Update();
    }

    void DoubleRed(Node x) {
        Node u = x->U();
        if (!u || u->c == BLACK)
            Restruct(x);
        else
            Recolor(x);
    }

    void Restruct(Node x) {
        Node mn = x, mid = x->p, mx = x->G();
        if ((mx->l == mid) != (mid->l == mn)) {
            std::swap(mid, mn);
            Rotate(mid);
        }
        Rotate(mid);

        mid->c = BLACK;
        mn->c = mx->c = RED;
    }

    void Recolor(Node x) {
        Node g = x->G(), u = x->U();
        if (u)
            u->c = BLACK;
        x->p->c = BLACK;
        g->c = RED;
        if (!g->p)
            g->c = BLACK;
        else if (g->p->c == RED)
            DoubleRed(g);
    }

    Node Insert(Node x, const T& v) {
        if (v == x->val)
            return x;

        Node* place;
        if (v < x->val)
            place = &x->l;
        else
            place = &x->r;
    
        if (*place)
            return Insert(*place, v);
        else {
            *place = new Node_(v, x);
            // cout << "alloc " << (*place) << " " << (*(*place)) << endl;
            (*place)->UpdateToRoot();
            if (x->c == RED)
                DoubleRed(*place);
            return *place;
        }
    }

    Node Find(Node x, const T& v) const {
        if (!x)
            return NIL;
        if (v == x->val)
            return x;
        else if (v < x->val)
            return Find(x->l, v);
        else
            return Find(x->r, v);
    }

    void Detach(Node x, Node subst) {
        // replace connection between x and x->p
        // to subst and x->p
        if (x->p) {
            if (x->IsLeft())
                x->p->l = subst;
            else
                x->p->r = subst;
            x->p->UpdateToRoot();
        }
        else {
            root = subst;
        }
        if (subst)
            subst->p = x->p;
        x->p = NIL;
    }


    void Fixup(Node x) {
        if (x->c == RED || !x->p) {
            x->c = BLACK;
            return;
        }

        Node s = x->S();
        if (s->c == RED) {
            s->c = BLACK;
            x->p->c = RED;
            Rotate(s);
            s = x->S();
        }
        assert(s && s->c == BLACK);

        Node sc = (s->IsLeft() ? s->r : s->l);
        if (IsBlack(s->l) && IsBlack(s->r)) {
            s->c = RED;
            if (s->p->c == RED) {
                s->p->c = BLACK;
            }
            else if (x->p->p) {
                Fixup(x->p);
            }
            
            return;
            // s = x->S();
        }
        else if (!IsBlack(sc) && IsBlack(s->IsLeft() ? s->l : s->r)) {
            sc->c = BLACK;
            s->c = RED;
            Rotate(sc);
            // s = x->S();
        }

        s = x->S();

        
        if (!IsBlack(s->IsLeft() ? s->l : s->r)) {
            s->c = x->p->c;
            Rotate(s);
            if (s->l)
                s->l->c = BLACK;
            if (s->r)
                s->r->c = BLACK;
        }
    }
    
    void Delete(Node x) {
        Node fix_pos = NIL;
        Color fix_color = x->c;
        // cout << "to delete " << x << " " << (*x) << endl;

        if (x->l && x->r) {
            // cout << "has both l, r" << endl;

            Node nxt = x->Successor();
            // cout << "nxt " << (*nxt) << endl;
            fix_color = nxt->c;

            if (nxt->r)
                fix_pos = nxt->r;
            else {
                // cout << "use dummy fix pos" << endl;
                fix_pos = dummy;
                // dummy->c = RED;
                dummy->p = nxt;
            }
            // cout << "fix_pos " << (*fix_pos) << endl;
            Detach(nxt, fix_pos);
            // cout << "detached nxt" << endl;

            nxt->r = x->r;
            nxt->l = x->l;
            nxt->r->p = nxt;
            nxt->l->p = nxt;
            nxt->UpdateToRoot();
            Detach(x, nxt);
            // cout << "nxt repalced x" << endl;
            // Debug(nxt, "", 0);
            
            nxt->c = x->c;
        }
        else {
            // cout << "has 0 or 1 child" << endl;
            if (x->l)
                fix_pos = x->l;
            else if (x->r)
                fix_pos = x->r;
            else {
                // cout << "use dummy fix pos" << endl;
                fix_pos = dummy;
                // dummy->c = RED;
                dummy->p = x;
            }
            Detach(x, fix_pos);
        }
        // cout << endl;
        // cout << "x " << x << " " << (*x) << endl;
        x->l = x->r = NIL;
        delete x;

        // cout << "fix_color " << fix_color << ", fix_pos " << (*fix_pos) << endl;
        if (fix_color == BLACK)
            Fixup(fix_pos);
        if (fix_pos == dummy) {
            // cout << "deletion end: dummy detach" << endl;
            Detach(dummy, NIL);
            // cout << "detached" << endl;
        }
    }

    void Debug(Node node, const string& pref, int flg) const {
        cout << pref;
        if (flg == 1)
            cout << "L:";
        else if (flg == 2)
            cout << "R:";
        cout << (*node) << endl;
        if (node->l) {
            Debug(node->l, pref+"  ", 1);
        }
        if (node->r) {
            Debug(node->r, pref+"  ", 2);
        }
    }

    int CheckValidInternal(Node x) const {
        if (x->l) {
            assert(x->l->p == x);
            assert(x->c == BLACK || x->l->c == BLACK);
        }
        if (x->r) {
            assert(x->r->p == x);
            assert(x->c == BLACK || x->r->c == BLACK);
        }
        int n_black = 0;
        if (x->c == BLACK)
            n_black++;
        int lb = -1, rb = -1;
        if (x->l) {
            lb = CheckValidInternal(x->l);
        }
        if (x->r) {
            rb = CheckValidInternal(x->r);
        }
        if (lb >= 0 && rb >= 0) {
            assert(lb == rb);
            n_black += lb;
        }
        else if (lb >= 0)
            n_black += lb;
        else if (rb >= 0)
            n_black += rb;
        return n_black;
    }

    Node root = NIL;
    Node_ __dummy;
    Node dummy = &__dummy;


};


}


#include <vector>
#include <set>
#include <chrono>
using namespace std;

vector<int> lst;

int main() {
    
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	rbtree::RBTree<int> tree;
	set<int> s;

	int n, v;
	cin >> n;
	lst.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}

	int i1=0,i2=0;
	int d1=0,d2=0;

	std::chrono::time_point st1 = std::chrono::system_clock::now();
	for (int v : lst) {
		if (s.find(v) == s.end()) {
			s.insert(v);
			i1++;
		}
		else {
			s.erase(v);
			d1++;
		}
	}
	std::chrono::duration<double> du1 = std::chrono::system_clock::now() - st1;
	cout << "set    time cost: " << du1.count() << " sec" << endl;


	std::chrono::time_point st2 = std::chrono::system_clock::now();
	for (int v : lst) {
		if (!tree.Has(v)) {
			tree.Insert(v);
			i2++;
		}
		else {
			tree.Delete(v);
			d2++;
		}
	}
	assert(i1 == i2 && d1 == d2);
	assert(s.size() == tree.Size());
	std::chrono::duration<double> du2 = std::chrono::system_clock::now() - st2;
	cout << "rbtree time cost: " << du2.count() << " sec" << endl;
	cout << i1 << " insertions, " << d1 << " deletions" << endl;
	



}

