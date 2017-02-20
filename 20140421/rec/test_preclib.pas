(** 
 * This is a sample judging unit. 
 * It implements a very simple strategy.
 * Feel free to modify the implementation part, 
 * and test your program against a better opponent.  
 * However, during the evaluation, your program will be
 * playing against a DIFFERENT opponent.
			
 * After each modification of this file, please recompile it 
 * using the following command:
 *   ppc386 -O2 preclib.pas
 * This command produces files preclib.o and preclib.ppu. 
 * These files are needed to compile your program, and 
 * should be placed in the directory, where your program is located.
 *)
unit preclib;

(**
 * Please do not modify the interface part of this file.
 * It HAS TO be compatible with declarations in the task description.
 *)
interface

type
  direction = (vertical, horizontal);

function dimension_x : longint;
function dimension_y : longint;
procedure cut(dir : direction; position : longint);

implementation

var 
  x, y : longint;                           { Private variables - size of the board }

(** 
 * Maximum of two integers 
 *)
function max(a, b : longint) : longint;     
begin
  if a > b then max := a
  else max := b;
end;

(**
 * Return x dimension of the board
 *)
function dimension_x : longint;             
begin
  writeln('dimension_x() = ', x);
  dimension_x := x;
end; 

(**
 * Return x dimension of the board
 *)
function dimension_y : longint;             
begin
  writeln('dimension_y() = ', y);
  dimension_y := y;
end; 

(**
 * This procedure makes a move for your opponent (computer).
 * If you want to implement your own strategy you should
 * change its first part.
 *)
procedure make_move;                        
var 
  r : longint;     { Where should we divide the board? }
begin
  { First part - make a move }
  if ((random(2) = 0) and (y > 1)) or (x = 1) then begin
    r := random(y - 1) + 1;
    y := max(r, y - r);
  end
  else begin
    r := random(x - 1) + 1;
    x := max(r, x - r);
  end;
  { Second part - check if computer won }
  if (x = 1) and (y = 1) then begin
    writeln('You lose!');
    halt(0);
  end;
end;

(**
 * Check if player's move is legal and register it
 *)
procedure cut(dir : direction; position : longint);
begin
  write('cut(');
  if dir = horizontal then
    write('horizontal')
  else
    write('vertical');
  writeln(', ', position, ')');

  { Register user move }
  if dir = horizontal then begin
    if (position < 1) or (position >= y) then begin
      writeln('Illegal move!');                            { Wrong move }
      halt(0);
    end;
    y := max(position, y - position);
  end
  else begin
    if (position < 1) or (position >= x) then begin
      writeln('Illegal move!');                            { Wrong move }
      halt(0);
    end;
    x := max(position, x - position);
  end;
  if (x = 1) and (y = 1) then begin
    writeln('You win!');                   { You win - congratulations! }
    halt(0);
  end;
  { Make computer player move }
  make_move;
end; 

(**
 * Some initialization.
 *)
begin
  randomize;
  writeln('Enter x dimension:');
  read(x);
  writeln('Enter y dimension:');      
  read(y);
end.
