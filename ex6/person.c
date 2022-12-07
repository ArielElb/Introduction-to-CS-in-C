/***********************
* Name: Ariel Elbaz.
* ID: 213073497.
* Assignment: ex_6
***********************/
#include "person.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#define CONVERT_CM_TO_M 100.0
/*********************************************************************************************************************
* Function name: load
* Input: const char* inputFile, Person persons[], int* numOfPersonsPtr
* Output: void
* Function Operation: the function loading all of the persons into the input file.
 * by using a while loop of getting every person each iteration and strtok function to fill the fields of the person.
**********************************************************************************************************************/
void load(const char* inputFile, Person persons[], int* numOfPersonsPtr) {
    FILE* input = fopen(inputFile, "r");
    /*
     * condition to print error msg if there is no file.
     */
    if (input == NULL) {
        printf("File not found: %s\n", inputFile);
        return;
    }

    char strToLoad[MAX_STR_LEN];
    /*
     * loading all the persons and their fields into the array of persons
     */
    while (fgets(strToLoad, MAX_STR_LEN, input)) {
        char tmpStr[MAX_STR_LEN];
        char *strAfterCut;
        strAfterCut = strtok(strToLoad, DELIM);
        strcpy(persons[*numOfPersonsPtr].firstName, strAfterCut);
        strAfterCut = strtok(NULL, DELIM);
        strcpy(persons[*numOfPersonsPtr].lastName, strAfterCut);
        strAfterCut = strtok(NULL, DELIM);
        strcpy(tmpStr , strAfterCut);
        persons[*numOfPersonsPtr].dateOfBirth.day = atoi(tmpStr);
        strAfterCut = strtok(NULL, DELIM);
        strcpy(tmpStr , strAfterCut);
        persons[*numOfPersonsPtr].dateOfBirth.month = atoi(tmpStr);
        strAfterCut = strtok(NULL, DELIM);
        strcpy(tmpStr , strAfterCut);
        persons[*numOfPersonsPtr].dateOfBirth.year = atoi(tmpStr);
        strAfterCut = strtok(NULL, DELIM);
        strcpy(tmpStr , strAfterCut);
        persons[*numOfPersonsPtr].height = atoi(tmpStr);
        strAfterCut = strtok(NULL, DELIM);
        strcpy(tmpStr , strAfterCut);
        persons[*numOfPersonsPtr].weight = atof(tmpStr);
        (*numOfPersonsPtr)++;

    }
    /*
     * condition to check if the closing of the file failed.
     */
    if (fclose(input)) {
        printf("Error with closing file: %s\n", inputFile);
        return;
    }
}


/*********************************************************************************************************************
* Function name: swapPersons
* Input: void* str, int i, int j
* Output: void
* Function Operation: the function casting the generic ptr that he getting to a person struct.
 * and swapping the person by saving a temp variable.
 * (I was helped by a presentation of the Tirgul).
**********************************************************************************************************************/
void swapPersons(void* str, int i, int j){
    //casting the ptr to person struct
    Person* personsArr = (Person*) str;
    //temp variable to save personArr[i].
    Person temp = personsArr[i];
    //swap the persons
    personsArr[i] = personsArr[j];
    personsArr[j] = temp;
}

/*********************************************************************************************************************
* Function name: comparePersonByFirstName
* Input: void* str, int i, int j
* Output: int -
* Function Operation: the function comparing the persons by using strcmp.
 * (I was helped by a presentation of the Tirgul).
**********************************************************************************************************************/
int comparePersonByFirstName(void* str, int i, int j){
    //casting from generic ptr to Person*
    Person* str_arr = (Person*) str;
    return strcmp(str_arr[i].firstName, str_arr[j].firstName);
}

/*********************************************************************************************************************
* Function name: comparePersonByLastName
* Input: void* str, int i, int j
* Output: int (>0 or <0)
* Function Operation: casting the generic pointer and comparing the last name of the person by using str compare
 * (I was helped by a presentation of the Tirgul).
**********************************************************************************************************************/
int comparePersonByLastName(void* str, int i, int j){
    //casting from generic ptr to Person*
    Person* str_arr = (Person*) str;
    return strcmp(str_arr[i].lastName, str_arr[j].lastName);
}

