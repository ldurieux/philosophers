NAME		= philosophers

SRCS		= \
			  main.c \
			  srcs/philo_start.c \
			  srcs/ft_strcmp.c \
			  srcs/philo_print_msg.c \
			  srcs/ft_strtoi.c \
			  srcs/philo_while_alive.c \
			  srcs/philo_wait_threads.c \
			  srcs/philo_init.c \
			  srcs/philo_thread.c \
			  srcs/get_time.c \
			  srcs/ft_usleep.c \
			  srcs/philo_data_init.c \
			  srcs/philo_data_destroy.c \

CCDEFS		= \

ASMSRCS		= \

LIB_NAMES	= \

LIB_DYN		= \
			  -lpthread

HEADERS		= \
			  includes \

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

CCDEFSFLGS	= $(foreach def,$(CCDEFS),-D $(def))

BUILDDIR	= build
OBJS		= $(SRCS:%.c=$(BUILDDIR)/%.o) $(ASMSRCS:%.s=$(BUILDDIR)/%.o)
DEPS		= $(SRCS:%.c=$(BUILDDIR)/%.d)
CC			= cc
CCWFLGS		= -Wall -Wextra -Werror
CCDBGFLGS	= -g3
CCO1FLGS	= -O1 -march=native
CCO2FLGS	= -O2 -march=native
CCO3FLGS	= -O3 -march=native
DEPSFLAGS	= -MMD -MP
RM			= rm -Rf
MAKE		= make -C
MKDIR		= mkdir
AR			= ar
ARFLAGS		= rcs
NASM		= nasm
NASMFLAGS	= -felf64

all : libs $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CCWFLGS) -o $(NAME) $(OBJS) $(LIB_LD) $(LIBS) $(LIB_DYN)

bonus : $(NAME)

libs :
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib); \
		)

clean :
		-$(RM) $(BUILDDIR)

fclean : clean
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) fclean; \
		)
		-$(RM) $(NAME)

re : fclean all

$(BUILDDIR)/%.o : %.s Makefile
		@mkdir -p $(@D)
		$(NASM) $(NASMFLAGS) -o $(BUILDDIR)/$@ $<

-include $(DEPS)

$(BUILDDIR)/%.o : %.c Makefile $(LIB_PATHS)
		@mkdir -p $(@D)
		$(CC) $(CCWFLGS) $(DEPSFLAGS) $(CCDBGFLGS) $(CCDEFSFLGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@

.PHONY: all clean fclean re bonus libs
