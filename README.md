# Blas Harvard CS50x

### Welcome! This is my Harvard's CS50 walkthrough!
This project contains two main branches that provide different configurations for compiling and running the code. The two branches are:

### **CS50 Branch**

The **CS50** branch is tailored to emulate the CS50 environment, using the `clang` compiler and the CS50 C library. This branch is primarily for users who want to work in a setup similar to the CS50 environment. If you are following the CS50 course or prefer using the CS50 library, this is the branch you should work with.

#### What's Included in the CS50 Branch:
This branch contains completed course files and is configured to match the CS50 environment used during the course. Here’s what you’ll find:

- **`clang`**:  
  We use `clang` as the default C compiler, which is preferred in the CS50 environment. Please make sure you have it installed in order to proceed.

- **Environment Variables**:  
  The environment is set up with specific environment variables that replicate the CS50 workflow, making it easier to compile and run your code. These include configurations for `clang` and the CS50 C library.  
  After cloning the repository, make sure to run the `setup_env.sh` script to automatically set up the environment variables. This will ensure that your setup mirrors the CS50 environment correctly and that everything is configured for compiling and linking with `clang` and the CS50 C library.  
  You can do this by running the following command in your terminal:
  
  ```bash
  source setup_env.sh
  ```

  This will set the necessary environment variables (CC, CFLAGS, LDLIBS) so you can compile your code using the correct flags and libraries. Once the script is sourced, you can use the make command to compile your C files. Simply run the following command:

  ```bash
  make <filename>
  ```

- **CS50 C Library**:  
  We utilize the CS50 C library, which provides helpful functions like `get_int()`, `get_string()`, and more. These functions simplify user input and string manipulation, making development more straightforward.

For more information on the CS50 C library, check out the official documentation:  
[CS50 Library for C](https://cs50.readthedocs.io/libraries/cs50/c/)


### **Standard Branch**

The **Standard** branch uses a more general configuration with standard C libraries. If you prefer working with the built-in C libraries or want to ensure your code is portable to different environments, this branch is a great choice.

#### What's Included in the Standard Branch:
Here’s what you can expect from this branch:

- **Standard C Libraries**:  
  This branch utilizes the built-in C libraries, such as `stdio.h`, `string.h`, and other common C libraries that are supported by all C compilers.

- **Compiler Flexibility**:  
  You can compile your code using any C compiler you prefer, such as `clang`, `gcc`, or any other compatible compiler. You may need to manually specify your compiler and compiler flags for different environments.

- **No External Libraries**:  
  Unlike the CS50 branch, this one doesn’t rely on external libraries like the CS50 library. It uses only basic functions from standard libraries, which ensures greater portability.

If you prefer working with standard C libraries or need your code to be more portable across different systems, this branch will serve your needs well.

### Cloning the Repository
```bash
git clone https://github.com/yourusername/project-name.git
cd project-name
```

## Conclusion

This project wouldn’t have been possible without the incredible learning experience I had with the **CS50 course**. A huge thank you to **David Malan** and the entire **CS50 staff** for their dedication to making computer science education accessible, engaging, and fun. The environment provided by CS50 and the tools they’ve introduced — like the `clang` compiler and the CS50 C library — played a crucial role in shaping the way I approach programming today.

To everyone who clones and tries out this project — thank you! Whether you're a fellow CS50 student, a seasoned programmer, or someone new to C programming, I hope this repository serves as a helpful resource in your journey. I’ve created this project to share the setup that worked for me and to make it easier for others to replicate the CS50 environment, but also to encourage exploration and experimentation with standard C libraries.

I encourage you to explore, modify, and build upon this project in your own unique way. Your efforts, questions, and feedback are always appreciated, and I hope this repository can continue to be a stepping stone in your learning.

Remember, programming is about persistence, creativity, and collaboration. Thank you again for being part of this process, and good luck with your coding journey!

Happy coding! 🌟
