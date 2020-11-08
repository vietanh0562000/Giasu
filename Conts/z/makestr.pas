const
  TaskName = 'makestr';
type
  int = longint;
var
  n, i, j, t: int;
  a: array[1..26] of int;
  ans: int64;
begin
  assign(input, TaskName+'.inp'); reset(input);
  assign(output, TaskName+'.out'); rewrite(output);

  read(n);
  for i := 1 to n do read(a[i]);

  for i := 1 to n do
    for j := i+1 to n do
      if(a[i] < a[j]) then
      begin
        t := a[i]; a[i] := a[j]; a[j] := t;
      end;
  t := a[1]; ans := 0;
  for i := 1 to n do
  begin
    if(a[i] < t) then t := a[i];
    inc(ans, t); dec(t);
    if(t=0) then break;
  end;
  writeln(ans);
  close(input); close(output);
end.
