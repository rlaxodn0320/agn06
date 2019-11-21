#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int l = 0;


void swap(char* left, char* right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}
int compare (const void * a, const void * h)
{
	return (*(char*)a - *(char*)h);
}
void PrintSortedPermutations(char* inStr, FILE *fp2, int n)
{
	char str3[64] = { 0 };

    // Re-implementation of algorithm described here:
    int strSize = strlen(inStr);
    // 0. Ensure input container is sorted
    qsort(inStr, strSize, sizeof(char), compare);

    int largerPermFound = 1;
    do{
		l++;
		if (n == 1 && l == 2)
			break;
		if (n == 2 && l == 3)
			break;
		if (n == 3 && l == 7)
			break;
		if (n == 4 && l == 25)
			break;
		if (n == 5 && l == 121)
			break;
		if (n == 6 && l == 721)
		    break;
        printf("[%04d]%s\n", l,inStr);
		sprintf(str3, "[%04d]%s\n", l, inStr);
		fputs(str3, fp2);
        int i;
        for (i = strSize - 2; i >= 0 && inStr[i] >= inStr[i+1]; --i)
		{
		}

        // if we couldn't find one, we're finished, else we can swap somewhere
        if (i > -1)
        {
            // 3 find character at index j such that 
            // inStr[j] = min(inStr[k]) && inStr[k] > inStr[i] for all k > i
            int j = i+1;
            int k;
            for(k=j;k<strSize && inStr[k];++k)
            {
                if (inStr[k] > inStr[i] && inStr[k] < inStr[j])
                    j = k;
            }

            // 3. Swap chars at i and j
            swap(&inStr[i], &inStr[j]);

            // 4. Sort string to the right of i
            qsort(inStr+i+1, strSize-i-1, sizeof(char), compare);
        }
        else
        {
            largerPermFound = 0;
        }

    }while(largerPermFound);
	printf("####@@####\n###@@@@###\n##@@@@@@##\n#@@@@@@@@#\n@@@@@@@@@@\nTaeWooKim\n@@@@@@@@@@\n#@@@@@@@@#\n##@@@@@@##\n###@@@@###\n####@@####");
}

int main(int argc, char* argv[]) {


	FILE* fp1, * fp2;
	char str[64] = { 0 };
	int sjh = 0;
	char str2[6] = { 0 };
	// see the usage of r, rt, w, wt, r+, w+
	if ((fp1 = fopen(argv[1], "r")) == NULL) { //fail to open file for read
		printf("fale to open file.");
		return 0;
	}

	if ((fp2 = fopen(argv[2], "wt")) == NULL) { //fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}


	fgets(str, sizeof(str), fp1);
	sjh = atoi(str);
	for (int m = 0; m < sjh; m++)
	{
		fgets(str, sizeof(str), fp1);
		str2[m] = str[0];
	}
	

	PrintSortedPermutations(str2, fp2, sjh);
	return 0;
	}



