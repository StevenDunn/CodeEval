// slang flavor soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class SlangFlavor {
  public static void Main(string[] args) {
    bool isSlang = false;
    int slangIndex = 0;
    string[] slang = {", yeah!", ", this is crazy, I tell ya.", ", can U believe this?", ", eh?", ", aw yea.", ", yo.", "? No way!", ". Awesome!"};
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string newLine = line;
        int offset = 0;
        for (int i = 0; i < line.Length; i++) {
          char c = line[i];
          if (c == '.' || c == '?' || c == '!') {
            if (isSlang) {
              newLine = new string(newLine.Take(i+offset).ToArray()) + slang[slangIndex] + new string(newLine.Skip(i + offset + 1).Take(newLine.Length - i - offset).ToArray());
              offset += slang[slangIndex].Length - 1;
              slangIndex++;
              if (slangIndex >= 8)
                slangIndex = 0;
            }
            isSlang = !isSlang;
          }
        }
        newLine = newLine.Trim();
        Console.WriteLine(newLine);
      }
    }
  }
}