program swimmers;
const
  input  = 'swimmers.in';
  output = 'swimmers.out';
  maxn = 54;
  maxv = 100000;
type
  list = array[0..maxn] of record
    id,dis: longint;
  end;

  queue = record
    front,rear: longint;
    d: list;
  end;
var
  p,c: array[1..maxn] of longint;
  q1,q2: queue;
  res: longint;
  n: longint;

  nlist: longint;
  lt: array[1..maxn] of longint;

procedure init;
var
  f: text;
  i: longint;
begin
  assign(f, input);
    reset(f);

  readln(f, n);
  for i := 1 to n do readln(f, p[i], c[i]);

  close(f);
end;

procedure sort;
var
  i,j,tmp: longint;
begin
  for i := 1 to n - 1 do
    for j := i + 1 to n do
      if p[i] > p[j] then
        begin
          tmp := p[i];  p[i] := p[j];  p[j] := tmp;
          tmp := c[i];  c[i] := c[j];  c[j] := tmp;
        end;
end;

procedure push(var q: queue; x,v: longint);
begin
  q.rear := (q.rear + 1) mod maxn;
  q.d[q.rear].id := x;
  q.d[q.rear].dis := v;
end;

function empty(t1,t2: longint): boolean;
begin
  empty := (t1 - t2 = 1) or (t2 - t1 = maxn - 1);
end;

procedure up(x: longint);
var
  u,v,t: longint;
  i,j: longint;
begin
  res := res + x;
  t := q1.front;

  while not empty(t,q1.rear) do
    begin
      v := q1.d[t].dis;
       if v > x then
        q1.d[t].dis := q1.d[t].dis - x
      else q1.d[t].dis := 0;

      t := (t + 1) mod maxn;
    end;

  t := q2.front;
  while not empty(t,q2.rear) do
    begin
      v := q2.d[t].dis;
      if v > x then q2.d[t].dis := q2.d[t].dis - x
               else q2.d[t].dis := 0;
      t := (t + 1) mod maxn;
    end;

  nlist := 0;
  while not empty(q1.front,q1.rear) and (q1.d[q1.front].dis = 0) do
    begin
      u := q1.d[q1.front].id;
      inc(nlist);  lt[nlist] := u;
      q1.front := (q1.front + 1) mod maxn;
    end;
  for i := 1 to nlist - 1 do
    for j := i + 1 to nlist do
      if lt[i] > lt[j] then
        begin
          u := lt[i];  lt[i] := lt[j];  lt[j] := u;
        end;
  for i := 1 to nlist do
    begin
      u := lt[i];
      push(q2,u,p[u]);
    end;


  nlist := 0;
  while not empty(q2.front,q2.rear) and (q2.d[q2.front].dis = 0) do
    begin
      u := q2.d[q2.front].id;
      dec(c[u]);
      if c[u] > 0 then
        begin
          inc(nlist);  lt[nlist] := u;
        end;
      q2.front := (q2.front + 1) mod maxn;
    end;
  for i := 1 to nlist - 1 do
    for j := i + 1 to nlist do
      if lt[i] > lt[j] then
        begin
          u := lt[i];  lt[i] := lt[j];  lt[j] := u;
        end;
  for i := 1 to nlist do
    begin
      u := lt[i];
      push(q1,u,p[u]);
    end;
end;

procedure solve;
var
  t,i,min: longint;
begin
  res := 0;
  q1.front := 1;  q1.rear := 0;
  q2.front := 1;  q2.rear := 0;

  for i := 1 to n do push(q1,i,p[i]);

  repeat
    min := maxv;

    if not empty(q1.front,q1.rear) then
      begin
        t := q1.front;
        while not empty(t,q1.rear) do
          begin
            if (min > q1.d[t].dis) and (q1.d[t].dis <> 0) then min := q1.d[t].dis;
            t := (t + 1) mod maxn;
          end;
      end;

    if not empty(q2.front,q2.rear) then
      begin
        t := q2.front;
        while not empty(t,q2.rear) do
          begin
            if (min > q2.d[t].dis) and (q2.d[t].dis <> 0) then min := q2.d[t].dis;
            t := (t + 1) mod maxn;
          end;
      end;

    if min = maxv then break;
    up(min);
  until false;
end;

procedure printresult;
var
  f: text;
begin
  assign(f, output);
    rewrite(f);
    writeln(f, res);
  close(f);
end;

begin
  init;
  sort;
  solve;
  printresult;
end.

