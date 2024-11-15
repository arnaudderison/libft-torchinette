#include "torche.h"

// Définition des variables globales
sigjmp_buf g_jump_buffer;
t_test_results g_results = {0, 0, 0, 0, 0};
const char *g_current_test = NULL;

void print_results(void)
{
    printf("\n%s=== Rapport Final ===%s\n", MAGENTA, RESET);
    printf("%sTests réussis : %d%s\n", GREEN, g_results.passed, RESET);
    printf("%sTests échoués : %d%s\n", RED, g_results.failed, RESET);
    printf("%sSegfaults    : %d%s\n", YELLOW, g_results.segfaults, RESET);
    printf("%sBus errors   : %d%s\n", YELLOW, g_results.bus_errors, RESET);
    printf("%sAbort errors : %d%s\n", YELLOW, g_results.abort_errors, RESET);
    printf("%sTotal tests  : %d%s\n", CYAN, 
        g_results.passed + g_results.failed, RESET);
}

static void signal_handler(int signum, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;
    char buffer[100];
    int len;

    switch (signum)
    {
        case SIGSEGV:
            len = snprintf(buffer, sizeof(buffer),
                "%s[SEGV]%s Test '%s' a provoqué une segmentation fault\n",
                RED, RESET, g_current_test);
            write(STDOUT_FILENO, buffer, len);
            g_results.segfaults++;
            break;
        case SIGBUS:
            len = snprintf(buffer, sizeof(buffer),
                "%s[BUS]%s Test '%s' a provoqué une bus error\n",
                RED, RESET, g_current_test);
            write(STDOUT_FILENO, buffer, len);
            g_results.bus_errors++;
            break;
        case SIGABRT:
            len = snprintf(buffer, sizeof(buffer),
                "%s[ABRT]%s Test '%s' a provoqué une abort error\n",
                RED, RESET, g_current_test);
            write(STDOUT_FILENO, buffer, len);
            g_results.abort_errors++;
            break;
        default:
            len = snprintf(buffer, sizeof(buffer),
                "%s[ERR]%s Test '%s' a provoqué une erreur inconnue (%d)\n",
                RED, RESET, g_current_test, signum);
            write(STDOUT_FILENO, buffer, len);
    }
    g_results.failed++;
    siglongjmp(g_jump_buffer, 1);
}

int setup_signal_handlers(void)
{
    struct sigaction sa;

    // Initialisation de la structure sigaction
    memset(&sa, 0, sizeof(sa));
    
    // Configuration du handler
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;  // Pour recevoir les informations détaillées
    
    // Bloquer tous les signaux pendant l'exécution du handler
    sigfillset(&sa.sa_mask);
    
    // Installation des handlers pour différents signaux
    if (sigaction(SIGSEGV, &sa, NULL) == -1)
    {
        perror("Erreur lors de l'installation du handler SIGSEGV");
        return (0);
    }
    if (sigaction(SIGBUS, &sa, NULL) == -1)
    {
        perror("Erreur lors de l'installation du handler SIGBUS");
        return (0);
    }
    if (sigaction(SIGABRT, &sa, NULL) == -1)
    {
        perror("Erreur lors de l'installation du handler SIGABRT");
        return (0);
    }
    return (1);
}
