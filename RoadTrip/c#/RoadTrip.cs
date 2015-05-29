// road trip soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class MixedContent {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] inputs = line.Trim().Split(';');
        int[] distances = new int[inputs.Length-1];
        
        int i = 0;
        foreach (string input in inputs) {
          if (input == "")
            continue;
          string[] splitInput = input.Split(',');
          distances[i] = Int32.Parse(splitInput[1]);
          i++;
        }

        Array.Sort(distances);

        List<int> results = new List<int>();
        int curPos = 0;
        foreach (int distance in distances) {
          int location = distance - curPos;
          results.Add(location);
          curPos = distance;
        }
        Console.WriteLine(String.Join(",", results));
      }
    }
  }
}
