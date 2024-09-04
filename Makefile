# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:18:46 by yokamura          #+#    #+#              #
#    Updated: 2023/06/22 23:58:02 by yokamura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
OBJ_DIR	:= obj
SRC_DIR	:= src

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
LFLAGS	:= -pthread
HEADERS	:= includes

SRCS_NAME	:=	main.c \
				utils/is_correct_argv.c utils/philo_utils.c \
				utils/ft_free.c utils/destroy_all_mutex.c \
				utils/get_now_time.c utils/is_finished.c \
				init/init_main.c init/init_mutex.c init/init_philo.c \
				init/set_hands_mutex.c \
				philo_processor/ft_philo_thread.c philo_processor/ph_main.c \
				monitor_processor/monitor_main.c \
				print/print_message.c 
				
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRCS_NAME))
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -I ./$(HEADERS) $(LFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -I ./$(HEADERS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
