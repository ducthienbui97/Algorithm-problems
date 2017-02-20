const
        finp    = 'artwork.in';
        fout    = 'artwork.out';
        maxn    = 22;

var
        fi,fo           : text;
        m,n             : longint;
        dx,dy           : array[0..maxn] of longint;

Procedure ofile;
        begin
            assign(fi,finp); reset(fi);
            assign(fo,fout); rewrite(fo);
        end;

Procedure cfile;
        begin
            close(fi); close(fo);
        end;

Procedure enter;
        var
            kq,i,x : longint;
        begin
            readln(fi,n,m);
            for i := 1 to n do
              begin
                  read(fi,x);
                  inc(dx[x]);
              end;
            for i := 1 to m do
              begin
                  read(fi,x);
                  inc(dy[x]);
              end;
            kq := 0;
            for i := maxn downto 1 do
              if dx[i] > dy[i] then kq := kq + dx[i] * i
              else kq := kq + dy[i] * i;
            writeln(fo,kq);
        end;

begin
    ofile;
    enter;
    cfile;
end.
