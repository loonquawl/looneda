INCDIR:=inc
SRCDIR:=src
DEPSDIR:=deps
OBJDIR:=objs
BUILDDIR:=build
PLUGINDIR=plugins
PRECOMPILED_INC:=precompiled_inc

BINARY_NAME:=leda

CLEANDIRS=$(BUILDDIR) $(OBJDIR)
MRPROPERDIRS=$(DEPSDIR) $(PRECOMPILED_INC)

INC_=$(INCDIR) $(PRECOMPILED_INC)
INC=$(addprefix -I,$(INC_))

FILES_=$(foreach file,$(notdir $(wildcard $(SRCDIR)/*.cc)),$(subst .cc,,$(file)))

OBJS=$(addsuffix .o,$(FILES_))
DEPS=$(addsuffix .mk,$(FILES_))

PRECOMPILED_HEADER_TARGETS=$(subst .hh,.gch,$(notdir $(wildcard $(INCDIR)/*.hh)))

CXXFILES=$(addsuffix .cc,$(FILES_))
SOURCE=$(CXXFILES)

SEARCHPATH=$(INCDIR) $(SRCDIR) $(DEPSDIR) $(BUILDDIR) $(PRECOMPILED_INC) $(OBJDIR)
VPATH+=$(foreach dir,$(SEARCHPATH),:$(dir))

CXX:=g++-4.7.3
CXXFLAGS:=-std=c++0x -pipe -g
LDFLAGS:=

DOXYGEN_OUTPUT:=docs/doxygen
DOXYGEN_CONFIG:=misc/doxygen.conf

.DEFAULT_GOAL:=all

include $(wildcard $(DEPSDIR)/*.mk)

.PHONY: all depend precomp_headers clean mrproper info debug docs clean_docs remake plugins

all: $(BINARY_NAME)

%.gch: %.hh
	$(CXX) $(CXXFLAGS) $(INC) $< -o $(PRECOMPILED_INC)/$@

%.mk: %.cc
	$(CXX) $(CXXFLAGS) $(INC) $< -MM -MF $(DEPSDIR)/$@

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INC) $< -c -o $(OBJDIR)/$@

$(BINARY_NAME): $(OBJS)
	$(info Linking: $^)
	$(CXX) $(LDFLAGS) $(addprefix $(OBJDIR)/,$(notdir $^)) -o $(BUILDDIR)/$@

depend: $(DEPS)

precomp_headers: $(PRECOMPILED_HEADER_TARGETS)

clean:
	$(info Cleaning directories: $(CLEANDIRS))
	$(foreach directory,$(CLEANDIRS),$(shell rm -rf $(directory)/*))

mrproper: clean clean_docs
	$(info Cleaning directories: $(MRPROPERDIRS))
	$(foreach directory,$(MRPROPERDIRS),$(shell rm -rf $(directory)/*))

info:
	$(info FILES_ $(FILES_))
	$(info INC $(INC))
	$(info DEPS $(DEPS))
	$(info SOURCE $(SOURCE))
	$(info PRECOMPILED_HEADER_TARGETS $(PRECOMPILED_HEADER_TARGETS))

debug: $(BINARY_NAME)
	gdb -x misc/gdbprofile $(BUILDDIR)/$(BINARY_NAME)

docs:
	doxygen $(DOXYGEN_CONFIG)

clean_docs:
	rm -rf $(DOXYGEN_OUTPUT)/*

remake: clean
	make all

plugins:
	make -C $(PLUGINDIR)/

tags:
	ctags -R

Makefile: depend

