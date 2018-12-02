//全自動減肥機關槍: segment tree
#include <iostream>
#include <cstdio>
#define N 1000000
using namespace std;

int n, q;
int method;
int l, r, c;
int w[N+5];

struct node {
    long long int sum, maximum;
    int left, right;
    node *left_node, *right_node;
    node(int l, int r) : left(l), right(r) {}
};

void build(node *p) {
    if (p->left == p->right) {
        p->sum = p->maximum = w[p->left];
        return;
    }
    int mid = (p->left + p->right)/2;
    p->left_node = new node(p->left, mid);
    build(p->left_node);
    p->right_node = new node(mid+1, p->right);
    build(p->right_node);
    p->sum = p->left_node->sum + p->right_node->sum;
    p->maximum = max(p->left_node->maximum, p->right_node->maximum);
    return;
}

void mod(node *p) {
    if (p->maximum < c) return;
    if (p->left == p->right) {
        p->sum %= c;
        p->maximum %= c;
        return;
    }
    if (p->left_node->right >= l) mod(p->left_node);
    if (p->right_node->left <= r) mod(p->right_node);
    p->sum = p->left_node->sum + p->right_node->sum;
    p->maximum = max(p->left_node->maximum, p->right_node->maximum);
    return;
}

long long counting(node *p) {
    if (p->left >= l && p->right <= r) return p->sum;
    long long int sum = 0;
    if (p->left_node->right >= l) sum += counting(p->left_node);
    if (p->right_node->left <= r) sum += counting(p->right_node);
    return sum;
}

int main(){
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    node *root = new node(0, n-1);
    build(root);
    for (int i = 0; i < q; i++) {
        scanf("%d", &method);
        if (method == 1) {
            scanf("%d%d%d", &l, &r, &c);
            mod(root);
        } else if (method == 2) {
            scanf("%d%d", &l, &r);
            long long int ans = counting(root);
            printf("%lld\n", ans);
        }
    }
}
