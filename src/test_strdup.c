/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:29:07 by aderison          #+#    #+#             */
/*   Updated: 2024/11/15 13:29:25 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torche.h"

// Test basique de strdup
static void test_strdup_basic(void)
{
    const char *str = "Hello, World!";

    TEST("ft_strdup (basic test)",
        char *dup = ft_strdup(str);
        char *orig = strdup(str);

        if (!dup)
        {
            printf("%s[KO]%s ft_strdup returned NULL\n", RED, RESET);
            free(orig);
            g_results.failed++;
            return;
        }

        if (strcmp(dup, orig) != 0)
        {
            printf("%s[KO]%s ft_strdup content differs: got \"%s\", expected \"%s\"\n",
                RED, RESET, dup, orig);
            free(dup);
            free(orig);
            g_results.failed++;
            return;
        }

        free(dup);
        free(orig);
    );
}

// Test avec une chaîne vide
static void test_strdup_empty(void)
{
    TEST("ft_strdup (empty string)",
        char *dup = ft_strdup("");
        char *orig = strdup("");

        if (!dup)
        {
            printf("%s[KO]%s ft_strdup returned NULL for empty string\n", 
                RED, RESET);
            free(orig);
            g_results.failed++;
            return;
        }

        if (strcmp(dup, orig) != 0 || strlen(dup) != 0)
        {
            printf("%s[KO]%s ft_strdup empty string test failed\n", RED, RESET);
            free(dup);
            free(orig);
            g_results.failed++;
            return;
        }

        free(dup);
        free(orig);
    );
}

// Test avec des caractères spéciaux
static void test_strdup_special_chars(void)
{
    const char *special_strings[] = {
        "Hello\0Hidden",      // Avec null byte
        "Tab\there",          // Avec tabulation
        "New\nLine",          // Avec newline
        "Return\rhere",       // Avec return
        "\x01\x02\x03",      // Caractères de contrôle
        "émoji 🌍 test",      // Avec émoji (UTF-8)
        NULL
    };
    int i = 0;

    TEST("ft_strdup (special characters)",
        while (special_strings[i])
        {
            char *dup = ft_strdup(special_strings[i]);
            char *orig = strdup(special_strings[i]);

            if (!dup || strcmp(dup, orig) != 0)
            {
                printf("%s[KO]%s ft_strdup failed with special chars\n", 
                    RED, RESET);
                free(dup);
                free(orig);
                g_results.failed++;
                return;
            }

            free(dup);
            free(orig);
            i++;
        }
    );
}

// Test avec une très longue chaîne
static void test_strdup_long_string(void)
{
    char *long_str = NULL;
    size_t len = 1000000; // 1MB

    TEST("ft_strdup (long string)",
        long_str = malloc(len + 1);
        if (!long_str)
        {
            printf("%s[KO]%s malloc failed in test\n", RED, RESET);
            g_results.failed++;
            return;
        }

        // Remplir la chaîne avec des patterns
        for (size_t i = 0; i < len; i++)
            long_str[i] = 'A' + (i % 26);
        long_str[len] = '\0';

        char *dup = ft_strdup(long_str);
        char *orig = strdup(long_str);

        if (!dup)
        {
            printf("%s[KO]%s ft_strdup failed with long string\n", RED, RESET);
            free(long_str);
            free(orig);
            g_results.failed++;
            return;
        }

        if (strcmp(dup, orig) != 0)
        {
            printf("%s[KO]%s ft_strdup long string content differs\n", 
                RED, RESET);
            free(long_str);
            free(dup);
            free(orig);
            g_results.failed++;
            return;
        }

        free(long_str);
        free(dup);
        free(orig);
    );
}

// Test de la gestion mémoire
static void test_strdup_memory(void)
{
    const int num_allocs = 1000;
    char **strings = NULL;
    char buf[20];
    int i = 0;

    TEST("ft_strdup (memory stress test)",
        strings = malloc(sizeof(char *) * num_allocs);
        if (!strings)
        {
            printf("%s[KO]%s malloc failed in test setup\n", RED, RESET);
            g_results.failed++;
            return;
        }

        // Faire plusieurs allocations
        while (i < num_allocs)
        {
            snprintf(buf, sizeof(buf), "Test%d", i);
            strings[i] = ft_strdup(buf);
            if (!strings[i])
            {
                printf("%s[KO]%s ft_strdup failed in stress test at i=%d\n",
                    RED, RESET, i);
                while (--i >= 0)
                    free(strings[i]);
                free(strings);
                g_results.failed++;
                return;
            }
            if (strcmp(strings[i], buf) != 0)
            {
                printf("%s[KO]%s ft_strdup content wrong in stress test\n",
                    RED, RESET);
                while (i >= 0)
                    free(strings[i--]);
                free(strings);
                g_results.failed++;
                return;
            }
            i++;
        }

        // Nettoyer
        i = 0;
        while (i < num_allocs)
            free(strings[i++]);
        free(strings);
    );
}

// Test des cas particuliers avec des espaces
static void test_strdup_spaces(void)
{
    const char *space_strings[] = {
        " ",                    // Un seul espace
        "   ",                  // Plusieurs espaces
        "\t\t\t",              // Tabs
        " Hello ",              // Espaces aux extrémités
        "  Multiple   Spaces  ", // Espaces multiples
        NULL
    };
    int i = 0;

    TEST("ft_strdup (space handling)",
        while (space_strings[i])
        {
            char *dup = ft_strdup(space_strings[i]);
            char *orig = strdup(space_strings[i]);

            if (!dup || strcmp(dup, orig) != 0)
            {
                printf("%s[KO]%s ft_strdup failed with spaces\n", RED, RESET);
                free(dup);
                free(orig);
                g_results.failed++;
                return;
            }

            free(dup);
            free(orig);
            i++;
        }
    );
}

void test_strdup(void)
{
    printf("\n%s=== Tests détaillés de ft_strdup ===%s\n", YELLOW, RESET);

    test_strdup_basic();         // Test basique
    test_strdup_empty();         // Test chaîne vide
    test_strdup_special_chars(); // Test caractères spéciaux
    test_strdup_long_string();   // Test longue chaîne
    test_strdup_memory();        // Test stress mémoire
    test_strdup_spaces();        // Test espaces
}