uses math;
const
 fin            ='stock.in';
 fout           ='stock.out';
 maxn           =244;

type
 node           =^link;
 link           =record
                v:longint;
                next:node;
                end;

var
 fi,fo          :text;
 cnode          :array[0..maxn] of node;
 c              :array[0..maxn,0..maxn] of boolean;
 free           :array[0..maxn] of longint;
 n,t            :longint;
 st,fn          :longint;
 result         :longint;

procedure mofile;
 begin
  assign(fi,fin);reset(fi);
  assign(fo,fout);rewrite(fo);
 end;

procedure dongfile;
 begin
  close(fo);close(fi);
 end;

procedure nhap;
 begin
  read(fi,n,t);
 end;

procedure chbi;
 var
  i:longint;
 begin
  fillchar(c,sizeof(c),false);
  for i:=1 to n do
  begin
   c[i,i] := true;
   cnode[i] := nil;
  end;
  result := 0;
 end;

procedure DFS(u,gt:longint);
 var
  v:longint;
  p:node;
 begin
  c[st,u] := true;
  free[u] := gt;
  if free[fn] = gt then exit;

  p := cnode[u];
  while p <> nil do
   begin
    if (free[p^.v] <> gt) and c[u,p^.v] then
     begin
      DFS(p^.v,gt);
     end;
    p := p^.next;
   end;
 end;

procedure add(u,v:longint);
 var
  p:node;
 begin
  new(p);
  p^.v:=v;
  p^.next := cnode[u];
  cnode[u] := p;
 end;

procedure xuli;
 var
  I:longint;
 begin
  for i:=1 to t do
   begin
    read(fi,st,fn);
    if c[st,fn] then
     begin
      inc(result);
      continue;
     end;
    DFS(st,i);
    if free[fn] = i then inc(result)
    else
    if c[fn,st] = false then
     begin
      add(fn,st);
      c[fn,st] := true;
     end;
   end;
 end;

procedure inkq;
 begin
  writeln(fo,result);
 end;

begin
 mofile;

 nhap;
 chbi;
 xuli;
 inkq;

 dongfile;
end.
