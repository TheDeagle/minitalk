# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 02:01:40 by hben-bou          #+#    #+#              #
#    Updated: 2023/01/25 12:33:26 by hben-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

server = server
client = client

server_bonus = server_bonus
client_bonus = client_bonus

SRV_C = server.c\
		minitalk_utils.c
		
SRV_O =	server.o\
		minitalk_utils.o

CLIENT_C =	client.c\
			minitalk_utils.c

			
CLIENT_O =	client.o\
			minitalk_utils.o


SRV_BONUS_C = 	server_bonus.c\
				minitalk_utils_bonus.c

SRV_BONUS_O =	server_bonus.o\
				minitalk_utils_bonus.o


CLIENT_BONUS_C =	client_bonus.c\
					minitalk_utils_bonus.c
			
CLIENT_BONUS_O =	client_bonus.o\
					minitalk_utils_bonus.o


CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

mandatory : $(server) $(client)
all : $(server) $(client) $(server_bonus) $(client_bonus)
bonus : $(server_bonus) $(client_bonus)
	
$(server): $(SRV_O) 
	$(CC) $(CFLAGS) $(SRV_C) -o $(server)

$(client): $(CLIENT_O)
	$(CC) $(CFLAGS) $(CLIENT_C) -o $(client)

$(server_bonus): $(SRV_BONUS_O)
	$(CC) $(CFLAGS) $(SRV_BONUS_C) -o $(server_bonus)

$(client_bonus): $(CLIENT_BONUS_C)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_C) -o $(client_bonus)
	
clean:
	$(RM) $(SRV_O) $(CLIENT_O) $(SRV_BONUS_O) $(CLIENT_BONUS_O)
	
fclean:
	$(RM) $(server) $(client) $(SRV_O) $(SRV_BONUS_O) $(CLIENT_O) $(server_bonus) $(client_bonus)

re : fclean all

.PHONY : all clean fclean re
