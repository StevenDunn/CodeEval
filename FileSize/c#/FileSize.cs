// file size soln in c# for code eval by steven a dunn

using System;
using System.IO;

class FileSize {
	public static void Main(string[] args) {
		FileInfo f = new FileInfo(args[0]);
		Console.WriteLine(f.Length);
	}
}