# STM32F446RE Tool Chain Project

A comprehensive Hardware Abstraction Layer (HAL) implementation for the STM32F446RE microcontroller, featuring GPIO and RCC (Reset and Clock Control) drivers with a simple LED control demonstration.

## 🚀 Project Overview

This project provides low-level drivers and abstractions for the STM32F446RE microcontroller, specifically targeting the STM32 Nucleo-F446RE development board. The implementation includes:

- **GPIO Driver**: Complete pin configuration and control functionality
- **RCC Driver**: System clock management and peripheral clock control
- **Hardware Abstraction**: Register-level access with type-safe interfaces
- **Example Application**: LED control demonstration on pin PA5

## 🔧 Hardware Requirements

### Primary Hardware
- **STM32 Nucleo-F446RE** development board
- USB cable (Type-A to Mini-B) for programming and power

### Microcontroller Specifications
- **MCU**: STM32F446RE (ARM Cortex-M4F @ 180MHz)
- **Flash Memory**: 512KB
- **RAM**: 128KB
- **Package**: LQFP64

### Pin Configuration (Current Implementation)
- **PA5**: GPIO Output (LED control) - Connected to onboard LED on Nucleo board

## 💻 Software Dependencies

### Required Tools
1. **ARM GNU Toolchain**: `arm-none-eabi-gcc` and related tools
2. **OpenOCD**: For debugging and flashing firmware
3. **Make**: Build system (GNU Make)

### Installation Instructions

#### Ubuntu/Debian
```bash
sudo apt update
sudo apt install gcc-arm-none-eabi openocd make
```

#### Windows
- Install [ARM GNU Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
- Install [OpenOCD](http://openocd.org/getting-openocd/)
- Ensure tools are in system PATH

#### macOS
```bash
brew install arm-none-eabi-gcc openocd make
```

## 🛠️ Build Instructions

### 1. Clone the Repository
```bash
git clone https://github.com/MahmoudAbdelrahman2002/tool_chain.git
cd tool_chain
```

### 2. Build the Project
```bash
# Clean previous builds
make clean

# Build all components
make all
```

### 3. Build Targets
- `make clean`: Remove all object files and binaries
- `make all`: Build complete project (default target)
- `final.elf`: Final executable for flashing to microcontroller

## 📱 Usage Instructions

### Flashing the Firmware
1. Connect your STM32 Nucleo-F446RE board via USB
2. Flash the firmware using OpenOCD:
```bash
make load
```

### Expected Behavior
After flashing, the onboard LED (connected to PA5) will turn on and remain lit, demonstrating successful GPIO configuration and control.

## 📁 Project Structure

```
tool_chain/
├── README.md                    # This file
├── makefile                     # Build configuration
├── main.c                       # Main application code
├── gpio.c                       # GPIO driver implementation
├── gpio.h                       # GPIO driver header
├── RCC.c                        # RCC driver implementation  
├── RCC.h                        # RCC driver header
├── STM32F446XX.h               # MCU register definitions
├── STM32F446RE_startup_code.c   # Startup/boot code
├── STM32F446RE_LS.ld           # Linker script
├── ERRORS.h                     # Error code definitions
├── common_macros.h             # Common utility macros
└── xpack-openocd-0.12.0-2/    # OpenOCD toolchain
```

## 🔌 GPIO Driver Features

### Supported Configurations
- **Modes**: Input, Output, Alternative Function, Analog
- **Output Types**: Push-Pull, Open-Drain
- **Speed Settings**: Low, Medium, Fast, High
- **Pull Resistors**: None, Pull-Up, Pull-Down
- **Alternative Functions**: AF0-AF15

### Usage Example
```c
// Configure PA5 as output
PIN_CONFIG_t config = {
    .port = PORTA,
    .pin = PIN5,
    .mode = OUTPUT,
    .speed = LOW_SPEED,
    .type = PUSH_PULL,
    .pull = NO_PULL
};

GPIO_pinInit(&config);
GPIO_WritePin(PORTA, PIN5, HIGH);
```

## ⚡ RCC Driver Features

### Clock Management
- HSI (High Speed Internal) oscillator control
- HSE (High Speed External) oscillator control  
- PLL configuration and control
- System clock source selection

### Peripheral Clock Control
- AHB1 peripheral clock enable/disable
- Supports all GPIO ports (A-H)
- DMA, CRC, and other peripheral clocks

### Usage Example
```c
// Enable GPIOA clock
RCC_AHB1EnablePeriphral(GPIOA_ENABLE);
```

## 🧪 Development Workflow

### Adding New Peripherals
1. Define register structures in appropriate header files
2. Implement driver functions in corresponding `.c` files
3. Add function prototypes to header files
4. Update makefile if new source files are added
5. Test with hardware before committing

### Debugging
- Use OpenOCD with GDB for step-by-step debugging
- Monitor register values through ST-Link debugger
- Utilize UART for runtime debugging output (when implemented)

## 🚧 Future Enhancements

### Planned Features
- [ ] UART driver implementation
- [ ] SPI driver implementation
- [ ] I2C driver implementation
- [ ] Timer/PWM drivers
- [ ] Interrupt handling framework
- [ ] Power management functions
- [ ] ADC driver implementation

### Code Quality Improvements
- [ ] Unit testing framework
- [ ] Doxygen documentation
- [ ] Static analysis integration
- [ ] Continuous integration setup

## 📋 Memory Layout

### Flash Memory (512KB)
- **0x08000000 - 0x0807FFFF**: Application code and constants

### RAM (128KB)
- **0x20000000 - 0x2001FFFF**: Main RAM for variables and stack

## ⚠️ Important Notes

### Safety Considerations
- Always verify pin configurations before connecting external hardware
- Use appropriate current limiting for LED/GPIO outputs
- Follow STM32 electrical characteristics guidelines

### Limitations
- Current implementation focuses on basic GPIO functionality
- Advanced features like DMA integration not yet implemented
- No real-time operating system (RTOS) integration

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Coding Standards
- Follow existing code style and naming conventions
- Add comments for complex register manipulations
- Test all changes on actual hardware when possible

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 📞 Support

For questions, issues, or contributions:
- Create an issue on GitHub
- Review existing documentation
- Check STM32F446RE reference manual for hardware-specific questions

---

**Built with ❤️ for embedded systems development**