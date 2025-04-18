obj-m := click_driver.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)


CC := gcc-11


all:
	@echo "Building with compiler: $(CC)"
	@echo "Disabling stack protection and profiling"
	$(MAKE) -C $(KDIR) M=$(PWD) \
		KCFLAGS="$(KCFLAGS)" \
		CC=$(CC) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
