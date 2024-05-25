##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##
SRC = src/events.c\
		src/main.c\
		src/radar.c\
		src/background/create_background.c\
		src/background/create_timer.c\
		src/utils/file_loader.c\
		src/utils/init_list.c\
		src/utils/init_shape.c\
		src/utils/free_array.c\
		src/utils/bounds.c\
		src/utils/check_texture.c\
		src/entities/entity_creator.c\
		src/entities/entity_displayer.c\
		src/entities/entity_destroyer.c\
		src/entities/entity_move.c\
		src/entities/check_end.c\
		src/collisions/check_collisions.c\
		src/collisions/check_tower.c\

SRC_UNIT = src/load_map.c\


FLAGS = -L./lib/my -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-system -lm

OBJ = $(SRC:.c=.o)

NAME = my_radar

CRI = --coverage -lcriterion

TEST_FILE = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
		make -C lib/my
		make all -C lib/my
		make clean -C lib/my
		gcc $(SRC) -o $(NAME) -g $(FLAGS)
		make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run: clean
		gcc -o $(TEST_FILE) $(SRC_UNIT) tests/test_organized.c $(FLAGS) $(CRI)
		./$(TEST_FILE) --verbose --full-stats

gcovr_branches:
		gcovr --exclude tests/ --branches
