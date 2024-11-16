#include "torche.h"

static void f_to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

static void f_to_index(unsigned int i, char *c)
{
    *c = i + '0';
}

static void f_alternate_case(unsigned int i, char *c)
{
    if ((i % 2) && *c >= 'a' && *c <= 'z')
        *c = *c - 32;
    else if (!(i % 2) && *c >= 'A' && *c <= 'Z')
        *c = *c + 32;
}

static void f_rot13(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'A' && *c <= 'Z')
        *c = ((*c - 'A' + 13) % 26) + 'A';
    else if (*c >= 'a' && *c <= 'z')
        *c = ((*c - 'a' + 13) % 26) + 'a';
}

static void test_ft_striteri(void)
{
    TEST("NULL string",
        char s[] = "test";
        ft_striteri(NULL, f_to_upper);
        if (strcmp(s, "test") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(NULL, f)", RED, RESET);
            printf("\nString was modified when it shouldn't have been");
            g_results.failed++;
            return;
        }
    );

    TEST("NULL function",
        char s[] = "test";
        ft_striteri(s, NULL);
        if (strcmp(s, "test") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(s, NULL)", RED, RESET);
            printf("\nString was modified when it shouldn't have been");
            g_results.failed++;
            return;
        }
    );

    TEST("Empty string",
        char s[] = "";
        ft_striteri(s, f_to_upper);
        if (strcmp(s, "") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(\"\", f)", RED, RESET);
            printf("\nEmpty string was modified");
            g_results.failed++;
            return;
        }
    );

    TEST("Basic to upper",
        char s[] = "Hello World!";
        ft_striteri(s, f_to_upper);
        if (strcmp(s, "HELLO WORLD!") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(\"Hello World!\", f_to_upper)", RED, RESET);
            printf("\nExpected: \"HELLO WORLD!\"");
            printf("\nGot: \"%s\"", s);
            g_results.failed++;
            return;
        }
    );

    TEST("Index conversion",
        char s[] = "test";
        ft_striteri(s, f_to_index);
        if (strcmp(s, "0123") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(\"test\", f_to_index)", RED, RESET);
            printf("\nExpected: \"0123\"");
            printf("\nGot: \"%s\"", s);
            g_results.failed++;
            return;
        }
    );

    TEST("Alternate case",
        char s[] = "Hello World";
        ft_striteri(s, f_alternate_case);
        if (strcmp(s, "hElLo wOrLd") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(\"Hello World\", f_alternate_case)", RED, RESET);
            printf("\nExpected: \"hElLo wOrLd\"");
            printf("\nGot: \"%s\"", s);
            g_results.failed++;
            return;
        }
    );

    TEST("ROT13",
        char s[] = "Hello, World!";
        ft_striteri(s, f_rot13);
        if (strcmp(s, "Uryyb, Jbeyq!") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(\"Hello, World!\", f_rot13)", RED, RESET);
            printf("\nExpected: \"Uryyb, Jbeyq!\"");
            printf("\nGot: \"%s\"", s);
            g_results.failed++;
            return;
        }
    );

    TEST("Special chars",
        char s[] = "!@#$%%&*()";
        char original[] = "!@#$%%&*()";
        ft_striteri(s, f_to_upper);
        if (strcmp(s, original) != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(\"!@#$%%%%&*()\", f_to_upper)", RED, RESET);
            printf("\nExpected: \"%s\"", original);
            printf("\nGot: \"%s\"", s);
            g_results.failed++;
            return;
        }
    );

    TEST("Long string",
        char s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        ft_striteri(s, f_alternate_case);
        if (strcmp(s, "aBcDeFgHiJkLmNoPqRsTuVwXyZaBcDeFgHiJkLmNoPqRsTuVwXyZ") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(alphabet, f_alternate_case)", RED, RESET);
            printf("\nExpected: \"aBcDeFgHiJkLmNoPqRsTuVwXyZaBcDeFgHiJkLmNoPqRsTuVwXyZ\"");
            printf("\nGot: \"%s\"", s);
            g_results.failed++;
            return;
        }
    );

    TEST("All spaces",
        char s[] = "     ";
        ft_striteri(s, f_to_upper);
        if (strcmp(s, "     ") != 0)
        {
            printf("\n%s[KO]%s: ft_striteri(\"     \", f_to_upper)", RED, RESET);
            printf("\nExpected: \"     \"");
            printf("\nGot: \"%s\"", s);
            g_results.failed++;
            return;
        }
    );

    TEST("ft_striteri - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 20;
        char *str = malloc(size + 1);
        if (!str)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        memset(str, 'a', size);
        str[size] = '\0';

        ft_striteri(str, f_to_upper);

        int success = (str[(size_t)INT_MAX + 10] == 'A');
        
        free(str);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("ft_striteri n'a pas modifié le caractère après INT_MAX\n");
            g_results.failed++;
            return;
        }
    });
}

void test_striteri(void)
{
    printf("%sft_striteri%s\n", YELLOW, RESET);
    test_ft_striteri();
    
}
