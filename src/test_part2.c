#include "torche.h"

static void test_strdup(void)
{
    TEST("ft_strdup", {
        const char *str = "Test string";
        char *dup = ft_strdup(str);
        if (!dup || strcmp(dup, str) != 0)
        {
            printf("%s[KO]%s ft_strdup\n", RED, RESET);
            g_results.failed++;
        }
        free(dup);
    });
}

static void test_substr(void)
{
    TEST("ft_substr", {
        char *str = "Hello, World!";
        char *sub = ft_substr(str, 7, 5);
        if (!sub || strcmp(sub, "World") != 0)
        {
            printf("%s[KO]%s ft_substr\n", RED, RESET);
            g_results.failed++;
        }
        free(sub);
    });
}

void test_part2(void)
{
    printf("\n%s=== Tests Part 2 ===%s\n", YELLOW, RESET);
    test_strdup();
    test_substr();
    // Ajouter les autres tests de la partie 2 ici
}