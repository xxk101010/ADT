LD := ld
CC := gcc
AR := ar
STRIP := strip

CFLAGS   += -I. -I./include -I./src 
LDFLAGS  += -fPIC -L./libs -pthread -lm 


TOOL_SRC := $(shell find . -name "*.c")
TOOL_OBJ := $(patsubst %.c, %.o, ${TOOL_SRC})

#SRC_LIB := $(shell find $(LIB_DIR) -name "*.a")

all:test_tool

test_tool:$(TOOL_OBJ) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	$(STRIP) -S $@


test_stack_balance:stack_balance.o stackar.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


test_stack_sort:stack_sort.o stackar.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_stack_post:stack_postFix.o stackar.o
	 $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


clean:
	rm -rf $(TOOL_OBJ) test_tool

.PHONY:all clean
