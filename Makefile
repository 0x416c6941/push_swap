# Compiler options.
CC = cc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -Wsign-conversion -pedantic -Werror	\
		 -g -fsanitize=address

# Headers.
INC_DIR = include

# Source files.
SRC_DIR = src
SRC_FILES = main.c args/parse_args.c args/check_args.c					\
			stack/stack_pop.c stack/stack_push.c stack/stack_swap.c		\
			stack/stack_rotate.c stack/stack_reverse_rotate.c			\
			ops/op_sa.c ops/op_sb.c ops/op_ss.c ops/op_pa.c ops/op_pb.c	\
			ops/op_ra.c ops/op_rb.c ops/op_rr.c							\
			ops/op_rra.c ops/op_rrb.c ops/op_rrr.c						\
			solve/algorithm/push_up_to_two.c							\
			solve/algorithm/find_closest_smaller.c						\
			solve/algorithm/find_max.c									\
			solve/algorithm/find_closest_bigger.c						\
			solve/algorithm/find_min.c									\
			solve/algorithm/calculate_node_position_in_stack.c			\
			solve/algorithm/count_operations_to_move_on_top.c			\
			solve/algorithm/cost_analysis.c								\
			solve/algorithm/find_best_node_to_b.c						\
			solve/algorithm/move_from_a_to_b.c							\
			solve/algorithm/sort_three.c								\
			solve/algorithm/find_best_node_to_a.c						\
			solve/algorithm/move_from_b_to_a.c							\
			solve/algorithm/final_sort_a.c								\
			solve/init_stacks.c solve/destroy_stacks.c					\
			solve/is_sorted.c solve/push_swap.c
SRC_FILES := $(addprefix $(SRC_DIR)/,$(SRC_FILES))

# Object files.
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Name of the resulting binary file.
NAME = push_swap

# For other Makefiles.
EXTERNAL_DIR = external
MAKE = make

# Libft.
LIBFT_DIR = $(EXTERNAL_DIR)/Libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

# Targets.
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)			# Create $(OBJ_DIR) if it doesn't exist.
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT_NAME)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
