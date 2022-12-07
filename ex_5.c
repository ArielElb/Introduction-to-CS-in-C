/***********************
* Name: Ariel Elbaz.
* ID: 213073497.
* Assignment: ex_5.
***********************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define OPTION_NOT_AVAILABLE "This option is not available right now, try again:\n"
#define WRONG_OPTION "Wrong option, try again:\n"
#define USER_CONFIRMATION "Are you sure? (y/n)\n"
#define DEFINE_DICTIONARY "Define a new dictionary:\n"
#define DICTIONARY_CREATED_SUCCESSFULLY "The dictionary has been created successfully!\n"
#define DICTIONARY_CREATION_FAILED "The creation of the dictionary has failed!\n"
#define CHOOSE_DICTIONARY "Choose a dictionary:\n"
#define ENTER_WORD_IN "Enter a word in "
#define WORD_ADD_SUCCEED "The word has been added successfully!\n"
#define WORD_ADD_FAILED "The addition of the word has failed!"
#define DELETION_WORD_SUCCEED "The word has been deleted successfully!\n"
#define DELETION_WORD_FAILED "The deletion of the word has failed!\n"
#define DELETION_WORD_CANCELED "The deletion of the word has been canceled.\n"
#define SEARCH_FAILURE "The search has failed successfully!"
#define THE_TRANSLATIONS_ARE "The translations are:\n"
#define NO_TRANSLATIONS "There are no translations for \"%s\" in this dictionary.\n"
#define DELETE_DICTIONARY_SUCCEED "The dictionary has been deleted successfully!\n"
#define DELETE_DICTIONARY_CANCELED "The deletion of the dictionary has been canceled.\n"
#define DELETE_DICTIONARY_FAILED "The deletion of the dictionary has failed!\n"
#define EXIT_MSG "Bye!\n"

typedef struct Word {
    char** translations;
    struct Word* next;
} Word;

typedef struct {
    char** languages;
    int numOfLanguages;
    Word* wordList;
} Dictionary;


/*********************************************************************************************************************
* Function name: freeArrOfPtr
* Input: char** str,int size (size of the arr)
* Output: void
* Function Operation: free the languages/translations of the word using for loop to free every pointer at his
 * index. and then free the pointer to the array of pointers.
**********************************************************************************************************************/
void freeArrOfPtr(char** str, int size){

    /*
     * loop to free the pointer at the arr in every index.
     */
    for (int i = 0; i < size;i++ ) {
        free(str[i]);
        str[i] = NULL;
    }
    //free the ptr to the arr of pointers.
    free(str);
    str = NULL;
}

/*********************************************************************************************************************
* Function name: freeWord
* Input: Word* wordToFree, Dictionary *chosenDict
* Output: void
* Function Operation: call the function that free the translations and than free the word itself,
**********************************************************************************************************************/
void freeWord(Word* wordToFree, Dictionary *chosenDict) {

    /*
     * if the word isn't NULL free the translations of the word.
     */
    if (wordToFree) {
        //free translations( the array of arrives isn't assigned dynamically that's why I can free).
        freeArrOfPtr(wordToFree->translations, chosenDict->numOfLanguages);
    }
    //free the struct Word after freed all the other pointers in the struct.
    free(wordToFree);
    wordToFree = NULL;
}

/*********************************************************************************************************************
* Function name: freeList
* Input: Word* head,Dictionary* chosenDict
* Output: void
* Function Operation: free the list of the words by using a while loop and iterating over the linked list.
**********************************************************************************************************************/
void freeList(Word* head,Dictionary* chosenDict) {

    /*
     * iterating over the list and deleting the words.
     */
    while (head) {
        Word* next = head->next;
        freeWord(head,chosenDict);
        head = next;
    }
}

