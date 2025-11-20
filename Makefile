# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syl <syl@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 08:32:46 by cmegret           #+#    #+#              #
#    Updated: 2025/10/09 16:15:06 by syl              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER1 = "redo header"                                              
                                              
# Redirection des erreurs
REDIRECT = > /dev/null 2>&1

# Codes de couleur
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# Nom de l'exécutable
NAME = miniRT
NAME2 = miniRT_bonus
# Compilateur
CC = cc -O3

# Flags de compilation -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra #-Werror #-Iincludes
LIBFLAGS = -Llib/libft -lft

# Fichiers sources
SRC_DIR = ./src
#SRCS = ${shell find ${SRC_DIR} -type f -name '*.c'}\

DEBUG = $(SRC_DIR)/debug/
PARSING = $(SRC_DIR)/parsing_me/
SAVING = $(SRC_DIR)/saving_data/
UTILS = $(SRC_DIR)/utils/
INIT = $(SRC_DIR)/new_data_management/
BONUS = $(SRC_DIR)/bonus/
RAY_CALCUL = $(SRC_DIR)/rays_calculs/
SOURCES =	./src/matrix/00_matrix_check.c \
	./src/matrix/00_matrix_creation.c \
	./src/matrix/00_matrix_multiplication.c \
	./src/matrix/00_matrix_operations.c \
	./src/matrix/00_matrix_rotation_rodrigues.c \
	./src/matrix/00_matrix_transl_scale.c \
	./src/matrix/00_matrix_transposing.c \
	./src/matrix/00_matrix_utils.c \
	./src/matrix/matrix_inverse.c \
	./src/matrix/matrix_minor_det.c \
	./src/matrix/matrix_submatrix.c \
	./src/rays_calculs/00_raytracing_main.c \
	./src/rays_calculs/01_camera_construction.c \
	./src/rays_calculs/02_viewport_construction.c \
	./src/rays_calculs/03_m_transformations.c \
	./src/rays_calculs/04_intersect_main.c \
	./src/rays_calculs/05_intersect_sphere_plan.c \
	./src/rays_calculs/06_intersect_cylinder.c \
	./src/rays_calculs/07_closest_obj.c \
	./src/rays_calculs/08_prepare_comps.c \
	./src/rays_calculs/09_light_shadow_main.c \
	./src/rays_calculs/10_shadows.c \
	./src/rays_calculs/11_light.c \
	./src/rays_calculs/shadows_cylinder.c \
	./src/rays_calculs/shadows_plan.c \
	./src/rays_calculs/shadows_sphere.c \
	./src/saving_data/save_camera.c \
	./src/saving_data/save_cylinder.c \
	./src/saving_data/save_light.c \
	./src/saving_data/save_plane.c \
	./src/saving_data/save_scene_file.c \
	./src/saving_data/save_sphere.c \
	./src/vect_point_color/add_substr.c \
	./src/vect_point_color/check_type_coord.c \
	./src/vect_point_color/colors_operation.c \
	./src/vect_point_color/copy_coord.c \
	./src/vect_point_color/math.c \
	./src/vect_point_color/print_vector_point.c \
	./src/vect_point_color/set_colors.c \
	./src/vect_point_color/vector_operations.c \
	./src/vect_point_color/vector_operations_length.c \
	./src/vect_point_color/color_operation2.c \
	./src/vect_point_color/s_create_point_vector.c \
	./src/window/event_hooks.c \
	./src/window/event_hooks_function.c \
	./src/window/image_to_window.c \
	./src/window/pixel_put.c \
	./src/new_data_management/init_memory_main.c \
	./src/new_data_management/init_pix.c \
	./src/new_data_management/free_main.c \
	./src/new_data_management/free_pix.c \
	./src/new_data_management/init_scene.c \
	./src/new_data_management/free_scene.c \
	./src/new_data_management/init_memory_shuttle.c \
	./src/new_data_management/free_memory_shuttle.c \
	./src/new_data_management/base_data.c \
	./src/new_data_management/init_cam.c \
	./src/new_data_management/init_lux.c \
	./src/new_data_management/create_image.c \
	./src/new_data_management/free_cam.c \
	./src/new_data_management/free_obj.c \
	./src/new_data_management/free_obj2.c \
	./src/new_data_management/init_each_obj.c \
	./src/new_data_management/free_lux.c \
	./src/bonus/00_raytracing_main_bonus.c \
	./src/bonus/01_reflection.c \
	./src/bonus/20_mouse_hooks.c \
	./src/bonus/transf_obj.c \
	./src/bonus/21_render_mode.c \
	./src/bonus/22_select_transformation.c \
	./src/bonus/23_select_obj_dim.c \
	./src/bonus/apply_modifications.c \
	./src/bonus/matrix_rotation.c \
	./src/bonus/print_action.c \
	./src/bonus/print_on_screen.c \
	./src/bonus/30_clean_mem_shuttle.c \
	./src/bonus/00_init_bonus.c\
	./src/bonus/00_time.c\
	./src/bonus/01_transparence.c\
	./src/bonus/01_refraction.c\
	./src/bonus/free_bonus.c \
	./src/bonus/01_lighting_bonus.c\
	./src/bonus/01_shadow_intersect.c\
	./src/bonus/export_jpg.c\
	./src/bonus/04_save_rt_main.c\
	$(INIT)init_object.c\
	$(INIT)init_object2.c\
	$(PARSING)map_check.c $(PARSING)map_check2.c\
	$(PARSING)map_struct.c $(PARSING)map_struct2.c\
	$(PARSING)verification.c $(PARSING)check_parameter.c\
	$(SAVING)save_triangle.c\
	$(SAVING)save_parameter.c\
	$(DEBUG)error.c\
	$(UTILS)utils.c $(UTILS)utils2.c\
	$(RAY_CALCUL)07_intersect_cone.c\
	$(RAY_CALCUL)08_intersect_triangle.c\
	$(RAY_CALCUL)pattern.c\
	$(RAY_CALCUL)pattern_form.c\
	$(RAY_CALCUL)pattern_perlin.c\
	$(RAY_CALCUL)texture.c\
	$(BONUS)coord_modified.c\
	$(BONUS)04_save_suite_rt.c\
	$(BONUS)04_write_file_rt.c\

