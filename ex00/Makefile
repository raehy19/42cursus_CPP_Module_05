# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 15:12:45 by rjeong            #+#    #+#              #
#    Updated: 2024/04/28 15:12:46 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := ex00

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP
RM := rm -f

all : $(NAME)

SRCS := \
	Bureaucrat.cpp \
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

