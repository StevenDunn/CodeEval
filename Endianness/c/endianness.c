// endianness soln in c for code eval by steven a dunn

#include <stdio.h>

int main (int argc, char* const argv[])
{
    // cribbed from boost
    short int number = 0x01;
    char *numPtr = (char*)&number;
    if (numPtr[0] == 1)
        puts("LittleEndian");
    else
        puts("BigEndian");
    return 0;
}