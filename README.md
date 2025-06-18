# Fractol

A beautiful fractal visualization program built with MiniLibX graphics library. This project allows you to explore and interact with various mathematical fractals in real-time.

> [!NOTE]
> **This version is specifically built for macOS** and uses the MiniLibX graphics library. The program provides an interactive way to explore the fascinating world of mathematical fractals with real-time zooming and panning capabilities.

## 🎨 Features

### Supported Fractals

| **Mandelbrot Set** | **Julia Set** |
|:---:|:---:|
| ![Mandelbrot Set](.gif_and_others/Mandelbrot.gif) | ![Julia Set](.gif_and_others/Julia_set.gif) |
| The classic fractal showing the boundary between bounded and unbounded values in the complex plane. | A family of fractals with customizable parameters that create stunning geometric patterns. |
| **Tricorn** | **Burning Ship** |
| ![Tricorn](.gif_and_others/TricornSmallZoom.gif) | ![Burning Ship](.gif_and_others/Burning_Ship_Fractal.gif) |
| A variation of the Mandelbrot set with different mathematical properties, creating unique symmetrical patterns. | A unique fractal with distinctive geometric patterns and sharp, angular structures. |

### Interactive Controls
- **Mouse Wheel**: Zoom in/out at cursor position
- **Arrow Keys**: Pan the view in all directions
- **ESC Key**: Exit the program
- **SHIFT Key**: Increase iteration count for higher detail (bonus feature)
- **TAB Key**: Additional control options

## 🚀 Installation & Usage

### Prerequisites
- macOS (this version is specifically built for macOS)
- GCC compiler
- MiniLibX library (included in the project)

### Building the Project
```bash
# Clone the repository
git clone <repository-url>
cd fractol

# Build the project
make
```

### Running the Program

#### Basic Usage
```bash
# Run Mandelbrot set
./fractol mandelbrot

# Run Julia set with default parameters
./fractol julia

# Run Julia set with custom parameters (between -2.0 and 2.0)
./fractol julia 0.3 -0.56

# Run Tricorn set
./fractol tricorn

# Run Burning Ship set
./fractol burning_ship
```

#### Parameter Constraints
- For Julia sets, parameters must be within the range [-2.0, 2.0]
- Parameters are automatically converted from string to double precision

## 🏗️ Project Structure

```
fractol/
├── srcs/                    # Source files
│   ├── main.c              # Main program entry point
│   ├── fractal_draws.c     # Fractal calculation algorithms
│   ├── window_management.c # Window and event handling
│   ├── configure_fractal.c # Fractal configuration and rendering
│   ├── error_management.c  # Input validation and error handling
│   └── characters_into_double.c # String to double conversion
├── inc/                    # Header files
│   └── fractol.h          # Main header with all definitions
├── mlx/                    # MiniLibX graphics library
├── utils/                  # Utility libraries
│   └── ft_printf/         # Custom printf implementation
├── Makefile               # Build configuration
├── Mandelbrot.gif         # Mandelbrot set demonstration
├── Julia_set.gif          # Julia set demonstration
└── README.md              # This file
```

## 🔧 Technical Details

### Graphics Library
- **MiniLibX**: A minimal graphics library for macOS
- **Window Size**: 500x500 pixels
- **Coordinate System**: Cartesian plane from (-2, -2) to (2, 2)
- **Color System**: RGB color mapping based on iteration count

### Mathematical Implementation
- **Iteration Limit**: Configurable (default: 1000 iterations)
- **Precision**: Double precision floating-point calculations
- **Zoom**: Infinite zoom capability with mouse wheel
- **Panning**: Smooth movement with arrow keys

### Memory Management
- Proper cleanup on program exit
- No memory leaks
- Efficient image buffer management

## 🎯 Key Functions

### Fractal Calculations
- `draw_mandelbrot()`: Renders the Mandelbrot set
- `draw_julia()`: Renders Julia sets with custom parameters
- `draw_tricorn()`: Renders the Tricorn fractal
- `draw_burningship()`: Renders the Burning Ship fractal

### User Interface
- `manage_key()`: Handles keyboard input
- `mouse_hook()`: Handles mouse interactions
- `close_red_cross()`: Handles window closing

### Utilities
- `ft_atod()`: Converts ASCII strings to double precision
- `color_fractal()`: Maps iteration count to RGB colors
- `map()`: Scales values between coordinate systems

## 🎨 Color Scheme

The program uses a dynamic color scheme where:
- Colors are mapped based on the number of iterations
- Higher iteration counts result in different color gradients
- The color mapping creates beautiful visual patterns

## 🐛 Error Handling

The program includes comprehensive error handling for:
- Invalid command line arguments
- Out-of-range parameters for Julia sets
- Missing or incorrect fractal names
- Proper cleanup on errors

## 📝 Examples

### Valid Commands
```bash
./fractol mandelbrot
./fractol julia 0.285 0.01
./fractol julia -0.4 0.6
./fractol tricorn
./fractol burning_ship
```

### Error Messages
The program provides helpful error messages when invalid input is provided, including examples of correct usage.

## 🔄 Build Commands

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild the project from scratch
```

## 📄 License

This project is part of the 42 curriculum and follows the school's coding standards and guidelines.

## 👨‍💻 Author

Created by [Your Name] as part of the 42 curriculum.

---

**Note**: This version is specifically built for macOS and uses the MiniLibX graphics library. The program provides an interactive way to explore the fascinating world of mathematical fractals with real-time zooming and panning capabilities.