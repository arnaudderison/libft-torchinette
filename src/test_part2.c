#include "torche.h"

static void free_split(char **split)
{
    if (!split)
        return;
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}

static void test_ft_substr(void)
{
    TEST("NULL string", {
        char *result = ft_substr(NULL, 0, 10);
        if (result != NULL) {
            printf("\n[KO]: ft_substr(NULL, 0, 10)\n");
            printf("\nExpected: NULL\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        }
    });

    TEST("Empty string", {
        char *result = ft_substr("", 0, 10);
        if (result == NULL || strlen(result) != 0) {
            printf("\n[KO]: ft_substr('', 0, 10)\n");
            printf("\nExpected: '' (empty string)\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        } else {
            free(result);
        }
    });

    TEST("Start beyond string length", {
        char *result = ft_substr("Hello", 10, 10);
        if (result != NULL && strlen(result) != 0) {
            printf("\n[KO]: ft_substr('Hello', 10, 10)\n");
            printf("\nExpected: '' (empty string)\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        } else {
            free(result);
        }
    });

    TEST("Length beyond string length", {
        char *result = ft_substr("Hello", 2, 10);
        if (result == NULL || strcmp(result, "llo") != 0) {
            printf("\n[KO]: ft_substr('Hello', 2, 10)\n");
            printf("\nExpected: 'llo'\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        } else {
            free(result);
        }
    });

    TEST("Normal case", {
        char *result = ft_substr("Hello World", 6, 5);
        if (result == NULL || strcmp(result, "World") != 0) {
            printf("\n[KO]: ft_substr('Hello World', 6, 5)\n");
            printf("\nExpected: 'World'\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        } else {
            free(result);
        }
    });

    TEST("Zero length", {
        char *result = ft_substr("Hello", 0, 0);
        if (result == NULL || strlen(result) != 0) {
            printf("\n[KO]: ft_substr('Hello', 0, 0)\n");
            printf("\nExpected: '' (empty string)\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        } else {
            free(result);
        }
    });

    TEST("Full string", {
        char *result = ft_substr("Hello", 0, 5);
        if (result == NULL || strcmp(result, "Hello") != 0) {
            printf("\n[KO]: ft_substr('Hello', 0, 5)\n");
            printf("\nExpected: 'Hello'\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        } else {
            free(result);
        }
    });

    TEST("Allocation failure", {
        char *result = ft_substr("Hello", 0, SIZE_MAX);
        if (result == NULL || strcmp(result, "Hello") != 0) {
            printf("\n%s[KO]: ft_substr with SIZE_MAX should fail result:%s", RED, RESET);
            printf("\nExpected: [%s]", result);
            printf("\nGot: NULL or Hello\n");
            free(result);
            g_results.failed++;
            return ;
        }
    });

    TEST("Large input string", {
        char *str = malloc(1000000);
        if (!str) {
            printf("\n[KO]: malloc failed for large string\n");
            g_results.failed++;
            return;
        }
        memset(str, 'A', 1000000 - 1);
        str[999999] = '\0';
        char *result = ft_substr(str, 999990, 10);
        if (result == NULL || strcmp(result, "AAAAAAAAA") != 0) {
            printf("\n%s[KO]: ft_substr for large string result [%s]\n%s", RED, result, RESET);
            free(result);
            free(str);
            g_results.failed++;
            return ;
        } else {
            free(result);
            free(str);
        }
    });

    TEST("Negative start value", {
        char *result = ft_substr("Hello", (unsigned int)-5, 3);
        if (result != NULL && strlen(result) != 0) {
            printf("\n[KO]: ft_substr('Hello', (unsigned int)-5, 3)\n");
            printf("\nExpected: '' (empty string)\n");
            printf("\nGot:      '%s'\n", result);
            free(result);
            g_results.failed++;
            return ;
        } else {
            free(result);
        }
    });
}

static void test_ft_strjoin(void)
{
    TEST("NULL strings", {
        char *result = ft_strjoin(NULL, NULL);
        if (result != NULL) {
            printf("\n%s[KO]%s: ft_strjoin(NULL, NULL)", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
    });

    TEST("First string NULL", {
        char *result = ft_strjoin(NULL, "World");
        if (result != NULL) {
            printf("\n%s[KO]%s: ft_strjoin(NULL, 'World')", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: '%s'", result);
            printf("\n%s[+] if the student returned NULL this test could be valid%s", YELLOW, RESET);
            free(result);
            g_results.failed++;
        }
    });

    TEST("Second string NULL", {
        char *result = ft_strjoin("Hello", NULL);
        if (result != NULL) {
            printf("\n%s[KO]%s: ft_strjoin('Hello', NULL)", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: '%s'", result);
            printf("\n%s[+]if the student returned NULL this test could be valid%s", YELLOW, RESET);
            free(result);
            g_results.failed++;
        }
    });

    TEST("Empty strings", {
        char *result = ft_strjoin("", "");
        if (result == NULL || strcmp(result, "") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('', '')", RED, RESET);
            printf("\nExpected: ''");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("First string empty", {
        char *result = ft_strjoin("", "World");
        if (result == NULL || strcmp(result, "World") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('', 'World')", RED, RESET);
            printf("\nExpected: 'World'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Second string empty", {
        char *result = ft_strjoin("Hello", "");
        if (result == NULL || strcmp(result, "Hello") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('Hello', '')", RED, RESET);
            printf("\nExpected: 'Hello'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Basic join", {
        char *result = ft_strjoin("Hello ", "World");
        if (result == NULL || strcmp(result, "Hello World") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('Hello ', 'World')", RED, RESET);
            printf("\nExpected: 'Hello World'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Multiple spaces", {
        char *result = ft_strjoin("   Hello   ", "   World   ");
        if (result == NULL || strcmp(result, "   Hello      World   ") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('   Hello   ', '   World   ')", RED, RESET);
            printf("\nExpected: '   Hello      World   '");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("All whitespace characters", {
        char *result = ft_strjoin("\n\t\r\v\f", " \n\t\r\v\f");
        if (result == NULL || strcmp(result, "\n\t\r\v\f \n\t\r\v\f") != 0) {
            printf("\n%s[KO]%s: ft_strjoin(whitespace1, whitespace2)", RED, RESET);
            printf("\nExpected: '\\n\\t\\r\\v\\f \\n\\t\\r\\v\\f'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Special characters", {
        char *result = ft_strjoin("Hello\n\t", "\vWorld\r");
        if (result == NULL || strcmp(result, "Hello\n\t\vWorld\r") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('Hello\\n\\t', '\\vWorld\\r')", RED, RESET);
            printf("\nExpected: 'Hello\\n\\t\\vWorld\\r'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    char s1[] = {1, 2, 3, 4, 5, 0};
    char s2[] = {6, 7, 8, 9, 10, 0};
    char expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    TEST("Non-printable characters", {
        
        char *result = ft_strjoin(s1, s2);
        if (result == NULL || memcmp(result, expected, 11) != 0) {
            printf("\n%s[KO]%s: ft_strjoin with non-printable characters", RED, RESET);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Numbers and special chars", {
        char *result = ft_strjoin("123!@#", "$%%^456");
        if (result == NULL || strcmp(result, "123!@#$%%^456") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('123!@#', '$%%^456')", RED, RESET);
            printf("\nExpected: '123!@#$%%^456'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Unicode characters", {
        char *result = ft_strjoin("é→♠", "☺★∞");
        if (result == NULL || strcmp(result, "é→♠☺★∞") != 0) {
            printf("\n%s[KO]%s: ft_strjoin('é→♠', '☺★∞')", RED, RESET);
            printf("\nExpected: 'é→♠☺★∞'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Long strings with repetition", {
        char *s1 = malloc(1000);
        char *s2 = malloc(1000);
        if (!s1 || !s2) {
            printf("\n%s[KO]%s: malloc failed for repetition test", RED, RESET);
            free(s1);
            free(s2);
            g_results.failed++;
            return;
        }
        
        for (int i = 0; i < 999; i++) {
            s1[i] = 'A' + (i % 26);
            s2[i] = 'Z' - (i % 26);
        }
        s1[999] = '\0';
        s2[999] = '\0';
        
        char *result = ft_strjoin(s1, s2);
        if (result == NULL || strlen(result) != 1998 || 
            strncmp(result, s1, 999) != 0 || 
            strncmp(result + 999, s2, 999) != 0) {
            printf("\n%s[KO]%s: ft_strjoin with repeating pattern", RED, RESET);
            free(result);
            free(s1);
            free(s2);
            g_results.failed++;
            return;
        }
        free(result);
        free(s1);
        free(s2);
    });

    TEST("Very large strings", {
        size_t size = 100000;
        char *s1 = malloc(size + 1);
        char *s2 = malloc(size + 1);
        
        if (!s1 || !s2) {
            free(s1);
            free(s2);
            return;
        }

        memset(s1, 'X', size);
        memset(s2, 'Y', size);
        s1[size] = '\0';
        s2[size] = '\0';

        char *result = ft_strjoin(s1, s2);
        if (!result) {
            g_results.failed++;
            free(s1);
            free(s2);
            return;
        }

        int failed = 0;
        size_t expected_len = size * 2;
        
        if (strlen(result) != expected_len) failed = 1;
        if (result[0] != 'X') failed = 1;
        if (result[size - 1] != 'X') failed = 1;
        if (result[size] != 'Y') failed = 1;
        if (result[expected_len - 1] != 'Y') failed = 1;

        if (failed) {
            printf("\n[KO]: ft_strjoin('XX...XX', 'YY...YY')");
            printf("\nExpected: String of length %zu starting with X and ending with Y", expected_len);
            printf("\nGot: '%c...%c%c...%c' (length: %zu)", 
                result[0], result[size-1], result[size], result[expected_len-1], strlen(result));
            g_results.failed++;
        }

        free(result);
        free(s1);
        free(s2);
    });

    TEST("Mixed length strings", {
        char *long_str = malloc(10000);
        if (!long_str) {
            printf("\n%s[KO]%s: malloc failed for mixed length test", RED, RESET);
            g_results.failed++;
            return;
        }
        memset(long_str, 'A', 9999);
        long_str[9999] = '\0';
        
        char *result = ft_strjoin(long_str, "x");
        if (result == NULL || strlen(result) != 10000 || 
            result[9998] != 'A' || result[9999] != 'x') {
            printf("\n[KO]: ft_strjoin failed with mixed length strings");
            free(result);
            free(long_str);
            g_results.failed++;
            return;
        }
        free(result);
        free(long_str);
    });
}

static void test_ft_strtrim(void){
    TEST("NULL NULL string", {
        char *result = ft_strtrim(NULL, NULL);
        if (result != NULL) {
            printf("\n%s[KO]%s: ft_strtrim(NULL, NULL)", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
    });

    TEST("NULL string", {
        char *result = ft_strtrim(NULL, "test");
        if (result != NULL) {
            printf("\n%s[KO]%s: ft_strtrim(NULL, 'test')", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
    });

    TEST("NULL set", {
        char *result = ft_strtrim("test", NULL);
        if (result != NULL) {
            printf("\n%s[KO]%s: ft_strtrim('test', NULL)", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
    });

    TEST("Empty string", {
        char *result = ft_strtrim("", " ");
        if (result == NULL || strcmp(result, "") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('', ' ')", RED, RESET);
            printf("\nExpected: ''");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Empty set", {
        char *result = ft_strtrim("hello", "");
        if (result == NULL || strcmp(result, "hello") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('hello', '')", RED, RESET);
            printf("\nExpected: 'hello'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Basic trim both ends", {
        char *result = ft_strtrim("   hello world   ", " ");
        if (result == NULL || strcmp(result, "hello world") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('   hello world   ', ' ')", RED, RESET);
            printf("\nExpected: 'hello world'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Multiple character set", {
        char *result = ft_strtrim("...hello...world...", ".");
        if (result == NULL || strcmp(result, "hello...world") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('...hello...world...', '.')", RED, RESET);
            printf("\nExpected: 'hello...world'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Mixed character set", {
        char *result = ft_strtrim(",.;!hello,.;!world,.;!", ",.;!");
        if (result == NULL || strcmp(result, "hello,.;!world") != 0) {
            printf("\n%s[KO]%s: ft_strtrim(',.;!hello,.;!world,.;!', ',.;!')", RED, RESET);
            printf("\nExpected: 'hello,.;!world'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Only set characters", {
        char *result = ft_strtrim("   ", " ");
        if (result == NULL || strcmp(result, "") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('   ', ' ')", RED, RESET);
            printf("\nExpected: ''");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("No trim needed", {
        char *result = ft_strtrim("hello world", " ");
        if (result == NULL || strcmp(result, "hello world") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('hello world', ' ')", RED, RESET);
            printf("\nExpected: 'hello world'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Whitespace characters", {
        char *result = ft_strtrim("\t\n\r\v\f hello world \t\n\r\v\f", "\t\n\r\v\f ");
        if (result == NULL || strcmp(result, "hello world") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('\\t\\n\\r\\v\\f hello world \\t\\n\\r\\v\\f', '\\t\\n\\r\\v\\f ')", RED, RESET);
            printf("Expected: 'hello world'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });
    
    TEST("Single character string", {
        char *result = ft_strtrim(" a ", " ");
        if (result == NULL || strcmp(result, "a") != 0) {
            printf("\n%s[KO]%s: ft_strtrim(' a ', ' ')", RED, RESET);
            printf("\nExpected: 'a'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("All characters in set", {
        char *result = ft_strtrim("abcde", "abcde");
        if (result == NULL || strcmp(result, "") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('abcde', 'abcde')", RED, RESET);
            printf("\nExpected: ''");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Alternating set characters", {
        char *result = ft_strtrim("abc123cba", "abc");
        if (result == NULL || strcmp(result, "123") != 0) {
            printf("\n%s[KO]%s: ft_strtrim('abc123cba', 'abc')", RED, RESET);
            printf("\nExpected: '123'");
            printf("\nGot: '%s'", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    });

    TEST("Long string trim", {
        char *input = malloc(1000);
        if (input) {
            memset(input, 'x', 999);
            input[999] = '\0';
            input[10] = 'h';
            input[988] = 'h';
            
            char *result = ft_strtrim(input, "x");
            if (result == NULL || strncmp(&input[10], result, 979) != 0) {
                printf("\n%s[KO]%s: ft_strtrim for long string", RED, RESET);
                printf("\nExpected string between two 'h' characters");
                printf("\nGot: '%s'", result);
                free(result);
                free(input);
                g_results.failed++;
                return;
            }
            free(result);
            free(input);
        }
    });
}

static void	test_ft_split(void)
{
    TEST("NULL input",
        char **tab = ft_split(NULL, ' ');
        if (tab != NULL)
        {
            printf("\n%s[KO]%s: ft_split(NULL, ' ')", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: not NULL");
            free_split(tab);
            g_results.failed++;
        }
    );

    TEST("NULL input with special char",
        char **tab = ft_split(NULL, '\0');
        if (tab != NULL)
        {
            printf("\n%s[KO]%s: ft_split(NULL, '\\0')", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: not NULL");
            free_split(tab);
            g_results.failed++;
        }
    );

    TEST("Empty string",
        char **tab = ft_split("", ' ');
        if (tab == NULL || tab[0] != NULL)
        {
            printf("\n%s[KO]%s: ft_split(\"\", ' ')", RED, RESET);
            printf("\nExpected: [NULL]");
            printf("\nGot: %s", !tab ? "NULL" : "not NULL terminated array");
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );

    TEST("Single char delimiter",
        char **tab = ft_split(" ", ' ');
        if (tab == NULL || tab[0] != NULL)
        {
            printf("\n%s[KO]%s: ft_split(\" \", ' ')", RED, RESET);
            printf("\nExpected: [NULL]");
            printf("\nGot: %s", !tab ? "NULL" : "not NULL terminated array");
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );

    TEST("Single char string",
        char **tab = ft_split("a", ' ');
        if (!tab || !tab[0] || tab[1] != NULL || strcmp(tab[0], "a") != 0)
        {
            printf("\n%s[KO]%s: ft_split(\"a\", ' ')", RED, RESET);
            printf("\nExpected: [\"a\", NULL]");
            printf("\nGot: %s", !tab ? "NULL" : "wrong content");
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );

    TEST("Basic split",
        char **tab = ft_split("hello world", ' ');
        if (!tab || !tab[0] || !tab[1] || tab[2] != NULL)
        {
            printf("\n%s[KO]%s: ft_split(\"hello world\", ' ')", RED, RESET);
            printf("\nExpected: [\"hello\", \"world\", NULL]");
            printf("\nGot: %s", !tab ? "NULL" : "wrong format");
            free_split(tab);
            g_results.failed++;
            return;
        }
        if (strcmp(tab[0], "hello") != 0 || strcmp(tab[1], "world") != 0)
        {
            printf("\n%s[KO]%s: ft_split(\"hello world\", ' ')", RED, RESET);
            printf("\nExpected: [\"hello\", \"world\", NULL]");
            printf("\nGot: [\"%s\", \"%s\", NULL]", tab[0], tab[1]);
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );

    TEST("Multiple delimiters",
        char **tab = ft_split("^^^hello^^^world^^^", '^');
        if (!tab || !tab[0] || !tab[1] || tab[2] != NULL)
        {
            printf("\n%s[KO]%s: ft_split(\"^^^hello^^^world^^^\", '^')", RED, RESET);
            printf("\nExpected: [\"hello\", \"world\", NULL]");
            printf("\nGot: %s", !tab ? "NULL" : "wrong format");
            free_split(tab);
            g_results.failed++;
            return;
        }
        if (strcmp(tab[0], "hello") != 0 || strcmp(tab[1], "world") != 0)
        {
            printf("\n%s[KO]%s: ft_split with multiple delimiters\n", RED, RESET);
            printf("\nExpected: [\"hello\", \"world\", NULL]");
            printf("\nGot: [\"%s\", \"%s\", NULL]", tab[0], tab[1]);
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );

    TEST("Split with \\0",
        char **tab = ft_split("hello\0world", '\0');
        if (!tab || !tab[0] || tab[1] != NULL || strcmp(tab[0], "hello") != 0)
        {
            printf("\n%s[KO]%s: ft_split with NULL character", RED, RESET);
            printf("\nExpected: [\"hello\", NULL]");
            printf("\nGot: %s", !tab ? "NULL" : "wrong content");
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );

    char **tab = ft_split("   one   two  three  four  five  ", ' ');
    char *expected[] = {"one", "two", "three", "four", "five", NULL};
    TEST("Multiple words",
        if (!tab)
        {
            printf("\n%s[KO]%s: ft_split with multiple words", RED, RESET);
            printf("\nGot: NULL");
            g_results.failed++;
            return;
        }
        int i = 0;
        while (expected[i])
        {
            if (!tab[i] || strcmp(tab[i], expected[i]) != 0)
            {
                printf("\n$%s[KO]%s: ft_split with multiple words", RED, RESET);
                printf("\nError at word %d", i + 1);
                printf("Expected: \"%s\"", expected[i]);
                printf("Got: \"%s\"", tab[i] ? tab[i] : "NULL");
                free_split(tab);
                g_results.failed++;
                return;
            }
            i++;
        }
        if (tab[i] != NULL)
        {
            printf("\n%s[KO]%s: ft_split with multiple words", RED, RESET);
            printf("\nExpected NULL termination after word %d", i);
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );

   TEST("Special chars",
        char **tab = ft_split("\t\v\f\r\n", '\n');
        if (!tab || !tab[0] || tab[1] != NULL)
        {
            printf("\n%s[KO]%s: ft_split(\"\\t\\v\\f\\r\\n\", '\\n')", RED, RESET);
            printf("\nExpected: [\"\\t\\v\\f\\r\", NULL]");
            printf("\nGot: %s", !tab ? "NULL" : "wrong format");
            if (tab)
            {
                printf("Real output: [");
                int i = 0;
                while (tab[i])
                {
                    printf("\"%s\"", tab[i]);
                    if (tab[i + 1])
                        printf(", ");
                    i++;
                }
                printf(", NULL]\n");
            }
            free_split(tab);
            g_results.failed++;
            return;
        }
        if (strcmp(tab[0], "\t\v\f\r") != 0)
        {
            printf("\n%s[KO]%s: ft_split(\"\\t\\v\\f\\r\\n\", '\\n')", RED, RESET);
            printf("\nExpected: [\"\\t\\v\\f\\r\", NULL]");
            printf("\nGot: [\"%s\", NULL]", tab[0]);
            free_split(tab);
            g_results.failed++;
            return;
        }
        free_split(tab);
    );
}

static void	test_ft_itoa(void)
{
    TEST("Zero test",
        char *str = ft_itoa(0);
        if (!str || strcmp(str, "0") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(0)", RED, RESET);
            printf("\nExpected: \"0\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("INT_MIN",
        char *str = ft_itoa(-2147483648);
        if (!str || strcmp(str, "-2147483648") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(INT_MIN)", RED, RESET);
            printf("\nExpected: \"-2147483648\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        size_t len = strlen(str);
        if (len != 11)
        {
            printf("\n%s[KO]%s: ft_itoa(INT_MIN) wrong length", RED, RESET);
            printf("\nExpected length: 11");
            printf("\nGot length: %zu", len);
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("INT_MAX",
        char *str = ft_itoa(2147483647);
        if (!str || strcmp(str, "2147483647") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(INT_MAX)", RED, RESET);
            printf("\nExpected: \"2147483647\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        size_t len = strlen(str);
        if (len != 10)
        {
            printf("\n%s[KO]%s: ft_itoa(INT_MAX) wrong length", RED, RESET);
            printf("\nExpected length: 10");
            printf("\nGot length: %zu", len);
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("All digits positive",
        char *str = ft_itoa(123456789);
        if (!str || strcmp(str, "123456789") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(123456789)", RED, RESET);
            printf("\nExpected: \"123456789\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("All digits negative",
        char *str = ft_itoa(-123456789);
        if (!str || strcmp(str, "-123456789") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(-123456789)", RED, RESET);
            printf("\nExpected: \"-123456789\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("INT_MIN + 1",
        char *str = ft_itoa(-2147483647);
        if (!str || strcmp(str, "-2147483647") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(-2147483647)", RED, RESET);
            printf("\nExpected: \"-2147483647\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("INT_MAX - 1",
        char *str = ft_itoa(2147483646);
        if (!str || strcmp(str, "2147483646") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(2147483646)", RED, RESET);
            printf("\nExpected: \"2147483646\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("Single digit pos",
        char *str = ft_itoa(7);
        if (!str || strcmp(str, "7") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(7)", RED, RESET);
            printf("\nExpected: \"7\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("Single digit neg",
        char *str = ft_itoa(-7);
        if (!str || strcmp(str, "-7") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(-7)", RED, RESET);
            printf("\nExpected: \"-7\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("All nines pos",
        char *str = ft_itoa(999999);
        if (!str || strcmp(str, "999999") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(999999)", RED, RESET);
            printf("\nExpected: \"999999\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );

    TEST("All nines neg",
        char *str = ft_itoa(-999999);
        if (!str || strcmp(str, "-999999") != 0)
        {
            printf("\n%s[KO]%s: ft_itoa(-999999)", RED, RESET);
            printf("\nExpected: \"-999999\"");
            printf("\nGot: %s", str ? str : "NULL");
            free(str);
            g_results.failed++;
            return;
        }
        free(str);
    );
}

static char f_to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

static char f_to_index(unsigned int i, char c)
{
    (void)c;
    return (i + '0');
}

static char f_alternate_case(unsigned int i, char c)
{
    if (i % 2 && c >= 'a' && c <= 'z')
        return (c - 32);
    if (!(i % 2) && c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

static char f_rot13(unsigned int i, char c)
{
    (void)i;
    if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
        return (c + 13);
    if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
        return (c - 13);
    return (c);
}

static void test_ft_strmapi(void)
{
    TEST("NULL string",
        char *result = ft_strmapi(NULL, f_to_upper);
        if (result != NULL)
        {
            printf("\n%s[KO]%s: ft_strmapi(NULL, f)", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: %s", result);
            free(result);
            g_results.failed++;
            return;
        }
    );

    TEST("NULL function",
        char *result = ft_strmapi("test", NULL);
        if (result != NULL)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"test\", NULL)", RED, RESET);
            printf("\nExpected: NULL");
            printf("\nGot: %s", result);
            free(result);
            g_results.failed++;
            return;
        }
    );

    TEST("Empty string",
        char *result = ft_strmapi("", f_to_upper);
        if (!result || strcmp(result, "") != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"\", f)", RED, RESET);
            printf("\nExpected: \"\"");
            printf("\nGot: %s", result ? result : "NULL");
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );

    TEST("Basic to upper",
        char *result = ft_strmapi("Hello World!", f_to_upper);
        if (!result || strcmp(result, "HELLO WORLD!") != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"Hello World!\", f_to_upper)", RED, RESET);
            printf("\nExpected: \"HELLO WORLD!\"");
            printf("\nGot: %s", result ? result : "NULL");
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );

    TEST("Index function",
        char *result = ft_strmapi("test", f_to_index);
        if (!result || strcmp(result, "0123") != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"test\", f_to_index)", RED, RESET);
            printf("\nExpected: \"0123\"");
            printf("\nGot: %s", result ? result : "NULL");
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );

    TEST("Alternate case",
        char *result = ft_strmapi("Hello World", f_alternate_case);
        if (!result || strcmp(result, "hElLo wOrLd") != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"Hello World\", f_alternate_case)", RED, RESET);
            printf("\nExpected: \"hElLo wOrLd\"");
            printf("\nGot: %s", result ? result : "NULL");
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );

    TEST("ROT13",
        char *result = ft_strmapi("Hello, World!", f_rot13);
        if (!result || strcmp(result, "Uryyb, Jbeyq!") != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"Hello, World!\", f_rot13)", RED, RESET);
            printf("\nExpected: \"Uryyb, Jbeyq!\"");
            printf("\nGot: %s", result ? result : "NULL");
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );

    TEST("Special chars",
        char *result = ft_strmapi("!@#$%%^&*()", f_to_upper);
        if (!result || strcmp(result, "!@#$%%^&*()") != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"!@#$%%^&*()\", f_to_upper)", RED, RESET);
            printf("\nExpected: \"!@#$%%^&*()\"");
            printf("\nGot: %s", result ? result : "NULL");
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );

    TEST("Long string",
        char *input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char *result = ft_strmapi(input, f_alternate_case);
        if (!result)
        {
            printf("\n%s[KO]%s: ft_strmapi(long_string, f_alternate_case)", RED, RESET);
            printf("\nGot: NULL");
            g_results.failed++;
            return;
        }
        char *expected = "aBcDeFgHiJkLmNoPqRsTuVwXyZaBcDeFgHiJkLmNoPqRsTuVwXyZ";
        if (strcmp(result, expected) != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(long_string, f_alternate_case)", RED, RESET);
            printf("\nExpected: \"%s\"", expected);
            printf("\nGot: \"%s\"", result);
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );

    TEST("All spaces",
        char *result = ft_strmapi("     ", f_to_upper);
        if (!result || strcmp(result, "     ") != 0)
        {
            printf("\n%s[KO]%s: ft_strmapi(\"     \", f_to_upper)", RED, RESET);
            printf("\nExpected: \"     \"");
            printf("\nGot: %s", result ? result : "NULL");
            free(result);
            g_results.failed++;
            return;
        }
        free(result);
    );
}

void test_part2(void)
{
    printf("\n%s=== Tests Part 2 ===%s\n", YELLOW, RESET);
    printf("%sft_substr%s\n", YELLOW, RESET);
    test_ft_substr();
    printf("%sft_strjoin%s\n", YELLOW, RESET);
    test_ft_strjoin();
    printf("%sft_strtrim%s\n", YELLOW, RESET);
    test_ft_strtrim();
    printf("%sft_split%s\n", YELLOW, RESET);
    test_ft_split();
    printf("%sft_itoa%s\n", YELLOW, RESET);
    test_ft_itoa();
    printf("%sft_strmapi%s\n", YELLOW, RESET);
    test_ft_strmapi();
    
}
