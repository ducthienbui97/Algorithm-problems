uses math,windows;
const
 fin            ='virus.in';
 fout           ='virus.out';
 maxn           =5;
 maxt           =34000000;
 maxqueue       =3000000;
 px             :array[1..8] of longint = (0,0,1,1,1,-1,-1,-1);
 py             :array[1..8] of longint = (1,-1,0,1,-1,0,1,-1);

type
 dulieu         =record
                x,y:longint;
                a:array[1..maxn,1..maxn] of char;
                end;
 sohieu         =record
                x,y,t:longint;
                end;


var
 fi,fo          :text;
 free           :array[1..maxn,1..maxn,0..maxt] of boolean;
 Queue          :array[0..maxqueue] of sohieu;
 minlen         :array[0..maxqueue] of longint;
 first,last     :longint;
 st             :dulieu;
 n              :longint;
 result         :longint;

 start,finish   :longword;

procedure mofile;
 begin
  assign(fi,fin);reset(fi);
  assign(fo,fout);rewrite(fo);
 end;

procedure dongfile;
 begin
  close(fo);close(fi);
 end;

function docbit(x,vt:longint) : longint;
 begin
  docbit := (x shr vt) and 1;
 end;

procedure chuyensohieu(var d:dulieu;var sh:sohieu) ;
 var
  i,j:longint;
 begin
  sh.x := d.x;
  sh.y := d.y;
  sh.t := 0;

  with sh do
   for i:= 1 to n do
    for j:= 1 to n do
     if d.a[i,j] <> '.' then t := t + (1 shl ((i-1) * n + j - 1));
 end;

procedure chuyendulieu(var sh:sohieu ; var d:dulieu);
 var
  i,j:longint;
 begin
  for i:=1 to n do
   for j:=1 to n do
    if docbit(sh.t,(i-1) * n + j - 1) = 1 then d.a[i,j] := '#'
    else d.a[i,j] := '.';

  d.x := sh.x;
  d.y := sh.y;
  d.a[sh.x,sh.y] := '@';
 end;

procedure nhap;
 var
  i,j:longint;
 begin
  readln(fi,n);

  with st do
   for i:=1 to n do
    begin
     for j:=1 to n do
      begin
       read(fi,a[i,j]);
       if a[i,j] = '@' then
        begin
         x := i;
         y := j;
        end;
      end;
     readln(fi);
    end;
 end;

procedure chbi;
 begin
  result := -1;
 end;

function demlaynhiem(var d:dulieu ; x,y:longint) : longint;
 var
  p,u,v,count : longint;
 begin
  count := 0;
  for p := 1 to 8 do
   begin
    u := x + px[p];
    v := y + py[p];
    if (u >= 1) and (u <= n)
    and (v >= 1) and (v <= n)
    and (d.a[u,v] <> '.') then inc(count);
   end;

  demlaynhiem := count;
 end;

procedure capnhat(var d:dulieu);
 var
  t,i,j:longint;
  dd:dulieu;
 begin
  with d do
   begin
    for i:=1 to n do
     for j:=1 to n do
      if a[i,j] = '#' then
       begin
        t := demlaynhiem(d,i,j);
        if (t >= 2) and (t <= 3) then dd.a[i,j] := '#'
        else dd.a[i,j] := '.';
       end;

    for i:=1 to n do
     for j:=1 to n do
      if a[i,j] = '.' then
       begin
        t := demlaynhiem(d,i,j);
        if t = 3 then dd.a[i,j] := '#'
        else dd.a[i,j] := '.';
       end;
   end;

  dd.x := d.x;
  dd.y := d.y;
  dd.a[d.x,d.y] := '@';
  d := dd;
 end;

procedure BFS;
 var
  u,v:dulieu;
  uu,vv:sohieu;
  p : longint;
 begin
  first := 1;
  last := 1;


  chuyensohieu(st,uu);

  queue[1] := uu;
  free[uu.x,uu.y,uu.t] := true;
  minlen[1] := 0;

  while first <= last do
   begin
    //chan time
    finish := gettickcount;
    if finish - start > 980 then exit;

    uu := queue[first];
    if uu.t = 1 shl ((uu.x - 1) * n + uu.y - 1) then
     begin
      result := minlen[first];
      exit;
     end;

    chuyendulieu(uu,u);

    for p:=1 to 8 do
     begin
      v.x := u.x + px[p];
      v.y := u.y + py[p];

      if (v.x >= 1) and (v.x <= n)
      and (v.y >= 1) and (v.y <= n)
      and (u.a[v.x,v.y] = '.') then
       begin
        v.a := u.a;
        v.a[v.x,v.y] := '@';
        v.a[u.x,u.y] := '.';

        capnhat(v);

        chuyensohieu(v,vv);

        if free[vv.x,vv.y,vv.t] = false then
         begin
          free[vv.x,vv.y,vv.t] := true;

          inc(last);
          minlen[last mod maxqueue] := minlen[first mod maxqueue] + 1;
          queue[last mod maxqueue] := vv;

          if vv.t = 1 shl ((vv.x - 1) * n + vv.y - 1) then
           begin
            result := minlen[last mod maxqueue];
            exit;
           end;
         end;
       end;
     end;

    inc(first);
   end;
 end;

procedure inkq;
 begin
  writeln(fo,result);
 end;

begin
 start := gettickcount;

 mofile;

 nhap;
 chbi;
 BFS;
 inkq;

 dongfile;
end.
