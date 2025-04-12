NAME = torchinette
LIBFT = libft.a
LIBFT_DIR = ../
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR) -Iinclude
SRC_DIR = src
OBJ_DIR = obj
LIBFT_FILES = 	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
				libft.h
SRCS = main.c \
       globals.c \
       test_part1.c \
       test_part2.c \
       test_atoi.c \
       test_bzero.c \
       test_calloc.c \
       test_strdup.c \
       test_striteri.c \
       utils.c \
       test_ft_fd.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Couleurs
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
ORANGE = \033[38;5;208m
BOLD = \033[1m
RESET = \033[0m

all: check $(NAME)
	@./$(NAME)

check:
	@missing_files=0; \
	for file in $(LIBFT_FILES); do \
		if [ ! -f $(LIBFT_DIR)/$$file ]; then \
			echo "$(RED)❌ Fichier manquant : $(LIBFT_DIR)/$$file$(RESET)"; \
			missing_files=1; \
		fi; \
	done; \
	if [ $$missing_files -eq 1 ]; then \
		echo "$(RED)⚠️  Compilation annulée à cause de fichiers manquants.$(RESET)"; \
		exit 1; \
	fi


# Règle pour compiler uniquement la libft
libft: $(LIBFT)

# Vérification de la norme (seulement pour la libft)
norm:
	@echo "$(YELLOW)Vérification de la norme de la libft...$(RESET)"
	@cd $(LIBFT_DIR) && norminette
	@echo "$(GREEN)Vérification de la norme de la libft terminée!$(RESET)"

# Aide
help:
	@echo "$(BOLD)Commandes disponibles:$(RESET)"
	@echo "$(YELLOW)make$(RESET)        - Compile le projet et lance les tests"
	@echo "$(YELLOW)make check$(RESET)  - Affiche un message d'erreur si il manque des fichiers sinon n'affiche rien"
	@echo "$(YELLOW)make libft.a$(RESET)  - Compile uniquement la libft"
	@echo "$(YELLOW)make norm$(RESET)   - Vérifie la norme de la libft"
	@echo "$(YELLOW)make clean$(RESET)  - Supprime les fichiers objets"
	@echo "$(YELLOW)make fclean$(RESET) - Supprime tous les fichiers générés"
	@echo "$(YELLOW)make re$(RESET)     - Recompile le projet"
	@echo "$(YELLOW)make help$(RESET)   - Affiche cette aide"

torch:
	@clear
	@echo "$(YELLOW)          /|"
	@echo "        /\\/ |/\\"
	@echo "        \\  ^   | /\\  /\\"
	@echo "  (\\/\\  / ^   /\\/  )/^ )"
	@echo "   \\  \\/^ /\\       ^  /"
	@echo "    )^       ^ \\     ("
	@echo "   (   ^   ^      ^\\  )"
	@echo "    \\___\\/____/______/$(RESET)"
	@echo "$(ORANGE)    [________________]"
	@echo "     |              |"
	@echo "     |     $(RED)//\\\\$(ORANGE)     |"
	@echo "     |    $(RED)<<$(YELLOW)()$(RED)>$(ORANGE)    |"
	@echo "     |     $(RED)\\\\/${YELLOW}/${ORANGE}     |"
	@echo "      \\____________/"
	@echo "          |    |"
	@echo "          |    |"
	@echo "          |    |"
	@echo "          |    |"
	@echo "          |    |"
	@echo "          |    |"
	@echo "          |    |$(RESET)"
	@echo "$(BOLD)$(ORANGE)aderison alias TheTorch...$(RESET)"
	@sleep 1

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT): $(shell find $(LIBFT_DIR) -type f -name "*.c") $(LIBFT_DIR)/libft.h
	@echo "$(YELLOW)Compilation de la libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(GREEN)Libft compilée avec succès!$(RESET)"

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT) torch
	@echo "$(YELLOW)Compilation du testeur...$(RESET)"
	@$(CC) $(OBJS) -L. -lft -o $(NAME)
	@echo "$(GREEN)Testeur compilé avec succès!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Nettoyage des fichiers objets...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(YELLOW)Nettoyage complet...$(RESET)"
	@rm -f $(NAME) $(LIBFT)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test torch libft norm help check