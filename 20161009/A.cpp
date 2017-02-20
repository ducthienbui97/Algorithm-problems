#include <bits/stdc++.h>
#define nil &leaf
using namespace std;
class Treap {
        int n;
        struct Node {
            int size;
            Node *left;
            Node *right;
            int value;
            int priority;
            int cnt;
            Node(Node* left,Node* right,int value,int priority = 0):
                left(left),right(right),value(value),priority(priority) {
                size = 1;
                cnt = 1;
                }
            };
        Node* update(Node* curr) {
            if(curr != nil)
                curr -> size = curr -> left -> size + curr -> right -> size + curr -> cnt;
            return curr;
            }
        Node leaf = Node(NULL,NULL,-1);
        Node* root;
    public:
        Treap() {
            leaf = Node(nil,nil,-1);
            leaf.size = 0;
            root = nil;
            }
        void split(Node* root,Node* &left,Node* &right,int v) {
            if(root == nil) {
                left = nil;
                right = nil;
                }
            else if(v > root -> value) {
                left = root;
                split(root->right,left->right,right,v);
                }
            else {
                right = root;
                split(root->left,left,right->left,v);
                }
            update(left);
            update(right);
            }
        Node* merge(Node* left,Node* right) {
            if(left  == nil) return update(right);
            if(right == nil) return update(left);
            if(left -> priority > right -> priority) {
                right -> left = merge(left,right->left);
                return update(right);
                }
            else {
                left -> right = merge(left->right,right);
                return update(left);
                }
            }
        Node* find_and_add(Node* r,int v) {
            Node* rep = nil;
            if(r==nil) return rep;
            if(r->value==v) {
                r-> cnt++;
                return update(r);
                }
            if(r -> value < v) {
                rep = find_and_add(r->right,v);
                update(r);
                return rep;
                }
            else {
                rep = find_and_add(r->left,v);
                update(r);
                return rep;
                }
            }
        void insert(int v) {
            Node* left = nil;
            Node* right = nil;
            split(root,left,right,v);
            Node* new_node = find_and_add(right,v);;
            if(new_node !=nil) {
                root = merge(left,right);
                }
            else {
                new_node = new Node(nil,nil,v,rand()*rand());
                root = merge(merge(left,new_node),right);
                }
            }
        int get(int v) {
            Node* left = nil;
            Node* right = nil;
            split(root,left,right,v);
            int rep = left->size;
            root = merge(left,right);
            return rep;
            }
        void debug(Node* x) {
            if(x == nil) return;
            cerr << x -> size <<" "<<x ->value;
            cerr <<"{";
            debug(x->left);
            debug(x->right);
            cerr <<"}";
            cerr << endl;
            }

    };
const int MAXN =1e5+10;
Treap IT[MAXN <<3];
void insert(int n,int l,int r,int u,int v) {
    if(l<=u&&u<=r) {
        IT[n].insert(v);
        }
    if(l>u||r<u||l>=r)
        return;
    insert(n<<1,l,(l+r)>>1,u,v);
    insert((n<<1)+1,((l+r)>>1)+1,r,u,v);
    }
int find(int n,int l,int r,int u,int v,int value) {
    if(l > v||r<u||u>v) return 0;
    if(u <= l&&r<=v) return IT[n].get(value);
    return find(n<<1,l,(l+r)>>1,u,v,value)+ find((n<<1)+1,((l+r)>>1)+1,r,u,v,value);
    }
main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n,m;
    cin >> n >>m;
    map<int,int> last;
    for(int i = 0; i < n; i++) {
        int v,ll;
        cin >> v;
        if(v==1||last.find(v)==last.end())
            last[v] = -1;
        ll= last[v];
        last[v] = i;
        insert(1,1,n,i+1,ll);
        }

    int ans = 0;
    for(int i = 0 ; i < m; i++) {
        int a,b,c,d;
        cin >> a>> b>>c>>d;
        int u,v;
        int l,r;
        u = (1LL*a*ans+b-1+n)%n;
        v = (1LL*c*ans+d-1+n)%n;
        l = min(u,v);
        r = max(u,v);
        ans = find(1,1,n,l+1,r+1,l);
        printf("%d\n",ans);
        }
    }


