# **************************************************************************** #
#									       #
#							  :::	   ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#						      +:+ +:+	      +:+      #
#    By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	       #
#						  +#+#+#+#+#+	+#+	       #
#    Created: 2023/11/26 19:20:16 by marcosv2	       #+#    #+#	       #
#    Updated: 2023/12/16 01:00:56 by marcosv2         ###   ########.fr        #
#									       #
# **************************************************************************** #

# Comamad Miscs

NAME	= libft.a
C_COMP	= cc
C_ARRC	= ar -rc
C_FLAG	= -Wall -Werror -Wextra
C_REMO	= rm -rf

# Dirs

D_HDRS	= -I ./includes/
D_SRCS	= srcs/
D_OBJS	= objs/

# Sources & Objects

DS_ISX		= ft_isx/
N_ISX		= ft_isalnum.c			\
		  ft_isalpha.c			\
		  ft_isascii.c			\
		  ft_isdigit.c			\
		  ft_isprint.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_ISX), $(N_ISX))

DS_TOX		= ft_tox/
N_TOX		= ft_itoa.c		\
		  ft_atoi.c		\
		  ft_tolower.c		\
		  ft_toupper.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_TOX), $(N_TOX))

DS_MEM		= ft_mem/
N_MEM		= ft_calloc.c			\
		  ft_bzero.c			\
		  ft_memchr.c			\
		  ft_memcmp.c			\
		  ft_memcpy.c			\
		  ft_memdel.c			\
		  ft_memmove.c			\
		  ft_memset.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_MEM), $(N_MEM))

DS_PUT		= ft_put/
N_PUT		= ft_putchar_fd.c		\
		  ft_putendl_fd.c		\
		  ft_putnbr_fd.c		\
		  ft_putstr.c			\
		  ft_putstr_fd.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_PUT), $(N_PUT))

DS_STR		= ft_str/
N_STR		= ft_strlen.c			\
		  ft_rejoin.c			\
		  ft_split.c			\
		  ft_strchr.c			\
		  ft_strdup.c			\
		  ft_striteri.c			\
		  ft_strjoin.c			\
		  ft_strlcat.c			\
		  ft_strlcpy.c			\
		  ft_strlen.c			\
		  ft_strmapi.c			\
		  ft_strncmp.c			\
		  ft_strnstr.c			\
		  ft_strrchr.c			\
		  ft_strrep.c			\
		  ft_strtrim.c			\
		  ft_substr.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_STR), $(N_STR))

DS_LST		= ft_list/
N_LST		= ft_lstadd_back_bonus.c	\
		  ft_lstadd_front_bonus.c	\
		  ft_lstclear_bonus.c		\
		  ft_lstdelone_bonus.c		\
		  ft_lstiter_bonus.c		\
		  ft_lstlast_bonus.c		\
		  ft_lstmap_bonus.c		\
		  ft_lstnew_bonus.c		\
		  ft_lstsize_bonus.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_LST), $(N_LST))

DS_TAB		= ft_tab/
N_TAB		= ft_freetab.c		\
		  ft_tabcpy.c		\
		  ft_tablen.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_TAB), $(N_TAB))

DS_PRINTF	= ft_printf/
N_PRINTF	= ft_printf.c			\
		  ft_ftypes.c			\
		  ft_printpercent.c		\
		  ft_printchar.c		\
		  ft_printstr.c			\
		  ft_printnbr.c			\
		  ft_printunsigned.c		\
		  ft_printhex.c			\
		  ft_printpointer.c		\
		  ft_printf_utils.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_PRINTF), $(N_PRINTF))

DS_READLINE	= ft_readline/
N_READLINE	= ft_readline.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_READLINE), $(N_READLINE))

# Objects Finalization

N_OBJS	= $(N_ISX:.c=.o)	\
	  $(N_TOX:.c=.o)	\
	  $(N_MEM:.c=.o)	\
	  $(N_PUT:.c=.o)	\
	  $(N_STR:.c=.o)	\
	  $(N_LST:.c=.o)	\
	  $(N_TAB:.c=.o)	\
	  $(N_PRINTF:.c=.o)	\
	  $(N_READLINE:.c=.o)
F_OBJS	= $(addprefix $(D_OBJS), $(N_OBJS))

# Colors
P_WHITE = \033[0m
P_LBLUE = \033[0;32m
P_BROWN = \033[0;33m
P_DBLUE = \033[0;34m
P_NCYAN = \033[0;36m
P_GREEN = \033[38;5;40m

# Mandatory Rules

all		: $(NAME)

$(D_OBJS)%.o	: $(D_SRCS)*/%.c
	@printf "\t$(P_BROWN)Generating $(NAME)..: %-33.33s\r $(P_WHITE)" $@
	@$(C_COMP) $(C_FLAG) -c $< -o $@ $(D_HDRS)

$(D_OBJS)	:
	@echo "$(P_LBLUE)Starting $(NAME) compilation...$(P_WHITE)"
	@echo "\n\t$(P_DBLUE)Creating $(NAME) objects directory...$(P_WHITE)"
	@mkdir $(D_OBJS)

$(NAME)		:  $(D_OBJS) $(F_OBJS)
	@echo "\n\t$(P_NCYAN)Finishing $(NAME)..: $(P_LBLUE)$(NAME)$(P_WHITE)\n"
	@$(C_ARRC) $(NAME) $(F_OBJS)
	@echo "$(P_GREEN)Done!$(P_WHITE)"

clean		:
	@echo "$(P_DBLUE)Cleaning $(NAME) objects...$(P_WHITE)"
	@$(C_REMO) $(D_OBJS)

fclean		: clean
	@echo "$(P_DBLUE)Deleting $(NAME)...$(P_WHITE)"
	@${C_REMO} $(NAME)

re		: fclean all

# Phony

.PHONY: all clean fclean re
