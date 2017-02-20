(**
 * A Pascal interface for judging library.
 * It includes C library which checks contestant's solution.
 *
 * Author: Szymon Wasik
 *)
unit preclib;

interface

type
  direction = (vertical, horizontal);

function dimension_x : longint;cdecl;
function dimension_y : longint;cdecl;
procedure cut(dir : direction; position : longint);cdecl;

implementation

{$LinkLib c}
{$L creclib.o}

function dimension_x : longint;cdecl;external;
function dimension_y : longint;cdecl;external;
procedure cut(dir : direction; position : longint);cdecl;external;

begin
end.
