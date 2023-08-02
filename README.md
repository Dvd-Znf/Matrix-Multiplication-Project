# The Matrix Multiplication Project
Multiplication, Addition and Tracing of matrices of your chosing  
![Screenshot](/Screenshot.png)  
## About:
mmp is a simple yet _cool_ CLI program that allows you to do _cool_ stuf with matrices, for your math class or whatever else   
It can be invoked from the terminal by using  `$ mmp`    
It's made in C++ and it features the readline library for it's CLI interface, this means:   
You can view history by moving up and down with the arrow keys      
And you can press TAB for autocompletion just like in bash!    
## Posible function:
Help - show posible commands  
New - register a new value for an integer or matrix  
Show - show a integer or a matrix  
Addition - show the sum of two matrices  
Trace - show the trace of a matrix  
Multiplication - multiply a matrix by an integer or by another matrix  
## To be added:
Add signal interupt handling     
Verbose mode/switch     
Non-interactive mode, which should be compatible with the Unix pipeline    
## How to install
### Dependecies:
- readline (library probably already included, if you use bash)    
- figlet   
- lolcat   
- cmake (build)   
You can install these from your package manager  
Ex:  
```console  
# apt install figlet lolcat cmake  
# pacman -S figlet lolcat cmake  
```
etc..  
### Build and install from source:
Requires gcc and cmake  
  
Build and install:  
```console   
$ git clone https://github.com/Dvd-Znf/Matrix-Multiplication-Project.git
$ mkdir Matrix-Multiplication-Project/build && cd Matrix-Multiplication-Project/build
$ cmake ..
# make install
```

## Thank you for reading my project <3
