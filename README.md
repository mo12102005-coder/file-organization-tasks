# File Organization Tasks

Five separate C++ programs. Compile and run each program on its own.

```sh
g++ -std=c++11 task1.cpp -o task1
./task1
```

Replace `task1` with the number of the task you want to run.
Files are read and written in the program's current working directory.

- `task1.cpp`: accepts a student's full name, ID and grade, then saves them in `Student.txt`.
- `task2.cpp`: reads an existing `fruit.txt` and appends `Fresh Fruits`. Create the fruit list before running, for example Apple, Orange and Banana on separate lines. Each run appends the message once.
- `task3.cpp`: creates `welcome.txt`, replaces `body` with `one`, then saves `Hello Everyone` in the same file.
- `task4.cpp`: saves names and ages in `persons.txt`, reads them into a vector, and writes the youngest and oldest people to `results.txt`. Includes all people tied for either age.
- `task5.cpp`: appends student records to `students.txt`, ending each record with `$`. Uses a 20-character name array, so names may contain up to 19 characters plus the string terminator. Enter `y` to add another record or `n` to stop.
