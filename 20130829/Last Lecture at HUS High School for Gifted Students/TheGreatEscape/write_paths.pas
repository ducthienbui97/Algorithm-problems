program write_paths;
var i,j,v:longint;
    f:text;
BEGIN
     assign(f,'paths.txt');
     rewrite(f);
     writeln(f,'tests\escape.i0-0');
     writeln(f,'tests\escape.o0-0');
     for i:=1 to 10 do
         begin
              if i<5 then v:=4 else v:=5;
              for j:=0 to v do
                  begin
                       writeln(f,'tests\escape.i',i,'-',j);
                       writeln(f,'tests\escape.o',i,'-',j);
                  end;
         end;
     close(f);
END.