/*********************************************************************************************************************
* Function name: freeDictionary
* Input: Dictionary* chosenDict
* Output: void
* Function Operation: free pointers in the Dictionary by call the functions freeList and freeArrOfPtr.
**********************************************************************************************************************/
void freeDictionary(Dictionary* dictionary){
    if (dictionary->languages != NULL)
        freeArrOfPtr(dictionary->languages, dictionary->numOfLanguages);
    if (dictionary->wordList != NULL)
        freeList(dictionary->wordList, dictionary);
}

/*********************************************************************************************************************
* Function name: printDictionary
* Input: Dictionary* dictionaryToPrint
* Output: void
* Function Operation: the function printing the languages of the dictionary.
**********************************************************************************************************************/
void printDictionary(Dictionary dictionaryToPrint) {
    char **lang;
    lang = dictionaryToPrint.languages;

    /*
     * print the languages in the dictionary.
     */
    for (int i = 0; i < dictionaryToPrint.numOfLanguages; ++i) {
        if (i == dictionaryToPrint.numOfLanguages - 1){
            printf("%s", lang[i]);
        }
        else {
            printf("%s,", lang[i]);
        }
    }
}

/*********************************************************************************************************************
* Function name: printDictionaries
* Input: Dictionary* dictionaries, const int* numOfDictionaries
* Output: void
* Function Operation: the function printing all the dictionaries by using for loop and iterating over the array of
 * the dictionaries.
**********************************************************************************************************************/
void printDictionaries(Dictionary* dictionaries,const int* numOfDictionaries) {

    /*
     * print the dictionary for each index i in the array of dictionaries.
     */
    for (int i = 0; i < (*numOfDictionaries); i++) {
        printf("%d. ",i+1);
        //printing the dictionary at index i ,in the arr of dictionaries.
        printDictionary(dictionaries[i]);
        printf("\n");
    }
}


/*********************************************************************************************************************
* Function name: printLangAndTrans
* Input: Dictionary* chosenDict,Word* head
* Output: void
* Function Operation: the function print the language and the translation for the word in that language by using for
 * loop.
**********************************************************************************************************************/
void printLangAndTrans(Dictionary* chosenDict,Word* head){
    Word* current = head;

    /*
     * printing the remaining languages and translations.
     */
    for (int i = 1; i < chosenDict->numOfLanguages; i++) {
        printf("%s: ", chosenDict->languages[i]);
        if (i < chosenDict->numOfLanguages -1)
            printf("%s, ", current->translations[i]);
        else
            printf("%s", current->translations[i]);
    }
    printf("\n");
}


/*********************************************************************************************************************
* Function name: chosenDictionary
* Input: Dictionary* dictionaries,int* numOfDictionaries
* Output: Dictionary* chosenDict
* Function Operation: the function  printing the dictionaries and asks the user to choose a dictionary and returns the
 * dictionary in the array of dictionaries that he chose.
 * if the user enter a number of dictionary that isn't exist , print error msg to the user and ask for another choice.
**********************************************************************************************************************/
Dictionary* chosenDictionary(Dictionary* dictionaries,int* numOfDictionaries){
    int userChoice;
    //calling the function that printing the dictionary.
    printDictionaries(dictionaries, numOfDictionaries);
    scanf("%d",&userChoice);

    /*
     * if the user enter a number of dictionary that isn't exist , print error msg to the user and ask for another
     * choice.
     */
    while (userChoice > *numOfDictionaries || 0 >= userChoice){
        printf(WRONG_OPTION);
        scanf("%d",&userChoice);
    }
    //initialize the dictionary the user chose and return him.
    Dictionary* chosenDict = &dictionaries[userChoice-1];
    return chosenDict;
}

