#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip[16];

    printf("Enter IPv4 address: ");
    scanf("%15s", ip);

    /* Check first octet and determine class */
    if (atoi(ip) >= 1 && atoi(ip) <= 126)
    {
        printf("\nValid IPv4 Address");
        printf("\nClass: A");

        strtok(ip, ".");
        printf("\nNetwork ID: %s", ip);
        printf("\nHost ID: %s.%s.%s",
               strtok(NULL, "."),
               strtok(NULL, "."),
               strtok(NULL, "."));
    }
    else if (atoi(ip) >= 128 && atoi(ip) <= 191)
    {
        printf("\nValid IPv4 Address");
        printf("\nClass: B");

        printf("\nNetwork ID: %s.%s",
               strtok(ip, "."),
               strtok(NULL, "."));

        printf("\nHost ID: %s.%s",
               strtok(NULL, "."),
               strtok(NULL, "."));
    }
    else if (atoi(ip) >= 192 && atoi(ip) <= 223)
    {
        printf("\nValid IPv4 Address");
        printf("\nClass: C");

        printf("\nNetwork ID: %s.%s.%s",
               strtok(ip, "."),
               strtok(NULL, "."),
               strtok(NULL, "."));

        printf("\nHost ID: %s",
               strtok(NULL, "."));
    }
    else if (atoi(ip) >= 224 && atoi(ip) <= 239)
    {
        printf("\nValid IPv4 Address");
        printf("\nClass: D (Multicast)");
    }
    else if (atoi(ip) >= 240 && atoi(ip) <= 255)
    {
        printf("\nValid IPv4 Address");
        printf("\nClass: E (Experimental)");
    }
    else
    {
        printf("\nInvalid IPv4 Address");
    }

    return 0;
}