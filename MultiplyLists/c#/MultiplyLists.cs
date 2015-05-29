// multiply lists soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class MultiplyLists {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] inputs = line.Split('|');
        int[] vals1 = inputs[0].Trim().Split().Select(x => Int32.Parse(x)).ToArray();
        int[] vals2 = inputs[1].Trim().Split().Select(x => Int32.Parse(x)).ToArray();

        for (int i = 0; i < vals1.Length; i++)
          Console.Write(vals1[i] * vals2[i] + " ");
        Console.WriteLine();
      }
    }
  }
}