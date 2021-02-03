APPDIR=app
BINDIR=bin
LIBDIR=lib
TESTDIR=test
SRCDIR=src
OBJDIR=obj

MAIN=$(APPDIR)/main.cpp
APP=cifrero

BINAPP=$(BINDIR)/$(APP)

_DIRS=$(APPDIR) $(BINDIR) $(OBJDIR)

_OBJS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(_OBJS))

_TESTS=$(wildcard $(TESTDIR)/*.cpp)
TESTS=$(patsubst $(TESTDIR)/t_%.cpp,$(TESTDIR)/t_%,$(_TESTS))

.PHONY: all

all : $(_DIRS) $(OBJS) $(BINAPP)

$(BINAPP) : $(MAIN) $(OBJS)
	g++ -o $@ $^ -I $(LIBDIR)
	./$(BINAPP)

$(_DIRS) :
	mkdir -p $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ -c -I $(LIBDIR) $< -o $@

test : $(TESTS)
	$(info ************  Testes concluídos com sucesso! ************)

$(TESTDIR)/t_% : $(TESTDIR)/t_%.cpp $(OBJS)
	g++ -o $@ -I $(LIBDIR) $^
	./$@

clean :
	rm -f obj/* bin/* ${TESTS}
