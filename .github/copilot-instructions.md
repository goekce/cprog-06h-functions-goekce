
- [ ] Follows the interaction example in the task and passes the autograder tests.
- Code is easy to follow, e.g.:
  - [ ] no code duplication
  - [ ] no deeply nested logic where a simpler structure works
- [ ] The code is commented where the *why* is not obvious.
- Variable names
  - [ ] are meaningful
  - [ ] follow one consistent convention: {term}`camel case` or {term}`snake case`
- [ ] Numbers with a special meaning have a name.
- [ ] (recommended) Only the programming structures introduced so far are used. 


The concepts we introduced so far can be found in the following links. All concepts are linked to specific sections of the chapters from Deitel's C How to Program book.

# 2. Chapter Intro to C programming

https://c-programming.aydos.de/c-basics/preparation/#reading-exercises

- 2.2
  - [ ] Comments
  - [ ] `#include` directive
  - [ ] `<stdio.h>` header
  - [ ] `main()` function
  - [ ] {term}`compiler`, linker and executable
  - [ ] `\n`, `\t`, `\"`
  - [ ] Indendation
  - [ ] `;` and statements
  - [ ] `{` and `}` (braces)
  - [ ] `printf`
- 2.3
  - [ ] Variable definition, e.g., `int x;`
    - [ ] Why do we need to define variables before using them?
    - [ ] What is an *identifier*?
    - [ ] Why should we choose meaningful variable names?
    - [ ] *{term}`camel case`* vs *{term}`snake case`* and which one is preferred in the book?
  - [ ] `&` operator used before variables in scanf
  - [ ] `scanf`
  - [ ] `%d` conversion specifier for `int` in `printf` and `scanf`
  - [ ] Why are many calculations performed in assignment statements (`=`)
- 2.4
  - [ ] Memory concepts, e.g., what happens in memory when you execute `sum = integer1 + integer2`
  - [ ] Does reading a value from memory change the value in memory? (**destructive** vs **non-destructive**[^microcontrollers-exception])
- 2.5
  - [ ] Arithmetic operators, e.g., `+`, `-`, `*`, `/`, `%`
  - [ ] Integer division, e.g., `5 / 2` evaluates to 2
  - [ ] Operator precedence, e.g., `*` and `/` have higher precedence than `+` and `-`, but parantheses win.
    - [ ] Why do we use *redundant parantheses*?
- 2.6
  - [ ] Selection (Decision making) `if` (without `else`, covered in next chapters)
  - [ ] Relational operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
  - [ ] Why can't we use C *keywords* like`auto` or `if` as a variable name? 
- 2.7 (optional)
  - [ ] Why should we use `puts()` instead of `printf()` for printing strings without formatting?


[^microcontrollers-exception]: Some microprocessors have destructive read, e.g., in their timers.


# 3. Chapter Structured Program development

https://c-programming.aydos.de/structured/preparation/#preparation-reading-structured


- 3.2 Algorithms
  - [ ] algorithm
  
- 3.3 Pseudocode
  - [ ] pseudocode
  - [ ] pseudocode vs flowchart?
  - [ ] Why is `int i` usually not part of the pseudocode?
  
