#include "torche.h"

static void	test_ft_fd_functions(void)
{
    int fd;
    char buf[1024];
    ssize_t ret;

    TEST("putchar_fd basic",
        fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putchar_fd('X', fd);
        close(fd);
        fd = open("/tmp/test_putchar", O_RDONLY);
        ret = read(fd, buf, 1);
        buf[ret] = '\0';
        close(fd);
        if (ret != 1 || buf[0] != 'X')
        {
            printf("\n%s[KO]%s: ft_putchar_fd('X', fd)", RED, RESET);
            printf("\nExpected: X");
            printf("\nGot: %s", buf);
            g_results.failed++;
            return;
        }
    );

    TEST("putchar_fd null char",
        fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putchar_fd('\0', fd);
        close(fd);
        fd = open("/tmp/test_putchar", O_RDONLY);
        ret = read(fd, buf, 1);
        close(fd);
        if (ret != 1 || buf[0] != '\0')
        {
            printf("\n%s[KO]%s: ft_putchar_fd('\\0', fd)", RED, RESET);
            printf("\nFailed to write null character");
            g_results.failed++;
            return;
        }
    );

    TEST("putstr_fd basic",
        fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putstr_fd("Hello World", fd);
        close(fd);
        fd = open("/tmp/test_putstr", O_RDONLY);
        ret = read(fd, buf, 1024);
        buf[ret] = '\0';
        close(fd);
        if (strcmp(buf, "Hello World") != 0)
        {
            printf("\n%s[KO]%s: ft_putstr_fd(\"Hello World\", fd)", RED, RESET);
            printf("\nExpected: Hello World");
            printf("\nGot: %s", buf);
            g_results.failed++;
            return;
        }
    );

    TEST("putstr_fd NULL",
        fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putstr_fd(NULL, fd);
        close(fd);
        fd = open("/tmp/test_putstr", O_RDONLY);
        ret = read(fd, buf, 1024);
        buf[ret] = '\0';
        close(fd);
        if (ret != 0)
        {
            printf("\n%s[KO]%s: ft_putstr_fd(NULL, fd)", RED, RESET);
            printf("\nWrote to file when input was NULL");
            g_results.failed++;
            return;
        }
    );

    TEST("putendl_fd basic",
        fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putendl_fd("Hello World", fd);
        close(fd);
        fd = open("/tmp/test_putendl", O_RDONLY);
        ret = read(fd, buf, 1024);
        buf[ret] = '\0';
        close(fd);
        if (strcmp(buf, "Hello World\n") != 0)
        {
            printf("\n%s[KO]%s: ft_putendl_fd(\"Hello World\", fd)", RED, RESET);
            printf("\nExpected: Hello World\\n");
            printf("\nGot: %s", buf);
            g_results.failed++;
            return;
        }
    );

    TEST("putendl_fd empty string",
        fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putendl_fd("", fd);
        close(fd);
        fd = open("/tmp/test_putendl", O_RDONLY);
        ret = read(fd, buf, 1024);
        buf[ret] = '\0';
        close(fd);
        if (strcmp(buf, "\n") != 0)
        {
            printf("\n%s[KO]%s: ft_putendl_fd(\"\", fd)", RED, RESET);
            printf("\nExpected: \\n");
            printf("\nGot: %s", buf);
            g_results.failed++;
            return;
        }
    );

    TEST("putnbr_fd zero",
        fd = open("/tmp/test_putnbr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putnbr_fd(0, fd);
        close(fd);
        fd = open("/tmp/test_putnbr", O_RDONLY);
        ret = read(fd, buf, 1024);
        buf[ret] = '\0';
        close(fd);
        if (strcmp(buf, "0") != 0)
        {
            printf("\n%s[KO]%s: ft_putnbr_fd(0, fd)", RED, RESET);
            printf("\nExpected: 0");
            printf("\nGot: %s", buf);
            g_results.failed++;
            return;
        }
    );

    TEST("putnbr_fd INT_MIN",
        fd = open("/tmp/test_putnbr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putnbr_fd(-2147483648, fd);
        close(fd);
        fd = open("/tmp/test_putnbr", O_RDONLY);
        ret = read(fd, buf, 1024);
        buf[ret] = '\0';
        close(fd);
        if (strcmp(buf, "-2147483648") != 0)
        {
            printf("\n%s[KO]%s: ft_putnbr_fd(INT_MIN, fd)", RED, RESET);
            printf("\nExpected: -2147483648");
            printf("\nGot: %s", buf);
            g_results.failed++;
            return;
        }
    );

    TEST("putnbr_fd INT_MAX",
        fd = open("/tmp/test_putnbr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            printf("\n%s[KO]%s: Could not create test file", RED, RESET);
            g_results.failed++;
            return;
        }
        ft_putnbr_fd(2147483647, fd);
        close(fd);
        fd = open("/tmp/test_putnbr", O_RDONLY);
        ret = read(fd, buf, 1024);
        buf[ret] = '\0';
        close(fd);
        if (strcmp(buf, "2147483647") != 0)
        {
            printf("\n%s[KO]%s: ft_putnbr_fd(INT_MAX, fd)", RED, RESET);
            printf("\nExpected: 2147483647");
            printf("\nGot: %s", buf);
            g_results.failed++;
            return;
        }
    );
}

void test_ft_fd()
{
    printf("\n%s=== Tests FT_FD ===%s\n", YELLOW, RESET);
    test_ft_fd_functions();
}