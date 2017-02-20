    #include <bits/stdc++.h>
    using namespace std;
    vector<pair<pair<int,int>,int> > p;
    vector<pair<int,int> > ans;
    int l,r,b,t;
    int min(){
        return min(min(abs(l),abs(r)),min(abs(b),abs(t)));
    }

    main(){
        ios_base::sync_with_stdio(false);
        int n;
        cin >> n;
        ans.resize(n);

        for(int i=0;i<n;i++){
            int R,W;
            cin >> R >> W;
            p.push_back(make_pair(make_pair(W,R),i));
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        l=r=b=t=p[0].first.second;
        ans[p[0].second] = make_pair(0,0);
        for(int i=1;i<n;i++){
            int R,W;
            R = p[i].first.second;
            W = p[i].first.first;
            if(l==min()){
                l-=R;
                ans[p[i].second]=(make_pair(0,l));
                l-=R;
                if(abs(t) < R) t =  R;
                if(abs(b) < R) b = -R;
            }
            else if(r==min()){
                r+=R;
                ans[p[i].second]=(make_pair(0,r));
                r+=R;
                if(abs(t) < R) t =  R;
                if(abs(b) < R) b = -R;
            }
            else if(b==min()){
                b-=R;
                ans[p[i].second]=(make_pair(b,0));
                b-=R;
                if(abs(r) < R) r =  R;
                if(abs(l) < R) l = -R;
            }
            else {
                t+=R;
                ans[p[i].second]=(make_pair(t,0));
                t+=R;
                if(abs(r) < R) r =  R;
                if(abs(l) < R) l = -R;
            }
        }
        for(int i=0;i<n;i++)
            cout <<ans[i].first<<" "<<ans[i].second<<endl;


    }
