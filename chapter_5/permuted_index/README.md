# Permuted Index

## Strategy

1. Read in each line
  - Must be able to handle arbitrary number of lines
  - functions: read_data
2. Create rotations for each line
  - Lines with n words will have n rotations
  - Append the beginning with spaces
  - functions: create_rotations, append_spaces, get_num_words
3. Sort the rotations
  - functions: compare
4. Unsort the rotations
  - Check to see if the first word is one of the original first words
  - Double check to make sure that the phrase is the same (just in case multiple
    phrases start with the same word)
  - functions: unsort (check_first_word, check_phrase)
5. Write the phrases correctly
  - functions: print_vec

* Use header files and break up the code into multiple files
