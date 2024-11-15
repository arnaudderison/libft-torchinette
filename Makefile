NAME = torchinette
LIBFT = libft.a
LIBFT_DIR = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR) -Iinclude

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c \
       globals.c \
       test_part1.c \
       test_part2.c \
	   test_atoi.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Couleurs
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "$(YELLOW)Compilation de la libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(GREEN)Libft compilée avec succès!$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Compilation du testeur...$(RESET)"
	$(CC) $(OBJS) -L. -lft -o $(NAME)
	@echo "$(GREEN)Testeur compilé avec succès!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Nettoyage des fichiers objets...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(YELLOW)Nettoyage complet...$(RESET)"
	@rm -f $(NAME) $(LIBFT)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

test: all
	@echo "$(YELLOW)Exécution des tests...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re test