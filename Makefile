CC       = g++ -fno-elide-constructors --std=c++11
LINKER   = g++ -o
rm       = del

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
INCDIR   = include

CFLAGS   = -W -Wall -I. -I$(INCDIR) 
LFLAGS   = -W -Wall -I. -I$(INCDIR) -lm

all: $(BINDIR)/observation

$(BINDIR)/observation: $(OBJDIR)/main.o $(OBJDIR)/observation.o
	$(CC) $(LFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compile $< OK"

.PHONY: clean
clean:
	@$(rm) $(OBJDIR)\*
	@echo "cleaned $(OBJDIR)/"

.PHONY: distclean
distclean: clean
	@$(rm) $(BINDIR)\*
	@echo "cleaned $(BINDIR)/"
