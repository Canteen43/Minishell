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
LIB1DIR =	Libft/
LIB2DIR =	FLib/
LIB1 = libft.a
LIB2 = flib.a
MYLIBS +=	$(LIB_DIR)$(LIB2DIR)$(LIB2)
MYLIBS +=	$(LIB_DIR)$(LIB1DIR)$(LIB1)

# Source files
SRC_FILES += main.c
SRC_FILES += builtins/echo.c

# Object files
OBJ_FILES 		=	$(SRC_FILES:%.c=$(OBJ_DIR)%.o)

# Rules
all: $(TARGET)

$(LIB_DIR)$(LIB1DIR)$(LIB1):
	$(MAKE) -C $(LIB_DIR)$(LIB1DIR) all

$(LIB_DIR)$(LIB2DIR)$(LIB2):
	$(MAKE) -C $(LIB_DIR)$(LIB2DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_FILES) $(MYLIBS)
	$(CC) $(OBJ_FILES) -o $(TARGET) $(SYSLIBFLAGS) $(MYLIBS)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR)$(LIB1DIR) clean
	$(MAKE) -C $(LIB_DIR)$(LIB2DIR) clean

fclean: clean
	rm -f $(TARGET) $(BONUS_TARGET)
	$(MAKE) -C $(LIB_DIR)$(LIB1DIR) fclean
	$(MAKE) -C $(LIB_DIR)$(LIB2DIR) fclean

re: fclean all

.PHONY: clean fclean all re