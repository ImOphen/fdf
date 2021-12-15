NAME=fdf
CSRCS= fdf.c ft_atoi.c ft_split.c ft_buttons.c ft_draw.c bresenham.c get_next_line.c graphics.c ft_strchr.c get_next_line_utils.c main.c ft_printf.c print_functions.c ft_rot_right.c ft_rotation_2.c ft_rotation_3.c
CFLAGS= -Wall -Wextra -Werror
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m
CC= gcc

OBJS=$(CSRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n------------------------------------------------------------------"
	@echo "\n$(_PURPLE)linking $(_GREEN)$(OBJS) $(_PURPLE)to $(_BLUE)$(NAME)$(_GREEN)..."
	@echo "\n------------------------------------------------------------------"

%.o:%.c
	@$(CC) $(CFLAGS) -c $^
	@echo "$(_YELLOW)Compiling $(_GREEN)$^ $(_YELLOW)to $(_GREEN)$@..."

clean :
	@rm -rf $(OBJS)
	@echo "\n$(_RED)-----REMOVING OBJECT FILES-----\n"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(_RED)-----REMOVING $(NAME)-----\n"

re : fclean all
