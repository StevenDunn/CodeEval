// swap elements soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class SwapElements {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] inputs = line.Split(':');
        string[] numbers = inputs[0].Trim().Split().ToArray();
        string[] ranges = inputs[1].Trim().Split(',').Select(x => x.Trim()).ToArray();
        foreach (string range in ranges) {
          string[] splitRange = range.Split('-');
          int start = Int32.Parse(splitRange[0]);
          int end = Int32.Parse(splitRange[1]);

          string temp = numbers[start];
          numbers[start] = numbers[end];
          numbers[end] = temp;
        }

        Console.WriteLine(String.Join(" ", numbers));
      }
    }
  }
}