SRCS = $(SOURCES)\
		./src/main.c 

SRCS_BONUS = $(SOURCES)\
		$(BONUS)main_bonus.c 

# Détection de l'OS pour choisir la bonne version de la MLX
#UNAME_S := $(shell uname -s)
#ifeq ($(UNAME_S),Darwin)
#	MLX_DIR := lib/minilibx_opengl
#	MLX_INC := -I$(MLX_DIR)
#	MLX_LNK := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
#else
	MLX_DIR := lib/minilibx-linux
	MLX_INC := -I$(MLX_DIR)
	MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
#endif

# Bibliothèques
LIBFT = lib/libft/libft.a

# Fichiers objets
OBJ_DIR = objs

OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

OBJ_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)

# all: start norm $(MLX_DIR)/libmlx.a $(NAME)
all: start norm $(MLX_DIR)/libmlx.a $(NAME)

bonus:start norm $(MLX_DIR)/libmlx.a $(NAME2)

$(NAME2): $(LIBFT) $(OBJ_BONUS)
	@echo "$(BLUE)Linking: $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ_BONUS) $(LIBFLAGS) $(MLX_LNK)
	@echo "$(GREEN)\nCompilation successful!\n$(RESET)"
# Règle pour compiler MinilibX
$(MLX_DIR)/libmlx.a:
	@echo "$(BLUE)Compiling MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR) $(REDIRECT)

# Règle pour compiler la libft
$(LIBFT):
	@echo "$(BLUE)Compiling: lib/libft$(RESET)"
	@$(MAKE) -C ./lib/libft -f Makefile $(REDIRECT)

# Règle pour l'exécutable final
$(NAME): $(LIBFT) $(OBJ)
	@echo "$(BLUE)Linking: $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFLAGS) $(MLX_LNK)
	@echo "$(GREEN)\nCompilation successful!\n$(RESET)"

# Règle pour les fichiers objets
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Règle pour compiler les tests
$(TEST_NAME): $(TEST_OBJS) $(LIBFT) $(MLX_DIR)/libmlx.a
	@echo "$(BLUE)Linking: $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJS) $(LIBFLAGS) $(MLX_LNK)
	@echo "$(GREEN)\nCompilation des tests réussie!\n$(RESET)"

# Règle pour la norminette
#norm:
#	@echo "$(YELLOW)Exécution de norminette sur les fichiers spécifiés dans SRC...$(RESET)"
#	@norminette $(SRCS) > norminette_output.txt || (echo "")
#	@error=0; \
#	while IFS= read -r line; do \
#		if ! echo "$$line" | grep -q 'OK!$$'; then \
#			echo "$(RED)Erreur dans le fichier : $$line$(RESET)"; \
#			error=1; \
#		fi; \
#	done < norminette_output.txt || (echo "$(MAGENTA)Erreur lors de la vérification du résultat de norminette$(RESET)"); \
#	if [ $$error -eq 0 ]; then \
#		echo "$(GREEN)Tous les fichiers spécifiés dans SRC sont conformes à la norme.$(RESET)"; \
#	fi
#	@rm norminette_output.txt
#	@echo " "

debug: CFLAGS += -g
debug: re

# Règle pour exécuter les tests
test: $(TEST_NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@./$(TEST_NAME)

# Règle pour nettoyer les fichiers objets
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(TEST_OBJS)
	@echo "$(RED)Cleaning MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR) clean $(REDIRECT)
	@echo "$(RED)Cleaning libft...$(RESET)"
	@$(MAKE) -C lib/libft/ clean $(REDIRECT)

# Règle pour nettoyer tout
fclean: clean
	@echo "$(RED)Cleaning executable(s)...$(RESET)"
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -f $(TEST_NAME)
	@$(MAKE) -C lib/libft/ fclean $(REDIRECT)
	@sleep 1
	clear

# Règle pour refaire tout
re: fclean all

# Règle pour rendre le makefile "phony"
.PHONY: all clean fclean re norm start debug test