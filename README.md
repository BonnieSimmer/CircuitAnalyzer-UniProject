This project is the capstone project for 'Computer Programming [CSE 131s]' course at Ain Shams University Faculty
of engineering spring 2024.

It consisted of three tasks that seamlessly extended the scope and objectives of one another.

Description :
●our task is to develop a C++ program that calculates the total resistance of an
electrical circuit based on a user-provided string description. The electrical
circuit will be described as One String, where the type of connection between
resistors is represented by either 'S' (Series) or 'P' (Parallel).

●Resistor value will be integer or float number

●Types of electrical circuit :
1- Series (will be represented as S or s )
2- Parallel (will be represented as P or p )

● It is guaranteed that each connection will end by e.

The application provides the following features :
1. Enable users to input electrical circuit configurations using one string representation. (The input is one string only)
2. The Circuit Analyzer must handle electrical circuit that has up to 12 resistors.
3. The Circuit Analyzer must handle 1 Parent type of electrical circuit with multiple childs connections, As we can replace 1 resistor value by a connection. (ex: P 1 2 S 1 1 e e Act as P 1 2 2 e )
4. Establish a systematic approach to evaluate the circuit and generate the desired output. (ex: The total resistance = X)
5. Error handling:
A- Program must check on the number of resistors, for Series
connection it must have 1 resistor or more, for Parallel connection
it must have 2 resistors or more, otherwise you must print error
message “Incorrect Input”.
B- Program must check that the only accepted connection is S or P,
otherwise you must print the error message “Wrong Description”.
