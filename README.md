# aosp_1


step 1: create a Kernal module at
 /sys/kernel/click/

step 2: create a make file at
 /sys/kernel/Makefile

step 3: insert the module at
sudo insmod click_driver.ko

step 4 : check for the sys interface at
ls /sys/kernel/click

step 5: Trigger the click from the userspace
echo 1 | sudo tee /sys/kernel/click/trigger

step 6: check for the Kernel log
sudo dmesg | tail

