UNAME=$(shell uname)

ifeq (Linux,$(strip $(UNAME)))
ARMASM=armasm
ARMCC=armcc
ARMLINK=armlink
ARMAR=armar
endif

all: clean ppp_code.c

######################
# AVR16 (PPP) ASSEMBLY
######################

AVR16_MCU = atxmega16a4
AVR16_ARCH = avrxmega2
PPP_LDSCRIPT = avr16.lds
CC_INCDIRS = header .

ppp_code.c: ppp.lo
	avr-objcopy -O binary ppp.lo ppp_code
	xxd -i ppp_code  $@
	avr-objdump -d $< > picop.dis
ppp.lo: ppp.loc
	avr-objcopy -g $< $@

ppp.loc: ppp.out $(PPP_LDSCRIPT)
	avr-ld -m $(AVR16_ARCH) -T $(PPP_LDSCRIPT) $< -o $@

ppp.out: $(PPP-CFILES)
	avr-gcc $< -c $(CC_INCDIRS:%=-I %) -mmcu=$(AVR16_MCU) -fno-jump-tables -o $@


clean:
	rm -rf *.out

