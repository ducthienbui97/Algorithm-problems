{$I+,OBJECTCHECKS-,Q+,R+,S+}
{$IFDEF NORMAL}
  {$I+,OBJECTCHECKS-,Q+,R+,S+}
{$ENDIF NORMAL}
{$IFDEF DEBUG}
  {$I+,OBJECTCHECKS-,Q+,R+,S+}
{$ENDIF DEBUG}
{$IFDEF RELEASE}
{$I-,OBJECTCHECKS-,Q+,R+,S+}
{$ENDIF RELEASE}
program CheckCirlceCut;
uses Crt, DOS;
const
  InputFile  = 'cut.in';
  OutputFile = 'cut.out';
  max = 100;
  eps = 1e-4;
  eps2 = 1e-10;
type
  Integer = LongInt;
  TCircle = record
    x, y, r : Real;
  end;
var
  C : array[1..max] of TCircle;
  maxX, maxY, maxr : Real;
  n : Integer;
  filename : String;
  t_id : Char;

 procedure InputData;
 var
   fi, fo : Text;
   i, tx, ty, tr : Integer;
 begin
   Assign(fi, InputFile + t_id);
   Reset(fi);
   Assign(fo, InputFile + 'p');
   Rewrite(fo);
   Readln(fi, tx, ty, n);
   Writeln(fo, tx, ' ', ty, ' ', n);
   maxX := tx;
   maxY := ty;
   for i := 1 to n do with C[i] do
   begin
     Readln(fi, tx, ty, tr);
     Writeln(fo, tx, ' ', ty, ' ', tr);
     x := tx;
     y := ty;
     r := tr;
   end;
   Close(fi);
   Close(fo);
 end;


 procedure Message(S : string);
 begin
   Writeln;
   Writeln('    ' + S + ' !');
   Readln;
   Halt;
 end;

 function Min(a, b : Real): Real;
 begin
   if (a < b) then Min := a
   else Min := b;
 end;

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

   for i := 1 to n do with C[i] do
    if (Distance(x, y, px, py)+eps < r + pr) then Exit;

   CheckCircle := true;
 end;

 function Case2X(x, y, r, py, pr : Real) : Boolean;
 var
   d, dy, dx : Real;
 begin
   dy := y - py;
   d := r + pr;
   if (Abs(dy) > d + eps) then
   begin
     Case2X := False;
     Exit;
   end;
   dx := sqrt(sqr(d) - sqr(dy) + eps2);
   Case2X := CheckCircle(x - dx, py, pr) or
             CheckCircle(x + dx, py, pr);
 end;

 function Case2Y(x, y, r, px, pr : Real) : Boolean;
 var
   d, dy, dx : Real;
 begin
   dx := x - px;
   d := r + pr;
   if (Abs(dx) > d + eps) then
   begin
     Case2Y := False;
     Exit;
   end;
   dy := sqrt(sqr(d) - sqr(dx) + eps2);
   Case2Y := CheckCircle(px, y + dy, pr) or
             CheckCircle(px, y - dy, pr);
 end;

 function CheckRadius(radius : Real): Boolean;
 var
   i, j : Integer;
   d, h, d1, d2, d3, dx, dy, cx, cy, px, py : Real;
 begin
   CheckRadius := True;
   if CheckCircle(radius, radius, radius) then Exit;
   if CheckCircle(radius, maxY - radius, radius) then Exit;
   if CheckCircle(maxX - radius, radius, radius) then Exit;
   if CheckCircle(maxX - radius, maxY - radius, radius) then Exit;
   {case 2}
   for i := 1 to n do with C[i] do
   begin
     if Case2X(x, y, r, radius, radius) then Exit;
     if Case2X(x, y, r, maxY - radius, radius) then Exit;
     if Case2Y(x, y, r, radius, radius) then Exit;
     if Case2Y(x, y, r, maxX - radius, radius) then Exit;
   end;
   {case 3}
   for i := 1 to n-1 do
    for j := i+1 to n do
    begin
      d1 := C[i].r + radius;
      d2 := C[j].r + radius;
      dx := C[j].x - C[i].x;
      dy := C[j].y - C[i].y;
      d3 := Distance(0, 0, dx, dy);
      if (d3 > d1 + d2 + eps) then Continue;
      d := ((d1-d2)*(d1+d2)/d3 + d3) / 2;
      h := sqrt(d1*d1 - d*d + eps2);
      dx := dx / d3;
      dy := dy / d3;
      cx := C[i].x + d*dx;
      cy := C[i].y + d*dy;
      px := cx + h*dy;
      py := cy - h*dx;
      if CheckCircle(px, py, radius) then Exit;
      px := cx - h*dy;
      py := cy + h*dx;
      if CheckCircle(px, py, radius) then Exit;
    end;
   CheckRadius := False;
 end;

 procedure Process;
 var
   r_min, r_max, r : Real;
 begin
   r_min := 0;
   r_max := Min(maxX, maxY)/2;
   while (r_min + eps < r_max) do
   begin
     r := (r_min + r_max) / 2;
     if CheckRadius(r) then r_min := r
     else r_max := r;
   end;
   maxr := r_min;
 end;



 procedure Check;
 var
   f : Text;
   x, y, r : Real;
 begin
   Assign(f, OutputFile);
   Reset(f);
   Readln(f, x, y, r);
   Close(f);
   if (maxr - 0.01 > r) then begin
     Writeln('SAI: Khong toi uu: ', maxr : 0 : 3, ' ', r : 0 : 3);
     Exit;
   end;
   if (CheckCircle(x, y, r) = False) then
   begin
     Writeln('LOI: Hinh tron dua ra khong hop le');
     Exit;
   end;
   Writeln('DUNG');
 end;

begin
  ClrScr;
  writeln('##################################################');
  writeln('########                                     #####');
  writeln('######## Chuong trinh cham bai CAT HINH TRON #####');
  writeln('########                                     #####');
  writeln('##################################################');
  Writeln;
  Write('File name : ');
  Readln(filename);
  filename := filename + '.exe';
  for t_id := '0' to '9' do
  begin
    Write('Test thu ' + t_id + ' - ');
    InputData;
    Process;
    Exec(filename, '');
    Check;
  end;
  Writeln('Done');
  Readln;
end.
