/***********************
* Name: Ariel Elbaz.
* ID: 213073497.
* Assignment: ex_3.
***********************/
#include <stdio.h>
#include <math.h>
#define START_RES 4
#define STEP_OF_TWO 2
#define MULTIPLY 2
#define LOWEST_LEN_INC_SUBS 1
#define FIRST_PRIMARY 2


/*********************************************************************************************************
* Function Name: isPrime
* Input: int numToCheck
* Output:  if prime return 1 - true
 *         if not prime return 0 - false
* Function Operation: the function getting  number and checking if he is primary or not..
**********************************************************************************************************/
int isPrime(int numToCheck){
    //checking only the sqrt of the given number to lower the running(we don't need to check two pair 2 times).
    int sqrtNum = floor(sqrt(numToCheck));

    for (int j = FIRST_PRIMARY; j <= sqrtNum; j++) {
        if (numToCheck % j == 0) {
            return 0; // if not prime return 0 - false
        }
    }
    return 1; // else  if prime return 1 - true
}


/*********************************************************************************************************
* Function Name: printPrimes
* Input: none (void)
* Output:  none(void)
* Function Operation: the function calling to isPrime function inside a for loop that running from 2 to SIZE.
 * if the number is primary so assigning him into the array.
 * and than printing all the numbers in the array with backspace between them.
**********************************************************************************************************/
void printPrimes(){
    int arr[SIZE];
    for(int i = 2;i < SIZE ;i++){
        if (isPrime(i)) {
            arr[i]= i;
            if ( i == SIZE -2)
            printf("%d",arr[i]);
            else
            printf("%d ",arr[i]);
        }
    }
}


/**********************************************************************8*********************************************
 * 5 Function Name: goldbach
 * Input: none(void)
 * Output: none(void)
 * Function Operation: the function calling to isPrime function inside a for loop that running from 2 to SIZE.
 * if the number is primary so assigning him into the array, and count how many primary numbers.
 * the second part of the function has 3 for loops -
 * first - going  through all the even result.
 * second - find the first primary number.
 * third - finds the second primary number that can match the first one for summing them to get the required result.
 *
 * and than printing the sum of the numbers and the result .
********************************************************************************************************************/
void goldbach() {
    int primes[SIZE];
    //initializing a counter for the indices of the array.
    int counter = 0;
    /*
     * a loop that running from 2 to size. because 1 and 0 are not primary numbers.
     * and calling isPrime to check if "i" is primary number.
     * if he is ,inside the if expression we will have 1(true).
     * it will go through the if and add the number into the array.
     * the counter meaning the number of the primary numbers we got.
     */
    for (int i = 2; i < SIZE; i++) {
        /*
         * if number "i" is prime put him into the array and add one to the counter.
         */
        if (isPrime(i)) {
            primes[counter] = i;
            //counts how many prime numbers there are.
            counter++;
        }
    }
    /*
     * a loop that start from the result 4 , until result is lower or equals to
      the last prime in the array multiplied by 2.
     * and then, increasing result by two in purpose to check the next result(all result are even).
     */
    for (int result = START_RES; result <= primes[counter - 1] * MULTIPLY; result += STEP_OF_TWO){
        /*
        * a for loop that running on the indices of the array from zero to SIZE to find the first number.
         */
        for (int i = 0; i <= SIZE; i++) {
            /*
             * a for loop that running on the "second index"-find the second number who can match.
             * for example if 3 is primes[0] so j=0 and so on.
             * running from j=i until the counter (checking all the combinations of summing the numbers in the array).
             * printing the result and the sum of all the combinations
             */
                for (int j = i; j < counter; j++) {

                    if (primes[i] + primes[j] == result)
                        //printing the result = prime1  + prime2 and new line .
                    printf("%d = %d + %d\n", primes[i] + primes[j], primes[i], primes[j]);
                }
            }


    }

}


