CH_NAME = checker
SW_NAME = push_swap
OS = $(shell uname)

INCDIR = ./includes

CH_SRCDIR = ./srcs
CH_OBJDIR = ./ch_obj

SW_SRCDIR = ./srcs
SW_OBJDIR = ./sw_obj

CH_SRC = checker.c \
			pile.c \
			ft_op_checker.c \
			cmd.c \
			check_tri.c \
			check_error.c \
			parsing.c \
			show.c

SW_SRC = push_swap.c \
					pile.c \
					ft_op_checker.c \
					check_error.c \
					parsing.c \
					sort_helper.c \
					check_tri.c \
					cmd.c \
					best_a_to_b.c \
					ft_outil.c \
					best_rotation.c \
					clear.c \
					sort_all.c \
					show.c \
					sort_pile.c \
					get_arg.c \

CH_OBJ		= $(addprefix $(CH_OBJDIR)/,$(CH_SRC:.c=.o))
SW_OBJ		= $(addprefix $(SW_OBJDIR)/,$(SW_SRC:.c=.o))

CC		= gcc
CFLAGS = -Wall -Wextra -Werror -g

FTDIR = ./libft
FT_LIB = $(addprefix $(FTDIR)/,libft.a)
FT_INC = -I $(FTDIR)
FT_LNK = -L $(FTDIR) -l ft

all: sw_obj ch_obj $(FT_LIB) $(SW_NAME) $(CH_NAME)

ch_obj:
		@mkdir -p $(CH_OBJDIR)

sw_obj:
		@mkdir -p $(SW_OBJDIR)

$(CH_OBJDIR)/%.o:$(CH_SRCDIR)/%.c
		@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(SW_OBJDIR)/%.o:$(SW_SRCDIR)/%.c
		@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FTDIR)

$(CH_NAME): $(CH_OBJ)
		@$(CC) $(CH_OBJ) $(FT_LNK) -lm -o $(CH_NAME)

$(SW_NAME): $(SW_OBJ)
		@$(CC) $(SW_OBJ) $(FT_LNK) -lm -o $(SW_NAME)

clean:
		rm -rf $(CH_OBJDIR) $(SW_OBJDIR)
		make -C $(FTDIR) clean

fclean: clean
		rm -f $(CH_NAME) $(SW_NAME)
		make -C $(FTDIR) fclean

re: fclean all
