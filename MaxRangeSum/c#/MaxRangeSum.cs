// max range sum soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class MaxRangeSum {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

          string[] inputs = line.Split(';');
          int n = Int32.Parse(inputs[0]);
          int[] vals = inputs[1].Split().Select(x => Int32.Parse(x)).ToArray();

          int maxGain = -101;
          for (int i = 0; i < vals.Length - n + 1; i++) {
            int subGain = vals.Skip(i).Take(n).Sum();
            if (subGain > maxGain)
              maxGain = subGain;
          }

          if (maxGain > 0)
            Console.WriteLine(maxGain);
          else
            Console.WriteLine(0);
      }
    }
  }
}