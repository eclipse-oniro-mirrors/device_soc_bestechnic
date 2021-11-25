cur_dir := $(dir $(lastword $(MAKEFILE_LIST)))

obj-y :=

ifeq ($(CP_BOOT), 1)
obj-y += cp_code.o
obj-y += cp_boot.o
endif
obj-y += cp_ipc.o

ccflags-y += -Inet/wifi -Inet/net_os

ifeq ($(NUTTX_BUILD),1)

export CP_BIN_NAME ?= nuttx_cmcp
$(obj)/cp_code.o : $(NUTTX_ROOT)/$(CP_BIN_NAME).bin
AFLAGS_cp_code.o += -DCP_BIN_NAME=$(CP_BIN_NAME).bin -I$(NUTTX_ROOT)

else

export CP_BIN_NAME ?= cmcp
$(obj)/cp_code.o : out/$(T)/$(CP_BIN_NAME).bin
AFLAGS_cp_code.o += -DCP_BIN_NAME=$(CP_BIN_NAME).bin -Iout/$(T)
out/$(T)/$(CP_BIN_NAME).bin : $(srctree)/out/$(CP_BIN_NAME)/$(CP_BIN_NAME).bin
	$(call CMDCPFILE,$(srctree)/out/$(CP_BIN_NAME)/$(CP_BIN_NAME).bin,$(srctree)/$@)
#	$(call CMDCPFILE,$(srctree)/out/$(CP_BIN_NAME)/$(CP_BIN_NAME).elf,$(srctree)/$(@:.bin=.elf))
#	$(call CMDCPFILE,$(srctree)/out/$(CP_BIN_NAME)/$(CP_BIN_NAME).map,$(srctree)/$(@:.bin=.map))
#	$(call CMDCPFILE,$(srctree)/out/$(CP_BIN_NAME)/$(CP_BIN_NAME).lst,$(srctree)/$(@:.bin=.lst))
$(srctree)/out/$(CP_BIN_NAME)/$(CP_BIN_NAME).bin : FORCE
	$(call echo-help,)
	$(call echo-help,INFO    Please make sure DSP bin is up to date: out/$(CP_BIN_NAME)/$(CP_BIN_NAME).bin)
# We cannot build $(CP_BIN_NAME) automatically here, because the env inherited by sub-make cannot be cleaned:
# E.g., KBUILD_SRC, TC, CHIP_HAS_CP, ...
	$(call echo-help,)

endif

