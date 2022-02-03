# HEXER

Hexer is a small hexadecimal viewer made in C/C++ with ncurses library.

It was intended to act like HxD but in cli.

For now, you can open file and navigate inside while staying on command line.

It will cast every value as a char, short, int, long based on the bytes you are on and the next ones.

## Installation

You will have to install GNU Make and the library ncurses.

Then, use make and the root of the repository
```bash
make
```

## Usage

```bash
./hexer name_of_the_file
```

## Contributing
Pull requests are welcome. Even if I don't think I will keep working on this project.

## License
[MIT](https://choosealicense.com/licenses/mit/)