/*********************************************************************************************************************
* Function name: getStr (some of the function taken from the TIGBUR WITH EYAL)
* Input: void
* Output: char* str
* Function Operation: the function getting a string from the user and allocating memory dynamically by using
 * reallocate until user enters -Enter  .
 * the function return that string in purpose to cut him later.
**********************************************************************************************************************/
char* getStr() {
    char* str = NULL;
    int sizeOfArr = 0;
    /*
     * allocating memory dynamically into an array of chars until user enters Enter
     */
    do {
        sizeOfArr++;
        char* tmp = str;
        //allocate new space of memory of size of char(1).
        str = realloc(str, sizeOfArr * sizeof(char));

        /*
         * check if allocation failed ,if yes - free the tmp pointer to the str and return NULL.
        */
        if (str == NULL) {
            free(tmp);
            return NULL;
        }
        scanf("%c", &str[sizeOfArr - 1]);
        //in case the  first char if we got \n wait for another char.
        if(str[0] == '\n' && sizeOfArr == 1) {
            scanf("%c", &str[sizeOfArr - 1]);
        }
    } while (str[sizeOfArr - 1] != '\n');
    //put \0 in the last index to let the compiler know the arr ended there.
    str[sizeOfArr - 1] = '\0';
    return str;
}

/*********************************************************************************************************************
* Function name: getStr
* Input: void
* Output: char* str
* Function Operation: the function getting a string from the user and allocating memory dynamically by using
 * reallocate until user enters -Enter  .
 * the function return that string in purpose to cut him later.
**********************************************************************************************************************/
char** arrOfString(char *str, int* counterOfWord) {
    //save temp pointer
    char** tempPtr = NULL;
    //temp ptr to the malloced allocated word.
    char* tmpWord = NULL;
    // initializing the first token for the options.
    char *token = NULL;
    char** arrOfPointers = NULL;
    const char splitOne[2] = ",";
    //getting the first token.
    token = strtok(str, splitOne);
    *counterOfWord = 0;

    /*
     * go through and find other tokens.
     */
    while (token != NULL) {
        //temp pointer to save the array if the new allocation  failed.
        tempPtr = arrOfPointers;
        arrOfPointers = (char **) realloc(arrOfPointers, ((*counterOfWord) + 1) * sizeof(char *));

        /*
         * if the allocation failed,print msg to the user and return the backup pointer.
         */
        if (arrOfPointers == NULL) {
            printf("The creation of the dictionary has failed!\n");
            freeArrOfPtr(arrOfPointers, *counterOfWord);
            return tempPtr;
        }
        //allocate new memory for the new word inside the arr.
        char *word = (char *) malloc((strlen(token) + 1) * sizeof(char));
        tmpWord = word;
        if (word == NULL) {
            printf("The creation of the dictionary has failed!\n");
            free(tmpWord);
            return NULL;
        }
        //copy assign the token inside word.
        strcpy(word, token);
        //point to the new word from the arr of pointers
        arrOfPointers[(*counterOfWord)] = word;
        //cut and get a new token for the word.
        token = strtok(NULL, splitOne);
        //counting how many words.
        (*counterOfWord)++;
    }
    //return the updated array of translations/languages
    return arrOfPointers;
}


/*********************************************************************************************************************
* Function name: buildDictionary
* Input: Dictionary* dictionaries,const int *numOfDictionaries
* Output: Dictionary dictionaries
* Function Operation: the function getting called in the function addDictionary.
* the purpose of the function is to assign the languages and the numOfLanguages into their field  in the
 * dictionary.
* the function calling getStr to get the long string of the user and than creating array of pointers to strings by
* calling arrOfString function.
**********************************************************************************************************************/
Dictionary * buildDictionary(Dictionary* dictionaries,const int *numOfDictionaries) {
    printf(DEFINE_DICTIONARY);
    //counting how many languages  there are.
    int counterOfLang = 0;

    /*
     * if the allocation didn't fail go through.
     */
    if (dictionaries != NULL) {
        //calling the func to get the long string from the user
        char *userStr = getStr();
        //split the str into the arr Of pointers to these strings.
        char **languages = arrOfString(userStr, &counterOfLang);
        //put the array of string inside languages.
        dictionaries[(*numOfDictionaries) - 1].languages = languages;
        //update the number of languages the dictionary have.
        dictionaries[(*numOfDictionaries) - 1].numOfLanguages = counterOfLang;
        dictionaries[(*numOfDictionaries) - 1].wordList = NULL;
    //free the user string that allocated with reallocate and the array of strings.
    free(userStr);
    userStr = NULL;
    }
    return dictionaries;
}


