# txtfind

A simple and fast command-line tool for finding text in files.

## About

`txtfind` is a lightweight and easy-to-use command-line utility written in C++ that allows you to quickly search for text within a file. It reads a file line by line and prints out the lines that contain your search query, along with the corresponding line number.

This tool was made using the `libutils` library.

## Features

- **Interactive Search**: Prompts for search input after specifying the target file.
- **Line Numbering**: Displays the exact line number where the text is found.
- **Colored Output**: Uses colors to highlight important information, making it easier to read.
- **Simple & Fast**: Built with performance and simplicity in mind.

## Building from Source

To build the project, you'll need a C++ compiler (like g++) and `make`.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/HassanIQ777/txtfind.git
    cd txtfind
    ```

2.  **Build the project:**
    -   To build the release version (optimized):
        ```bash
        make
        ```
    -   To build the debug version:
        ```bash
        make debug
        ```
    The executable `txtfind` will be created in the root 
    directory of the repository.

3.  **Clean up build files:**
    ```bash
    make clean
    ```

## Usage

To use `txtfind`, simply provide a file path as an argument:

```bash
./txtfind <path/to/your/file>
```

The program will then prompt you to enter the text you want to find.

### Example

```bash
./txtfind main.cpp
Enter text to find:
> print

'print' found on line (6):
using funcs::print;

'print' found on line (13):
		print /*useless comment*/ ("Usage:\n");

'print' found on line (14):
		print(argv[0], " ", color::TXT_CYAN, "<FILE>", color::_RESET, "\n");
...
```

## Contributing

Contributions are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request.

## License

This project is licensed under the terms of the LICENSE file.
