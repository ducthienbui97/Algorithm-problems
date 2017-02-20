{$M 10000000}
{$MODE OBJFPC}
const
  fin='sed.in';
  fou='sed.out';
  maxn=10;
  base=1000000000000003;
  hashkey=1000003;
  oa=ord('a');
  maxq=100000;

type
  arr=array[1..maxn] of string;
  restype=array[1..1000000] of string;

type
  thash=^linkhash;
  linkhash=record
    v:int64;
    next:thash;
  end;

var
  n:longint;
  start,finish:string;
  a,b:array[1..maxn] of string;
  qd:array[1..maxq] of longint;
  q:array[1..maxq] of string;
  front,rear:longint;
  hash:array[0..hashkey] of thash;
  res:longint;

function code(const s:string):int64;
var
  i:longint;
begin
  result:=0;
  for i:=1 to length(s) do
    result:=(result*int64(23)+int64(ord(s[i])-oa)+1) mod base;
end;

function free(c:int64):boolean;
var
  p:thash;
begin
  p:=hash[c mod hashkey];
  while p<>nil do
    begin
      if p^.v=c then exit(false);
      p:=p^.next;
    end;
  exit(true);
end;

procedure mark(c:int64);
var
  p:thash;
begin
  new(p);
  p^.v:=c;
  p^.next:=hash[c mod hashkey];
  hash[c mod hashkey]:=p;
end;

function match(const x:string;vt:longint;y:string):boolean;
var
  i:longint;
begin
  for i:=vt to vt+length(y)-1 do
    if x[i]<>y[i-vt+1] then
      exit(false);
  exit(true);
end;

procedure solve;
var
  i,j,l:longint;
  x,y:string;
  c:int64;
begin
  front:=0;
  rear:=1;
  q[1]:=start;
  mark(code(q[1]));
  repeat
    inc(front);
    x:=q[front];
    l:=length(x);
    for i:=1 to n do
      begin
        y:='';
        j:=1;
        while j+length(a[i])-1<=l do
          begin
            if match(x,j,a[i]) then
              begin
                y:=y+b[i];
                j:=j+length(a[i]);
              end
            else
              begin
                y:=y+x[j];
                j:=j+1;
              end;
          end;
        if j<=l then
          y:=y+copy(x,j,l-j+1);
        if length(y)>124 then continue;
//        writeln(i,' ',x,'->',y);
        c:=code(y);
        if free(c) then
          begin
            mark(c);
            inc(rear);
            if rear>=maxq then
              begin
                writeln(-1);
                close(input);close(output);
                halt;
              end;
            q[rear]:=y;
            qd[rear]:=qd[front]+1;
            if y=finish then
              begin
                writeln(qd[rear]);
                close(input);close(output);
                halt;
              end;
         end;
      end;
  until front>=rear;
end;

var
  i,j:longint;
  s:string;

begin
  assign(input,fin);reset(input);
  assign(output,fou);rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      for j:=1 to length(s) do
        if s[j]=' ' then
          begin
            a[i]:=copy(s,1,j-1);
            b[i]:=copy(s,j+1,length(s)-j);
            break;
          end;
    end;
  readln(start);
  readln(finish);
  if start=finish then
    writeln(0)
  else
    begin
      solve;
      writeln(-1);
    end;
  close(input);close(output);
end.