/*********************************************************************************************************************
* Function name: addDictionary
* Input: Dictionary* dictionaries,int *numOfDictionaries
* Output: Dictionary dictionaries
* Function Operation: the function adding a new dictionary to the array of dictionaries by reallocating memory for
 * the new dictionary.
 * the function also calling buildDictionary function in purpose to fill the dictionary languages and update the
 * number of languages in the dictionary
**********************************************************************************************************************/
Dictionary* addDictionary(Dictionary* dictionaries,int *numOfDictionaries) {

    /*
     * initialize the pointer dictionaries when there are no dictionaries to avoid bugs.
     */
    if (*numOfDictionaries == 0)
        dictionaries =  NULL;
    //temp ptr to dictionaries.
    Dictionary* tmpPtrToDictionaries = NULL;
    tmpPtrToDictionaries = dictionaries;
    //allocate space for  a new dictionary in the array of dictionaries.
    dictionaries = (Dictionary*)realloc(dictionaries, ((*numOfDictionaries) + 1) * (sizeof(Dictionary)));
    //increase the number of dictionaries.
    (*numOfDictionaries)++;
    /*
     * if  the allocation failed return the temporary pointer to the array of dictionaries.
     */
    if (dictionaries == NULL) {
        printf(DICTIONARY_CREATION_FAILED);
        return tmpPtrToDictionaries;
    }
    //call the function that fills the fields in the new dictionary
    dictionaries = buildDictionary(dictionaries,numOfDictionaries);
    //print a msg if the dictionary built successfully.
    printf(DICTIONARY_CREATED_SUCCESSFULLY);
    return dictionaries;
}


/*********************************************************************************************************************
* Function name: buildWord
* Input: void
* Output: Word* (the Word to add to the list)
* Function Operation: the function allocate new memory in size of the struct Word,and verify that the allocation has
 * not failed.
* secondly, the function calling getStr and arrOfStrings function in purpose to get the word and translations of the
 * word into the dictionary.
 * if the progress went successfully print a msg to the user that the worded ha been added
**********************************************************************************************************************/
Word* buildWord() {
    //a variable to count how many translations there are.
    int counterOfTranslations = 0;
    //allocate memory for new Word struct.
    Word* wordToAdd = (Word*)malloc(sizeof(Word));
    /*
     * if the allocation of the word to add failed print msg to the user
     */
    if (wordToAdd == NULL){
        printf(WORD_ADD_FAILED);
        return NULL;
    }
    //getting the user translations
    char *userStr = getStr();
    //sorting the user translations.
    char** translations = arrOfString(userStr, &counterOfTranslations);
    //assign the new translations into the field in the Word.
    wordToAdd->translations = translations;
    wordToAdd->next = NULL;
    //if the Word is not NULL and didn't fail print a msg to the user.
    printf(WORD_ADD_SUCCEED);
    free(userStr);
    return wordToAdd;
}


/*********************************************************************************************************************
* Function name: addWordToDictionarySetup
* Input: Dictionary* dictionaries,int *numOfDictionaries
* Output: void
* Function Operation: the function adding a new Word struct at the beginning of the Word linked list of the dictionary.
 * The function receive the word to add by calling the function buildWord and adding the word at the begging of the
 * list.
**********************************************************************************************************************/
void addWordToDictionarySetup(Dictionary* dictionaries, int *numOfDictionaries){
    //ask the user to choose a dictionary
    printf(CHOOSE_DICTIONARY);
    Dictionary* chosenDict = chosenDictionary(dictionaries,numOfDictionaries);
    printf(ENTER_WORD_IN);
    printDictionary(*chosenDict);
    printf(":\n");
    //ptr to the list /the head of the list.
    Word* firstWord = NULL;
    firstWord = chosenDict->wordList;
    //getting new struct of Word.
    Word* wordToAdd = buildWord();

    /*
     * if the head isn't pointing to NULL so there is a Word struct in the list.
     */
    if (firstWord != NULL && wordToAdd != NULL){
        //put the next pointer of the existing Word struct to
        wordToAdd->next = chosenDict->wordList;
    }
    chosenDict->wordList = wordToAdd;
}


