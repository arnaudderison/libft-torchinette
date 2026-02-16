# 🔥 Torchinette

> ⚠️ **This project is no longer maintained.**

## Description
Torchinette is a tester for libft, designed to thoroughly verify each function in your library. With its user-friendly interface and detailed tests, Torchinette helps you validate your libft implementation.

## 🛠️ Installation

### Prerequisites
- GCC
- Make
- Norminette
- Your libft must be in a folder named `libft` at the project root
- All mandatory libft files must be present

### Installation Steps
1. Clone the repository:
```bash
cd <PATH_TO_YOUR_LIBFT>
```

2. Enter the directory:
```bash
git clone https://github.com/arnaudderison/libft-torchinette torchinette
```

3. Place your libft in the appropriate folder:
```bash
cd torchinette && make
```

## 🚀 Usage

### Compilation and Testing
To compile and run all tests:
```bash
make
```
This will:
1. Check for all required libft files
2. Compile the libft if all files are present
3. Compile the tester
4. Run all tests automatically

### Available Make Commands
- `make` : Checks files, compiles the project and runs tests
- `make check` : Verifies the presence of all required libft files
- `make libft.a` : Compiles only the libft
- `make norm` : Checks the norminette for libft
- `make clean` : Removes object files
- `make fclean` : Removes object files and executable
- `make re` : Fully recompiles the project
- `make help` : Displays all available commands

## 📋 Required Files
The following files must be present in your libft folder:
```
ft_atoi.c     ft_isascii.c   ft_memchr.c    ft_strchr.c    ft_strnstr.c
ft_bzero.c    ft_isdigit.c   ft_memcmp.c    ft_strdup.c    ft_strrchr.c
ft_calloc.c   ft_isprint.c   ft_memcpy.c    ft_strlcat.c   ft_tolower.c
ft_isalnum.c  ft_memset.c    ft_memmove.c   ft_strlcpy.c   ft_toupper.c
ft_isalpha.c  ft_strlen.c    ft_strncmp.c   libft.h
```

## 📋 Tested Functions

### Part 1 - Libc Functions
- isalpha, isdigit, isalnum, isascii, isprint
- strlen, memset, bzero, memcpy, memmove
- strlcpy, strlcat
- toupper, tolower
- strchr, strrchr
- strncmp, memchr, memcmp
- strnstr, atoi

### Part 2 - Additional Functions
- strdup
- calloc
- substr, strjoin
- strtrim
- split
- itoa
- strmapi
- striteri
- putchar_fd, putstr_fd, putendl_fd, putnbr_fd

## 🎨 Interface
The tester uses color codes for better readability:
- 🟢 Green: Test passed
- 🔴 Red: Test failed
- 🟡 Yellow: Information messages

## 🚀 Upcoming Updates

### Version 2.0 - Bonus Tests (Coming Soon)
The libft bonus functions will soon be tested:
- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

### Version 2.1 - Educational Mode (In Development)
A new educational mode will be added to:
- Explain each encountered error in detail
- Propose solutions and approaches to fix bugs
- Provide concrete examples of correct usage

## 📚 Educational Resources

### Understanding Common Errors
| Error Type | Useful Resources |
|------------|------------------|
| Segmentation fault | [Understanding and debugging segfaults](link) |
| Memory leaks | [Valgrind and memory management](link) |
| Buffer overflow | [Protection against overflows](link) |
| Undefined behavior | [Undefined behaviors in C](link) |

### Recommended Documentation
- 📖 [C Reference Manual](link)
- 🔍 [Pointers in C explained simply](link)
- 🧮 [Memory manipulation in C](link)
- 📝 [Coding best practices](link)

### Debugging Tools
- GDB: Basic usage guide
- Valgrind: Detecting memory leaks
- LLDB: GDB alternative for MacOS

### Community and Support
- 42 Help Forum
- Dedicated Discord channel (coming soon)
- Weekly code review sessions (coming soon)

## 🎯 Future Goals

### Short Term (1-2 months)
- [ ] Add bonus function tests
- [ ] Implement educational mode
- [ ] Improve error messages

### Medium Term (3-6 months)
- [ ] Enhanced user interface
- [ ] Performance tests
- [ ] Interactive debug mode

### Long Term (6+ months)
- [ ] Multilingual support
- [ ] Customizable tests

## 💡 Community Suggestions
We're open to your suggestions! Here are some currently under consideration:
- Verbose mode for more detailed test information
- Additional edge case tests
- Compatibility with other 42 projects

## 🤝 Contributing
Contributions are welcome! Feel free to:
1. Fork the project
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## 🐛 Bug Reporting
If you find a bug, please create a detailed issue including:
- Bug description
- Steps to reproduce
- Expected behavior
- Screenshots if possible

## 📝 License
This project is under free license.

## ✨ Author
- [@aderison](https://github.com/arnaudderison/libft-torchinette) - Creator and maintainer

## 🙏 Acknowledgments
- To the 42 community for their support
- To all project contributors

---
*"Let Torchinette light your way to a perfect libft!"* 🔥


