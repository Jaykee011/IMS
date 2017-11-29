CXX?=g++

NAME = model
OBJ = model.cc

# C++ compiler flags
CXXFLAGS  = -Wall
CXXFLAGS += -g  # add debug info
CXXFLAGS += -lsimlib
CXXFLAGS += -lm

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)