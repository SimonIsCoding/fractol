# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 17:15:43 by simarcha          #+#    #+#              #
#    Updated: 2024/04/01 13:07:26 by simarcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
NAME				= fractol
RM					= rm -rf

#FILES AND PATHS
#HEADER
INCLUDE_DIR			= inc/
INCLUDE_FILES		= fractol.h
INCLUDE				= $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))

#UTILS - The annexes functions that I used for this project
UTILS_DIR			= utils/
UTILS_FILES			= 
UTILS				= $(addprefix $(UTILS_DIR), $(UTILS_FILES))
OBJ_UTILS			= $(UTILS:.c=.o)

#SRCS - Where the main files for this project are located
SRCS_DIR			= srcs/
SRCS_FILES			= main.c \
             		characters_into_double.c \
					error_management.c \
					window_management.c \
					mandelbrot_functions.c
SRCS				= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJ_SRCS			= $(SRCS:.c=.o)

#MINILIB
MINILIB_DIR			= mlx/
MINILIB_ARCHIVE		= $(addprefix $(MINILIB_DIR), libmlx.a)
MINILIB_FLAGS		= -framework OpenGL -framework AppKit -lm

#LIBFT 
LIBFT_DIR			= utils/libft/
LIBFT_ARCHIVE		= $(addprefix $(LIBFT_DIR), libft.a)

#RULES AND COMMANDS
all:				$(LIBFT_ARCHIVE) $(NAME)
#all:				$(LIBFT_ARCHIVE) $(MINILIB_ARCHIVE) $(NAME)

%.o:				%.c Makefile $(INCLUDE)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ_UTILS) $(OBJ_SRCS) $(LIBFT_ARCHIVE) Makefile
					$(CC) $(CFLAGS) $(OBJ_UTILS) $(OBJ_SRCS) -L$(LIBFT_DIR) -lft $(MINILIB_FLAGS) $(MINILIB_ARCHIVE) -o $(NAME)


$(LIBFT_ARCHIVE):
					@$(MAKE) -s -C $(LIBFT_DIR)
					@echo "Compiled $(LIBFT_ARCHIVE)."

$(MINILIB_ARCHIVE):
					$(MAKE) -s -C $(MINILIB_DIR)
					@echo "Compiled $(MINILIB_ARCHIVE)."

clean:
				    @echo "\033[1;31m\033[1mDeleting every object files\033[0m" 
					@echo "\033[1mCleaning the object srcs files\033[0m"
					$(RM) $(OBJ_UTILS) $(OBJ_SRCS)
					@echo ""
					@echo "\033[1mCleaning the object libft files\033[0m"
					@$(MAKE) clean -C $(LIBFT_DIR)
					@echo ""
					@echo "\033[1mCleaning the mlx (aka minilibX) object and archive files\033[0m"
#					@$(MAKE) clean -C $(MINILIB_DIR)

fclean:				clean
				    @echo "\033[1;31m\033[1mDeleting the executable and archive files\033[0m" 
					$(RM) $(NAME)
					@echo ""
					@echo "\033[1;31m\033[1mCleaning the object and archive libft files\033[0m"
					$(MAKE) fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY:				all clean fclean re
