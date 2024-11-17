#include "torche.h"

static void test_isalpha(void)
{
    TEST("ft_isalpha", {
        int success = 1;

        success &= (!!ft_isalpha('a') == !!isalpha('a'));
        if (!success) printf("Fail: 'a' -> ft_isalpha('a') = %d, isalpha('a') = %d\n", ft_isalpha('a'), isalpha('a'));

        success &= (!!ft_isalpha('Z') == !!isalpha('Z'));
        if (!success) printf("Fail: 'Z' -> ft_isalpha('Z') = %d, isalpha('Z') = %d\n", ft_isalpha('Z'), isalpha('Z'));

        success &= (!!ft_isalpha('0') == !!isalpha('0'));
        if (!success) printf("Fail: '0' -> ft_isalpha('0') = %d, isalpha('0') = %d\n", ft_isalpha('0'), isalpha('0'));

        success &= (!!ft_isalpha(' ') == !!isalpha(' '));
        if (!success) printf("Fail: ' ' -> ft_isalpha(' ') = %d, isalpha(' ') = %d\n", ft_isalpha(' '), isalpha(' '));

        success &= (!!ft_isalpha('@') == !!isalpha('@'));
        if (!success) printf("Fail: '@' -> ft_isalpha('@') = %d, isalpha('@') = %d\n", ft_isalpha('@'), isalpha('@'));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}


static void test_isdigit(void)
{
    TEST("ft_isdigit", {
        int success = 1;

        success &= (!!ft_isdigit('5') == !!isdigit('5'));
        if (!success) printf("Fail: '5' -> ft_isdigit('5') = %d, isdigit('5') = %d\n", ft_isdigit('5'), isdigit('5'));

        success &= (!!ft_isdigit('a') == !!isdigit('a'));
        if (!success) printf("Fail: 'a' -> ft_isdigit('a') = %d, isdigit('a') = %d\n", ft_isdigit('a'), isdigit('a'));

        success &= (!!ft_isdigit('0') == !!isdigit('0'));
        if (!success) printf("Fail: '0' -> ft_isdigit('0') = %d, isdigit('0') = %d\n", ft_isdigit('0'), isdigit('0'));

        success &= (!!ft_isdigit(' ') == !!isdigit(' '));
        if (!success) printf("Fail: ' ' -> ft_isdigit(' ') = %d, isdigit(' ') = %d\n", ft_isdigit(' '), isdigit(' '));

        success &= (!!ft_isdigit('\0') == !!isdigit('\0'));
        if (!success) printf("Fail: '\\0' -> ft_isdigit('\\0') = %d, isdigit('\\0') = %d\n", ft_isdigit('\0'), isdigit('\0'));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}


static void test_isalnum(void)
{
    TEST("ft_isalnum", {
        int success = 1;

        success &= (!!ft_isalnum('5') == !!isalnum('5'));
        if (!success) printf("Fail: '5' -> ft_isalnum('5') = %d, isalnum('5') = %d\n", ft_isalnum('5'), isalnum('5'));

        success &= (!!ft_isalnum('a') == !!isalnum('a'));
        if (!success) printf("Fail: 'a' -> ft_isalnum('a') = %d, isalnum('a') = %d\n", ft_isalnum('a'), isalnum('a'));

        success &= (!!ft_isalnum('Z') == !!isalnum('Z'));
        if (!success) printf("Fail: 'Z' -> ft_isalnum('Z') = %d, isalnum('Z') = %d\n", ft_isalnum('Z'), isalnum('Z'));

        success &= (!!ft_isalnum('!') == !!isalnum('!'));
        if (!success) printf("Fail: '!' -> ft_isalnum('!') = %d, isalnum('!') = %d\n", ft_isalnum('!'), isalnum('!'));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}


static void test_isascii(void)
{
    TEST("ft_isascii", {
        int success = 1;
        success &= (!!ft_isascii('A') == !!isascii('A'));
        success &= (!!ft_isascii(127) == !!isascii(127));
        success &= (!!ft_isascii(128) == !!isascii(128));
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}

static void test_isprint(void)
{
    TEST("ft_isprint", {
        int success = 1;
        success &= (!!ft_isprint(' ') == !!isprint(' '));
        success &= (!!ft_isprint('A') == !!isprint('A'));
        success &= (!!ft_isprint(32) == !!isprint(32));
        success &= (!!ft_isprint(127) == !!isprint(127));
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
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
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });

    TEST("ft_strlen - long string", {
        int success = 1;
        
        char *long_str = malloc(1000001);
        if (!long_str)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }
        memset(long_str, 'a', 1000000);
        long_str[1000000] = '\0';
        
        success &= (ft_strlen(long_str) == strlen(long_str));
        free(long_str);
        
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }
        g_results.passed++;
    });

    TEST("ft_strlen - INT_MAX overflow test", {
        int success = 1;
        
        char *str = malloc((size_t)INT_MAX + 3);
        if (!str)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        size_t test_size = (size_t)INT_MAX + 1;
        memset(str, 'a', test_size);
        str[test_size] = '\0';
        success &= (ft_strlen(str) == strlen(str));

        free(str);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur détectée : votre ft_strlen utilise probablement un int au lieu de size_t\n");
            g_results.failed++;
            return;
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
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset(\'A\', 10)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        ft_memset(str1, 0, 10);
        memset(str2, 0, 10);
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset(0, 10)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        ft_memset(str1, 255, 10);
        memset(str2, 255, 10);
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset(255, 10)\n");
            printf("Expected: ");
            for (int i = 0; i < 10; i++) printf("%c", str2[i]);
            printf("\nGot:      ");
            for (int i = 0; i < 10; i++) printf("%c", str1[i]);
            printf("\n");
            success = 0;
        }

        ft_memset(str1, 127, 10);
        memset(str2, 127, 10);
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset(127, 10)\n");
            printf("Expected: ");
            for (int i = 0; i < 10; i++) printf("%c", str2[i]);
            printf("\nGot:      ");
            for (int i = 0; i < 10; i++) printf("%c", str1[i]);
            printf("\n");
            success = 0;
        }

        ft_memset(str1, 'B', 10);
        memset(str2, 'B', 10);
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset('B', 10)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        ft_memset(str1, 'A', 50);
        memset(str2, 'A', 50);
        if (memcmp(str1, str2, 50) != 0) {
            printf("Fail: ft_memset('A', 50)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        ft_memset(str1, 'C', 5);
        memset(str2, 'C', 5);
        if (memcmp(str1, str2, 5) != 0) {
            printf("Fail: ft_memset('C', 5)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        ft_memset(str1, 'Z', 50);
        memset(str2, 'Z', 50);
        if (memcmp(str1, str2, 50) != 0) {
            printf("Fail: ft_memset('Z', 50)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        ft_memset(str1, 'X', 0);
        memset(str2, 'X', 0);
        if (memcmp(str1, str2, 50) != 0) {
            printf("Fail: ft_memset('X', 0)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        ft_memset(str1, 'A', 10);
        ft_memset(str1 + 20, 'B', 10);
        memset(str2, 'A', 10);
        memset(str2 + 20, 'B', 10);
        if (memcmp(str1, str2, 50) != 0) {
            printf("Fail: ft_memset(Partial fill)\n");
            printf("Expected: ");
            for (int i = 0; i < 50; i++) printf("%c", str2[i]);
            printf("\nGot:      ");
            for (int i = 0; i < 50; i++) printf("%c", str1[i]);
            printf("\n");
            success = 0;
        }

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
        }
    });

    TEST("ft_memset - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 100;
        char *str = malloc(size);
        if (!str)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        ft_memset(str, 'A', size);

        int success = 1;
        for (size_t i = 0; i < size; i++)
        {
            if (str[i] != 'A')
            {
                success = 0;
                break;
            }
        }

        free(str);
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : memset n'a pas rempli après INT_MAX\n");
            g_results.failed++;
            return;
        }
    });
}


static void test_memcpy(void)
{
    TEST("ft_memcpy", {
        char str1[50];
        char str2[50];
        int success = 1;

        ft_memcpy(str1, "Hello", 6);
        memcpy(str2, "Hello", 6);
        if (memcmp(str1, str2, 6) != 0) {
            printf("\nFail: ft_memcpy('Hello', 6)");
            printf("\nExpected: %s\n", str2);
            printf("\nGot:      %s\n", str1);
            success = 0;
        }

        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "Hello", 0);
        if (memcmp(str1, str2, 50) != 0) {
            printf("\nFail: ft_memcpy('Hello', 0)");
            printf("\nExpected: ");
            for (int i = 0; i < 50; i++) printf("%c", str2[i]);
            printf("\nGot:      ");
            for (int i = 0; i < 50; i++) printf("%c", str1[i]);
            printf("\n");
            success = 0;
        }

        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "Hello", 6);
        memcpy(str2, "World", 6);
        if (memcmp(str1, str2, 6) == 0) {
            printf("\nFail: ft_memcpy with different strings");
            printf("\nExpected: %s", str2);
            printf("\nGot:      %s", str1);
            success = 0;
        }

        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "Hello", 50);
        memcpy(str2, "Hello", 50);
        if (memcmp(str1, str2, 50) != 0) {
            printf("\nFail: ft_memcpy(n > 50)");
            printf("\nExpected: %s", str1);
            printf("\nGot: %s", str2);
            success = 0;
        }

        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "\0\0\0\0", 4);
        memcpy(str2, "\0\0\0\0", 4);
        if (memcmp(str1, str2, 4) != 0) {
            printf("\nFail: ft_memcpy with special characters ('\\0')");
            printf("\nExpected: ");
            for (int i = 0; i < 4; i++) printf("%c", str2[i]);
            printf("\nGot:      ");
            for (int i = 0; i < 4; i++) printf("%c", str1[i]);
            success = 0;
        }

        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "HelloWorld", 5); 
        memcpy(str2, "HelloWorld", 5);
        if (memcmp(str1, str2, 5) != 0) {
            printf("\nFail: ft_memcpy partial copy ('Hello')");
            printf("\nExpected: %s", str2);
            printf("\nGot:      %s", str1);
            success = 0;
        }

        ft_memcpy(str1, "HelloWorld", 5);
        ft_memcpy(str1 + 2, str1, 5);
        memcpy(str2, "HelloWorld", 5);
        memcpy(str2 + 2, str2, 5);
        if (memcmp(str1, str2, 5) == 0) {
            printf("\nFail: ft_memcpy with overlap");
            printf("\nExpected: HeHelloWorld");
            printf("\nGot:      %s", str1);
            success = 0;
        }

        if (!success)
        {
            printf("%s[KO]%s ft_memcpy\n", RED, RESET);
            g_results.failed++;
        }
    });

    TEST("ft_memcpy - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 100;
        char *src = malloc(size);
        char *dst = malloc(size);
        if (!src || !dst)
        {
            free(src);
            free(dst);
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        memset(src, 'B', size);
        
        ft_memcpy(dst, src, size);

        int success = (memcmp(src, dst, size) == 0);

        free(src);
        free(dst);
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : memcpy n'a pas copié après INT_MAX\n");
            g_results.failed++;
            return;
        }
    });
}

static void test_memmove(void)
{
    TEST("ft_memmove", {
        char str1[50];
        char str2[50];
        int success = 1;

        memmove(str1, "Hello", 6);
        ft_memmove(str2, "Hello", 6);
        success &= (memcmp(str1, str2, 6) == 0);

        memmove(str1 + 2, str1, 4); // Test with overlap
        ft_memmove(str2 + 2, str2, 4);
        success &= (memcmp(str1, str2, 6) == 0);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
        }
    });

    TEST("ft_memmove - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 100;
        char *buffer = malloc(size * 2);
        if (!buffer)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        memset(buffer, 'C', size);
        
        ft_memmove(buffer + 1, buffer, size - 1);

        int success = 1;
        for (size_t i = 1; i < size; i++)
        {
            if (buffer[i] != 'C')
            {
                success = 0;
                break;
            }
        }

        free(buffer);
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : memmove n'a pas déplacé après INT_MAX\n");
            g_results.failed++;
            return;
        }
    });
}

static void test_strlcpy(void)
{
    TEST("ft_strlcpy", {
        int success = 1;
        char str1[50];
        char str2[50];

        size_t result1 = ft_strlcpy(str1, "Hello", 50);
        size_t result2 = ft_test_strlcpy(str2, "Hello", 50);
        if (result1 != result2) {
            printf("\nFail: ft_strlcpy('Hello', 50)\n");
            printf("\nExpected: %zu\n", result2);
            printf("\nGot:      %zu\n", result1);
            success = 0;
        }
        
        result1 = ft_strlcpy(str1, "", 50);
        result2 = ft_test_strlcpy(str2, "", 50);
        if (result1 != result2) {
            printf("\nFail: ft_strlcpy('', 50)\n");
            printf("\nExpected: %zu\n", result2);
            printf("\nGot:      %zu\n", result1);
            success = 0;
        }
        result1 = ft_strlcpy(str1, "Hello", 3);
        result2 = ft_test_strlcpy(str2, "Hello", 3);
        if (result1 != result2) {
            printf("\nFail: ft_strlcpy('Hello', 3)\n");
            printf("\nExpected: %zu\n", result2);
            printf("\nGot:      %zu\n", result1);
            success = 0;
        }

        ft_strlcpy(str1, "Hello", 50);
        ft_test_strlcpy(str2, "Hello", 50);
        if (strcmp(str1, str2) != 0) {
            printf("\nFail: ft_strlcpy content mismatch\n");
            printf("\nExpected: '%s'\n", str2);
            printf("\nGot:      '%s'\n", str1);
            success = 0;
        }
    
        ft_strlcpy(str1, "Hello", 6);
        ft_test_strlcpy(str2, "Hello", 6);
        if (strcmp(str1, str2) != 0) {
            printf("\nFail: ft_strlcpy content mismatch for size 6\n");
            printf("\nExpected: '%s'\n", str2);
            printf("\nGot:      '%s'\n", str1);
            success = 0;
        }

        ft_strlcpy(str1, "Hello", 4);
        ft_test_strlcpy(str2, "Hello", 4);
        if (strcmp(str1, str2) != 0) {
            printf("\nFail: ft_strlcpy content mismatch for size 4\n");
            printf("\nExpected: '%s'\n", str2);
            printf("\nGot:      '%s'\n", str1);
            success = 0;
        }

        if (!success)
        {
            printf("\n%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });

    TEST("ft_strlcpy - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 20;
        char *src = malloc(size + 1);
        char *dst = malloc(size + 1);
        if (!src || !dst)
        {
            free(src);
            free(dst);
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        memset(src, 'A', size);
        src[(size_t)INT_MAX + 1] = 'B';
        src[size] = '\0';

        size_t result = ft_strlcpy(dst, src, size + 1);
        
        int success = (result == size) && (dst[(size_t)INT_MAX + 1] == 'B');
        
        free(src);
        free(dst);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("ft_strlcpy n'a pas copié correctement après INT_MAX\n");
            g_results.failed++;
            return;
        }

    });
}



static void test_strlcat(void)
{
    TEST("ft_strlcat", {
        int success = 1;
        char str1[50];
        char str2[50];

        ft_strlcpy(str1, "Hello", 50);
        ft_strlcat(str1, " World", 50);
        ft_test_strlcpy(str2, "Hello", 50);
        ft_test_strlcat(str2, " World", 50);
        success &= (strcmp(str1, str2) == 0);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });

    TEST("ft_strlcat - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 50;
        char *dst = malloc(size + 1);
        char *src = malloc(2);
        if (!dst || !src)
        {
            free(dst);
            free(src);
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        // Préparer les chaînes
        memset(dst, 'A', size - 1);
        dst[size - 1] = '\0';
        src[0] = 'B';
        src[1] = '\0';

        // Concaténer
        size_t result = ft_strlcat(dst, src, size + 1);
        
        int success = (result == size) && (dst[size - 1] == 'B');
        
        free(dst);
        free(src);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("ft_strlcat n'a pas géré correctement la taille > INT_MAX\n");
            g_results.failed++;
            return;
        }
        printf("%s[OK]%s\n", GREEN, RESET);
        g_results.passed++;
    });
}

static void test_toupper(void)
{
    TEST("ft_toupper", {
        int success = 1;
        success &= (ft_toupper('a') == toupper('a'));
        success &= (ft_toupper('z') == toupper('z'));
        success &= (ft_toupper('A') == toupper('A'));
        success &= (ft_toupper('1') == toupper('1'));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}

static void test_tolower(void)
{
    TEST("ft_tolower", {
        int success = 1;
        success &= (ft_tolower('A') == tolower('A'));
        success &= (ft_tolower('Z') == tolower('Z'));
        success &= (ft_tolower('a') == tolower('a'));
        success &= (ft_tolower('1') == tolower('1'));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}

static void test_strchr(void)
{
    TEST("ft_strchr", {
        int success = 1;
        success &= (ft_strchr("Hello", 'e') == strchr("Hello", 'e'));
        success &= (ft_strchr("Hello", 'z') == strchr("Hello", 'z'));
        success &= (ft_strchr("Hello", '\0') == strchr("Hello", '\0'));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}

static void test_strrchr(void)
{
    TEST("ft_strrchr", {
        int success = 1;
        success &= (ft_strrchr("Hello", 'l') == strrchr("Hello", 'l'));
        success &= (ft_strrchr("Hello", 'z') == strrchr("Hello", 'z'));
        success &= (ft_strrchr("Hello", '\0') == strrchr("Hello", '\0'));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}

static void test_strncmp(void)
{
    TEST("ft_strncmp", {
        int success = 1;
        success &= (ft_strncmp("Hello", "Hello", 5) == strncmp("Hello", "Hello", 5));
        success &= (ft_strncmp("Hello", "Hella", 5) == strncmp("Hello", "Hella", 5));
        success &= (ft_strncmp("Hello", "Hellz", 3) == strncmp("Hello", "Hellz", 3));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}

static void test_memchr(void)
{
    TEST("ft_memchr", {
        int success = 1;
        success &= (ft_memchr("Hello", 'e', 5) == memchr("Hello", 'e', 5));
        success &= (ft_memchr("Hello", 'z', 5) == memchr("Hello", 'z', 5));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });

     TEST("ft_memchr - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 100;
        size_t target_pos = (size_t)INT_MAX + 42;
        unsigned char *str = malloc(size);
        if (!str)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        memset(str, 'A', size);
        
        str[target_pos] = 'B';

        void *result = ft_memchr(str, 'B', size);
        
        if (result != (str + target_pos))
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : ft_memchr n'a pas trouvé le caractère après INT_MAX\n");
            printf("Probablement dû à l'utilisation de int au lieu de size_t\n");
            free(str);
            g_results.failed++;
            return;
        }

        free(str);
    });

    TEST("ft_memchr - NULL byte test after INT_MAX", {
        size_t size = (size_t)INT_MAX + 100;
        size_t target_pos = (size_t)INT_MAX + 50;
        unsigned char *str = malloc(size);
        if (!str)
        {
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        memset(str, 'A', size);
        
        str[target_pos] = '\0';

        void *result = ft_memchr(str, '\0', size);
        
        if (result != (str + target_pos))
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : ft_memchr n'a pas trouvé le \\0 après INT_MAX\n");
            free(str);
            g_results.failed++;
            return;
        }

        free(str);
    });
}

static void test_memcmp(void)
{
    TEST("ft_memcmp", {
        int success = 1;
        success &= (ft_memcmp("Hello", "Hello", 5) == memcmp("Hello", "Hello", 5));
        success &= (ft_memcmp("Hello", "Hellz", 5) == memcmp("Hello", "Hellz", 5));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });

    TEST("ft_memcmp - size_t vs int test", {
        size_t size = (size_t)INT_MAX + 1000;
        char *s1 = malloc(size);
        char *s2 = malloc(size);
        if (!s1 || !s2)
        {
            free(s1);
            free(s2);
            printf("%s[MALLOC ERROR]%s\n", RED, RESET);
            g_results.failed++;
            return;
        }

        memset(s1, 'D', size);
        memset(s2, 'D', size);
        
        size_t target_pos = (size_t)INT_MAX + 42;
        s2[target_pos] = 'E';

        int result = ft_memcmp(s1, s2, size);
        int expected = memcmp(s1, s2, size);

        free(s1);
        free(s2);
        
        if ((result < 0 && expected >= 0) || (result >= 0 && expected < 0))
        {
            printf("%s[KO]%s\n", RED, RESET);
            printf("Erreur : memcmp n'a pas détecté la différence après INT_MAX\n");
            g_results.failed++;
            return;
        }
    });
}

static void test_strnstr(void)
{
    TEST("ft_strnstr", {
        int success = 1;
        success &= (ft_strnstr("Hello, world", "world", 20) == ft_test_strnstr("Hello, world", "world", 20));
        success &= (ft_strnstr("Hello, world", "world", 5) == ft_test_strnstr("Hello, world", "world", 5));

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
    });
}

void test_part1(void)
{
    printf("\n%s=== Tests Part 1 ===%s\n", YELLOW, RESET);
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_strlen();
    test_memset();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_toupper();
    test_tolower();
    test_strchr();
    test_strrchr();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_strnstr();
}
