# 🌙 lucid-shell  
A lightweight custom UNIX shell written in C.  
Supports built-in commands, environment variables, PATH searching, parsing, and basic shell behavior — all coded from scratch.

---

## ✨ Features

### 🔧 Built-in Commands
- `cd` — change directory  
- `pwd` — print working directory  
- `echo` — supports normal text + `$ENV` variables  
- `env` — list environment variables  
- `setenv` — set environment variable  
- `unsetenv` — unset environment variable  
- `which` — detect built-in or external command  
- `exit` / `quit` — exit the shell  

### 🧠 Shell Capabilities
- Token-based input parsing  
- PATH-based external command searching  
- Custom implementations:
  - `my_strdup`
  - `my_strcmp`
  - `my_strcpy`
  - `my_strlen`
  - `my_strncmp`
- Environment variable handling via `my_getenv`  
- Error handling for invalid commands  
- Clean memory management  

---

## 📁 Project Structure
<br>
├── Makefile<br>
├── README.md<br>
└── src/<br>
&emsp;├── main.c<br>
&emsp;├── input_parser.c<br>
&emsp;├── builtins.c<br>
&emsp;├── executor.c<br>
&emsp;├── helper.c<br>
&emsp;└── myshell.h<br>

---

## 🛠️ Build Instructions

Compile the shell:

```bash
make
```
## 🎬 Usage

To start the shell, run the compiled executable from your project directory:

```bash
./shell
```
## 🛠️ Make Build Clean

```bash
make clean
```
---

## ▶️ Usage Examples
Navigation
```bash
[lucid-shell]> pwd
/home/user
[lucid-shell]> cd src
```
Echo
```bash
[lucid-shell]> echo hello world
hello world
```
View Environment
```bash
[lucid-shell]> env
PATH=/usr/bin:/bin:...
HOME=/home/username
```
Which Command
```bash
[lucid-shell]> which ls
/usr/bin/ls

[lucid-shell]> which cd
cd: built in command
```
Exit
```bash
exit
or
quit
```
---
## 📝 Requirements
- `GCC or Clang`
- `Linux, Unix, or WSL`
- `Basic C understanding`
