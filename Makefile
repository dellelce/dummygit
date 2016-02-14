
#
# dummygit, 2016 by Antonio Dell'elce
#

CC             = gcc
TARGET         = dgit

SHELL          = /bin/bash

CFILES         = dummygit.c
OFILES         = dummygit.o
LDFLAGS	       = 


LOC_HFILES     = 
HFILES         = $(LOC_HFILES)

INCLUDES       =  -I.
DEBUG          = 
CFLAGS         = -Wall -O2  $(INCLUDES) $(DEBUG)
LIBS           = 


#
# --- RULES ---
#

all: $(TARGET)

$(TARGET):   $(OFILES)
	@echo "LINK " $(TARGET)
	@$(CC) -o $(TARGET) $(LDFLAGS) $(OFILES) $(LIBS)

#
# -- DEPS --
#

dummygit.o: dummygit.c $(HFILES) 
	@echo "CC "dummygit.c
	@$(CC) -c $(CFLAGS) -o dummygit.o dummygit.c

 
#  
# clean
#    
     
clean:
	rm -f $(TARGET) $(OFILES) $(LOC_HFILES) *.exe

#
# redo
#

redo: clean all

