const
        finp    = 'jobplan.in';
        fout    = 'jobplan.out';
        maxn    = 3000;
        max     = 1000000;
        oo      = 2 * round(1e9);

type
        point   = ^bg;
        bg      = record
                a : longint;
                next : point;
        end;

var
        fi,fo           : text;
        dq,cq,spt,
        n,m,t           : longint;
        s               : array[0..50] of string;
        id              : array[0..maxn] of point;
        q               : array[0..max] of longint;
        iq              : array[0..maxn] of boolean;
        p,trace,d       : array[0..maxn] of longint;
        cost,
        c,f             : array[0..maxn,0..maxn] of longint;


Procedure ofile;
        begin
            assign(fi,finp); reset(fi);
            assign(fo,fout); rewrite(fo);
        end;

Procedure cfile;
        begin
            close(fi); close(fo);
        end;

Procedure push(u,v : longint);
        var
            p : point;
        begin
            new(p); p^.a := v;
            p^.next := id[u]; id[u] := p;
        end;

Procedure tao_dt;
        var
            i,j,u,k : longint;
        begin
            t := n * m + n + 1;
            for i := 1 to n do
              begin
                  push(0,i);
                  c[0,i] := 1;
              end;

            for i := 1 to n do
              for j := 1 to m do
                if s[j,i] = 'Y' then
                  for k := 1 to n do
                    begin
                        u := j * n + k;
                        push(i,u); push(u,i);
                        c[i,u] := 1;
                    end;

            for i := 1 to m do
              for k := 1 to n do
                begin
                    u := i * n + k;
                    push(u,t);
                    c[u,t] := 1;
                    cost[u,t] := p[i] * ( 2 * k - 1 );
                end;
        end;

Procedure day(u : longint);
        begin
            inc(cq); if cq > max then cq := 1;
            q[cq] := u; iq[u] := true;
            inc(spt);
        end;

Procedure lay(var u : longint);
        begin
            u := q[dq]; iq[u] := false;
            inc(dq); if dq > max then dq := 1;
            dec(spt);
        end;

function findpath : boolean;
        var
            i,u,v,dau : longint;
            p : point;
        begin
            for i := 1 to t do
              begin
                  trace[i] := - 1;
                  d[i] := oo;
              end;
            fillchar(iq,sizeof(iq),0);
            dq := 1; cq := 0; spt := 0;
            day(0);
            while spt > 0 do
              begin
                  lay(u);
                  p := id[u];
                  while p <> nil do
                    begin
                        v := p^.a;
                        if f[u,v] = 0 then dau := 1 else dau := - 1;
                        if (c[u,v] > f[u,v]) and (d[u] + dau * cost[u,v] < d[v]) then
                          begin
                              trace[v] := u;
                              d[v] := d[u] + dau * cost[u,v];
                              if not iq[v] then day(v);
                          end;
                        p := p^.next;
                    end;
              end;
            if trace[t] > 0 then exit(true) else exit(false);
        end;

Procedure tangluong;
        var
            u,v : longint;
        begin
            v := t;
            repeat
              u := trace[v];
              inc(f[u,v]); dec(f[v,u]);
              v := u;
            until u = 0;
        end;

Procedure xuli;
        var
            kt : boolean;
            kq,i,dem : longint;
        begin
            repeat
              kt := findpath;
              if kt then tangluong;
            until kt = false;

            kq := 0; dem := 0;
            for i := 1 to t - 1 do
              if f[i,t] = 1 then
              begin
                kq := kq + cost[i,t];
                inc(dem);
              end;

            if dem < n then writeln(fo,-1) else
            writeln(fo,kq);
        end;

Procedure enter;
        var
            i,j : longint;
        begin
            readln(fi,m,n);
            for i := 1 to m do
              readln(fi,s[i]);
            for i := 1 to m do read(fi,p[i]);
            tao_dt;
            xuli;
        end;

begin
    ofile;
    enter;
    cfile;
end.
