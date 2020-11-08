const
  TaskName = 'prodsum';
  MAXN = 1+200000;
type
  int = longint;
var
  n, i: int;
  a: array[0..MAXN] of int;
  s: array[0..MAXN] of int64;
  total, t, ans: int64;
begin
  assign(input, TaskName+'.inp'); reset(input);
  assign(output, TaskName+'.out'); rewrite(output);

  read(n);
  total := 0; s[0] := 0;
  for i := 1 to n do begin
    read(a[i]);
    total := total + int64(i)*a[i];
    s[i] := s[i-1]+a[i];
  end;

  ans := 0;
  for i := 1 to n do begin
      t := s[i]-s[0]-int64(i)*a[i]+int64(0)*a[i];
      if(ans < t) then ans := t;
      t := s[i]-s[n]-int64(i)*a[i]+int64(n)*a[i];
      if(ans < t) then ans := t;
  end;
  writeln(total+ans);

  close(input); close(output);
end.
