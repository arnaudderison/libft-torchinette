#include "torche.h"

static void test_isalpha(void)
{
    TEST("ft_isalpha", {
        int success = 1;
        success &= (!!ft_isalpha('a') == !!isalpha('a'));
        success &= (!!ft_isalpha('Z') == !!isalpha('Z'));
        success &= (!!ft_isalpha('0') == !!isalpha('0'));
        success &= (!!ft_isalpha(' ') == !!isalpha(' '));
        if (!success)
        {
            printf("%s[KO]%s ft_isalpha\n", RED, RESET);
            g_results.failed++;
        }
    });
}

static void test_strlen(void)
{
    TEST("ft_strlen", {
        int success = 1;
        success &= (ft_strlen("Hello") == strlen("Hello"));
        success &= (ft_strlen("") == strlen(""));
        success &= (ft_strlen("Test") == strlen("Test"));
        success &= (ft_strlen("Test") == strlen("Test"));
        if (!success)
        {
            printf("%s[KO]%s ft_strlen\n", RED, RESET);
            g_results.failed++;
        }
    });
}

static void test_memset(void)
{
    TEST("ft_memset", {
        char str1[50];
        char str2[50];
        int success = 1;
        
        ft_memset(str1, 'A', 10);
        memset(str2, 'A', 10);
        success &= (memcmp(str1, str2, 10) == 0);
        
        if (!success)
        {
            printf("%s[KO]%s ft_memset\n", RED, RESET);
            g_results.failed++;
        }
    });
}

void test_part1(void)
{
    printf("\n%s=== Tests Part 1 ===%s\n", YELLOW, RESET);
    test_isalpha();
    test_strlen();
    test_memset();
    // Ajouter les autres tests de la partie 1 ici
}