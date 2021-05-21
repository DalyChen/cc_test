
VERSION = V1
MAKEFLAGS += -rR --include-dir=$(CURDIR)

$(info /*************** start ***************/)
$(info ${VERSION})

################################################################################
ifeq ("$(origin V)", "command line")
	KBUILD_VERBOSE = $(V)
endif
ifndef KBUILD_VERBOSE
  KBUILD_VERBOSE = 0
endif

ifeq ($(KBUILD_VERBOSE),1)
  quiet =
  Q =
else
  quiet=quiet_
  Q = @
endif

$(info make version: ${MAKE_VERSION})
$(info MAKEFLAGS: x$(MAKEFLAGS))
ifneq ($(filter 4.%,$(MAKE_VERSION)),)	# make-4
ifneq ($(filter %s ,$(firstword x$(MAKEFLAGS))),)
  quiet=silent_
endif
else					# make-3.8x
ifneq ($(filter s% -s%,$(MAKEFLAGS)),)
  quiet=silent_
endif
endif

$(info quiet: ${quiet} Q: ${Q} KBUILD_VERBOSE: ${KBUILD_VERBOSE})

################################################################################
ifeq ($(KBUILD_SRC),)

ifeq ("$(origin O)", "command line")
  KBUILD_OUTPUT := $(O)
endif

PHONY := _all
_all:

# Cancel implicit rules on top Makefile
$(CURDIR)/Makefile Makefile: ;

ifneq ($(KBUILD_OUTPUT),)
saved-output := $(KBUILD_OUTPUT)
# $(info saved-output: ${saved-output})
KBUILD_OUTPUT := $(shell mkdir -p $(KBUILD_OUTPUT) && cd $(KBUILD_OUTPUT) && /bin/pwd)
$(info KBUILD_OUTPUT: ${KBUILD_OUTPUT})

$(if $(KBUILD_OUTPUT),\
	 $(info create output directory "$(saved-output)" success),\
	 $(error failed to create output directory "$(saved-output)"))

PHONY += $(MAKECMDGOALS) sub-make
$(info ${PHONY})


$(filter-out _all sub-make $(CURDIR)/Makefile, $(MAKECMDGOALS)) _all: sub-make
	@:

# sub-make: FORCE
# 	$(Q)$(MAKE) -C $(KBUILD_OUTPUT) KBUILD_SRC=$(CURDIR) \
# 	-f $(CURDIR)/Makefile $(filter-out _all sub-make,$(MAKECMDGOALS))

# # Leave processing to above invocation of make
# skip-makefile := 1
endif # ifneq ($(KBUILD_OUTPUT),)


endif # ifeq ($(KBUILD_SRC),)
