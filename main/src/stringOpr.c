#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringOpr.h"

char *rep_str(const char *s)
{
    char *ret;
    int i, count = 0;
    const char *old = "0x1c";
    const char *new1 = "~";
    int newlen = strlen(new1);
    int oldlen = strlen(old);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], old) == &s[i])
        {
            count++;
            i += oldlen - 1;
        }
    }
    ret = (char *)malloc(i + count * (newlen - oldlen));
    i = 0;
    while (*s)
    {
        if (strstr(s, old) == s) //compare the substring with the newstring
        {
            strcpy(&ret[i], new1);
            i += newlen; //adding newlength to the new string
            s += oldlen; //adding the same old length the old string
        }
        else
            ret[i++] = *s++;
    }
    ret[i] = '\0';
    return ret;
}

char *ssid(char s[])
{
    char *token = strtok(s, "0x1c");
    return token;
}

char *pwd(char *s)
{
    char *token = strtok(s, "0x1c");
    token = strtok(NULL, "");
    token++;
    token++;
    token++;
    return token;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringOpr.h"

char *rep_str(const char *s)
{
    char *ret;
    int i, count = 0;
    const char *old = "0x1c";
    const char *new1 = "~";
    int newlen = strlen(new1);
    int oldlen = strlen(old);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], old) == &s[i])
        {
            count++;
            i += oldlen - 1;
        }
    }
    ret = (char *)malloc(i + count * (newlen - oldlen));
    i = 0;
    while (*s)
    {
        if (strstr(s, old) == s) //compare the substring with the newstring
        {
            strcpy(&ret[i], new1);
            i += newlen; //adding newlength to the new string
            s += oldlen; //adding the same old length the old string
        }
        else
            ret[i++] = *s++;
    }
    ret[i] = '\0';
    return ret;
}

char *ssid(char s[])
{
    char theCopy[24];
    char *token;
    strcpy(theCopy, s);
    printf("\n SSID - %s \n", s);
    token = strtok(theCopy, "0x1c");
    return token;
}

char *pwd(char s[])
{
    char theCopy[32];
    char *token;
    strcpy(theCopy, s);
    printf("\n PWD - %s \n", s);
    token = strtok(theCopy, "0x1c");
    printf("\n token1 - %s \n", token);
    token = strtok(NULL, "0x1c");
    printf("\n token1 - %s \n", token);

    return token;
}

*/