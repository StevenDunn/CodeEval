// racing chars soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class RacingChars {
  static char update_direction(int prev, int index) {
    if (index < prev)
      return '/';
    else if (index == prev)
      return '|';
    else
      return '\\';
  }

  public static void Main(string[] args) {
    char direction = '|';
    int prev = -1;

    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        char[] output_line = line.Trim().ToCharArray();
        int gate_index = line.IndexOf('_');
        if (prev == -1)
          prev = gate_index;
        int checkpoint_index = line.IndexOf('C');
        if (checkpoint_index == -1) {
          direction = update_direction(prev, gate_index);
          output_line[gate_index] = direction;
          prev = gate_index;
        }
        else {
          direction = update_direction(prev, checkpoint_index);
          output_line[checkpoint_index] = direction;
          prev = checkpoint_index;
        }
        Console.WriteLine(new string(output_line));
      }
    }
  }
}