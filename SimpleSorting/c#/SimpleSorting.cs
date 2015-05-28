// simple sorting soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class SimpleSorting {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;
        
        float[] values = line.Split(' ').Select(x => float.Parse(x)).ToArray();
        Array.Sort(values);
        string result = string.Concat(values.Select(x => string.Format("{0:0.000} ", x)));
        Console.WriteLine(result);
      }
    }
  }

}