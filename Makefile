# The compiler
CC =	cc

# Compiler flags
CFLAGS :=	-Wall -Wextra -Werror

# Debugging (DEBUG=1)
ifeq ($(DEBUG), 1)
	CFLAGS		+=	-g3 -O0
endif

# Targets
TARGET =	minishell


# Directories
SRC_DIR =	src/
INC_DIR =	inc/
OBJ_DIR =	obj/
LIB_DIR =	lib/



# My libraries


# Source files
SRC_FILES += main.c
SRC_FILES += builtins/echo.c

# Object files
OBJ_FILES 		=	$(SRC_FILES:%.c=$(OBJ_DIR)%.o)

# Rules
all: $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_FILES) 
	$(CC) $(OBJ_FILES) -o $(TARGET)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: clean fclean all re