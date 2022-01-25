NAME_SERVER		=	server
NAME_CLIENT		=	client
NAME_SERVER_D	=	server_debug
NAME_CLIENT_D	=	client_debug
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FLAGS_D		=	-g
SRCS_SERVER		=	${shell find srcs/server -name "*.c"}
SRCS_CLIENT		=	${shell find srcs/client -name "*.c"}
SRCS_SHARED		=	$(shell find srcs/shared -name "*.c")
OBJS_SERVER		=	${SRCS_SERVER:%.c=%.o}
OBJS_CLIENT		=	${SRCS_CLIENT:%.c=%.o}
OBJS_SHARED		=	${SRCS_SHARED:%.c=%.o}
OBJS_SERVER_D	=	${SRCS_SERVER:%.c=%_debug.o}
OBJS_CLIENT_D	=	${SRCS_CLIENT:%.c=%_debug.o}
OBJS_SHARED_D	=	${SRCS_SHARED:%.c=%_debug.o}
INCLUDES		=	-I includes
RM				=	rm -rf

%.o					:	%.c
						$(CC) $(CC_FLAGS) ${INCLUDES} -c $< -o $@

%_debug.o			:	%.c
						$(CC) $(CC_FLAGS) ${INCLUDES} -c $< -o $@

all					:	${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}		:	$(OBJS_SERVER) $(OBJS_SHARED)
						$(CC) $^ -o $(NAME_SERVER)

${NAME_CLIENT}		:	$(OBJS_CLIENT) $(OBJS_SHARED)
						$(CC) $^ -o $(NAME_CLIENT)

debug				:	${NAME_SERVER_D} ${NAME_CLIENT_D}

${NAME_SERVER_D}	:	$(OBJS_SERVER) $(OBJS_SHARED)
						$(CC) $^ -o ${NAME_SERVER_D}

${NAME_CLIENT_D}	:	$(OBJS_CLIENT) $(OBJS_SHARED)
						$(CC) $^ -o ${NAME_CLIENT_D}

clean				:
						$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SHARED) $(OBJS_SERVER_D) $(OBJS_CLIENT_D) $(OBJS_SHARED_D)

fclean				:	clean 
						$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_D) $(NAME_CLIENT_D)

re					:	fclean all

.PHONY				:	all debug clean fclean re