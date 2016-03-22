// simple or trump soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compare_hands(char*, char*, char*);
int convert(char*);

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[16];
		while (fgets(line, sizeof(line), fp))
		{
			char *token, *hands, *hand1, *hand2, *trump;
			int comp;

			token = strtok(line, "|");
			hands = line;

			token = strtok(NULL, "|");
			trump = token;

			token = strtok(hands, " ");
			hand1 = token;

			token = strtok(NULL, " ");
			hand2 = token;

			comp = compare_hands(hand1, hand2, trump);
			if (comp < 0)
				printf("%s \n", hand1);
			else if (comp > 0)
				printf("%s \n", hand2);
			else
				printf("%s %s \n", hand1, hand2);
		}
		fclose(fp);
	}
	return 0;
}


int compare_hands(char* hand1, char* hand2, char* trump)
{
	int idx;
	char sub1[4], sub2[4];
	char hand1_copy[strlen(hand1)], hand2_copy[strlen(hand2)];

	memset(hand1_copy, '\0', sizeof(hand1_copy));
	memset(hand2_copy, '\0', sizeof(hand2_copy));

	strcpy(hand1_copy, hand1);
	strcpy(hand2_copy, hand2);

	if (hand1_copy[strlen(hand1_copy) - 1] != hand2_copy[strlen(hand2_copy) - 1])
	{
		if (hand1_copy[strlen(hand1_copy)-1] == trump[1])
		{
			hand1_copy[0] = 'T';
			strcpy(hand1_copy+1, hand1 + strlen(hand1) - 1);
		}

		if (hand2_copy[strlen(hand2_copy)-1] == trump[1])
		{
			hand2_copy[0] = 'T';
			strcpy(hand2_copy+1, hand2 + strlen(hand2) - 1);
		}
	}

	memcpy(sub1, &hand1_copy[0], strlen(hand1_copy));
	sub1[strlen(hand1_copy)-1] = '\0';
	memcpy(sub2, &hand2_copy[0], strlen(hand2_copy));
	sub2[strlen(hand2_copy)-1] = '\0';

	int val_1 = convert(sub1);
	int val_2 = convert(sub2);
	if (val_1 > val_2)
		return -1;
	else if (val_1 < val_2)
		return 1;
	return 0;
}


int convert(char* val)
{
	if (!strcmp(val, "T"))
		return 15;
	if (!strcmp(val, "A"))
		return 14;
	if (!strcmp(val, "K"))
		return 13;
	if (!strcmp(val, "Q"))
		return 12;
	if (!strcmp(val, "J"))
		return 11;
	return atoi(val);
}