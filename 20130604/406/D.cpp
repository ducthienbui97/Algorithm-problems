#include <stdio.h>

class trie {
  public :
    struct node {
        map<int,int> a;
        int value;
        int& operator[] (int i){ return a[i%29]; }
        node() { for (int i=0; i<29; i++) a[i]=0; value=0; }
    };

    vector <node> a;

    int& operator[] (char *s){
        int pos=0, i, c;
        for (i=0; c=s[i]; i++) {
            if (a[pos][c]==0) {
                a.push_back(node());
                a[pos][c] = a.size()-1;    }
            pos=a[pos][c];  }
        return a[pos].value;
    }

    void clear(){ a.clear(); a.push_back(node()); }
    trie(){ clear(); }
};

main(){


}
