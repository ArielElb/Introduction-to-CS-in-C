#include <string.h>
#include <stdio.h>

#define  SIZE_OF_STR 336
#define  OPTIONS 16
#define  OPTIONS_LEN 21
#define  CLUE_LEN 21
#define  MAX_TRIES 5
#define  MAX_LETTERS_TRIES 25
#define  CASE_ZERO 0
#define  CASE_ONE 1
#define  CASE_TWO 2
#define  CASE_THREE 3
#define  CASE_FOUR 4
#define  CASE_FIVE 5

/********************************************************************************************************************
* Function name: printFace
* Input: int errorsCounter (valid values ->intnumber  0 - 5.
* Output: void .
* Function Operation: printing the face for each case depending on how many mistakes/errors the user did by using
 * switch case.
********************************************************************************************************************/
void printFace(int errorsCounter) {
    switch (errorsCounter) {
        case CASE_ZERO:
            printf(" _________________\n"
                   "|                |\n"
                   "|                |\n"
                   "|                |\n"
                   "|                |\n"
                   "|                |\n"
                   "|________________|\n");
            break;
        case CASE_ONE:
            printf(" _________________\n"
                   "|                |\n"
                   "|  **            |\n"
                   "|  **            |\n"
                   "|                |\n"
                   "|                |\n"
                   "|________________|\n");
            break;
        case CASE_TWO:
            printf(" _________________\n"
                   "|                |\n"
                   "|  **        **  |\n"
                   "|  **        **  |\n"
                   "|                |\n"
                   "|                |\n"
                   "|________________|\n");
            break;
        case CASE_THREE:
            printf(" _________________\n"
                   "|  --            |\n"
                   "|  **        **  |\n"
                   "|  **        **  |\n"
                   "|                |\n"
                   "|                |\n"
                   "|________________|\n");
            break;
        case CASE_FOUR:
            printf(" _________________\n"
                   "|  --        --  |\n"
                   "|  **        **  |\n"
                   "|  **        **  |\n"
                   "|                |\n"
                   "|                |\n"
                   "|________________|\n");
            break;
        case CASE_FIVE:
            printf(" _________________\n"
                   "|  --        --  |\n"
                   "|  **        **  |\n"
                   "|  **        **  |\n"
                   "|                |\n"
                   "| \\/\\/\\/\\/\\/\\/\\  |\n"
                   "|________________|");
            break;
            //if errorCounter don't match any case so brake.
        default:
            break;
    }
}

