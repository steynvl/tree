# Tree
A recursive directory listing program that produces a depth indented listing of files.

## Installing 

#### Preliminaries
It is assumed that you have [CMake](https://cmake.org/install/) installed on your system. 

#### Building
```bash
$ git clone https://github.com/steynvl/tree
$ cd tree
$ mkdir bin && cd bin
$ cmake ..
$ make
$ ./tree --help
```

If you want to install the program then you can run the following
```bash
$ sudo make install
$ tree --help
```


## Example
```bash
$ cd ~/inferrer
$ tree
.
├─── inferrer
│   ├─── oracle
│   │   ├───  active_oracle.py
│   │   ├───  passive_oracle.py
│   │   ├───  __init__.py
│   │   └───  oracle.py
│   ├─── algorithms
│   │   ├─── active
│   │   │   ├─── nlstar
│   │   │   │   ├───  nlstar.py
│   │   │   │   ├───  observation_table.py
│   │   │   │   ├───  __init__.py
│   │   │   │   └───  row.py
│   │   │   ├─── lstar
│   │   │   │   ├───  __init__.py
│   │   │   │   └───  lstar.py
│   │   │   ├───  __init__.py
│   │   │   └───  active_learner.py
│   │   ├─── passive
│   │   │   ├─── gold
│   │   │   │   ├───  __init__.py
│   │   │   │   └───  gold.py
│   │   │   ├─── rpni
│   │   │   │   ├───  __init__.py
│   │   │   │   └───  rpni.py
│   │   │   ├───  passive_learner.py
│   │   │   └───  __init__.py
│   │   ├───  __init__.py
│   │   └───  algorithm.py
│   ├─── logger
│   │   ├───  logger.py
│   │   ├───  __init__.py
│   │   ├───  logger_manager.py
│   │   └───  singleton.py
│   ├─── automaton
│   │   ├───  fsa.py
│   │   ├───  __init__.py
│   │   ├───  state.py
│   │   ├───  nfa.py
│   │   └───  dfa.py
│   ├─── utils
│   │   ├───  observation_table.py
│   │   ├───  __init__.py
│   │   └───  utils.py
│   ├───  inferrer.py
│   └───  __init__.py
├───  inferrer_cli.py
├───  README.md
├───  Pipfile
├───  Pipfile.lock
└───  .gitignore

12 directories, 39 files
```

## Resources
This program was inspired by the Linux [tree](https://linux.die.net/man/1/tree) command. 

