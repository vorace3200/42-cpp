NAME		= zombieHorde

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Zombie.cpp NewZombie.cpp RandomChump.cpp ZombieHorde.cpp
OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME) a.out

re:			fclean all

.PHONY:		all clean fclean re 