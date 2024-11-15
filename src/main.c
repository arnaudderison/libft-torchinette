#include "torche.h"

int main(int argc, char **argv)
{
    (void)argv;

    if (!setup_signal_handlers())
    {
        printf("%sErreur lors de l'initialisation des handlers de signaux%s\n",
            RED, RESET);
        return (1);
    }

    printf("%s=== LA TORCHINETTE - LIBFT (aderison) ===%s\n", MAGENTA, RESET);

    if (argc > 1)
    {
        printf("Mode test spécifique non implémenté\n");
        return (1);
    }

    test_atoi();
    test_part1();
    test_part2();
    print_results();

    return (g_results.failed > 0);
}