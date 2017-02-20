{$IFDEF NORMAL}
  {$I+,OBJECTCHECKS-,Q+,R+,S+}
{$ENDIF NORMAL}
{$IFDEF DEBUG}
  {$I+,OBJECTCHECKS-,Q+,R+,S+}
{$ENDIF DEBUG}
{$IFDEF RELEASE}
{$I-,OBJECTCHECKS-,Q+,R+,S+}
{$ENDIF RELEASE}
program Test;
const
  InputFile = 'cut.in';
  max = 100;
  limit = 10000;
  eps = 1e-4;
type
  Integer = LongInt;
  TCircle = record
    x, y, r : Real;
  end;
var
  f : Text;
  C : array[1..max] of TCircle;
  ch : Char;
  maxX, maxY : Integer;
  n, m, i : Integer;
  px, py, pr : Integer;

 function Distance(x1, y1, x2, y2 : Real) : Real;
 begin
   Distance := sqrt(sqr(x1 - x2) + sqr(y1 - y2));
 end;

 function CheckCircle(px, py, pr : Real) : Boolean;
 var
   i : Integer;
 begin
   CheckCircle := False;
   if ((px-pr < -eps) or (py-pr < -eps) or
       (maxX-px-pr < -eps) or (maxY-py-pr < -eps)) then Exit;

   for i := 1 to m do with C[i] do
    if (Distance(x, y, px, py)+eps < r + pr) then Exit;

   CheckCircle := true;
 end;

begin
  Randomize;
  n := 0;
  for ch := '0' to '9' do
   begin
     Assign(f, InputFile + ch);
     Rewrite(f);
     {Write(' Test thu '+ ch + ' ---> dai, rong, n = ');
     Readln(maxX, maxY, n);}
     maxX := 10000;
     maxY := 10000;
     n := n + 10;
     Writeln(f, maxX, ' ', maxY, ' ', n);
     for i := 1 to n do
     begin
       m := i-1;
       repeat
         px := Random(maxX);
         py := Random(maxY);
         pr := Random(maxY div 2) + 1;
       until CheckCircle(px, py, pr);
       Writeln(f, px, ' ', py, ' ', pr);
       with C[i] do
       begin
         x := px;
         y := py;
         r := pr;
       end;
     end;
     Close(f);
   end;
end.
