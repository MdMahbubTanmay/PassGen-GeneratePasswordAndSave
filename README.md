PassGen: Offline Password Generator V1.69
*Whats New In 1.69:
  *Reset Password Option Added.
  *Reset Full tool option added
  *Bugs fixed for windows devices
  *Logics Improved
PassGen is a simple and secure offline password management tool built in C. It allows you to generate strong, random 
passwords, assign unique titles to them, and save them directly to your local machine.

[![Interface](https://i.postimg.cc/0yvRnP8Z/Screenshot-20250906-131732.jpg)](https://postimg.cc/dL5xtMZT)

Features:
 * Offline-first: All data is stored locally on your device, ensuring your passwords are never exposed to the internet.
 * Strong Password Generation: Creates strong, randomized passwords using a simple algorithm.
 * Local Encryption: Your saved passwords and titles are stored in a binary format, providing a basic level of encryption to protect your data.
 * Session Protection: The application is protected by a password, which you set on first run, to prevent unauthorized access.
 * Password Management:
   * View a list of all saved passwords with their titles.
   * Add new passwords and assign them a unique title.
   * Edit existing passwords and their titles.
 * Cross-platform Compatibility: Supports both Windows and Unix-based systems (like Linux and macOS).
Getting Started
Prerequisites
 * A C compiler (e.g., GCC or Clang).
How to Compile
To compile the source code, open your terminal or command prompt, navigate to the directory where you saved the code, and run the following command:
'''gcc -o PassGen passgen.c'''

This command compiles the main.c file and creates an executable named PassGen.
How to Run
After compiling, you can run the application from your terminal:
'''./PassGen'''

Note: If you are using Windows, you may need to uncomment the #include <windows.h> line at the top of the main.c file before compiling.
Usage
On the first run, the application will prompt you to set a master password to protect the tool. Remember this password, as you'll need it every time you want to access your saved passwords.
Once you enter the correct master password, you will be presented with a menu of options to manage your passwords. Simply follow the on-screen instructions to interact with the tool.
Developer's Note
This is a personal project, so feel free to explore the code and suggest improvements. If you encounter any bugs or have ideas for new features, please submit a bug report or pull request.
 * Author: Md Mahbub Tanmay
 * GitHub: github.com/MdMahbubTanmay
