# Hangman Game in C++

Welcome to the Hangman Game in C++! This is a classic word-guessing game designed to be played right in your terminal window.

## How to Play

1. **Compile the Game:**
   - Make sure you have a C++ compiler installed on your system.
   - Open your terminal and navigate to the project directory.
   - Compile the game using the following command:
     ```bash
     g++ hangman.cpp -o hangman
     ```

2. **Run the Game:**
   - Start the Hangman game by running the compiled executable:
     ```bash
     ./hangman
     ```

3. **Game Rules:**
   - You will be presented with a series of underscores representing a hidden word.
   - Guess letters one at a time by entering them in the terminal.
   - You have a limited number of incorrect guesses (usually 6) before the game is over.
   - If you guess a letter correctly, it will be revealed in the word.
   - Continue guessing until you guess the entire word or run out of guesses.

4. **Winning and Losing:**
   - If you guess the word correctly within the allowed number of tries, you win!
   - If you run out of guesses before revealing the word, you lose.

## Customization

You can customize the game by modifying the word list in the source code (WordGenerator.cpp) or using a build in feature. Feel free to add your own words or themes to make the game more interesting.

## Requirements

- C++ compiler (e.g., g++)
- Terminal or command prompt

## Compatibility

This Hangman game is designed to run on various operating systems, including Windows, macOS, and Linux.

## Contributing

If you'd like to contribute to this project, feel free to submit pull requests or open issues. Your contributions and feedback are greatly appreciated!

## License

This project is open source.

Have fun playing Hangman in your terminal! If you encounter any issues or have suggestions for improvement, please let us know.
