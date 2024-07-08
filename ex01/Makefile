# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 02:15:19 by rjeong            #+#    #+#              #
#    Updated: 2024/07/09 02:15:20 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex01

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP
RM := rm -f

all : $(NAME)

SRCS := \
	Bureaucrat.cpp \
	Form.cpp \
	main.cpp

OBJS := \
	$(SRCS:.cpp=.o)

DEPS := \
	$(SRCS:.cpp=.d)

-include $(DEPS)

clean :
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	make all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re

