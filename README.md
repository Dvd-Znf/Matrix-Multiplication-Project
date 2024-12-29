# The Matrix Multiplication Project
![GitHub Release](https://img.shields.io/github/v/release/Dvd-Znf/Matrix-Multiplication-Project?include_prereleases&logo=GitHub&label=Latest%20release%20version%3A&color=lightgreen)     
Multiplication, Addition and Tracing of matrices of your chosing  
![Screenshot](/Screenshot.png)  
> [!WARNING]
> I plan to do a, MASSIVE amount of refactoring to the code base to account for propper Object-Oriented Programing paradigm.      
>     
> Until this notice is removed, consider the master branch unstable.     
## About:
mmp is a simple yet _cool_ CLI program that allows you to do _cool_ stuf with matrices, for your math class or whatever else   
It can be invoked from the terminal by using  `$ mmp`    
It's made in C++ and it features the readline library for it's CLI interface, this means:   
You can view history by moving up and down with the arrow keys      
And you can press TAB for autocompletion just like in bash!    
## Posible function:
Help - show posible commands  
Version - show current installed version  
New - register a new value for an integer or matrix  
Show - show a integer or a matrix  
Addition - show the sum of two matrices  
Transpose - show transpose of a matrix     
Trace - show the trace of a matrix  
Multiplication - multiply a matrix by an integer or by another matrix  
## To be added:
- [ ] Verbose mode/switch         
- [ ] Non-interactive(inline) mode
- [ ] Package for AUR    
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
