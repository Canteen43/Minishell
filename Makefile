#### MAIN SETTINGS ####

# Compiler to be used
CC				:= cc

# Compiler flags
CFLAGS			:= -Wall -Werror -Wextra -pedantic -O3

# Include directories
INCLUDES		:= -Iinc/

# Target executable
TARGET			:= minishell

# Libraries to be linked (if any)
LIBS			:= -lreadline

# Source files directory
SRC_DIR			:= src/
# Source files
SRC_FILES		+= main.c
SRC_FILES		+= core/f_execute.c
SRC_FILES		+= builtins/f_echo.c
SRC_FILES		+= builtins/f_pwd.c
SRC_FILES		+= utils/f_strcmp.c
SRC_FILES		+= utils/f_strncmp.c


# Object files directory
OBJ_DIR			:= obj/
# Object files
OBJ_FILES		:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))


# Dependency files directory
DEP_DIR			:= dep/
# Dependency files
DEPENDS			:= $(patsubst %.o, $(DEP_DIR)%.d, $(OBJ_FILES))
-include $(DEPENDS)

#### SHELL COMMANDS ####
RM				:= /bin/rm -f
MKDIR			:= /bin/mkdir -p
TOUCH			:= /bin/touch

#### DEBUG SETTINGS ####
ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -O0
endif

#### TARGET COMPILATION ####
.DEFAULT_GOAL	:= all

all: $(TARGET) ## Build this project

# Compilation rule for object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(@D)
	@echo -n "[build] "
	$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

# Rule for linking the target executable
$(TARGET): $(OBJ_FILES)
	@echo -n "\n[link] "
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) $(LIBS)
	-@echo -n "🚀 $(MAGENTA)" && ls -lah $(TARGET) && echo -n "$(RESET)"

#### LOCAL LIBS COMPILATION ####

#### ADDITIONAL RULES ####

clean: ## Clean objects and dependencies
	@echo -n "[clean] "
	$(RM) $(OBJ_FILES)
	@echo -n "[clean] "
	$(RM) -r $(OBJ_DIR)
	@echo -n "[clean] "
	$(RM) $(DEPENDS)
	@echo -n "[clean] "
	$(RM) -r $(DEP_DIR)

fclean: clean ## Restore project to initial state
	@echo -n "[fclean] "
	$(RM) $(TARGET)

re: fclean all ## Rebuild project

help: ## Show help info
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

.PHONY: all re clean fclean help

#### COLORS ####
# Color codes
RESET		:= \033[0m
BOLD		:= \033[1m
UNDERLINE	:= \033[4m

# Regular colors
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
MAGENTA		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m

# Background colors
BG_BLACK	:= \033[40m
BG_RED		:= \033[41m
BG_GREEN	:= \033[42m
BG_YELLOW	:= \033[43m
BG_BLUE		:= \033[44m
BG_MAGENTA	:= \033[45m
BG_CYAN		:= \033[46m
BG_WHITE	:= \033[47m

# Credits:
# This Makefile was copied from https://github.com/tesla33io/philosophers.git
# Gratitude to the maker
# It was edited to fit the needs of our project (Gabe and Karl)