# Image Processing Toolkit

## Overview

The Image Processing Toolkit is a comprehensive C programming project aimed at providing a versatile set of functions for various image processing tasks.
Whether you need to manipulate ImageX files or perform operations on PPM and PGM images, this toolkit has you covered.
From basic tasks like copying and resizing images to more advanced functions like hiding messages within images, the toolkit offers a wide range of capabilities to meet your image processing needs.

**The code has been written few years ago, in french (variables, functions, comments...).**

## Features

- **ImageX Manipulation:** Functions for manipulating ImageX files, including reading, writing, copying, mirroring, juxtaposing, rotating, resizing, and hiding images within other images.
- **PPM and PGM Support:** Dedicated functions for handling PPM (Portable Pixel Map) and PGM (Portable Gray Map) image formats, ensuring compatibility and efficiency.
- **Organized Project Structure:** Modular organization with separate C source files for each image processing task, facilitating easy navigation, maintenance, and customization.
- **Easy Integration:** Simple compilation and execution process, along with clear instructions on how to use the toolkit for your image processing tasks.

## Project Structure

The project is structured as follows:

- `copie.c`, `copiepgm.c`: Functions for copying PPM and PGM images, respectively.
- `freeim.c`, `freeimpgm.c`: Functions to free memory allocated for PPM and PGM images, respectively.
- `jhori.c`, `jverti.c`: Functions for horizontal and vertical juxtaposition of PPM images.
- `Lecture.c`, `Lecturepgm.c`: Functions for reading PPM and PGM image files, respectively.
- `main.c`: Main file orchestrating various image processing operations.
- `memoire.c`, `memoirepgm.c`: Functions for memory allocation for PPM and PGM images, respectively.
- `mhori.c`, `mverti.c`: Functions for horizontal and vertical mirroring of PPM images.
- `pmtoc.c`: Functions for hiding messages within images.
- `pro.h`: Header file containing function prototypes and structure definitions.
- `red.c`: Functions for resizing images.
- `restitute.c`: Functions for extracting concealed messages from images.
- `rot270.c`: Function for rotating PPM images by 270 degrees.
- `Write.c`, `Writepgm.c`: Functions for writing modified PPM and PGM images to files, respectively.

## Getting Started

**You can run the `ImageProcessingToolkit/make.bat` file or run this below:**

1. **Compilation**: Compile the project using a C compiler such as GCC.

   ```bash
   gcc -o image_processor main.c copie.c copiepgm.c freeim.c freeimpgm.c jhori.c jverti.c Lecture.c Lecturepgm.c memoire.c memoirepgm.c mhori.c mverti.c pmtoc.c red.c restitute.c rot270.c Write.c Writepgm.c
   ```

2. **Execution**: Run the compiled executable.

   ```bash
   ./image_processor
   ```

3. **Functionality**:
   - Modify the `main.c` file to perform specific image processing tasks as needed.
   - Ensure that input image files are provided as arguments to the respective functions.

## Testing

The functionality of the toolkit has been verified using color images provided and XnView software for PPM images.
For PGM images, publicly available JPG images were converted for testing.

## Challenges Faced

- Understanding and formatting the requirements demanded efforts to ensure compliance.
- Some issues were encountered in function design due to pointer properties.
- Formulas in certain loops required considerable thought and paper testing.
- Difficulty in predicting program execution and outcomes.

## Specific Challenges and Resolutions

- Horizontal and vertical mirroring functions initially faced allocation errors, resolved by memory reallocation.
- Horizontal juxtaposition function required additional loops to write both images correctly.
- Vertical juxtaposition function involved writing the entire image in memory followed by the mirror image.
- Rotation function applied transformation matrices to write the rotated image.

## Example

For the horizontal juxtaposition:
![Horizontal juxtaposition](/ImageProcessingToolkit/images/images_output/Horizontal_juxtaposition.png "Horizontal juxtaposition")

## Conclusion

The Image Processing Toolkit offers a robust solution for various image processing tasks, overcoming challenges through careful analysis and testing.
With its modular structure and comprehensive functionality, the toolkit empowers users to efficiently manipulate and process images to meet their specific needs.

## Dependencies

This project relies on standard C libraries (stdio.h, stdlib.h) for file I/O operations and memory management.
The [XnView](https://www.xnview.com/en/xnview/) software has been used to verify images.
[Download packages](https://www.xnview.com/wiki/index.php/Download_Packages).

## License

This project is licensed under the [MIT License](LICENSE).
