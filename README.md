# S-EE-M24

- Developed on Fedora 28
- Attempted to abide by [The Power of 10 Rules by G. J. Holzmann](http://web.eecs.umich.edu/~imarkov/10rules.pdf) for writing Safety-Critical Code

## Requirements
* gcc
* make
* cmake >= 3.0
* C++ Standard Library

## Usage
### Section 1 & 2
Simply run `make` within the respective folder which will create an executable.
On most systems, these can be executed as `./MatrixMult` or `./CounterTest`, respectively.

### Section 2
After cloning the repo, run:

```
cd Section3
mkdir build
cd build
cmake ..
make
```

This will create an executable within the `Section3\build` directory, `LinkedListExample`, which can be run as in Section 1 & 2.
