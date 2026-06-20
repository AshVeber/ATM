# ATM (Automated Teller Machine)
ATM is a 100% C++ indenpendent, open source backend project for your bank functionality that attracts with its own simplicity, low weight and readable code.

It provides the latest ATM features for your transactions from cash to funds on your card. This project is **not** just some ATM! This is the whole **system** in some code lines that can download and upload the data about **you** on "AV" company' server! It does not stand still and keeps pace with technological progress!

## Thank YOU for choosing US! 

# WELCOME TO ATM
"AV" company focuses on the convenience andhigh functionality of its products. While other ATMs offer ony dull, utilitarian features, WE invite YOU to step into the shoes of an IT SPECIALIST and run our project via the terminal. The task may seem simple but that's only on paper!
So, why us? Good question!
## OUR ATM IS ABOUT:
- simplicity (some 253 code lines)
- cross-platform capability (Windows, Linux, Android, whatever.)
- open source


# QUICK START
## Option 1

### LINUX
*Required dependencies: git, g++ compiler, CMake (version 4.3.3 or higher)*

#### Step 1:
Open the terminal and run those commands.

*Install Cmake*

Arch Linux:
```
# Bash
sudo pacman -S cmake
sudo yay -S cmake
```
Ubuntu-based/Debian:
```
# Bash
sudo apt install cmake
```
*Install g++ compiler*

Arch Linux:
```
# Bash
sudo pacman -S g++
sudo yay -S g++
```
Ubuntu-based/Debian:
```
# Bash
sudo apt-get install g++
```
*Install git*

Arch Linux:
```
# Bash
sudo pacman -S git
sudo yay -S git
```
Ubuntu-based/Debian:
```
# Bash
sudo apt install git
```
#### Step 2:

Clone the repository.
```
# Bash
git clone REPOSITORY
```

#### step 3:

Find the path to the repository.
```
# Bash
find -name "ATM"
```
Write this commands
```
# Bash
cd <YOUR_PATH_TO_ATM>
mkdir build && cd build
cmake ..
make
./ATM
```
*ENJOY!*


### WINDOWS (Did not tested)
*Required dependencies: git, VScode, CMake (version 4.3.3 or higher)*

#### Step 1:

*Install git*
> https://git-scm.com/install/windows

*Install VScode*
> https://code.visualstudio.com/download?_exp_download=fb315fc982

*Install CMake*
>https://cmake.org/download/

#### Step 2:
- Run the VScode.
- Download "CMake Tools" and "C/C++ Extension Pack" from Extensions (CTRL+SHIFT+X)
- Create folder.
- Create ".vscode" folder in previous folder.
- Open VScode and create "tasks.json" in ".vscode" and write this:
```
  {
    "version":"2.0.0",
    "tasks": [
        {
            "label":"Build and Run C++",
            "type":"shell",
            "command":"g++",
            "args": ["${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}.exe", "&&", "${fileDirname}\\${fileBasenameNoExtension}.exe"],
            "problemMatcher":["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```
#### Step 3:
Clone the repository using git
```
# Bash
git clone <REPOSITORY>
```
Write this commands
```
# Bash
cd <YOUR_PATH_TO_ATM>
mkdir build
cd build
cmake ..
cmake --build .
```
*ENJOY!*

### MacOs (did not tested)
*Required dependencies: compiler, CMake (version 4.3.3 or higher)*

#### Step 1:

*Install compiler*
```
# Bash
xcode-select --install
```

*Install CMake*
(Install Homebrew before)
```
# Bash
brew install cmake
```
#### Step 2:
Follow this commands:
```
# Bash
git clone <REPOSITORY>
cd ATM
mkdir build
cd build
cmake ..
make
./ATM
```
*ENJOY!*

# LICENSE
MIT - See individual plugin licenses in their respective directories.

# ABOUT OWNER
## *Ash Veber*
The young prorammer with huge potential! Ash interests ML engineering, devops, backend, frontend and ...BLENDER! You can ask Ash to write your dream code just for €5-10 per service!

### Veber's contacts
Telegram: @Tolfee
email: ashveber42@gmail.com