/*********************************************************************************************************************
* Function name: deleteWord
* Input: Dictionary *chosenDict,char* userWord(the word the user want to delete) ,int* wordFound (flag to check the
 * word is in dictionary)
* Output: void
* Function Operation: case 1: no  words in the dictionary , nothing to delete - return from the function.
 * case 2: remove word from the beginning of the list.
 * case 3: removing a word from the middle of the list or the end.
 * the function iterating over the linked list of the word and searching if the word that user is in there .
**********************************************************************************************************************/
Word *deleteWord(Dictionary *chosenDict,char* userWord,int* wordFound){
    *wordFound = 0;
    //the head of the list(the wordlist ptr)
    Word *head = chosenDict->wordList;
    //initializing current as head
    Word* current = head;
    //ptr to the previous word in the list.
    Word* previous;
    /*
     * if there are no words in the list
     */
    if (head == NULL)
        return head;
        /*
         * removing a word from the beginning of the list.
         * if the word that the user want to delete is in the dictionary go through the condition.
         */
            if (strcmp(current->translations[0],userWord) == 0){
                head = head->next;
                (*wordFound) = 1;
                freeWord(current,chosenDict);
                return head;
        }
        /*
        * a loop for finding the right word in translations
        */
        while (current != NULL && strcmp(current->translations[0], userWord) != 0)  {
            //advance current further and assign prev as current before the advance.
            previous = current;
            current = current->next;
        }
        if (current != NULL) {
            (*wordFound) = 1;
            //the pointer next of prev now pointing to the Word after current(the next pointer of current).
            previous->next = current->next;
            //calling the  function that free the Word wanted to be deleted.
            freeWord(current, chosenDict);
        }
    return head;
}



/*********************************************************************************************************************
* Function name: deleteWordFromDictSetup
* Input: Dictionary* dictionaries,int *numOfDictionaries
* Output: void
* Function Operation: the function calling the function chosenDictionary in purpose to know what word the user
 * want to delete.
 * than, getting the word the user want to delete and calling the function deleteWord to delete the word from the
 * linked list.
 * if the word has found in the dictionary and the user confirmed he want to delete the word, print a message to the
 * user telling him the word has been deleted successfully.
 * otherwise, print a msg telling the deletion of the word has failed.
**********************************************************************************************************************/
void deleteWordFromDictSetup(Dictionary* dictionaries, int *numOfDictionaries) {
    //char to confirm the deletion of the word.
    char userSure;
    printf(CHOOSE_DICTIONARY);
    //call the function that returns the dictionary the user chose.
    Dictionary *chosenDict = chosenDictionary(dictionaries, numOfDictionaries);
    printf(ENTER_WORD_IN);
    //initialize the source language.
    char *sourceLang = chosenDict->languages[0];
    //printing the source language.
    printf("%s:\n", sourceLang);
    //the word the user want to delete
    char* userWord = getStr();
    int wordFound = 0;
    printf(USER_CONFIRMATION);
    //getting the confirmation from the user.
    scanf(" %c", &userSure);
    chosenDict->wordList = deleteWord(chosenDict,userWord,&wordFound);
    /*
     * checking if the user entered y for confirm to delete or n to cancel and.
     */
    if ((wordFound == 0) && userSure == 'y')
        printf(DELETION_WORD_FAILED);
    else if (userSure == 'y' && wordFound == 1) {
            printf(DELETION_WORD_SUCCEED);
    }
    if (userSure != 'y')
        printf(DELETION_WORD_CANCELED);
    //free the user word to avoid  memory leaks.
    free(userWord);
    userWord = NULL;
}