/******************************************************************************************************************
* Function name: gameRun
* Input:const char* arr,char* clue arr <= 21, clue <= 21
* Output: void
* Function Operation: Prints face based on num of errors, asks if user wants clue by inputting '*',if yes show him
* the clue.
* print letters already guessed: The letters that you already tried :a , b , c , d...(example).
* prompts for user guess. If incorrect guess, increment errors counter, add guess to the array of letters that
* already guessed.
* Once reached 5 errors, lose and print message: The word is ******, good job!.
* If guessed whole word, win and print message:The word is ******, GAME OVER! .
*****************************************************************************************************************/
void gameRun(const char* arr, char* clue) {
    int isLetterGuessed;
    int isClueAsked = 0;
    char lettersGuessed[MAX_LETTERS_TRIES] = { 0 };
    // arr for new word
    char finalWord[MAX_LETTERS_TRIES] = { 0 };
    int numOfGuesses = 0;
    int errorsCounter = 0;
    //flag for checking if user entered '*' (for not rising up the errors counter).
    int isAsteriskEntered;
    //init the guess
    char guess = '\0';
    //the word length (without the /0) .
    int wordLen = strlen(arr);

    /*
    * initialize the array with '_';
    */
    for (int j = 0; j < wordLen; j++) {
        finalWord[j] = '_';
        if (arr[j] == ' ') {
            finalWord[j] = ' ';
        }
    }
    /*
    * the while loop of the game that running until the user won or did five errors/mistakes and lost.
    */
    while (errorsCounter < MAX_TRIES) {
        //flag to check if the letter already guessed.
        isLetterGuessed = 0;
        /*
        * flag to check if '*' is already entered . for not counting it in the array of the letters
        * that guessed.
        */
        isAsteriskEntered = 0;
        //print the face
        printFace(errorsCounter);
        /*
         *for that printing the final word
         */
        for (int i = 0; i < wordLen; i++) {
            printf("%c", finalWord[i]);
        }
        printf("\n");
        //if the user didn't ask for clue , show the msg.
        if (isClueAsked == 0) {
            printf("do you want a clue? press -> *\n");
        }
        printf("The letters that you already tried:");
        /*
        * a for loop that printing the letters the user already guessed.
        */
        for (int j = 0; j < numOfGuesses; j++) {
            if (j == 0) {
                printf(" %c", lettersGuessed[j]);
                continue;
            }
            //printing the letters that the user guessed from j = 1;
            printf(", %c", lettersGuessed[j]);
        }

        printf("\n");
        /*
        *checking if he asked for clue already and if the guess is "*".
        * if he didnt asked for clue ---> show him the clue.
        */
        if (guess == '*' && isClueAsked == 0) {
            printf("the clue is: %s.\n", clue);
        }
        printf("please choose a letter:\n");
        //clean the buffer to avoid bugs and to get invisible chars.
        //get the guess from the user.
        scanf(" %c", &guess);
        /*
        *check if the user asked for clue during the game.
        */
        if (guess == '*' && isClueAsked == 0) {
            printf("the clue is: %s.\n", clue);
            isClueAsked = 1;
        }
        /*
        * checking if the letter is already guessed.
        * If yes, print a msg telling the user he already guessed the letter and stop the for loop.
        */
        for (int i = 0; i < MAX_LETTERS_TRIES; i++) {
            /*
             if letters guessed flag is 0 meaning that he guessed already.
             */
            if (lettersGuessed[i] == guess) {
                isLetterGuessed = 1;
                printf("You've already tried that letter.\n");
                break;
            }
        }
        /*
        if the word not guessed already and the input isn't "*"
        put the guess in the array of the letters that guessed
        */
        if (guess != '*' && isLetterGuessed == 0) {
            lettersGuessed[numOfGuesses] = guess;
        // moving to the next index for the next letter.
            numOfGuesses++;
        }
        /*
        * a for loop that putting the guess in the finalWord if the guess is in the original word and checks if the
        * original word has '*'.
        */
        for (int i = 0; i < wordLen; i++) {
            if (guess == arr[i]) {
                //if the letter in the word active flag
                isAsteriskEntered = 1;
                finalWord[i] = arr[i];
            }
        }
        /*
        if user entered '*' don't rise up the errors counter.
        */
        if (guess == '*') {
            isAsteriskEntered = 1;
        }
        /*
        * if the user didn't enter '*' and he entered wrong letter, add one to the errors counter.
        */
        if (isAsteriskEntered == 0 && isLetterGuessed == 0) {
            errorsCounter++;
        }
        /*
        * If the combination of the guesses is the original word than print a msg that saying that the user won and
        * shows him the original word than stop the game
        */
        if (strcmp(arr, finalWord) == 0) {
            printFace(errorsCounter);
            printf("The word is %s, good job!", finalWord);
            break;
        }
        /*
        * if the user have five errors/mistakes print the face at case five and print a msg saying that the game
        * ended and show him the original word.
        */
        if (errorsCounter == CASE_FIVE) {
            printFace(errorsCounter);
            printf("\nThe word is %s, GAME OVER!", arr);
            break;
        }
    }
}
/********************************************************************************************************************
* Function name: splitOptions
* Input: char *str, char* clue, char (*arr)[OPTIONS_LEN]
* Output: int counter (number of options).
* Function Operation: Split string until ":", load into variable 'clue'. Split until "," enter loop, load token into
* array, loop  until token equals to NULL , and load all tokens into array.
********************************************************************************************************************/
int splitOptions(char* str, char* clue, char (*arr)[OPTIONS_LEN]) {
    const char splitOne[2] = ":";
    // initializing the first token for the options.
    char *token = NULL;
    const char splitTwo[2] = ",";
    // initializing the second token for the name.
    char *token2 = NULL;
    // getting clue by using str tok func.
    token2 = strtok(str, splitOne);
    strcpy(clue, token2);
    //getting the first token.
    token = strtok(NULL, splitTwo);
    int i = 0;
    int counter = 0;
    /*
     * go through and find other tokens.
     */
    while (token != NULL) {

        strcpy(arr[i], token);
        token = strtok(NULL, splitTwo);
        i++;
        //counting how many names
        counter++;
    }
    return counter;
}

/***********************************************************************************
* Function name: sortLexicographical
* Input: char (*arr)[OPTIONS_LEN], int numOfStr
* Output: void
* Function Operation: Sort user inputted options by lexicographical order by using bobble sort.
***********************************************************************************/
void sortLexicographical(char (*arr)[OPTIONS_LEN], int numOfStr) {
    //creating temp for saving the real arr .
    char arrTemp[OPTIONS_LEN];
    /*
    * bubble sort
    * loops that running on the string and the letters and swapping when need to get a lexicographical order.
    */
    for (int i = 0; i < numOfStr; ++i) {
        for (int j = i + 1; j < numOfStr; ++j) {
            /*
             *swapping the strings to get lexicographical order.
            */
            if (strcmp(arr[i], arr[j]) > 0) {
                //copying the original array at index i into the temp arr.
                strcpy(arrTemp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], arrTemp);
            }
        }
    }
}

int main() {
    //init the str
    char str[SIZE_OF_STR] = { 0 };
    //init two-dim array of the options and the options len.
    char arr[OPTIONS][OPTIONS_LEN] = { 0 };
    char clue[CLUE_LEN] = { 0 };
    //ask the user to enter his string.
    printf("Enter your words:\n");
    scanf("%[^\n]", str);
    //call splitOptions and get the number of options we got
    int numOfStr = splitOptions(str, clue, arr);
    //calling printLexicographical to sort the array.
    sortLexicographical(arr, numOfStr);
    //ask the user to choose an option
    printf("choose an option:\n");
    //printing the options to the user.
    for (int i = 0; i < numOfStr; ++i) {
        printf("%d: %s\n", i + 1, arr[i]);
    }
    //getting the option from the user.
    int userChoice = 0;
    scanf("%d", &userChoice);
    //calling the func that running the game.
    gameRun(arr[userChoice - 1], clue);
}