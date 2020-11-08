const
  TaskName = 'buymilk';
var
  a, b, c, d: int64;

function solve(x: int64): int64;
var
  e, t1, t2: int64;
begin
  e := c-d;
  if( (b<e) or (a<c) ) then exit(x div b)
  else exit( (a-d) div e + ((a-d) mod e+d) div b );
  t1 := 0; t2 := 0;
  if(x>=b) then
    t1 := x div b + solve(x mod b);
  if(x>=c) then
    t2 := (x-c) div (c-d) + 1 + solve(d+(x-c) mod (c-d));
  if(t1 > t2) then exit(t1) else exit(t2);
end;

begin
  assign(input, TaskName+'.inp'); reset(input);
  assign(output, TaskName+'.out'); rewrite(output);

  read(a, b, c, d);
  writeln(solve(a));

  close(input); close(output);
end.
