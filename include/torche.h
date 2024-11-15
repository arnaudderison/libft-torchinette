/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torche.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:07:19 by aderison          #+#    #+#             */
/*   Updated: 2024/11/15 13:02:30 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TORCHE_H
#define TORCHE_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <signal.h>
# include <setjmp.h>
# include <unistd.h>
# include "libft.h"

// Codes couleur
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

// Structure pour les résultats
typedef struct s_test_results {
    int passed;
    int failed;
    int segfaults;
    int bus_errors;
    int abort_errors;
} t_test_results;

// Variables globales
extern sigjmp_buf g_jump_buffer;
extern t_test_results g_results;
extern const char *g_current_test;

// Macro pour les tests
# define TEST(name, code) do { \
    g_current_test = name; \
    printf("%sTesting %s...%s\n", BLUE, name, RESET); \
    if (sigsetjmp(g_jump_buffer, 1) == 0) { \
        code; \
        printf("%s[OK]%s %s\n", GREEN, RESET, name); \
        g_results.passed++; \
    } \
} while(0)

// Prototypes
int     setup_signal_handlers(void);
void    test_part1(void);
void    test_part2(void);
void    test_atoi(void);
void    print_results(void);

#endif