// lowest unique number soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class LowestUniqueNumber {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        int[] nums = line.Split().Select(x => Int32.Parse(x)).ToArray();
        int lowest = 10;
        var groups = nums.GroupBy(x => x);
        foreach (var group in groups)
          if (group.Count() == 1 && group.Key < lowest)
            lowest = group.Key;

        if (lowest == 10)
          Console.WriteLine(0);
        else
          Console.WriteLine(Array.IndexOf(nums, lowest) + 1);
      }
    }
  }
}