/*********************************************************************************************************************
* Function name: comparePersonByHeight
* Input: void* str, int i, int j
* Output: int (>0 or <0)
* Function Operation:casting the generic pointer and return positive number if the first person is higher or negative
 * number if lower.
 * (I was helped by a presentation of the Tirgul).
**********************************************************************************************************************/
int comparePersonByHeight(void* str, int i, int j){
    //casting from generic ptr to Person*
    Person* int_arr = (Person*) str;
    return int_arr[i].height - int_arr[j].height;
}

/*********************************************************************************************************************
* Function name: comparePersonByHeight
* Input: vo0
 * id* str, int i, int j
* Output: int (<0 or >0)
* Function Operation:casting the generic pointer and return positive number if the first person weight is bigger or
 * negative
 * number if lower.
 * (I was helped by a presentation of the Tirgul).
**********************************************************************************************************************/
int comparePersonByWeight(void* arr, int i, int j){
    //casting from generic ptr to Person*
    Person* int_arr = (Person*) arr;
    if(int_arr[i].weight < int_arr[j].weight)
        return -1;
    return 0;
}

/*********************************************************************************************************************
* Function name: comparePersonByBMI
* Input: void* str, int i, int j
* Output: int (1- if the first person BMI is bigger ,-1 - if lower .
* Function Operation:casting the generic pointer and return 1 or -1 depends on which person BMI is bigger.
**********************************************************************************************************************/
int comparePersonByBMI(void* str, int i, int j) {
    //casting from generic ptr to Person*
    Person* int_arr = (Person*) str;
    double personOneHeight = ((int_arr[i].height) / CONVERT_CM_TO_M);
    double personTwoHeight = ((int_arr[j].height) / CONVERT_CM_TO_M);
    //calculate the persons BMI
    double bmiOne = (int_arr[i].weight/(personOneHeight * personOneHeight));
    double bmiTwo = (int_arr[j].weight/(personTwoHeight * personTwoHeight));
    /*
     * if the first person BMI is smaller return -1 to switch them
     */
    if(bmiOne < bmiTwo)
        return -1;
    return 0;
}

/*********************************************************************************************************************
* Function name: comparePersonByDate
* Input: void* str, int i, int j
* Output: int (-1 if first person is younger)
* Function Operation:casting the generic pointer and return 1 or -1 depends on which person is older .
 * case 1: if the first person is younger  in years return -1
 * case 2: if the person born in the same year and is younger because of the months -return -1
 * case 3: the persons born in the same year and month and the first person is younger in days - return  -1
**********************************************************************************************************************/
int comparePersonByDate(void* str, int i, int j){
    Person* int_arr = (Person*) str;
    /*
     * check if the first person is younger in the year
     */
    if (int_arr[i].dateOfBirth.year < int_arr[j].dateOfBirth.year ){
        return -1;
    }
    /*
     * check if the first person is younger in the month
     */
    else if (int_arr[i].dateOfBirth.year == int_arr[j].dateOfBirth.year && int_arr[i].dateOfBirth.month <
    int_arr[j].dateOfBirth.month){
        return -1;
    }
    /*
     * check if the first person is younger in the days
     */
    else if (int_arr[i].dateOfBirth.year == int_arr[j].dateOfBirth.year && int_arr[i].dateOfBirth.month ==
     int_arr[j].dateOfBirth.month && int_arr[i].dateOfBirth.day < int_arr[j].dateOfBirth.day )
        return  -1;
    else
        return 1;

}

/*********************************************************************************************************************
* Function name: save
* Input: const char* outputFile, Person persons[], int numOfPersons
* Output: void
* Function Operation: save the sorted array of persons in the output file.
**********************************************************************************************************************/
void save(const char* outputFile, Person persons[], int numOfPersons){
    FILE* output = fopen(outputFile, "w");
    /*
     * if the creation of the input file failed,print error msg.
     */
    if (!output) {
        printf("Error with file: %s\n", outputFile);
        return;
    }
    /*
     * save in each line of the file the person after sorting the array
     */
    for (int i = 0; i < numOfPersons; i++) {
        fprintf(output,"%s,%s,", persons[i].firstName,persons[i].lastName);
        fprintf(output,"%d,%d,%d",persons[i].dateOfBirth.day,persons[i].dateOfBirth.month,persons[i].dateOfBirth.year);
        fprintf(output,",%d,%.02f",persons[i].height,persons[i].weight);
        if(i == numOfPersons - 1)
            break;
        fprintf(output, "\n");
    }
    /*
     * if the closing of the file failed , print error msg,
     */
    if (fclose(output)) {
        printf("Error with closing file: %s\n", outputFile);
        return;
    }
}


