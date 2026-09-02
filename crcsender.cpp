#include <stdio.h>
#include <string.h>
int main()
{
    char data[100], generator[100], codeword[200];
    int dataLen, genLen, i, j;
    printf("----- CRC Sender Side -----\n");

    printf("Enter data bits: ");
    scanf("%s", data);
    printf("Enter generator bits: ");
    scanf("%s", generator);

    dataLen = strlen(data);
    genLen = strlen(generator);

    //  Determine the length of generator
    printf("\nLength of data = %d", dataLen);
    printf("\nLength of generator = %d\n", genLen);

    // Append  zeros to data
    strcpy(codeword, data);

    for (i = 0; i < genLen - 1; i++)
    {
        codeword[dataLen + i] = '0';
    }

    codeword[dataLen + genLen - 1] = '\0';

    printf("\nData after appending zeros: %s\n", codeword);

    //  Perform  XOR division
    for (i = 0; i <= strlen(codeword) - genLen; i++)
    {
        if (codeword[i] == '1')
        {
            for (j = 0; j < genLen; j++)
            {
                if (codeword[i + j] == generator[j])
                    codeword[i + j] = '0';
                else
                    codeword[i + j] = '1';
            }
        }
    }

    //   remainder
    printf("Remainder: ");

    for (i = dataLen; i < dataLen + genLen - 1; i++)
    {
        printf("%c", codeword[i]);
    }

    //  Append remainder to original data
    printf("\nCodeword: %s", data);

    for (i = dataLen; i < dataLen + genLen - 1; i++)
    {
        printf("%c", codeword[i]);
    }

    // Transmit the codeword
    printf("\n\nCodeword transmitted successfully.\n");

    return 0;
}                                                                                  