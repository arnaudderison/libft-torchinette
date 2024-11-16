/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:22:15 by aderison          #+#    #+#             */
/*   Updated: 2024/11/16 20:49:14 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torche.h"

static int is_memory_zero(void *ptr, size_t size)
{
    unsigned char *bytes = (unsigned char *)ptr;
    size_t i = 0;

    while (i < size)
    {
        if (bytes[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

static int memory_equals(void *ptr1, void *ptr2, size_t size)
{
    return (memcmp(ptr1, ptr2, size) == 0);
}

static void test_calloc_basic(void)
{
    TEST("ft_calloc (basic allocation)",
        void *ptr1 = ft_calloc(5, sizeof(int));
        void *ptr2 = calloc(5, sizeof(int));

        if (!ptr1)
        {
            printf("%s[KO]%s ft_calloc returned NULL for basic allocation\n", 
                RED, RESET);
            g_results.failed++;
            return;
        }

        if (!is_memory_zero(ptr1, 5 * sizeof(int)))
        {
            printf("%s[KO]%s ft_calloc memory not initialized to zero\n", 
                RED, RESET);
            g_results.failed++;
            free(ptr1);
            free(ptr2);
            return;
        }

        if (!memory_equals(ptr1, ptr2, 5 * sizeof(int)))
        {
            printf("%s[KO]%s ft_calloc memory differs from system calloc\n", 
                RED, RESET);
            g_results.failed++;
            free(ptr1);
            free(ptr2);
            return;
        }

        free(ptr1);
        free(ptr2);
    );
}

static void test_calloc_zero(void)
{
    TEST("ft_calloc (zero size)",
        void *ptr1 = ft_calloc(0, sizeof(int));
        void *ptr2 = calloc(0, sizeof(int));
        
        void *ptr3 = ft_calloc(5, 0);
        void *ptr4 = calloc(5, 0);
        
        void *ptr5 = ft_calloc(0, 0);
        void *ptr6 = calloc(0, 0);

        if ((ptr1 == NULL) != (ptr2 == NULL))
        {
            printf("%s[KO]%s ft_calloc(0, sizeof(int)) behavior mismatch\n", 
                RED, RESET);
            g_results.failed++;
        }
        if ((ptr3 == NULL) != (ptr4 == NULL))
        {
            printf("%s[KO]%s ft_calloc(5, 0) behavior mismatch\n", 
                RED, RESET);
            g_results.failed++;
        }
        if ((ptr5 == NULL) != (ptr6 == NULL))
        {
            printf("%s[KO]%s ft_calloc(0, 0) behavior mismatch\n", 
                RED, RESET);
            g_results.failed++;
        }

        free(ptr1);
        free(ptr2);
        free(ptr3);
        free(ptr4);
        free(ptr5);
        free(ptr6);
    );
}

static void test_calloc_large(void)
{
    TEST("ft_calloc (large allocation)",
        size_t count = 1024;
        size_t size = 1024;
        void *ptr1 = ft_calloc(count, size);
        void *ptr2 = calloc(count, size);

        if (!ptr1)
        {
            printf("%s[KO]%s ft_calloc failed on large valid allocation\n", 
                RED, RESET);
            g_results.failed++;
            free(ptr2);
            return;
        }

        if (!is_memory_zero(ptr1, count * size))
        {
            printf("%s[KO]%s ft_calloc large allocation not zeroed\n", 
                RED, RESET);
            g_results.failed++;
            free(ptr1);
            free(ptr2);
            return;
        }

        free(ptr1);
        free(ptr2);
    );
}

static void test_calloc_overflow(void)
{
    TEST("ft_calloc (overflow protection)",
        // Test avec SIZE_MAX
        void *ptr1 = ft_calloc(SIZE_MAX, SIZE_MAX);
        void *ptr2 = calloc(SIZE_MAX, SIZE_MAX);
        
        void *ptr3 = ft_calloc(SIZE_MAX, 2);
        void *ptr4 = calloc(SIZE_MAX, 2);
        
        if (ptr1 != NULL || ptr3 != NULL)
        {
            printf("%s[KO]%s ft_calloc didn't protect against overflow\n", 
                RED, RESET);
            g_results.failed++;
        }

        if ((ptr1 == NULL) != (ptr2 == NULL) || 
            (ptr3 == NULL) != (ptr4 == NULL))
        {
            printf("%s[KO]%s ft_calloc overflow behavior differs from system\n", 
                RED, RESET);
            g_results.failed++;
        }

        free(ptr1);
        free(ptr2);
        free(ptr3);
        free(ptr4);
    );
}

static void test_calloc_alignment(void)
{
    TEST("ft_calloc (memory alignment)",
        void *ptr1 = ft_calloc(1, sizeof(char));
        void *ptr2 = ft_calloc(1, sizeof(int));
        void *ptr3 = ft_calloc(1, sizeof(long));
        void *ptr4 = ft_calloc(1, sizeof(double));

        if (((uintptr_t)ptr1 & (sizeof(char) - 1)) != 0 ||
            ((uintptr_t)ptr2 & (sizeof(int) - 1)) != 0 ||
            ((uintptr_t)ptr3 & (sizeof(long) - 1)) != 0 ||
            ((uintptr_t)ptr4 & (sizeof(double) - 1)) != 0)
        {
            printf("%s[KO]%s ft_calloc memory not properly aligned\n", 
                RED, RESET);
            g_results.failed++;
        }

        free(ptr1);
        free(ptr2);
        free(ptr3);
        free(ptr4);
    );
}

static void test_calloc_various_sizes(void)
{
    const size_t test_counts[] = {1, 2, 4, 8, 16, 32, 64, 128};
    const size_t test_sizes[] = {1, 2, 4, 8, 16, 32, 64, 128};
    size_t i = 0;
    size_t j;

    TEST("ft_calloc (various sizes)",
        while (i < sizeof(test_counts) / sizeof(test_counts[0]))
        {
            j = 0;
            while (j < sizeof(test_sizes) / sizeof(test_sizes[0]))
            {
                void *ptr1 = ft_calloc(test_counts[i], test_sizes[j]);
                void *ptr2 = calloc(test_counts[i], test_sizes[j]);

                if (!ptr1 || !is_memory_zero(ptr1, test_counts[i] * test_sizes[j]))
                {
                    printf("%s[KO]%s ft_calloc failed for count=%zu size=%zu\n",
                        RED, RESET, test_counts[i], test_sizes[j]);
                    g_results.failed++;
                    free(ptr1);
                    free(ptr2);
                    return;
                }

                free(ptr1);
                free(ptr2);
                j++;
            }
            i++;
        }
    );
}

static void test_calloc_stress(void)
{
    TEST("ft_calloc (stress test)",
        const int num_allocations = 1000;
        void **ptrs = ft_calloc(num_allocations, sizeof(void *));
        size_t i = 0;

        if (!ptrs)
        {
            printf("%s[KO]%s ft_calloc failed to allocate pointers array\n", 
                RED, RESET);
            g_results.failed++;
            return;
        }

        while (i < num_allocations)
        {
            size_t size = (i % 100) + 1; 
            ptrs[i] = ft_calloc(size, sizeof(int));
            
            if (!ptrs[i] || !is_memory_zero(ptrs[i], size * sizeof(int)))
            {
                printf("%s[KO]%s ft_calloc failed in stress test at i=%zu\n",
                    RED, RESET, i);
                while (i > 0)
                    free(ptrs[--i]);
                free(ptrs);
                g_results.failed++;
                return;
            }
            i++;
        }
        i = 0;
        while (i < num_allocations)
            free(ptrs[i++]);
        free(ptrs);
    );
}


static void test_overflow_calloc()
{
    TEST("ft_calloc - int overflow test", {
        int success = 1;
        
        size_t test_size = (size_t)INT_MAX + 50;
        char *ptr = ft_calloc(1, test_size);
        for (size_t i = 0; i < test_size; i++)
        {
            if (ptr[i] != 0)
            {
                success = 0;
                break;
            }
        }
        free(ptr);
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : ft_calloc a échoué avec size > INT_MAX\n");
            printf("Probablement dû à l'utilisation de int au lieu de size_t\n");
            g_results.failed++;
            return;
        }
        g_results.passed++;
    });
}
void test_calloc(void)
{
    printf("\n%s=== Tests détaillés de ft_calloc ===%s\n", YELLOW, RESET);
    
    test_calloc_basic();
    test_calloc_zero();
    test_calloc_large();
    test_calloc_overflow();
    test_calloc_alignment();
    test_calloc_various_sizes();
    test_calloc_stress();
    test_overflow_calloc();
}