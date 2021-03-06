// Iterators yielding arrays - by value or by reference?

const P = {1..1};
var cnt = 222;

var global: [P]int;

iter rtValIter() : [P]int {
  var p: [P]int;
  p[1] = 111;
  writeln("rtval-1 ", p[1]);
  yield p;
  writeln("rtval-2 ", p[1]);
  yield p;
  writeln("rtval-3 ", p[1]);
}

iter rtRefIter() ref : [P]int {
  global[1] = 111;
  writeln("rtref-1 ", global[1]);
  yield global;
  writeln("rtref-2 ", global[1]);
  yield global;
  writeln("rtref-3 ", global[1]);
}

iter ntValIter() {
  var p: [P]int;
  p[1] = 111;
  writeln("ntval-1 ", p[1]);
  yield p;
  writeln("ntval-2 ", p[1]);
  yield p;
  writeln("ntval-3 ", p[1]);
}

iter ntRefIter() ref {
  global[1] = 111;
  writeln("ntref-1 ", global[1]);
  yield global;
  writeln("ntref-2 ", global[1]);
  yield global;
  writeln("ntref-3 ", global[1]);
}

writeln();

for rtValVar in rtValIter() {
  writeln("   body ", rtValVar[1], "  cnt ", cnt);
  rtValVar[1] = cnt;
  cnt += 111;
}
writeln();

for rtRefVar in rtRefIter() {
  writeln("   body ", rtRefVar[1], "  cnt ", cnt);
  rtRefVar[1] = cnt;
  cnt += 111;
}
writeln();

for ntValVar in ntValIter() {
  writeln("   body ", ntValVar[1], "  cnt ", cnt);
  ntValVar[1] = cnt;
  cnt += 111;
}
writeln();

for ntRefVar in ntRefIter() {
  writeln("   body ", ntRefVar[1], "  cnt ", cnt);
  ntRefVar[1] = cnt;
  cnt += 111;
}
writeln();
