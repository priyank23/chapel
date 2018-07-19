use DataFrames;

var A = ["a", "b", "c", "d", "e"];
var I = ["A", "B", "C", "D", "E"];
var letters = new unmanaged TypedSeries(A, new unmanaged TypedIndex(I));

writeln(letters);
writeln();
writeln("contains A: " + letters.idx.contains("A"));
writeln("contains F: " + letters.idx.contains("F"));
