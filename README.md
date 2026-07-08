# Inverted-Search
Inverted Search Engine in C using hash tables and linked lists for efficient keyword indexing and retrieval.


A C-based Inverted Search Engine that builds an inverted index from multiple text files to enable fast and efficient keyword searches. Instead of scanning every file for every query, the application maps each word to the files in which it appears using hash tables and linked lists, significantly improving search performance.

## Features

* Builds an inverted index from multiple text files
* Fast keyword-based search using hash tables
* Displays files containing the searched keyword
* Tracks word occurrences across files
* Supports dynamic handling of multiple input files
* Efficient indexing with linked lists and dynamic memory allocation

## Technologies Used

* C Programming
* Hash Tables
* Linked Lists
* File Handling
* String Manipulation
* Dynamic Memory Allocation

## How It Works

1. Reads multiple text files provided as command-line arguments.
2. Extracts and processes individual words from each file.
3. Creates an inverted index mapping words to the files where they occur.
4. Searches the generated index for user-entered keywords.
5. Displays the matching files and occurrence details.

## Compilation

```bash
gcc *.c -o inverted_search
```

## Execution

```bash
./inverted_search file1.txt file2.txt file3.txt
```

## Learning Outcomes

* Implementation of hash tables and linked lists
* Efficient indexing and searching algorithms
* File handling and text processing in C
* Dynamic memory management
* Practical application of data structures in search systems

## Future Enhancements

* Case-insensitive keyword search
* Phrase-based search support
* Save and load index from files
* Ranking search results based on keyword frequency
* Graphical User Interface (GUI)
