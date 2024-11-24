# Multithreaded File Management System

## Overview

This project is a multithreaded file management system written in C. It allows users to perform various file operations concurrently while ensuring data integrity and synchronization. It leverages POSIX threads (pthreads) and semaphores for concurrency control. Supported operations include file reading, writing, renaming, copying, deletion, and metadata display.

## Features

- **Concurrent File Reading**: Multiple threads can read from the same file simultaneously.
- **Exclusive File Writing**: Ensures that only one thread can write to a file at a time.
- **File Deletion**: Allows users to delete files using dedicated threads.
- **File Renaming**: Implements functionality to rename files safely.
- **File Copying**: Enables copying of files with thread management.
- **File Metadata Display**: Shows details like file size, creation date, and permissions.
- **Error Handling**: Robust error handling for all file operations.
- **Logging Operations**: Logs actions performed on files for auditing.

## Technologies Used

- Python 3.x
- Threading module for concurrency
- Standard file handling libraries

## File Structure

file_management_system/
│
├── main.c                 # Entry point of the program
├── file_manager.c         # Main file management logic
├── file_operations.c      # Implementation of various file operations
├── log_operations.c       # Logging functionality
├── file_operations.log    # Log file for file operations
└── Makefile               # For building the project


## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/file_management_system.git
   cd file_management_system
   ```

## Usage

- **1.Run the program:**
  ```bash
  ./file_manager
  ```

- **2.Menu Options**
The program provides a menu for users to choose operations:
**1:** Concurrent File Reading
**2:** Exclusive File Writing
**3:** File Copying
**4:** File Renaming
**5:** File Deletion
**6:** File Metadata Display
**0:** Exit the program

## Example Operations
**Writing data to a file (2):** Enter the data to write when prompted.
**Reading a file (1):**Displays the file content across multiple threads.
**Renaming a file (4):** Input source and target filenames.
**Copying a file (3):**Input the source and destination filenames.
**Deleting a file (5):** Specify the filename to delete.
**Viewing metadata (6):** Metadata such as size, permissions, and timestamps will be displayed.

## Logging

All file operations are logged in file_operations.log.
Logs include the operation performed, the filename, and a timestamp.

## Synchronization Approach
Semaphores: Used for exclusive access to critical sections, such as writing, renaming, copying, and deletion.
Read-Write Locks: Allows multiple threads to read simultaneously but provides exclusive access for writing.
Shared Variables: Protected using semaphores to ensure consistency when tracking read counts.

## Error Handling

The program ensures graceful handling of common errors such as:

File not found
Permission issues
Invalid input


## Building and Running with Makefile
The Makefile simplifies the compilation process:
```bash
make        # Compiles the project
make clean  # Cleans the build artifacts

```

## Example Execution
Menu:
1. Concurrent File Reading.
2. Exclusive File Writing.
3. File Copying.
4. File Renaming.
5. File Deletion.
6. File Metadata Display.
0. Exit

Enter your choice: 1
Read from example.txt: Sample text from file -> Thread_id: 140511256921856.
...

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements

Thank you to all contributors and resources that helped in the development of this project.

```bash

### Instructions for Use

1. Create a new file in your project directory named `README.md`.
2. Copy the entire content above (from the line with `# Multithreaded File Management System` to the end).
3. Paste it into the `README.md` file.
4. Save the file.

Feel free to customize any part of the README to better fit your project!
```
