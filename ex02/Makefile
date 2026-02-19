NAME=Identify
OBJS=src/main.o src/Base.o
INCLUDE=src/Base.hpp
CXX= c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m
RED = \033[31m

all: $(NAME) 
	@echo Execute o Programa: ./Identify

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 
	@echo -e "$(GREEN)[✓] Compilado: $(NAME)$(RESET)"

$(OBJS): $(INCLUDE)

clean:
	rm -f $(OBJS)
	rm -rf objs
	@echo -e "$(RED)Objectos eliminados$(RESET)"

fclean: clean
	@rm -rf $(NAME)

re: fclean  all

