# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 16:40:18 by ndesprez          #+#    #+#              #
#    Updated: 2023/05/24 21:26:01 by ndesprez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c 
		$(CC) $(CFLAGS) client.c utils/error.c utils/ft_printf.c -o client
$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c utils/error.c utils/ft_printf.c -o server
clean:
fclean:
	rm -rf $(CLIENT) $(SERVER)

re: fclean all
