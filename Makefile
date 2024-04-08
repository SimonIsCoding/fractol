# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 17:15:43 by simarcha          #+#    #+#              #
#    Updated: 2024/04/08 21:29:53 by simarcha         ###   ########.fr        #
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
					configure_fractal.c \
					fractal_draws.c \

SRCS				= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJ_SRCS			= $(SRCS:.c=.o)

#MINILIB
MINILIB_DIR			= mlx/
MINILIB_ARCHIVE		= $(addprefix $(MINILIB_DIR), libmlx.a)
MINILIB_FLAGS		= -framework OpenGL -framework AppKit -lm

#LIBFT 
LIBFT_DIR			= utils/ft_printf/libft/
LIBFT_ARCHIVE		= $(addprefix $(LIBFT_DIR), libft.a)

#FT_PRINTF 
FT_PRINTF_DIR		= utils/ft_printf/
FT_PRINTF_ARCHIVE	= $(addprefix $(FT_PRINTF_DIR), libftprintf.a)

#RULES AND COMMANDS
all:				$(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(MINILIB_ARCHIVE) $(NAME)

%.o:				%.c Makefile $(INCLUDE)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ_SRCS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) Makefile
					$(CC) $(CFLAGS) $(OBJ_SRCS) -L$(LIBFT_DIR) -L$(FT_PRINTF_DIR) -lft -lftprintf $(MINILIB_FLAGS) $(MINILIB_ARCHIVE) -o $(NAME)

$(LIBFT_ARCHIVE):
					@$(MAKE) -s -C $(LIBFT_DIR)
					@echo "Compiled $(LIBFT_ARCHIVE)."

$(FT_PRINTF_ARCHIVE):
					@$(MAKE) -s -C $(FT_PRINTF_DIR)
					@echo "Compiled $(FT_PRINTF_ARCHIVE)."

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
					@echo "\033[1mCleaning the ft_printf object files\033[0m"
					@$(MAKE) clean -C $(FT_PRINTF_DIR)
					@echo ""
					@echo "\033[1mCleaning the mlx (aka minilibX) object and archive files\033[0m"
					@$(MAKE) clean -C $(MINILIB_DIR)

fclean:				clean
				    @echo "\033[1;31m\033[1mDeleting the executable and archive files\033[0m" 
					$(RM) $(NAME)
					@echo ""
					@echo "\033[1;31m\033[1mCleaning the libft object and archive files\033[0m"
					$(MAKE) fclean -C $(LIBFT_DIR)
					@echo ""
					@echo "\033[1;31m\033[1mCleaning the ft_printf object and archive files\033[0m"
					$(MAKE) fclean -C $(FT_PRINTF_DIR)

re:					fclean all

.PHONY:				all clean fclean re
