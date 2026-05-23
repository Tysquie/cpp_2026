CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
 
TARGET  = warzywniak
SRCS    = main.cpp Product.cpp Vegetable.cpp Fruit.cpp Juice.cpp Cart.cpp Checkout.cpp
OBJS    = $(SRCS:.cpp=.o)
 
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS) $(TARGET)
 
