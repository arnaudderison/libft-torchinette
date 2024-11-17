#include "torche.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void clear_terminal(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int check_norm(void)
{
    int status;
    pid_t pid;
    int dev_null;

    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        dev_null = open("/dev/null", O_WRONLY);
        dup2(dev_null, STDOUT_FILENO);
        dup2(dev_null, STDERR_FILENO);
        if (chdir("libft") == -1)
            exit(1);
        execlp("norminette", "norminette", NULL);
        exit(1);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
    {
        printf("%sLibft à la norme ✓%s\n\n", GREEN, RESET);
        return (0);
    }
    printf("%sLibft pas à la norme ✗%s\n\n", RED, RESET);
    return (1);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (!setup_signal_handlers())
    {
        printf("%sErreur lors de l'initialisation des handlers de signaux%s\n",
            RED, RESET);
        return (1);
    }
    clear_terminal();
    printf("%s=== LA TORCHINETTE - LIBFT (aderison) ===%s\n", MAGENTA, RESET);
    
    check_norm();

    if (argc > 1)
    {
        printf("Mode test spécifique non implémenté\n");
        return (1);
    }
    test_atoi();
    test_bzero();
    test_calloc();
    test_strdup();
    test_part1();
    test_part2();
    test_striteri();
    test_ft_fd();
    print_results();
    return (g_results.failed > 0);
}