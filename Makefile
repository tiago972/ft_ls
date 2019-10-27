CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g3
NAME = ft_ls
OBJDIR = objs
SRCDIR = ./srcs
SRC = main.c \
	  parse_opt.c \
	  handle_error.c \
	  add_file.c \
	  add_folders.c \
	  debog.c
INCL = ./includes
LIBCREATOR = $(addprefix $(LIBDIR)/, $(LIB))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
include libft/Makefile_lib

$(NAME): $(OBJ) $(NAME_LIB)
	@$(CC) $(CFLAGS) -I $(INCL) $^ -o $@ 
	@echo "\n\033[38;5;208m$(NAME)\033[0m is ready to amazed you\n" 

$(OBJDIR)/%.o: $(SRCDIR)/%.c  
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS) 
	@echo "\033[38;5;82m$@\033[0m has been created" 

clean: 
	@rm -rf $(OBJDIR)
	@echo "\033[38;5;208m$(OBJDIR)\033[0m has been deleted" 

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;208m$(NAME)\033[0m has been deleted" 

re: fclean all

fclean_all: fclean_lib fclean

re_all: fclean_lib re

.PHONY: clean fclean all
