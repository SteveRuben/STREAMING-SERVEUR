SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))
OBJS = $(SRCS:.cpp=.o)
TEMPS = $(SRCS:.cpp=.txt)
 
CFLAGS = -std=c++11 `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`
 
all: $(PROGS)
 
%: %.cpp
 
	g++  $(CFLAGS)  -o $@ $< $(LDFLAGS) -lpthread
 
clean:
	@rm -f $(PROGS) $(OBJS) $(TEMPS)
	@echo "DONE!"