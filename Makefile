CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11 -fdiagnostics-color=always
LDFLAGS=-g

SRCS=calculator.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: calculator

calculator: $(OBJS)
	$(CXX) $(LDFLAGS) -o calculator $(OBJS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend