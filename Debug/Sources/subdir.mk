################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Bluethoot.c \
../Sources/Events.c \
../Sources/analogicas.c \
../Sources/aux_telas.c \
../Sources/auxiliar.c \
../Sources/dadosFlash.c \
../Sources/display.c \
../Sources/main.c \
../Sources/nivel_tanque.c \
../Sources/telaPrincipal.c \
../Sources/velocimetro.c 

OBJS += \
./Sources/Bluethoot.o \
./Sources/Events.o \
./Sources/analogicas.o \
./Sources/aux_telas.o \
./Sources/auxiliar.o \
./Sources/dadosFlash.o \
./Sources/display.o \
./Sources/main.o \
./Sources/nivel_tanque.o \
./Sources/telaPrincipal.o \
./Sources/velocimetro.o 

C_DEPS += \
./Sources/Bluethoot.d \
./Sources/Events.d \
./Sources/analogicas.d \
./Sources/aux_telas.d \
./Sources/auxiliar.d \
./Sources/dadosFlash.d \
./Sources/display.d \
./Sources/main.d \
./Sources/nivel_tanque.d \
./Sources/telaPrincipal.d \
./Sources/velocimetro.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Rosimar/workspace.kds/Ms_200/Static_Code/PDD" -I"C:/Users/Rosimar/workspace.kds/Ms_200/Static_Code/IO_Map" -I"C:/Users/Rosimar/workspace.kds/Ms_200/Sources" -I"C:/Users/Rosimar/workspace.kds/Ms_200/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


