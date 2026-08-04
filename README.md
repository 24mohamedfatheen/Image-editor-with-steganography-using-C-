# Image-editor-with-steganography-using-C-

About project----
A lightweight, 16-bit low-level image processing and steganography engine written in pure C for Turbo C / DOS environments.
This tool parses uncompressed .ppm (P3 ASCII) image data directly into dynamic far-memory arrays, executes real-time matrix transformations, and features custom bitwise payload encryption.

⭐This project was developed by me for a class demo which was conducted successfully.


Features---

Image Processing & Filters---
Glitch / Cyberpunk Matrix: Pixel buffer displacement for high-contrast digital glitching.
TV Static / Noise: Dynamic grain injection via pseudorandom noise loops.
Underwater Tint: Vignette-style spatial luminance falloff with deep blue/cyan colour shifting.
Old Camera (Sepia): Classic warm-tone sepia matrix transformation.
Brightness & Invert: RGB inversion and linear luminance manipulation.

Spycraft & Visualization----
LSB Steganography: Hide and extract encrypted text payloads inside the Least Significant Bits of pixel RGB channels without visual distortion.
ASCII Art Generator: Converts RGB pixel brightness matrices into raw ASCII terminal previews.



How to Run (Turbo C / DOSBox)---
Clone or copy MAIN.C into your Turbo C BIN folder.
Add a folder named images inside the BIN folder 
Place a .ppm (P3 ASCII format) sample image inside images folder.
Open Turbo C, compile, and run (Ctrl + F9).
