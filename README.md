# Lexical Analyzer in C

## Overview

This project is a simple **Lexical Analyzer** implemented in C. It performs lexical analysis on a given source code by identifying and categorizing tokens such as **keywords**, **identifiers**, **numbers**, **operators**, and **symbols**. The analyzer is designed to process C-like syntax and can be used as a foundational tool for understanding compiler design or lexical analysis concepts.

---

## Features

- **Token Recognition**:
  - Identifies **keywords** (e.g., `int`, `if`, `while`).
  - Detects **identifiers** (e.g., variable names).
  - Recognizes **numbers** (integer literals).
  - Classifies **operators** (e.g., `+`, `-`, `*`, `/`, `=`, `<`, `>`).
  - Detects **symbols** (e.g., `(`, `)`, `{`, `}`, `;`, `,`).

- **Interactive Input**:
  - Allows users to input source code line by line.
  - Terminates input when the user types `END`.

- **Simple and Modular**:
  - Easy-to-understand code structure.
  - Modular functions for token recognition and analysis.

---

## How It Works

1. **Input Source Code**:
   - The program prompts the user to enter source code line by line.
   - Input ends when the user types `END`.

2. **Lexical Analysis**:
   - The `analyzeLexically` function processes the input code character by character.
   - It categorizes tokens into:
     - **Keywords**: Predefined words like `int`, `if`, etc.
     - **Identifiers**: User-defined names like variables.
     - **Numbers**: Integer literals.
     - **Operators**: Symbols like `+`, `-`, `=`, etc.
     - **Symbols**: Characters like `(`, `)`, `{`, `}`, etc.

3. **Output**:
   - The program prints the categorized tokens with their types.

---

## Code Structure

- **`isKeyword` Function**:
  - Checks if a given word is a keyword by comparing it against a predefined list.

- **`analyzeLexically` Function**:
  - Processes the input code and categorizes tokens.

- **`main` Function**:
  - Handles user input and calls the lexical analyzer.

---

## Prerequisites

- **C Compiler**: Ensure you have a C compiler installed (e.g., GCC).
- **Basic Knowledge of C**: Familiarity with C programming will help in understanding and modifying the code.

---

## How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/lexical-analyzer.git
   ```

2. **Navigate to the Project Directory**:
   ```bash
   cd lexical-analyzer
   ```

3. **Compile the Code**:
   ```bash
   gcc lexical_analyzer.c -o lexical_analyzer
   ```

4. **Run the Program**:
   ```bash
   ./lexical_analyzer
   ```

5. **Input Source Code**:
   - Enter your source code line by line.
   - Type `END` to finish input and see the lexical analysis output.

---

## Example Input and Output

### Input:
```c
int main() {
    int a = 10;
    if (a > 5) {
        return 0;
    }
}
END
```

### Output:
```
[Keyword] int
[Identifier] main
[Symbol] (
[Symbol] )
[Symbol] {
[Keyword] int
[Identifier] a
[Operator] =
[Number] 10
[Symbol] ;
[Keyword] if
[Symbol] (
[Identifier] a
[Operator] >
[Number] 5
[Symbol] )
[Symbol] {
[Keyword] return
[Number] 0
[Symbol] ;
[Symbol] }
[Symbol] }
```

---

## Customization

- **Add More Keywords**:
  - Update the `keywords` array in the code to include additional keywords.

- **Extend Token Recognition**:
  - Modify the `analyzeLexically` function to recognize more token types (e.g., floating-point numbers, strings).

---

## Contributing

Contributions are welcome! If you have suggestions, bug reports, or feature requests, please open an issue or submit a pull request.

---


## Acknowledgments

- Inspired by compiler design and lexical analysis concepts.
- Built as a learning tool for understanding tokenization in programming languages.

---
