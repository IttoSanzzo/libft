# **************************************************************************** #
#									       #
#							  :::	   ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#						      +:+ +:+	      +:+      #
#    By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	       #
#						  +#+#+#+#+#+	+#+	       #
#    Created: 2023/11/26 19:20:16 by marcosv2	       #+#    #+#	       #
#    Updated: 2023/12/29 16:43:20 by marcosv2         ###   ########.fr        #
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
		  ft_isprint.c			\
		  ft_open_quotes.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_ISX), $(N_ISX))

DS_TOX		= ft_tox/
N_TOX		= ft_itoa.c			\
		  ft_ttos.c			\
		  ft_atoi.c			\
		  ft_tolower.c			\
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
		  ft_memset.c			\
		  ft_free.c			\
		  ft_gptr.c			\
		  ft_gint.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_MEM), $(N_MEM))

DS_PUT		= ft_put/
N_PUT		= ft_putchar_fd.c		\
		  ft_putendl_fd.c		\
		  ft_putnbr_fd.c		\
		  ft_putstr_fd.c		\
		  ft_putchar.c			\
		  ft_putstr.c			\
		  ft_putnbr.c			\
		  ft_puttab.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_PUT), $(N_PUT))

DS_STR		= ft_str/
N_STR		= ft_strlen.c			\
		  ft_freejoin.c			\
		  ft_prejoin.c			\
		  ft_sujoin.c			\
		  ft_split.c			\
		  ft_splitq.c			\
		  ft_strchr.c			\
		  ft_strdup.c			\
		  ft_striteri.c			\
		  ft_strjoin.c			\
		  ft_strlcat.c			\
		  ft_strlcpy.c			\
		  ft_strcpy.c			\
		  ft_strlen.c			\
		  ft_strmapi.c			\
		  ft_strncmp.c			\
		  ft_strnstr.c			\
		  ft_strrchr.c			\
		  ft_strrep.c			\
		  ft_strdrep.c			\
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

DS_STRMAN	= ft_strman/
N_STRMAN	= ft_stradd_bgn.c		\
		  ft_stradd_end.c		\
		  ft_stradd_n.c			\
		  ft_strrem_bgn.c		\
		  ft_strrem_end.c		\
		  ft_strrem_n.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_STRMAN), $(N_STRMAN))

DS_TAB		= ft_tab/
N_TAB		= ft_freetab.c			\
		  ft_tabcpy.c			\
		  ft_tablen.c			\
		  ft_tabadd_bgn.c		\
		  ft_tabadd_end.c		\
		  ft_tabadd_n.c			\
		  ft_tabrem_bgn.c		\
		  ft_tabrem_end.c		\
		  ft_tabrem_n.c			\
		  ft_tabsmove.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_TAB), $(N_TAB))

DS_ANSI		= ft_ansi/
N_ANSI		= ft_ansi_fclear.c		\
		  ft_ansi_clear.c		\
		  ft_ansi_resetl.c		\
		  ft_ansi_drl.c			\
		  ft_ansi_drd.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_ANSI), $(N_ANSI))

DS_UTILS	= ft_utils/
N_UTILS		= ft_getarg_p.c			\
		  ft_getrstr_p.c		\
		  ft_getstr_p.c			\
		  ft_getchar.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_UTILS), $(N_UTILS))

DS_PRINTF	= ft_printf/
N_PRINTF	= ft_printf.c			\
		  ft_printc.c			\
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

DS_GNL		= ft_gnl/
N_GNL		= get_next_line.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_GNL), $(N_GNL))

DS_READLINE	= ft_readline/
N_READLINE	= ft_sreadline.c		\
		  ft_readline.c			\
		  ft_rlconfig.c			\
		  ft_rlhistory.c		\
		  rl_checks.c			\
		  rl_moviments.c		\
		  rl_go.c			\
		  rl_specials.c			\
		  rl_utils.c
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_READLINE), $(N_READLINE))

# Objects Finalization

N_OBJS	= $(N_ISX:.c=.o)	\
	  $(N_TOX:.c=.o)	\
	  $(N_MEM:.c=.o)	\
	  $(N_PUT:.c=.o)	\
	  $(N_STR:.c=.o)	\
	  $(N_STRMAN:.c=.o)	\
	  $(N_LST:.c=.o)	\
	  $(N_TAB:.c=.o)	\
	  $(N_ANSI:.c=.o)	\
	  $(N_UTILS:.c=.o)	\
	  $(N_PRINTF:.c=.o)	\
	  $(N_GNL:.c=.o)	\
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
	@${C_REMO} COMPILADO.out

re		: fclean all

# Personals

normiet		:
	@norminette -R CheckForbiddenSourceHeader | grep Error! | wc -l

tc		: all
	@$(C_COMP) $(C_FLAG) -o COMPILADO.out mainlibft.c libft.a

ohayou		: tc
	@./COMPILADO.out ohayou

valt		: tc
	@valgrind ./COMPILADO.out default

# Phony

.PHONY: all clean fclean re tc ohayou valt
