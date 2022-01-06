NAME_SERVER		=	server
NAME_CLIENT		=	client
#NAME_LIB		=	libft.a
#NAME_LIB_SHORT	=	ft
#PATH_LIB		=	lib/libft
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FDEBUG		=	-g
SRCS_SERVER		=	${shell find srcs/server -name "*.c"}
SRCS_CLIENT		=	${shell find srcs/client -name "*.c"}
SRCS_SHARED		=	$(shell find srcs/shared -name "*.c")
OBJS_SERVER		=	${SRCS_SERVER:.c=.o}
OBJS_CLIENT		=	${SRCS_CLIENT:.c=.o}
OBJS_SHARED		=	${SRCS_SHARED:.c=.o}
INCLUDES		=	-I includes
RM				=	rm -rf

.c.o					:	
							$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all						:	${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}			:	$(OBJS_SERVER) $(OBJS_SHARED)
							$(CC) $(CC_FLAGS) $(OBJS_SERVER) $(OBJS_SHARED) -o $(NAME_SERVER)

${NAME_CLIENT}			:	$(OBJS_CLIENT) $(OBJS_SHARED)
							$(CC) $(CC_FLAGS) $(OBJS_CLIENT) $(OBJS_SHARED) -o $(NAME_CLIENT)

#${NAME_LIB}			:	
#							@$(MAKE) -C $(PATH_LIB)

debug					:	${NAME_SERVER}_debug ${NAME_CLIENT}_debug

${NAME_SERVER}_debug	:	$(OBJS_SERVER) $(OBJS_SHARED)
							$(CC) $(CC_FLAGS) $(CC_FDEBUG) $(OBJS_SERVER) $(OBJS_SHARED) -o $(NAME_SERVER)_debug

${NAME_CLIENT}_debug	:	$(OBJS_CLIENT) $(OBJS_SHARED)
							$(CC) $(CC_FLAGS) $(CC_FDEBUG) $(OBJS_CLIENT) $(OBJS_SHARED) -o $(NAME_CLIENT)_debug
clean					:
							$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SHARED)

fclean					:	clean 
							$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER)_debug $(NAME_CLIENT)_debug

re						:	fclean all

.PHONY					:	all clean fclean re