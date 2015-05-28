// minimum distance soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class MinimumDistance {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

          int[] addresses = line.Split().Select(x => Int32.Parse(x)).Skip(1).Take(line.Length).ToArray();
          Array.Sort(addresses);
          int min = addresses.First();
          int max = addresses.Last();

          long min_distance = 500000;
          for (int i = min; i <= max; i++) {
            long distance = getDistance(addresses, i);
            if (distance < min_distance)
              min_distance = distance;
          }
          Console.WriteLine(min_distance);
      }
    }
  }

  static long getDistance(int[] addresses, int i) {
    long distance = 0;
    foreach (int address in addresses)
      distance += Math.Abs(address - i);
    return distance;
  }
}
