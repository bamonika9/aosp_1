obj-m := click_driver.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

# Use GCC 11
CC := gcc-11

# Pass kernel compile flags safely
# override KCFLAGS := -fno-stack-protector -fno-pg

all:
	@echo "Building with compiler: $(CC)"
	@echo "Disabling stack protection and profiling"
	$(MAKE) -C $(KDIR) M=$(PWD) \
		KCFLAGS="$(KCFLAGS)" \
		CC=$(CC) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
