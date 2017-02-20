#include "necklace.h"
#include <bits/stdc++.h>
using namespace std;
struct Pearl {
    Pearl* next[22];
    int color;
    int h;
    };
struct neck {
    Pearl *l,*r;
    neck() {
        l=r=0;
        }
    };
vector<neck> lis;
void init (void) {
    /* Insert your initialization code here.  */
    neck ne;
    lis.push_back(ne);
    }

int pearl (int neck_id, int on_left) {
    /* Insert your code for the Pearl function here.  */
    return on_left? lis[neck_id].l->color:lis[neck_id].r->color;
    }

void create (int from, char operation, int on_left, int param) {
    /* Insert your code for the create function here.  */
    if(operation=='A') {
        neck new_neck;
        Pearl* x=new Pearl;
        memset(x->next,0,sizeof x->next);
        if(on_left) x->next[0]=lis[from].l;
        else x->next[0]=lis[from].r;
        if(x->next[0])
                x->h=x->next[0]->h+1;
        else x->h=1;
        for(int i=1; i<21; i++)
            if(x->next[i-1]) {
                x->next[i]=x->next[i-1]->next[i-1];
                }
        x->color=param;
        if(!lis[from].l) {
            new_neck.l=new_neck.r=x;
            }
        else {
            if(on_left) new_neck.l=x,new_neck.r=lis[from].r;
            else new_neck.r=x,new_neck.l=lis[from].l;
            }
        lis.push_back(new_neck);
        }
    if(operation=='R') {
        neck new_neck=lis[from];
        if(lis[from].l!=lis[from].r) {
            Pearl *ll=lis[from].l,*rr=lis[from].r;
            if(ll->h<rr->h) {
                for(int i=20; i>=0; i--)
                    if(rr->next[i]&&rr->next[i]->h>ll->h) rr=rr->next[i];
                if(rr->next[0]==lis[from].l) {
                    if(on_left) {
                        new_neck.l=rr;
                        }
                    else {
                        new_neck.r=new_neck.r->next[0];
                        }
                    }
                else {
                    if(on_left) new_neck.l=new_neck.l->next[0];
                    else new_neck.r=new_neck.r->next[0];
                    }
                }
            else {
                for(int i=20; i>=0; i--)
                    if(ll->next[i]&&ll->next[i]->h>rr->h) ll=ll->next[i];
                if(ll->next[0]==lis[from].r) {
                    if(!on_left) {
                        new_neck.r=ll;
                        }
                    else {
                        new_neck.l=new_neck.l->next[0];
                        }
                    }
                else {
                    if(on_left) new_neck.l=new_neck.l->next[0];
                    else new_neck.r=new_neck.r->next[0];
                    }
                }
            }
            else new_neck.l=new_neck.r=0;
        lis.push_back(new_neck);
        }
    }
    main(){

    }
