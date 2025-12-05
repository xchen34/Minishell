# 💻 Minishell - Custom Command Interpreter

| Attribute | Description |
| :--- | :--- |
| **Project Goal** | Build a simple, custom version of the Bash shell. |
| **Language** | C (Adherence to Norm). |
| **Technical Focus** | Process Management (`fork`, `execve`, `wait`), File Descriptors, Lexical Parsing. |
| **Memory Constraint** | All heap-allocated memory must be properly freed (No leaks tolerated in own code). |

## 🎯 Mandatory Implemented Features

The Minishell must replicate the essential functionality of Bash, ensuring correct execution and environment handling:

### 1. Execution & Process Control
**Execution:** Search and launch executables using the `PATH` environment variable, as well as relative or absolute paths
**Pipes (`|`):** Implement pipelines where the output of one command is connected to the input of the next.
**Signals (Interactive Mode):** Handle keyboard signals as follows:
    * `ctrl-C` (`SIGINT`): Displays a new prompt on a new line.
    * `ctrl-D` (`EOF`): Exits the shell.
    * `ctrl-\` (`SIGQUIT`): Does nothing.

### 2. I/O Redirections
The shell must correctly implement the following I/O stream redirections:
* `<`: Redirects input.
* `>`: Redirects output.
* `>>`: Redirects output in append mode.
* `<<<`: Handles **heredoc** (reading input until a specified delimiter is seen).

### 3. Quoting & Expansion
**History:** Must maintain a working command history.
**Quotes:** Implement both single (`'`) and double (`"`) quotes for string literalization.
**Variable Expansion:** Expand environment variables (`$VAR`) and the exit status variable (`$?`) to their corresponding values.
* *(Note: Single quotes prevent all interpretation; double quotes prevent all interpretation except for `$`).*

### 4. Built-in Commands
The shell must implement its own versions of the following standard built-in commands
* `echo` with option `-n`
* `cd` (relative or absolute path only)
* `pwd`
* `export`
* `unset`
* `env`
* `exit`

## 🛠️ How to Run

1.  **Compilation:**
    ```bash
    make
    ```
2.  **Execution:**
    ```bash
    ./minishell
    ```
3.  **Use:** The shell will display a prompt and is ready to accept commands.

