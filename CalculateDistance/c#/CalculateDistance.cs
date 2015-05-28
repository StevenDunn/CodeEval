// calculate distance soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class FindAWriter {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] inputs = line.Split(new String[] { ") (" }, StringSplitOptions.None);
        int[] coord1 = inputs[0].Substring(1).Split(',').Select(x => Int32.Parse(x)).ToArray();
        int[] coord2 = inputs[1].Substring(0, inputs[1].Length - 1).Split(',').Select(x => Int32.Parse(x)).ToArray();

        int distance = (int)Math.Sqrt(
          Math.Pow(coord1[0] - coord2[0], 2) + 
          Math.Pow(coord1[1] - coord2[1], 2));

        Console.WriteLine(distance);
      }
    }
  }
}