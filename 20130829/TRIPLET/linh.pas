program triplet;
const
  input  = 'triplet.in';
  output = 'triplet.out';
var
  a1,a2,b1,b2,c1,c2: longint;
  res: int64;
  i,inf,sup: longint;

procedure init;
var
  f: text;
begin
  assign(f, input);
    reset(f);
    read(f, a1, a2, b1, b2, c1, c2);
  close(f);
end;

procedure solve;
var
  k: longint;
begin
  res := 0;
  //Check whether a <= sqrt(c2)
  k := trunc(sqrt(c2));
  if k > a2 then k := a2;

  for i := a1 to k do
    begin
      inf := c1 div i;
      if c1 mod i <> 0 then inc(inf);

      sup := c2 div i;
      if inf < b1 then inf := b1;
      if sup > b2 then sup := b2;
      if sup >= inf then res := res + (sup - inf + 1);
    end;

  //Check whether b <= sqrt(c2)
  k := trunc(sqrt(c2));
  if k > b2 then k := b2;
  for i := b1 to k do
    begin
      inf := c1 div i;
      if c1 mod i <> 0 then inc(inf);

      sup := c2 div i;
      if inf < a1 then inf := a1;
      if sup > a2 then sup := a2;
      if sup >= inf then res := res + (sup - inf + 1);
    end;

  //Check whether a and b <= sqrt(c2)
  k := trunc(sqrt(c2));
  if k > b2 then k := b2;
  for i := b1 to k do
    begin
      inf := c1 div i;
      if c1 mod i <> 0 then inc(inf);
      if inf < a1 then inf := a1;

      sup := c2 div i;
      if sup > a2 then sup := a2;
      if sup > trunc(sqrt(c2)) then sup := trunc(sqrt(c2));
      if sup >= inf then res := res - (sup - inf + 1);
    end;
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
  solve;
  printresult;
end.