// Fizzbuzz solution in Obj-C for CodeEval.com by Steven A. Dunn

#import <Foundation/Foundation.h>
#import <stdio.h>

const int LINE_SIZE = 100;

NSString* fizzBuzz(int, int, int);

int main(int argc, char* argv[])
{
  NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
  FILE* inputFile = fopen(argv[1], "r");
  char rawLine[LINE_SIZE];
  if (inputFile != NULL)
  {
    while (fgets(rawLine, LINE_SIZE, inputFile) != NULL)
    {
      NSString* line = [NSString stringWithFormat:@"%s", rawLine];
      NSArray* tokens = [line componentsSeparatedByString: @" "];

      int A = [[tokens objectAtIndex:0] integerValue];
      int B = [[tokens objectAtIndex:1] integerValue];
      int N = [[tokens objectAtIndex:2] integerValue];

      NSString* result = fizzBuzz(A, B, N);
      puts([result UTF8String]);
    }
    fclose(inputFile);
  }
  [pool drain];
  return 0;
}

NSString* fizzBuzz(int A, int B, int N)
{
  NSString* result = [[NSString alloc] init];
  int i;
  for(i = 1; i <= N; ++i)
  {
    if (i % A == 0 && i % B == 0) 
      result = [result stringByAppendingString:@"FB"]; 
    else if (i % A == 0)
      result = [result stringByAppendingString:@"F"];
    else if (i % B == 0)
      result = [result stringByAppendingString:@"B"];
    else
      result = [result stringByAppendingFormat:@"%d", i];

    result = [result stringByAppendingString:@" "];
  }
  return result;
}
