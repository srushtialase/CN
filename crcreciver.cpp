#include <stdio.h>
#include <string.h>

int main()
{
    char codeword[200], generator[100];
    int codeLen, genLen;
    int i, j;
    int error = 0;
    printf("----- CRC Receiver Side -----\n");

    //  Read received codeword and generator
    printf("Enter received codeword: ");
    scanf("%s", codeword);

    printf("Enter generator bits: ");
    scanf("%s", generator);

    codeLen = strlen(codeword);
    genLen = strlen(generator);

    // Determine generator length
    printf("\nLength of generator = %d\n", genLen);

    // Perform XOR division
      for (i = 0; i <= codeLen - genLen; i++)
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

    // Check the remainder
    printf("Remainder: ");

    for (i = codeLen - genLen + 1; i < codeLen; i++)
    {
        printf("%c", codeword[i]);

        if (codeword[i] == '1')
            error = 1;
    }

    //  Check whether error is occurred or not
    if (error == 0)
    {
        printf("\n\nNo error detected.");
        printf("\nData received correctly.");
    }
    else
    {
        printf("\n\nError detected in received data.");
    }

    //  Stop
    return 0;
}