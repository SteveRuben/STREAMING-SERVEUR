SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))
OBJS = $(SRCS:.cpp=.o)
TEMPS = $(SRCS:.cpp=.txt)
 
CFLAGS = -std=c++11 `pkg-config --cflags opencv`
LDFLAGS = `pkg-config --libs opencv`
 
all: $(PROGS)
 
%: %.cpp
 
	g++  $(CFLAGS)  -o $@ $< $(LDFLAGS) -lpthread
 
clean:
	@rm -f $(PROGS) $(OBJS) $(TEMPS)
	@echo "Limpo!"

