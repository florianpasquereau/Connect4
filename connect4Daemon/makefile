NAME			= connect4_d

SRC_NAME		= $(sort main.c connect4.c ssl.c responseGrid.c grid.c cell.c)

INCLUDES		= connect4.h

LIBRARY			= -lssl -lcrypto -ljson-c

OTHERS			= libft Makefile auteur

OTHER_FLAGS 	=

GCC				= gcc
CFLAGS			= -Wall -Wextra -Werror

OBJ_NAME		= $(SRC_NAME:.c=.o)

SRCDIR			= srcs
OBJDIR			= objs
INCDIR			= incs

SRC				= $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ				= $(addprefix $(OBJDIR)/, $(OBJ_NAME))
INC				= $(addprefix $(INCDIR)/, $(INCLUDES))

All : $(NAME)

$(NAME) : $(OBJDIR) $(OBJ)
	$(GCC) $(CFLAGS) $(OTHER_FLAGS) -o $(NAME) $(OBJ) $(LIBRARY)
	@echo "\033[0;32m"$(NAME) "DONE\033[0m"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC)
	$(GCC) -I $(INCDIR)/ $(CFLAGS) -o $@ -c $<

$(OBJDIR) : 
	mkdir -p $(OBJDIR)

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_32)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(OBJDIR)

re : fclean All
