# langX

It's a script language. I made it for quick developing.



## Directory

1. `3rd`
   1. Simple notepad config files.
2. `cmake`
   1. `cmake` search files. (**.cmake*)
3. `docs`
   1. Document. (English and Chinese.)
4. `extern`
   1. Lex and yacc files.
   2. Lex and yacc generated files.
5. `include`
   1. Headers.
6. `source`
   1. Sources.
7. `lib`
   1. Extra libraries files.
   2. This will be deleted.
8. `mod`
   1. Nothing
9. `modProjects`
   1. langX mods
   2. core/mysql/python-bridge/redis/...
10. `rtlib`
    1. Runtime library. (WIP)
    2. May all write by langX.
11. `scripts`
    1. Test scripts.
    2. Example scripts.
12. `notImplementation`
    1. Just ideas.



## Compile and install

1. Please read section `Dependent` first.

2. Install `flex`,`bison`,`log4cpp`.  

3. Install `cmake`.

4. ```shell
   mkdir build && cd build
   cmake ..
   make
   sudo make install 
   ```

5. Now, the simplest program is installed, you can use `langX [filename]` to test it.
6. Note: langX do not have any options now(**include --version**).
7. You can try to compile mods now. 



## Dependent

### simple runable program

- flex
- yacc(bison)
- Log4cpp

### lib core

- Nothing



### lib mysql

- mysql-devel (mysql-connector-c)



### lib python

- python-devel



### lib redis

- hiredis



### lib zip

- zlib



### lib json

- cjson



## Others

**PR and Issue is welcome!**

