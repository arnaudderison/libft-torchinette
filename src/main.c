#include "torche.h"

void    clear_terminal(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
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