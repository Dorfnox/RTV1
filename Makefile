# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2017/11/21 21:31:15 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FILES = main \
		initialize \
		file_parsing \
		objects_parsing \
		lights_parsing \
		settings_parsing \
		info_panel \
		images \
		free \
		hooks \
		hook_arrays \
		set_keyhooks \
		hooks_exit \
		hooks_expose \
		hooks_mousemove \
		hooks_mouse_press \
		hooks_raytrace_func \
		hooks_lighting_model \
		hooks_rotate_object_x \
		hooks_rotate_object_y \
		hooks_rotate_object_z \
		hooks_translate_object_x \
		hooks_translate_object_y \
		hooks_translate_object_z \
		hooks_rotate_camera_x \
		hooks_rotate_camera_y \
		hooks_rotate_camera_z \
		hooks_translate_camera_x \
		hooks_translate_camera_y \
		hooks_translate_camera_z \
		hooks_speed \
		hook_loop \
		vector_math \
		vector_math2 \
		vector_math3 \
		rotate \
		rotate_camera \
		sphere_stuff \
		plane_stuff \
		cylinder_stuff \
		cone_stuff \
		raytracing \
		raytracing_light \
		shading

C_LOC = src/
C_NAM = $(addsuffix .c, $(FILES))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FILES))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

LIB_LOC = libft/
LIB_NAM = libft.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

H_LOCS = -I inc -I libft/inc -I minilibx
HEADERS = inc/$(addsuffix .h, $(NAME)) inc/rtv1_macros.h minilibx/mlx.h

C_FLAGS = -Wall -Wextra -Werror

MLBX = minilibx/libmlx.a

MLBX_FLAGS = -L minilibx -lmlx -framework OpenGL -framework Appkit -g

TEST_MAIN = main_for_testing.c

RED = [31m
GREEN = [32m
BLUE = [34m
YELLOW = [33m
MAGENTA = [35m
GREY = [37m
GREEN_LIGHT = [92m
YELLOW_LIGHT = [93m
YELLOW_BOLD = [1;33m
YELLOW_LIGHT_BOLD = [1;93m
MAGENTA_LIGHT = [95m
BLINK = [5m
GREEN_LIGHT_BLINK = [5;92m
END_COLOUR = \033[0m

all: $(NAME)

$(NAME): $(O_SRC) $(LIB_SRC) $(MLBX)
	@echo "$(YELLOW_BOLD)Compiling executable... $@$(END_COLOUR)"
	@gcc $(C_FLAGS) $(MLBX_FLAGS) -lpthread $^ -o $@
	@echo
	@echo "$(GREEN_LIGHT)     xxXXXXXXXXxx     $(END_COLOUR)"
	@echo "$(GREEN_LIGHT)  xXX------------XXx  $(END_COLOUR)"
	@echo "$(GREEN_LIGHT)xXX---$(END_COLOUR) $(GREEN_LIGHT_BLINK)COMPLETE$(END_COLOUR) $(GREEN_LIGHT)---XXx$(END_COLOUR)"
	@echo "$(GREEN_LIGHT)xXX----$(END_COLOUR) $(GREEN_LIGHT_BLINK)YIPPEE$(END_COLOUR) $(GREEN_LIGHT)----XXx$(END_COLOUR)"
	@echo "$(GREEN_LIGHT)  xXX------------XXx  $(END_COLOUR)"
	@echo "$(GREEN_LIGHT)     XXxxxxxxxxXX     $(END_COLOUR)"
	@echo

$(O_LOC)%.o: $(C_LOC)%.c $(HEADERS) 
	@echo "$(GREY)Re-compiling src file... $(END_COLOUR)$(YELLOW)$<$(END_COLOUR)"
	@gcc $(C_FLAGS) $(H_LOCS) -c $< -o $@

$(LIB_SRC): force
	@echo "$(YELLOW)\n----------- Checking $@ Library -----------$(END_COLOUR)"
	@printf "$(YELLOW_LIGHT)$@ re-compile status: $(END_COLOUR)"
	@make -C $(LIB_LOC)
	@echo "$(YELLOW)----------- $@ Check Complete -----------\n$(END_COLOUR)"

$(MLBX): force
	@echo "$(YELLOW)\n----------- Checking $@ Library -----------$(END_COLOUR)"
	@printf "$(YELLOW_LIGHT)$@ re-compile status: $(END_COLOUR)"
	@make -C minilibx
	@echo "$(YELLOW)----------- $@ Check Complete -----------\n$(END_COLOUR)"

force:
	@true

clean:
	@/bin/rm -rf $(O_SRC)
	@make clean -C $(LIB_LOC)
	@make clean -C minilibx
	@echo "$(GREEN)cleaned!$(END_COLOUR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_LOC)
	@echo "$(GREEN)fcleaned!$(END_COLOUR)"

re: fclean all

test: $(NAME)
	@./$(NAME) shapes/a_little_bit_of_everything.shape

.PHONY: all test force clean fclean re
