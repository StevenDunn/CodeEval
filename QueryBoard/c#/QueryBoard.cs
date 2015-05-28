// Query Board soln in c# for code eval by steven a dunn

using System;
using System.IO;

class QueryBoard {

  static int[,] board = new int[256, 256];

  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;
        
        string[] inputs = line.Split(' ');
        string command = inputs[0];
        string param1 = inputs[1];
        string param2 = "";
        if (inputs.Length > 2)
          param2 = inputs[2];

        parseCommand(command, param1, param2);
      }
    }
  }

  static void parseCommand(string command, string p1, string p2) {
    int param1 = Int32.Parse(p1);
    int param2 = 0;
    if (p2.Length != 0)
      param2 = Int32.Parse(p2);

    int sum = 0;
  
    if (command == "SetRow")
      for (int i = 0; i < 256; i++)
        board[i, param1] = param2;

    else if (command == "SetCol")
      for (int j = 0; j < 256; j++)
        board[param1, j] = param2;

    else if (command == "QueryRow") {
      for (int i = 0; i < 256; i++)
        sum += board[i, param1];
      Console.WriteLine(sum);
    }

    else if (command == "QueryCol") {
      for (int j = 0; j < 256; j++)
        sum += board[param1, j];
     Console.WriteLine(sum);
    }
  }
}