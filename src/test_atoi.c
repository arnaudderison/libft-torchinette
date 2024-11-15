/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:58:16 by aderison          #+#    #+#             */
/*   Updated: 2024/11/15 20:21:25 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torche.h"

// Fonction auxiliaire pour tester un seul cas d'atoi
static int test_single_atoi(const char *str)
{
    int expected = atoi(str);
    int result = ft_atoi(str);
    if (result != expected)
    {
        printf("%s[KO]%s ft_atoi(\"%s\") = %d, expected %d\n",
            RED, RESET, str, result, expected);
        return (0);
    }
    return (1);
}

static void test_atoi_basic(void)
{
    const char *basic_tests[] = {
        "0", "1", "42", "-42", "+42",
        "1234567890", "-1234567890",
        NULL
    };
    
    TEST("ft_atoi (basic numbers)",
        for (int i = 0; basic_tests[i]; i++)
            if (!test_single_atoi(basic_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

static void test_atoi_whitespace(void)
{
    const char *whitespace_tests[] = {
        "  42", "\t42", "\n42", "\v42", "\f42", "\r42",
        "  \t\n\v\f\r42",
        "  +42", "  -42",
        "  \t\n\v\f\r-42",
        NULL
    };
    
    TEST("ft_atoi (whitespace handling)",
        for (int i = 0; whitespace_tests[i]; i++)
            if (!test_single_atoi(whitespace_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

static void test_atoi_signs(void)
{
    const char *sign_tests[] = {
        "+42", "-42", "++42", "--42", "+-42", "-+42",
        "+", "-", "++", "--",
        NULL
    };
    
    TEST("ft_atoi (sign handling)",
        for (int i = 0; sign_tests[i]; i++)
            if (!test_single_atoi(sign_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

static void test_atoi_invalid(void)
{
    const char *invalid_tests[] = {
        "abc", "42abc", "abc42",
        "42.42", "42,42",
        "", " ", "\t\n\v\f\r",
        "9999999999999999999999999",
        "-9999999999999999999999999",
        NULL
    };
    
    TEST("ft_atoi (invalid input)",
        for (int i = 0; invalid_tests[i]; i++)
            if (!test_single_atoi(invalid_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

static void test_atoi_limits(void)
{
    char int_max_str[12];
    char int_min_str[13];
    
    snprintf(int_max_str, sizeof(int_max_str), "%d", INT_MAX);
    snprintf(int_min_str, sizeof(int_min_str), "%d", INT_MIN);
    
    const char *limit_tests[] = {
        int_max_str, int_min_str,
        "2147483647",    // INT_MAX
        "2147483648",    // INT_MAX + 1
        "-2147483648",   // INT_MIN
        "-2147483649",   // INT_MIN - 1
        NULL
    };
    
    TEST("ft_atoi (limit values)",
        for (int i = 0; limit_tests[i]; i++)
            if (!test_single_atoi(limit_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

static void test_atoi_zero(void)
{
    const char *zero_tests[] = {
        "0", "+0", "-0",
        "000", "+000", "-000",
        "0000000000",
        "00042", "-00042",
        NULL
    };
    
    TEST("ft_atoi (zero handling)",
        for (int i = 0; zero_tests[i]; i++)
            if (!test_single_atoi(zero_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

static void test_atoi_long_numbers(void)
{
    const char *long_tests[] = {
        "99999999999999999999999999",
        "-99999999999999999999999999",
        "184467440737095516151",
        "-184467440737095516151",
        "10000000000000000000000000",
        "-10000000000000000000000000",
        NULL
    };
    
    TEST("ft_atoi (long numbers)",
        for (int i = 0; long_tests[i]; i++)
            if (!test_single_atoi(long_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

static void test_atoi_mixed(void)
{
    const char *mixed_tests[] = {
        "  +42abc", "\t-42.123",
        "42  43", "-42-43",
        "+-+-42", "--++42",
        "42.", ".42",
        "     ++++42", "     ----42",
        "9999999999a",
        NULL
    };
    
    TEST("ft_atoi (mixed cases)",
        for (int i = 0; mixed_tests[i]; i++)
            if (!test_single_atoi(mixed_tests[i]))
            {
                g_results.failed++;
                return;
            }
    );
}

void test_atoi(void)
{
    printf("\n%s=== Tests détaillés de ft_atoi ===%s\n", YELLOW, RESET);
    test_atoi_basic();
    test_atoi_whitespace();
    test_atoi_signs();
    test_atoi_invalid();
    test_atoi_limits();
    test_atoi_zero();
    test_atoi_long_numbers();
    test_atoi_mixed();
}
