PROJ_NAME = project_main
SRC = project_main.c\
test/test_project_main.c

INC =unity
TEST = unity/unity.c

$(PROJ_NAME): $(SRC) $(TEST)
	gcc -I $(INC) $(SRC) $(TEST) -o $(PROJ_NAME) -lm

