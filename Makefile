NAME			=	gnl

SRCS			=	get_next_line.c				\
					get_next_line_utils.c		\

BONUS_SRCS		=	get_next_line_bonus.c		\
					get_next_line_utils_bonus.c	\

HEADER			=	get_next_line.h

BONUS_HEADER	=	get_next_line_bonus.h

OBJ_DIR			=	obj/

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

BONUS_OBJS		=	$(addprefix $(OBJ_DIR), $(BONUS_SRCS:.c=.o))

CC				=	gcc
RM				=	rm -rf
MKDIR			=	mkdir -p
FLAGS			=	-Wall -Wextra -Werror

all				:	$(NAME)

bonus			:	$(BONUS_OBJS) $(BONUS_HEADER) Makefile
			@$(CC) -o $(NAME) $(FLAGS) $(BONUS_OBJS)

$(OBJ_DIR)%.o	:	%.c $(HEADER) Makefile
				@$(MKDIR) $(dir $@)
				$(CC) $(FALGS) -c $< -o $@

$(NAME)			:	$(OBJS)
				@$(CC) $(FLAGS) -o $@ $^

clean			:
				$(RM) $(OBJ_DIR)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re gnl