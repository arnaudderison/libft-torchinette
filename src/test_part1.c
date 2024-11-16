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
}

static void test_memset(void)
{
    TEST("ft_memset", {
        char str1[50];
        char str2[50];
        int success = 1;
        
        // Test avec 'A' sur les 10 premiers octets
        ft_memset(str1, 'A', 10);
        memset(str2, 'A', 10);
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset(\'A\', 10)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        // Test avec 0 sur les 10 premiers octets
        ft_memset(str1, 0, 10);
        memset(str2, 0, 10);
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset(0, 10)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        // Test avec une valeur limite (255) sur les 10 premiers octets
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

        // Test avec une valeur limite (127) sur les 10 premiers octets
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

        // Test avec remplissage d'une chaîne déjà remplie avec une autre valeur
        ft_memset(str1, 'B', 10);
        memset(str2, 'B', 10);
        if (memcmp(str1, str2, 10) != 0) {
            printf("Fail: ft_memset('B', 10)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        // Test avec un n plus grand que la taille de la chaîne
        ft_memset(str1, 'A', 50);
        memset(str2, 'A', 50);
        if (memcmp(str1, str2, 50) != 0) {
            printf("Fail: ft_memset('A', 50)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        // Test avec un n partiel, remplissage des 5 premiers octets sur une chaîne de 10
        ft_memset(str1, 'C', 5);
        memset(str2, 'C', 5);
        if (memcmp(str1, str2, 5) != 0) {
            printf("Fail: ft_memset('C', 5)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        // Test avec un n égal à la taille de la chaîne (50)
        ft_memset(str1, 'Z', 50);
        memset(str2, 'Z', 50);
        if (memcmp(str1, str2, 50) != 0) {
            printf("Fail: ft_memset('Z', 50)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        // Test avec n = 0, aucune modification de la chaîne
        ft_memset(str1, 'X', 0);
        memset(str2, 'X', 0);
        if (memcmp(str1, str2, 50) != 0) {
            printf("Fail: ft_memset('X', 0)\n");
            printf("Expected: %s\n", str2);
            printf("Got:      %s\n", str1);
            success = 0;
        }

        // Vérifier que le reste de la chaîne après le remplissage partiel reste inchangé
        ft_memset(str1, 'A', 10);  // Remplir les 10 premiers octets
        ft_memset(str1 + 20, 'B', 10);  // Remplir les 10 octets après le 20ème
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

        // Résultat du test
        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
        }
    });
}


static void test_memcpy(void)
{
    TEST("ft_memcpy", {
        char str1[50];
        char str2[50];
        int success = 1;

        // Test de copie basique avec 6 octets
        ft_memcpy(str1, "Hello", 6);
        memcpy(str2, "Hello", 6);
        if (memcmp(str1, str2, 6) != 0) {
            printf("\nFail: ft_memcpy('Hello', 6)");
            printf("\nExpected: %s\n", str2);
            printf("\nGot:      %s\n", str1);
            success = 0;
        }

        // Test avec n = 0, aucune donnée ne doit être copiée
        memset(str1, 0, 50);
        memset(str2, 0, 50);  // Initialiser str2 à zéro
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

        // Test avec des données différentes
        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "Hello", 6);
        memcpy(str2, "World", 6);
        if (memcmp(str1, str2, 6) == 0) {  // Les chaînes ne doivent pas être identiques
            printf("\nFail: ft_memcpy with different strings");
            printf("\nExpected: %s", str2);
            printf("\nGot:      %s", str1);
            success = 0;
        }

        // Test avec n > taille de destination (ex : 50)
        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "Hello", 50);  // Copie plus de données que la taille du tableau
        memcpy(str2, "Hello", 50);
        if (memcmp(str1, str2, 50) != 0) {  // La fonction ne doit pas provoquer de dépassement mémoire
            printf("\nFail: ft_memcpy(n > 50)");
            printf("\nExpected: %s", str1);
            printf("\nGot: %s", str2);
            success = 0;
        }

        // Tester avec des caractères spéciaux : '\0' et 0xFF
        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "\0\0\0\0", 4);
        memcpy(str2, "\0\0\0\0", 4);
        if (memcmp(str1, str2, 4) != 0) {  // Doit être égal même si \0 est présent
            printf("\nFail: ft_memcpy with special characters ('\\0')");
            printf("\nExpected: ");
            for (int i = 0; i < 4; i++) printf("%c", str2[i]);
            printf("\nGot:      ");
            for (int i = 0; i < 4; i++) printf("%c", str1[i]);
            success = 0;
        }

        // Tester avec des copies partielles (n < longueur de la chaîne)
        memset(str1, 0, 50);
        memset(str2, 0, 50);
        ft_memcpy(str1, "HelloWorld", 5);  // Copie seulement "Hello"
        memcpy(str2, "HelloWorld", 5);
        if (memcmp(str1, str2, 5) != 0) {  // Les premiers 5 caractères doivent être égaux
            printf("\nFail: ft_memcpy partial copy ('Hello')");
            printf("\nExpected: %s", str2);
            printf("\nGot:      %s", str1);
            success = 0;
        }

        // Test avec chevauchement de mémoire (cas non défini pour memcpy mais utile pour voir l'effet)
        ft_memcpy(str1, "HelloWorld", 5);  // Copier "Hello" dans str1
        ft_memcpy(str1 + 2, str1, 5);  // Copier "Hello" à partir de str1[2]
        memcpy(str2, "HelloWorld", 5);
        memcpy(str2 + 2, str2, 5);
        if (memcmp(str1, str2, 5) == 0) {  // Ce test peut échouer si la fonction ne gère pas les chevauchements
            printf("\nFail: ft_memcpy with overlap");
            printf("\nExpected: HeHelloWorld");
            printf("\nGot:      %s", str1);
            success = 0;
        }

        // Résultat global du test
        if (!success)
        {
            printf("%s[KO]%s ft_memcpy\n", RED, RESET);
            g_results.failed++;
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
}

static void test_strlcpy(void)
{
    TEST("ft_strlcpy", {
        int success = 1;
        char str1[50];
        char str2[50];

        // Test 1: Copie complète avec un tampon suffisamment grand
        size_t result1 = ft_strlcpy(str1, "Hello", 50);
        size_t result2 = strlcpy(str2, "Hello", 50);
        if (result1 != result2) {
            printf("\nFail: ft_strlcpy('Hello', 50)\n");
            printf("\nExpected: %zu\n", result2);
            printf("\nGot:      %zu\n", result1);
            success = 0;
        }
        
        // Test 2: Copie d'une chaîne vide
        result1 = ft_strlcpy(str1, "", 50);
        result2 = strlcpy(str2, "", 50);
        if (result1 != result2) {
            printf("\nFail: ft_strlcpy('', 50)\n");
            printf("\nExpected: %zu\n", result2);
            printf("\nGot:      %zu\n", result1);
            success = 0;
        }

        // Test 3: Copie avec une taille de tampon plus petite que la chaîne
        result1 = ft_strlcpy(str1, "Hello", 3);
        result2 = strlcpy(str2, "Hello", 3);
        if (result1 != result2) {
            printf("\nFail: ft_strlcpy('Hello', 3)\n");
            printf("\nExpected: %zu\n", result2);
            printf("\nGot:      %zu\n", result1);
            success = 0;
        }

        // Test 4: Vérification du contenu copié avec un tampon plus grand
        ft_strlcpy(str1, "Hello", 50);
        strlcpy(str2, "Hello", 50);
        if (strcmp(str1, str2) != 0) {
            printf("\nFail: ft_strlcpy content mismatch\n");
            printf("\nExpected: '%s'\n", str2);
            printf("\nGot:      '%s'\n", str1);
            success = 0;
        }

        // Test 5: Copie avec un tampon exactement de la taille de la chaîne + 1
        ft_strlcpy(str1, "Hello", 6);
        strlcpy(str2, "Hello", 6);
        if (strcmp(str1, str2) != 0) {
            printf("\nFail: ft_strlcpy content mismatch for size 6\n");
            printf("\nExpected: '%s'\n", str2);
            printf("\nGot:      '%s'\n", str1);
            success = 0;
        }

        // Test 6: Test avec un tampon plus petit que la chaîne mais avec l'allocation correcte
        ft_strlcpy(str1, "Hello", 4);
        strlcpy(str2, "Hello", 4);
        if (strcmp(str1, str2) != 0) {
            printf("\nFail: ft_strlcpy content mismatch for size 4\n");
            printf("\nExpected: '%s'\n", str2);
            printf("\nGot:      '%s'\n", str1);
            success = 0;
        }

        // Résultat final
        if (!success)
        {
            printf("\n%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
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
        strlcpy(str2, "Hello", 50);
        strlcat(str2, " World", 50);
        success &= (strcmp(str1, str2) == 0);

        if (!success)
        {
            printf("%s[KO]%s\n", RED, RESET);
            g_results.failed++;
            return ;
        }
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
}

static void test_strnstr(void)
{
    TEST("ft_strnstr", {
        int success = 1;
        success &= (ft_strnstr("Hello, world", "world", 20) == strnstr("Hello, world", "world", 20));
        success &= (ft_strnstr("Hello, world", "world", 5) == strnstr("Hello, world", "world", 5));

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
