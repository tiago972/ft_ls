CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I $(INCL)
NAME = ft_ls
OBJDIR = objs
SRCDIR = ./srcs
SRC = main.c \
	add_file.c
INCL = ./includes
LIBCREATOR = $(addprefix $(LIBDIR)/, $(LIB))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
include libft/Makefile_lib

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	@$(CC) $(CFLAGS) -I $(INCL) $(LIBCREATOR) -o $@ $^
	@echo "\n\033[38;5;4;1;4m$(NAME)\033[0m compiled successfully\n" 

$(OBJDIR)/%.o : $(SRCDIR)/%.c  
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