/*******************************************************************************************************************
* Function Name: reversed
* Input: int numToReverse (positive numbers from 1 to LIMIT.
* Output: int reversed num.
* Function Operation: the function getting a positive number and returns his reversed number.
********************************************************************************************************************/
int reversed(int numToReverse){
    int const MOD_TEN = 10;
    int const MULTIPLY_TEN = 10;
    int const DIV_TEN = 10;
    int reminder = 0;
    int reversedNum = 0;
    //using temp variable for saving the initial value of num .
    int tempNum = numToReverse;
    /*
     * while the number is not zero find the reminder.
     * the reversedNum will be the reminder plus the num multiplied by ten.
     * division the number by ten until he is zero in purpose to find the last digit.
     */
    while(tempNum != 0){
        reminder = tempNum % MOD_TEN;
        reversedNum = reversedNum * MULTIPLY_TEN + reminder;
        tempNum /= DIV_TEN;
    }
    //returning the value of the reversed number.
    return reversedNum;
}


/*********************************************************************************************************************
* Function Name: returnLychrel.
* Input: int input (positive numbers from 1 to LIMIT.
* Output: int num - if the number is a palindrome so return his value.
*         int returnLychrel(result) - if the result isn't a palindrome call returnLychrel(result) in recursive.
* Function Operation: the function getting a positive number and finding the result of the number and his reversed.
 * if the number is a palindrome so return his value.
 * when num isn't a palindrome print the sum of the number and his reversed (only the numbers not the result).
 * if the result isn't a palindrome print the result and  call returnLychrel(result) in recursive.
********************************************************************************************************************/
int returnLychrel(int num){
    // a variable - that showing the result of the sum of  number and his reversed.
    int result = num + reversed(num);
    /*
     * check if num is a palindrome.
     */
    if (num == reversed(num)){
        //return the palindrome number.
        return num;
    }
    //printing the two numbers of the sum (the number and his reversed).
    printf("%d+%d=", num, reversed(num));
    //checking if the result is a palindrome.
    if(result != reversed(result))
    //printing the result of the sum of the number and his revered.
        printf("%d:",result);
    // return the result of the num and his reversed.
    return returnLychrel(result);
}


/*******************************************************************************************************************
* Function Name: lychrel
* Input: void(none).
* Output: void(none).
* Function Operation: the function going through a for loop from 1 to LIMIT and checking if the number is a palindrome.
 * if the number(i) is palindrome so print the number .
 * else , print the number with ":" and than print the value that got returned from the function : returnLychrel
 * after calling the func with "i" as the parameter.
********************************************************************************************************************/
void lychrel() {
    /*
     * a for loop the going from 1 to LIMIT and checking if the current number(i) is
     * palindrome or not.
     * if palindrome - print the number and then call returnLychrel with the parameter i.
     * not palindrome - print the number: and call the function returnLychrel.
     */
    for (int i = 1; i < LIMIT; i++) {
    /*
     * checking if the number i is equals to his reversed (palindrome).
     */
        if (i == reversed(i)){
            //printing "i" if his already a palindrome.
            printf("%d\n",i);
        }
        else {
        //printing "i" .
        printf("%d:", i);
        //printing the palindrome number.
        printf("%d\n", returnLychrel(i));
        }
    }
}
//declaring on the function increasingSubSequence.
int increasingSubSequence(int arrSeq[], int arrLen, int lenOfIncSub[]);
//declaring on the function maxISS.
int maxLenLIS(int arrLIS[], int arrLen);


/*******************************************************************************************************************
* Function Name: subSetSeqMax
* Input: void(none).
* Output: void(none).
* Function Operation: the function getting a number that representing what is gonna be the length of the sequence.
 * receiving the number of elements that the user entered  and than the users entering the numbers into the array.
 * at the end of the func , calling the function increasingSubSequence and printing the longest length of the subSeq.
********************************************************************************************************************/
void subSetSeqMax() {
    //the array that represents the value of every the length of every subsequence.
    int arrLIS[SIZE];
    //the length of the array.
    int arrLen;
    //printing a msg to the user asking to enter the number of element that will be in the array.
    printf("Enter the number of elements\n");
    scanf("%d", &arrLen);
    int arr[SIZE];
    /*
     * getting the numbers from the user. into an array.
     * and assigning the lowest length of the longestIncreasingSubSequence int LIS at every index.
     */
    for (int i = 0; i < arrLen; i++) {
        // putting 1 at every index in the array.
        arrLIS[i] = LOWEST_LEN_INC_SUBS;
        //getting the numbers from the user into the array.
        scanf("%d", &arr[i]);
    }
    // printing the length of the longest subsequence.
    printf("%d",increasingSubSequence(arr, arrLen, arrLIS));
}


