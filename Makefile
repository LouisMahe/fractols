NAME := fractol

LIBS := ft mlx mlx_Linux Xext X11 m
LIBS_TARGET := lib/libft.a \
			minilibx-linux/libmlx.a \
			minilibx-linux/libmlx_Linux.a

INCS := include \
	lib \
	minilibx-Linux

SRCS_DIR := src
SRCS := main_mandel.c \
		ft_mandel_algo.c \
		ft_print_pixel.c \
		ft_rectangle_mandel.c \
		ft_rectange_mandel2.c \
		ft_hooks.c \
		ft_hooks2.c \
		ft_smooth_algo.c \
		ft_smooth_algo2.c \
		ft_smooth_rectangle.c \
		ft_cubic_interpol.c \
		ft_cubic_interpol2.c \
		ft_cubic_interpol3.c \
		ft_cubic_interpol4.c \
		ft_cubic_interpol5.c\
		ft_julia_algo.c \
		ft_colors.c \
		ft_smooth_colors.c \
		ft_parse.c \
		ft_ship.c \
		ft_ship_algo.c


SRCS_BONUS :=


INC := include/fractols.h
SRCS := $(SRCS:%=$(SRCS_DIR)/%)
SRCS_BONUS := $(SRCS_BONUS:%=$(SRCS_DIR)/%)

BUILD_DIR := obj
OBJS := $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS := $(SRCS_BONUS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)

CC := cc -g3 -Wall -Wextra -Werror
CHFLAGS := $(addprefix -I,$(INCS))
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))

RM := rm -rf
DIR_DUP = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS)  $(LDLIBS) -o $(NAME)

# bonus: $(BONUS)

# $(BONUS): $(OBJS_BONUS) $(LIBS_TARGET)
#	$(CC) $(LDFLAGS) $(OBJS_BONUS)  $(LDLIBS) -o $(BONUS)


$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)
	$(DIR_DUP)
	$(CC) $(CHFLAGS) -c -o $@ $<


clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(RM) $(BUILD_DIR)

fclean: clean
	$(MAKE) -C lib fclean
	$(MAKE) -C minilibx-linux clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

