NAME = ex02
TEST_NAME = test_runner

SRCS = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp\
	 src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS = src/tests.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $(TEST_NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

tests: $(TEST_NAME)

.PHONY: all clean fclean re tests