- 3.4 Control structures
  - [ ]  sequential execution, transfer of control -- how do these compare to the [Big 3 table](#big3-table)?
  - [ ] `goto` statement (avoided in structured program development)
  - [ ] structured programming and goto elimination[^spaghetti-code]
  - [ ] single-entry/single-exit control statements
  - [ ] control statement stacking
  - [ ] selection statements
    - [ ] single selection `if`
    - [ ] double selection `if-else`
    - [ ] multiple selection `switch` (introduced in chapter 4)
  - [ ] iteration statements in C
    - [ ] (pre-test loop) `while`
    - [ ] (post-test loop) `do-while` (introduced in chapter 4)
    - [ ] (pre-test loop with counter) `for` (introduced in chapter 4)
  
- 3.5 `if` selection statement
  - [ ] `if` structure (in flowchart)
  - [ ] indentation (white spaces) when using `if`
  
- 3.6 `if..else` selection statement
  - [ ] `if..else` structure (in flowchart)
  - [ ] conditional expression
    - [ ] *the* ternary operator `? :`
  - [ ] nested `if..else` statements[^nested-if-else]
  - [ ] compound statement or block `{ }`
  - [ ] Error types
    - [ ] syntax
    - [ ] execution time (fatal, non-fatal)
  
- 3.7 `while` iteration statement
  - [ ] `while` structure (in flowchart)
  - [ ] infinite loop 💀
- 3.8 Formulating algorithms: Stepwise refinement 1: Counter-controlled iteration  
  - [ ] counter-controlled (or definite) iteration 
  - [ ] garbage value (uninitialized variable)
  - [ ] `%s` conversion specifier for strings (introduced first in section 2.7)
- 3.9 Stepwise refinement case study 2: {term}`sentinel`-controlled iteration
  - [ ] sentinel values
  - [ ] top-down refinement (compare it with beginning a flowchart with a single process and then converting it into multiple processes)
  - [ ] program phases: initialization, processing, termination
  - [ ] converting between types 
    - [ ] cast operator `(type)`
    - [ ] explicit `double avg = (double) sum / count;` (if `sum` and `count` are `int`)
    - [ ] implicit `double avg = sum / count;` 
  - [ ] floating point number formatting (`"%.2f\n"`)
  - [ ] productivity: pseudocode, flowchart vs writing C code
- 3.10 Stepwise refinement case study 3: Nested control statements
  - [ ] nesting an `if` into a `while` (while there are students to process, increment the number of passed students if ...)
- 3.11 Assignment operators
  - [ ] `+=`, `-=`, `*=`, `/=`, `%=` 🆒
- 3.12 Increment and decrement operators
  - [ ] increment `++` and decrement `--` operators 😎
  - [ ] pre-increment `++i` vs post-increment `i++`
- (optional) 3.13 Secure C programming 🛡️
  - [ ] Arithmetic overflow
  - [ ] `INT_MAX` and `INT_MIN` from `<limits.h>`
  - [ ] `scanf_s` and `printf_s`
  
  Supplementary: One of the exercises that we will cover in the lecture (similar to 3.18) requires reading doubles, but the chapter does not cover it: `scanf("%lf", ...)

  [^spaghetti-code]: Also called [🍝 Spaghetti code](https://en.wikipedia.org/wiki/Spaghetti_code).
[^nested-if-else]: The right one is shorthand for the left one, and is more readable:
    ::::{grid}
    :::{grid-item}
    ```c
    if (c1) {
      ;
    } else {
      if (c2) {
          ;
      } else {
          ;               
      }
    }
    ```
    :::
    :::{grid-item}
    ```c
    if (c1) {
      ;
    } else if (c2) {
      ;
    } else {
      ;
    }
    ```
# 4. Chapter Program Control

https://c-programming.aydos.de/control/preparation/#reading-exercises


- [ ] 4.2 Iteration
  - [ ] sentinel-controlled
  - [ ] counter-controlled
  - [ ] control variable
- [ ] 4.3 Counter-controlled iteration
  - [ ] name, initial value, iteration condition, increment or decrement
  - [ ] using integers vs doubles as the iteration variable
- [ ] 4.4 `for` iteration
  - [ ] syntax
  - [ ] flowchart
  - [ ] life-time of the iteration variable/s
  - [ ] off-by-one error
  - [ ] iteration variable used in the body
- [ ] 4.5 Examples
  - [ ] different increments
  - [ ] compound-interest calculation for subsequent years
  - [ ] floating-point representational errors
- [ ] 4.6 `switch` multiple-selection
  - [ ] syntax
  - [ ] flowchart
  - [ ] reading character input `(grade = getchar()) != EOF` 
  - [ ] assignments have values `a = b = 0`
  - [ ] `EOF`, {kbd}`Ctrl` + {kbd}`d` on Linux/macOS, {kbd}`Ctrl` + {kbd}`z` on Windows
  - [ ] controlling expression
  - [ ] `default`
  - [ ] limitation: each `case` can test only a constant integral expression
- [ ] 4.7 `do-while`
  - [ ] syntax
  - [ ] flowchart
  - [ ] ⚠️prof: `do-while` is better for iterations where the sentinel is the data that we need to get in each iteration. For example [EV charger earning calculator](#structured-stepwise-refinement-ev-charger-earning-example)
- [ ] 4.8 `break`, `continue`
  - [ ] some argue that these break the rules of structured programming
  - [ ] result in simple code and better performance
- [ ] 4.9 Logical operators
  - [ ] `&&` and
  - [ ] `||` or
  - [ ] `!` not
  - [ ] precedence `&&` > `||`
  - [ ] short-circuit evaluation `a == 1 && b > 42`
  - [ ] ⚠️prof: instead of `_Bool` and `stdbool.h` use directly `bool` in C23 (the standard that our template uses) 
- [ ] 4.10 Confusing equality vs assignment operators `==`, `=`
  - [ ] lvalues vs rvalues
  - [ ] using `7 == x` against assignment
  - [ ] constants can be only rvalues in an assignment statement
  - [ ] confusing `==` vs `=` in standalone statements, e.g., `x == 1` (luckily a modern language server warns about this.)
- [ ] 4.11 structured programming summary
  - [ ] flowcharts for sequence, three selections `if` `if-else` `switch`, three iterations `while` `do..while` `for`
  - [ ] stacking rule
  - [ ] nesting rule
  - [ ] three forms of control (#big3)
- [ ] 4.12 Secure C programming
  - [ ] return value of `scanf`
  - [ ] range checking after `scanf`


# 5. Chapter Functions

https://c-programming.aydos.de/functions/preparation/#reading-exercises


- [ ] 1. {term}`Divide and conquer`
- [ ] 2. Modularizing programs in C
  - [ ] C standard library
  - [ ] Meaning of *defining*, *calling* functions, and *returning* from functions
- [ ] 3. Math library functions
  - [ ] `ceil`, `floor`, `sqrt`, `cbrt`, `fabs` (float abs), `pow`, `fmod`, `sin`, ...
- [ ] 4. Functions
  - [ ] {term}`software reusability`
  - [ ] {term}`abstraction`
  - [ ] {term}`decomposition`
- [ ] 5. Function Definitions
  - [ ] Example: `square`
  - [ ] {term}`local variable`
  - [ ] Syntax 
  - [ ] `return` vs `return value`
- [ ] 6. {term}`function prototype`
    - vs function header: the first line of a function definition
  - [ ] {term}`argument coercion` or type promotion
  - [ ] conversion in mixed-type expressions
  -  Function prototype notes:

     > If there’s no function prototype for a function, the compiler forms one from the first occurrence of the function—either the function definition or a call to the function. This typically leads to warnings or errors, depending on the compiler.
     
     Part of this information is dated. Newer C standard do not create a prototype for you, if you use a function without declaring it first.
- [ ] 7. {term}`Function call stack` and stack frames
  - {term}`stack overflow`
  - function call order (Function-call stack in action)
- [ ] 8. Headers
  - e.g., `string.h`, `time.h`
- [ ] 9. Passing arguments by value and by reference
  - [ ] {term}`side effect`
- [ ] 10. Random-number generation 
  - [ ] `rand` from `stdlib.h`
  - [ ] range 0 to `RAND_MAX`
  - [ ] scaling using `%`
  - [ ] `%s` conversion specifier for strings. (was introduced in section 2.7 first, and then 3.8)
- [ ] 11. Case study: Rock ✊🪨, paper ✋📄, scissors ✌️✂️
  - [ ] `enum` {type}`enumerated type`
  - [ ] used `char *`: it returns a string, e.g., `char *f() { return "hello"; }`
- (storage-classes)=
  12. {term}`Storage class`es 
  - [ ] defines *storage duration* (e.g., `static`), *scope* (visibility), and *linkage* (not discussed here)
  - [ ] `auto` (implicit for function variables) vs `static`[^static]
  - [ ] `static` vs `extern` : block or compilation unit scope vs global scope
    - global variables and function names are extern as defautl
  - [ ] we should try to avoid global variables
- [ ] 13. Scope rules
  - [ ] function scope (inside a function)
  - [ ] file scope (defined outside any function)
  - [ ] block scope (`{}`)
  - [ ] function-prototype scope (variable names)
- [ ] 14. Recursion
- [ ] 15. Example using recursion: Fibonacci series
- [ ] 16. {term}`Recursion` vs {term}`iteration`
  - [ ] recursion has function calling overhead, so choose iteration if you can.
  - [ ] good software engineering vs high performance
- [ ] 17. Security: Secure random-number generation
  - [ ] industrial security requires *true* random number generation. Do not use `rand` for this purpose!

[^static]: `static` is relevant for interrupts in microcontroller programming, where we may want a variable in the interrupt handler to survive also after the function's return. 
  
#

Based on the mistakes, recommend review chapters.