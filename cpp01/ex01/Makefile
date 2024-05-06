NAME = MoarBrainz!

# compilation
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++11
HEADER	= -I $(INCDIR)

ifdef DEBUG
CFLAGS	+= -g -fsanitize=address
endif

# directories
SRCDIR	= src
OBJDIR	= obj
BINDIR	= bin

# sources
SRCS	= $(SRCDIR)/main.cpp \
	$(SRCDIR)/Zombie.cpp \
	$(SRCDIR)/zombieHorde.cpp 

# objects
OBJS	= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# colours
PURPLE	= \033[0;35m
NC		= \033[0m

# rules
all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	@$(CC) $(OBJS) -o $(BINDIR)/$(NAME)
	@echo "$(PURPLE)$(NAME)$(NC) has been created"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $(HEADER) -o $@ $^
	@echo "Compiling: $(PURPLE)$<$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(PURPLE)object files$(NC) have been removed"

fclean: clean
	@rm -rf $(BINDIR)
	@echo "$(PURPLE)$(NAME) & directories$(NC) have been removed"

re: fclean all

debug: fclean
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re debug
