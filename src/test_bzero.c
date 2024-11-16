/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:10:28 by aderison          #+#    #+#             */
/*   Updated: 2024/11/16 20:42:55 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torche.h"

static int compare_memory(void *m1, void *m2, size_t n)
{
    unsigned char   *p1;
    unsigned char   *p2;
    size_t          i;

    p1 = (unsigned char *)m1;
    p2 = (unsigned char *)m2;
    i = 0;
    while (i < n)
    {
        if (p1[i] != p2[i])
            return (0);
        i++;
    }
    return (1);
}

static void test_bzero_basic(void)
{
    char str1[50];
    char str2[50];

    memset(str1, 'A', sizeof(str1));
    memset(str2, 'A', sizeof(str2));

    TEST("ft_bzero (basic test)",
        ft_bzero(str1, 10);
        bzero(str2, 10);
        if (!compare_memory(str1, str2, sizeof(str1)))
        {
            printf("%s[KO]%s ft_bzero failed basic test\n", RED, RESET);
            g_results.failed++;
            return;
        }
    );
}

static void test_bzero_zero_length(void)
{
    char str1[10];
    char str2[10];

    memset(str1, 'B', sizeof(str1));
    memset(str2, 'B', sizeof(str2));

    TEST("ft_bzero (zero length)",
        ft_bzero(str1, 0);
        bzero(str2, 0);
        if (!compare_memory(str1, str2, sizeof(str1)))
        {
            printf("%s[KO]%s ft_bzero failed zero length test\n", RED, RESET);
            g_results.failed++;
            return;
        }
    );
}

static void test_bzero_full_buffer(void)
{
    char str1[100];
    char str2[100];

    memset(str1, 'C', sizeof(str1));
    memset(str2, 'C', sizeof(str2));

    TEST("ft_bzero (full buffer)",
        ft_bzero(str1, sizeof(str1));
        bzero(str2, sizeof(str2));
        if (!compare_memory(str1, str2, sizeof(str1)))
        {
            printf("%s[KO]%s ft_bzero failed full buffer test\n", RED, RESET);
            g_results.failed++;
            return;
        }
    );
}

static void test_bzero_partial(void)
{
    char str1[20];
    char str2[20];
    
    const size_t test_sizes[] = {1, 5, 10, 15, 19};
    size_t i = 0;

    TEST("ft_bzero (partial buffer)",
        while (i < sizeof(test_sizes) / sizeof(test_sizes[0]))
        {
            memset(str1, 'D', sizeof(str1));
            memset(str2, 'D', sizeof(str2));

            ft_bzero(str1, test_sizes[i]);
            bzero(str2, test_sizes[i]);

            if (!compare_memory(str1, str2, sizeof(str1)))
            {
                printf("%s[KO]%s ft_bzero failed with size %zu\n",
                    RED, RESET, test_sizes[i]);
                g_results.failed++;
                return;
            }
            i++;
        }
    );
}

static void test_bzero_aligned(void)
{
    long aligned_buf1[50];
    long aligned_buf2[50];
    char *ptr1 = (char *)aligned_buf1;
    char *ptr2 = (char *)aligned_buf2;
    size_t i = 0;

    TEST("ft_bzero (memory alignment)",
        while (i < 8)
        {
            memset(aligned_buf1, 0xFF, sizeof(aligned_buf1));
            memset(aligned_buf2, 0xFF, sizeof(aligned_buf2));

            ft_bzero(ptr1 + i, 16);
            bzero(ptr2 + i, 16);

            if (!compare_memory(aligned_buf1, aligned_buf2, sizeof(aligned_buf1)))
            {
                printf("%s[KO]%s ft_bzero failed with alignment offset %zu\n",
                    RED, RESET, i);
                g_results.failed++;
                return;
            }
            i++;
        }
    );
}

static void test_bzero_overlap(void)
{
    char str1[30];
    char str2[30];
    
    memset(str1, 'E', sizeof(str1));
    memset(str2, 'E', sizeof(str2));

    TEST("ft_bzero (overlapping regions)",
        ft_bzero(str1 + 5, 10);
        bzero(str2 + 5, 10);
        
        ft_bzero(str1, 15);
        bzero(str2, 15);
        
        if (!compare_memory(str1, str2, sizeof(str1)))
        {
            printf("%s[KO]%s ft_bzero failed overlapping test\n", RED, RESET);
            g_results.failed++;
            return;
        }
    );
}

static void test_bzero_large(void)
{
    const size_t size = 1024 * 1024; // 1MB
    void *ptr1 = malloc(size);
    void *ptr2 = malloc(size);

    if (!ptr1 || !ptr2)
    {
        if (ptr1) free(ptr1);
        if (ptr2) free(ptr2);
        return;
    }

    memset(ptr1, 0xFF, size);
    memset(ptr2, 0xFF, size);

    TEST("ft_bzero (large allocation)",
        ft_bzero(ptr1, size);
        bzero(ptr2, size);
        
        if (!compare_memory(ptr1, ptr2, size))
        {
            printf("%s[KO]%s ft_bzero failed large allocation test\n", RED, RESET);
            g_results.failed++;
        }
    );

    free(ptr1);
    free(ptr2);
}

static void overflow_bzero(void)
{
    TEST("ft_bzero - size_t vs int test", {
        int success = 1;
        
        size_t size = (size_t)INT_MAX + 50;
        char *str = malloc(size);
        if (!str)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }
        memset(str, 'A', size);

        ft_bzero(str, size);

        for (size_t i = 0; i < size; i++)
        {
            if (str[i] != 0)
            {
                success = 0;
                break;
            }
        }

        free(str);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : La mémoire n'a pas été correctement mise à zéro\n");
            printf("Cela peut être dû à l'utilisation de int au lieu de size_t\n");
            g_results.failed++;
            return;
        }
        g_results.passed++;
    });
}

void test_bzero(void)
{
    printf("\n%s=== Tests détaillés de ft_bzero ===%s\n", YELLOW, RESET);
    
    test_bzero_basic();        // Test basique
    test_bzero_zero_length();  // Test avec longueur zéro
    test_bzero_full_buffer();  // Test buffer complet
    test_bzero_partial();      // Test buffer partiel
    test_bzero_aligned();      // Test alignement mémoire
    test_bzero_overlap();      // Test chevauchement
    test_bzero_large();        // Test grande allocation
    overflow_bzero();
}