/*********************************************************************************************************************
* Function name: searchWord
* Input: Dictionary* dictionaries,int *numOfDictionaries
* Output: void
* Function Operation: the function getting the first word in the link , if there are no words - print a msg to the
 * user saying there are no translations for his word in the dictionary,
 * iterating over the linked list and searching the user word in the dictionary,
 * if no words has been found print a msg to the user.
**********************************************************************************************************************/
void searchWord(char* userWord,Word* head,Dictionary* chosenDict){
    Word* current = head;
    if (current == NULL) {
        printf(NO_TRANSLATIONS,userWord);
        return;
    }

    /*
     * while the last word isn't NULL go through the linked list and compare the source language of every word
     * with the word the user want to search.
     */
    while (current != NULL ) {
        if (strcmp(current->translations[0], userWord) == 0) {
            printf(THE_TRANSLATIONS_ARE);
            printLangAndTrans(chosenDict,head);
            break;
            //if the word not in the dictionary print msg to the user
        }
        current = current->next;
    }
    if (current == NULL)
    printf(NO_TRANSLATIONS,userWord);
}


/*********************************************************************************************************************
* Function name: searchWordInDictionarySetup
* Input: Dictionary* dictionaries,int* numOfDictionaries
* Output: void
* Function Operation: receive the dictionary want to search a word in.
 * than , get the word the user wanna search from the user. call the function searchWord to make the search.
**********************************************************************************************************************/
void searchWordInDictionarySetup(Dictionary* dictionaries, int* numOfDictionaries) {
    printf(CHOOSE_DICTIONARY);
    //call the function that returns the dictionary the user chose.
    Dictionary *chosenDict = chosenDictionary(dictionaries, numOfDictionaries);
    printf(ENTER_WORD_IN);
    char *sourceLang = chosenDict->languages[0];
    printf("%s:\n", sourceLang);
    char* userWord = getStr();
    /*
     * if the allocation failed = print msg to the user.
     */
    if (userWord == NULL){
        printf(SEARCH_FAILURE);
    }
    searchWord(userWord,chosenDict->wordList,chosenDict);
    //free the user word to avoid  memory leaks.
    free(userWord);
    userWord = NULL;
}

/*********************************************************************************************************************
* Function name: deleteDictionary
* Input: Dictionary* dictionaries,int* numOfDictionaries
* Output: Dictionary* dictionaries
* Function Operation: deleting the dictionary the user chose  from the array of dictionaries .
 * the function getting the number of the dictionary the user want to delete, and than free all the pointers in the
 * selected dictionary.
 * than taking all the every dictionary in the array one index backwards.
 * than reallocate the size of the array less by one and return the updated array from the function.
**********************************************************************************************************************/
Dictionary* deleteDictionary(Dictionary* dictionaries,int* numOfDictionaries) {
    //temp pointer to the array of dictionaries in case the reallocation failed
    Dictionary *tempDict = dictionaries;
    //number of dictionary
    int userChoice = 0;
    printf(CHOOSE_DICTIONARY);
    printDictionaries(dictionaries, numOfDictionaries);
    scanf("%d", &userChoice);
    //the dictionary the user chose
    Dictionary* chosenDict;
    //variable for user confirmation
    char isSure;

    /*
     * if the user entered a wrong option ask him to enter a number again.
     */
    while (userChoice > *numOfDictionaries || userChoice <= 0){
        printf("Wrong option, try again:\n");
        scanf("%d", &userChoice);
   }
    //the dictionary the user chose
    chosenDict = &dictionaries[userChoice-1];
    printf(USER_CONFIRMATION);
    scanf(" %c", &isSure);
    /*
     * if the user confirmed he wants to delete the dictionary,free the dictionary and print msg to the user,
     */
    if (isSure == 'y'){
    //free the chosen dictionary.
    freeDictionary(chosenDict);
        printf(DELETE_DICTIONARY_SUCCEED);
    }
    else {
        printf(DELETE_DICTIONARY_CANCELED);
        return NULL;
    }

    /*
     * take all the dictionaries after the index of the required dictionary to delete and take them backwards.
     */
    for (int i = userChoice - 1; i < *(numOfDictionaries) - 1; i++) {
        dictionaries[i] = dictionaries[i + 1];
    }
    //minimize the array of dictionaries by 1 after the user chose to delete dictionary
    dictionaries = (Dictionary*) realloc(dictionaries, ((*numOfDictionaries)-1) * (sizeof(Dictionary)));
    (*numOfDictionaries)--;

    /*
     * if the reallocation has failed return the temp pointer to the arr of pointers and print a msg to the user.
     */
    if (dictionaries == NULL && (*numOfDictionaries) != 0) {
        printf(DELETE_DICTIONARY_FAILED);
        return tempDict;
    }
    //return the pointer to dictionaries.
    return dictionaries;
}

