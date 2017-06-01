CXX := g++
LUAC := luac
LUA_ROOT := /usr/local
LUA_INCLUDE := $(LUA_ROOT)/include
LUA_LIBPATH := $(LUA_ROOT)/lib
LUA_LIBS := -llua

CXXFLAGS := -W -Wall -I$(LUA_INCLUDE) -Iinc/ -DAI_DEV_KIT
LDFLAGS := -L$(LUA_LIBPATH) $(LUA_LIBS)

SRCS := srcs/main.cpp \
	srcs/LuaManager.cpp\
	srcs/IA.cpp \

OBJS := $(SRCS:%.cpp=objs/%.o)

NAME := test_ia

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDFLAGS)
	@echo -e "\033[38;5;10m=== $(NAME): Compiled !\033[0m"

objs/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.luac: %.lua
	$(LUAC) -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY : all clean fclean re
