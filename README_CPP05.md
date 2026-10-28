# CPP05

Exceptions and a bureaucracy simulation.

Part of my C++ modules at [Codam](https://www.codam.nl) (42 Network), written in C++98.

**Concepts:** exceptions, class hierarchies, abstract base classes, a factory built without `if/else if` chains.

## Exercises

| Folder | Exercise | What it does |
| --- | --- | --- |
| `ex00` | Mommy, when I grow up, I want to be a bureaucrat! | `Bureaucrat` with a grade from 1 to 150 and custom exceptions for out-of-range values. |
| `ex01` | Form up, maggots! | `Form` that a `Bureaucrat` can sign if their grade is high enough. |
| `ex02` | No, you need form 28B, not 28C... | Abstract `AForm` with `ShrubberyCreationForm`, `RobotomyRequestForm` and `PresidentialPardonForm`. |
| `ex03` | At least this beats coffee-making | `Intern` that creates forms by name through a factory using pointers to member functions. |

## Build and run

Each exercise is self-contained. From the repository root:

```sh
cd ex00
make
./<executable>
```

`make fclean` removes the build output. Code is compiled with `-Wall -Wextra -Werror -std=c++98`.

## Index

This repository is the entry point for the series. The earlier modules:

| Module | Focus |
| --- | --- |
| [CPP00](https://github.com/onmore1/CPP00) | Basics of C++: classes, member functions, streams and `std::string`. |
| [CPP01](https://github.com/onmore1/CPP01) | Memory allocation, references vs pointers, and file streams. |
| [CPP02](https://github.com/onmore1/CPP02) | Ad-hoc polymorphism and the Orthodox Canonical Form with a fixed-point number class. |
| [CPP03](https://github.com/onmore1/CPP03) | Inheritance, from single to diamond. |
| [CPP04](https://github.com/onmore1/CPP04) | Subtype polymorphism, abstract classes and deep copies. |