/*********************************************************************************************************************
* Function name: freeAllMemory
* Input: Dictionary* dictionaries,const int* numOfDictionaries
* Output: void
* Function Operation: the function free all the memory allocated dynamically to avoid memory leaks,using for loop and
 * calling freeDictionary.
 * printing a msg to the user that he exit the program.
**********************************************************************************************************************/
void freeAllMemory(Dictionary* dictionaries,const int* numOfDictionaries){

    /*
     * free the dictionary in the array of dictionaries in the ith index.
     */
    for (int i = 0; i < *numOfDictionaries; i++) {
        if (&dictionaries[i] != NULL)
        freeDictionary(&dictionaries[i]);
    }
    //free the pointer to the array
    free(dictionaries);
    printf(EXIT_MSG);
}

/*********************************************************************************************************************
* Function name: menu
* Input: Dictionary* dictionaries, int *numOfDictionaries
* Output: void
* Function Operation: the function printing the dictionaries manger and asking the user to choose an option.
 * if the user enters an invalid option,ask him to enter again.
 * in the switch case , every case calling a function that will execute the option the user chose.
**********************************************************************************************************************/
void menu(Dictionary* dictionaries, int *numOfDictionaries){
    int userChoice;
    Dictionary* tempDict = NULL;

    do{
        printf("Welcome to the dictionaries manager!\n"
               "Choose an option:\n"
               "1. Create a new dictionary.\n"
               "2. Add a word to a dictionary.\n"
               "3. Delete a word from a dictionary.\n"
               "4. Find a word in a dictionary.\n"
               "5. Delete a dictionary.\n"
               "6. Exit.\n");
        //flag to check if user chose a not valid option.
        int valid = 0;
        /*
         * if the option isn't valid , ask the user to choose again until he entered a valid option.
         */
        while(!valid) {
            scanf("%d%*c", &userChoice);
            /*
             * checking if the user entered option 2-5 without creating a dictionary.
             */
            if ((*numOfDictionaries) == 0  && userChoice > 1 && userChoice < 6) {
                printf(OPTION_NOT_AVAILABLE);
                continue;
            }
            valid = 1;
            switch (userChoice) {
                case 1:
                    dictionaries = addDictionary(dictionaries, numOfDictionaries);
                    break;
                case 2:
                    addWordToDictionarySetup(dictionaries, numOfDictionaries);
                    break;
                case 3:
                    deleteWordFromDictSetup(dictionaries, numOfDictionaries);
                    break;
                case 4:
                    searchWordInDictionarySetup(dictionaries, numOfDictionaries);
                    break;
                case 5:
                    tempDict = dictionaries;
                    dictionaries = deleteDictionary(dictionaries,numOfDictionaries);
                    if (dictionaries == NULL)
                        dictionaries = tempDict;
                    break;
                case 6:
                     freeAllMemory(dictionaries,numOfDictionaries);
                    break;
                default:
                    valid = 0;
                    printf(WRONG_OPTION);
            }
        }
    }   while (userChoice != 6);
}


int main(){
    //pointer to array of structs.
    Dictionary* dictionaries = NULL;
    //pointer of the number of dictionaries the user entered.
    int numOfDictionaries = 0;
    menu(dictionaries,&numOfDictionaries);
    return 0;

}
