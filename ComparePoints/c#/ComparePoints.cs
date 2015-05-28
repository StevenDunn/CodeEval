// compare points soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class ComparePoints {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        int[] points = line.Split().Select(x => Int32.Parse(x)).ToArray();
        int o = points[0];
        int p = points[1];
        int q = points[2];
        int r = points[3];

        if (o == q) {
          if (p == r) Console.WriteLine ("here");
          if (p < r) Console.WriteLine ("N");
          if (p > r) Console.WriteLine ("S");
        }
        if (o < q) {
          if (p == r) Console.WriteLine ("E");
          if (p < r) Console.WriteLine ("NE");
          if (p > r) Console.WriteLine ("SE");
        }
        if (o > q) {
          if (p == r) Console.WriteLine ("W");
          if (p < r) Console.WriteLine ("NW");
          if (p > r) Console.WriteLine ("SW");
        }
      }
    }
  }
}