/*******************************************************************************************************************
* Function Name: increasingSubSequence.
* Input:
 * int arr[] - the array of the numbers that the user entered.
 * int arrLen - the length of the array by the given number of the user in func(subSetSeqMax)
 * int lenOfIncSub[] - the array that initialized with the LOWEST_LEN_INC_SUB(1) .
* Output: maxLenLIS(lenOfIncSub, arrLen) - the value  the got returned from maxLenILS of the LIS.
* Function Operation:
 * the function got two for loops: the first one if running on the arr from 1 to the length of the array.
 * the second for loop is running from j=0 until i<j .
 * and checking if the number at index i is greater than the number at index j AND the number at index i is lower or
 * equals to the number at index i .
 * the loop is going through every index and if the LIS at index j is greater than the LIS at index i and the num
 * at index j is lower than the num at index i.
 * update the value of the LIS to the LIS at index j + 1 (the starting value).
 * initialize the length of the increasing sub sequence at index1 to be : 1+ the previous number at index j.
 * in the end of the function,we calling the function maxLenILS and getting the value of the longest increasing subSeq.
 * and returning the value.
********************************************************************************************************************/
int increasingSubSequence(int arrSeq[], int arrLen, int lenOfIncSub[]) {
    // a for that running on the arr that the user gave from i until the end of the array.
    for (int i = 1; i <= arrLen; i++) {
        /*
         * a for loop for the LIS - running from the current number until the next number in the array.
         */
        for (int j = 0; j < i; j++) {
            /*if the number at index i is lower than the number at index j of the array
             * and the number at i in the array of the LIS is lower than the number in index j
             * the new value of the number in the index j is 1+number at index j.
             */
            if (arrSeq[i] > arrSeq[j] && lenOfIncSub[i] <= lenOfIncSub[j])
                lenOfIncSub[i] = LOWEST_LEN_INC_SUBS + lenOfIncSub[j];
        }
    }
    // calling to maxLenLIS with the  array LIS and the length of the array
    // returning the longest increasing subsequence.
    return maxLenLIS(lenOfIncSub, arrLen);
/*********************************************************************************************************
* Function Name: maxLenLIS
* Input:
 * int arrLIS[] - getting the array that got all the lengths of the increasing sub sequences.
 * int arrLen - the length of the array.
* Output: int maxOfLenLIS.
* Function Operation: the function going through the array LIS and finding what is the highest number there that
 * represent the length of the longest increasing sub sequence.
 * and returning it.
**********************************************************************************************************/
}
int maxLenLIS(int arrLIS[], int arrLen){
    int maxOfLenLIS = LOWEST_LEN_INC_SUBS;
    /*
     * a loop for getting the longest value of the increasing subsequence.
     */
    for (int j = 0; j < arrLen ; j++){
        if (arrLIS[j] > maxOfLenLIS)
            maxOfLenLIS = arrLIS[j];
    }
    // return the value of the longest increasing subsequence.
    return maxOfLenLIS;
}
/*********************************************************************************************************
* Function Name: menu
* Input: no parameters.
* Output: void (none).
* Function Operation: the function showing the user a menu and asking him to enter a number between 1-4.
 * each number leading to different case in the switch case.
 * if the user enters a number that not in the range 1-4 he will get an "wrong option" message.
**********************************************************************************************************/
void menu(){
    int userChoice;
        printf("1: primes\n2: goldbach\n3: lychrel\n4: max set\n");
        scanf("%d",&userChoice);
        switch (userChoice) {
            case 1:
                printPrimes();
                break;
            case 2:
                goldbach();
                break;
            case 3:
                lychrel();
                break;
            case 4:
                subSetSeqMax();
                break;
            default:
                printf("Wrong option!\n");

        }

    }
/*********************************************************************************************************
* Function Name: main
* Input: no parameters.
* Output: none / 0.
* Function Operation: the function calling the menu func.
**********************************************************************************************************/
    int main() {
menu();
    return 0;
}