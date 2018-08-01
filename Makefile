CPP = g++
CPPFLAGS = -std=c++11 -c -g -Wall# -fno-stack-protector
LDFLAGS = -g

EXE = test
SRCDIR := ./src
OBJDIR := ./obj
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS)) $(OBJDIR)/main.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $^
	
$(OBJDIR)/main.o: ./main.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)/*.o $(EXE) 
