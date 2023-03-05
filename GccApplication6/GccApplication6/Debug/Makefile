################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../adc_source.cpp \
../CPPFile1.cpp \
../main.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
adc_source.o \
CPPFile1.o \
main.o

OBJS_AS_ARGS +=  \
adc_source.o \
CPPFile1.o \
main.o

C_DEPS +=  \
adc_source.d \
CPPFile1.d \
main.d

C_DEPS_AS_ARGS +=  \
adc_source.d \
CPPFile1.d \
main.d

OUTPUT_FILE_PATH +=GccApplication6.elf

OUTPUT_FILE_PATH_AS_ARGS +=GccApplication6.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./adc_source.o: .././adc_source.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\New folder\Surveyaan\7.0\Packs\atmel\ATmega_DFP\1.7.374\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -B "D:\New folder\Surveyaan\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega2560" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./CPPFile1.o: .././CPPFile1.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\New folder\Surveyaan\7.0\Packs\atmel\ATmega_DFP\1.7.374\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -B "D:\New folder\Surveyaan\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega2560" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\New folder\Surveyaan\7.0\Packs\atmel\ATmega_DFP\1.7.374\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -B "D:\New folder\Surveyaan\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega2560" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="GccApplication6.map" -Wl,--start-group -Wl,-lm -Wl,-lprintf_flt -Wl,-lprintf_min -Wl,-lscanf_flt -Wl,-lscanf_min  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega2560 -B "D:\New folder\Surveyaan\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega2560"  
	@echo Finished building target: $@
	"D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "GccApplication6.elf" "GccApplication6.hex"
	"D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "GccApplication6.elf" "GccApplication6.eep" || exit 0
	"D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "GccApplication6.elf" > "GccApplication6.lss"
	"D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "GccApplication6.elf" "GccApplication6.srec"
	"D:\New folder\Surveyaan\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "GccApplication6.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "GccApplication6.elf" "GccApplication6.a" "GccApplication6.hex" "GccApplication6.lss" "GccApplication6.eep" "GccApplication6.map" "GccApplication6.srec" "GccApplication6.usersignatures"
	