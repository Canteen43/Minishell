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

SRC_FILES		+= core/f_signal_setup.c
SRC_FILES		+= core/f_init.c
SRC_FILES		+= core/f_gc_malloc.c
SRC_FILES		+= core/f_gc_clean.c
SRC_FILES		+= core/f_free_and_exit.c

SRC_FILES		+= builtins/f_echo.c
SRC_FILES		+= builtins/f_pwd.c
SRC_FILES		+= builtins/f_env.c
SRC_FILES		+= builtins/f_cd.c
SRC_FILES		+= builtins/f_unset.c
SRC_FILES		+= builtins/f_export.c

SRC_FILES		+= env/f_env_add_back.c
SRC_FILES		+= env/f_env_create_2da.c
SRC_FILES		+= env/f_env_create_lnklst.c
SRC_FILES		+= env/f_env_remove_one.c
SRC_FILES		+= env/f_env_find_key.c
SRC_FILES		+= env/f_env_keyvaluetostr.c
SRC_FILES		+= env/f_env_last.c
SRC_FILES		+= env/f_env_lstlen.c
SRC_FILES		+= env/f_env_new.c
SRC_FILES		+= env/f_env_strtokey.c
SRC_FILES		+= env/f_env_strtovalue.c

SRC_FILES		 += token/f_get_token_end.c
SRC_FILES		 += token/f_tokenize.c
SRC_FILES		 += token/f_tok_add_back.c
SRC_FILES		 += token/f_tok_last.c
SRC_FILES		 += token/f_tok_new.c
SRC_FILES		 += token/f_print_tokens.c
SRC_FILES		 += token/f_create_tokens.c
SRC_FILES		 += token/f_tok_check_syntax.c
SRC_FILES		 += token/f_tok_remove_one.c
SRC_FILES		 += token/f_tok_remove_one_universal.c
SRC_FILES		 += token/f_unite_double_ops.c
SRC_FILES		 += token/f_add_categories.c
SRC_FILES		 += token/f_expand_variables.c
SRC_FILES		 += token/f_var_find_key.c
SRC_FILES		 += token/f_var_new_string.c
SRC_FILES		 += token/f_var_end.c
SRC_FILES		 += token/f_resolve_quotes.c
SRC_FILES		 += token/f_join_tokens.c
SRC_FILES		 += token/f_delete_white_toks.c
SRC_FILES		 += token/f_toks_to_cmds_n_args.c
SRC_FILES		 += token/f_add_arg_to_tok.c

SRC_FILES		+= utils/f_memcpy.c
SRC_FILES		+= utils/f_strchr.c
SRC_FILES		+= utils/f_strcmp.c
SRC_FILES		+= utils/f_strjoin.c
SRC_FILES		+= utils/f_strlen.c
SRC_FILES		+= utils/f_strncmp.c
SRC_FILES		+= utils/f_split.c

SRC_FILES		+= utils/get_next_line/get_next_line_utils.c
SRC_FILES		+= utils/get_next_line/get_next_line.c

SRC_FILES		+= execution/f_do_execute.c
SRC_FILES		+= execution/f_do_pipe.c
SRC_FILES		+= execution/f_execution.c
SRC_FILES		+= execution/f_exit_clean.c
SRC_FILES		+= execution/f_get_cmd_path.c
SRC_FILES		+= execution/f_heredoc.c
SRC_FILES		+= execution/f_init_pipex.c
SRC_FILES		+= execution/f_open_file.c
SRC_FILES		+= execution/f_set_redirects.c
SRC_FILES		+= execution/f_execute_builtin.c
SRC_FILES		+= execution/f_final_execute.c
SRC_FILES		+= execution/f_find_final_cmd.c

SRC_FILES		+= utils/f_strdup.c
SRC_FILES		+= utils/f_strscmp.c
SRC_FILES		+= utils/f_strncpy.c
SRC_FILES		+= utils/f_strcpy.c
SRC_FILES		+= utils/f_is_alpha.c
SRC_FILES		+= utils/f_is_dig.c


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