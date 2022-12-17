# ValidCheck
This program is designed to determine if a string is a valid check for a particular set of rules. The program accepts an input string and a debug flag, and returns whether or not the string is a valid check.


## Usage
To use ValidCheck, compile the program and run it with the following command:
```
./ValidCheck [string] [debug flag]
```

Alternatively, run the program without any parameters, then the program will prompt for an input string


## Rules
A string is considered a valid check if it meets the following criteria:

+ It contains only the characters a, b, c, d, m, n, o, and p.
+ It begins and ends with an a, b, c, or d.
+ Any m in the string is immediately followed by an a.
+ Any n in the string is immediately followed by a b.
+ Any o in the string is immediately followed by a c.
+ Any p in the string is immediately followed by a d.
If the string is a valid check, the program will print the characters a, b, c, and d in the order they appear in the string, with any m, n, o, or p characters removed.


## Debug Mode
If debug mode is enabled, the program will print additional information about the checking process, including when the stack grows and when characters are popped from the stack.

To enable debug mode, include the -d flag when running the program.
