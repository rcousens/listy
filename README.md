Status
======

- Not ready for production. Check back soon!



Features
========

- Doxygen documentation generation is built-in by default. If their guidelines are followed, HTML documentation will be updated automatically subsequent to compilation. Otherwise, please alter the config.txt file to disable documentation generation.

- CMake, configured to produce multiple executables and cross-platform builds:
	- one for each file's unit tests
	- the project executable (from files in the /src directory)
	- an umbrella test, which calls all other tests sequencially, reporting the results

- Utility data structures and algorithms stored in the /src/util directory. These are dependent only on the C standard library, and include the following:
	- binary search trees
	- ternary search trees
	- hash tables
	- linked lists
	- vectors (dynamic arrays)
	- queues
	- stacks
	- memory pools (w/ garbage collection)
	- string algorithms
	- error-handling macros

- File generator scripts:
	- to automate file creation
	- to standardize file documentation
	- to attribute files to their creators

- Configuration file for quick modifications:
	- project name
	- version & status
	- authors



Installation
============

- Clone this repository to your local machine:
- Rename the top-level directory.
- Modify the configuration file.
```
git clone git@github.com:dasmithii/C-Project-Template.git
mv C-Project-Template PROJECT_NAME
cd PROJECT_NAME
open config.txt
```



Compilation
===========

- Go to top-level directory.
- Run these commands:

```
cmake .
make
```
- Executables will be places in /bin