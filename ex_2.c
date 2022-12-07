#include <stdio.h>
#include <math.h>
/***************************************************************************
 * Full Name: Ariel Elbaz.
 * ID : 213073497
 * ex_2
 **************************************************************************/


/******************************************************************************************************************
* Function Name: hexDecimalToDecimal
* Input:  none .
* Output: none.
* Function Operation: the function getting a revered number (char) from the user and converting him to a decimal number.
 * if the number isn't between the ASCII values :c<'a' || c> 'f') && (c <'0' ||c >'9')&& (c<'A'||c > 'F'.
 * the function printing error .else : printing the decimal number after the convert.
******************************************************************************************************************/
void hexDecimalToDecimal(){
    //define consts for subtraction them to get a decimal digit
    const int NUM_CONV_CAPS = 87;
    const int NUM_CONV_LOW = 55;
    const int NUM_CONV_CHAR = 48;
    // the decimal value of the hexadecimal digit and
    // result : the final output (decimal num) ,place : stores the exponent value.
    int digit, place = 0,error = 0;
    unsigned long long result = 0;
    // the char that holds the user input value.
    char c;
    char cError;
    printf("Enter a reversed number in base 16:\n");// asks the user to enter a number.
    scanf(" %c",&c);
    /*;
     * while c isn't enter go through the loop.
     * get the values of all the chars in the ascii table and put them in result
     * if they're standing by all the if conditions.
     */
    while (c != '\n'){
        /*
         * if c isn't between : '1'-'9', 'a'-'f', 'A'-'F', print error.
         */
        if((c<'a' || c> 'f') && (c <'0' ||c >'9')&& (c<'A'||c > 'F')) {
            printf("Error!\n");
            //cleaning the buffer to avoid printing error multi times.
            scanf("%*[^\n]");
            //using a flag for error to be printed once
            error++;
            cError=c;
        }
        
        if(c <= '9' && c >= '0'){
            digit = c - NUM_CONV_CHAR;
        }
        if(c >= 'A' && c <= 'F'){
            digit = c - NUM_CONV_LOW;
        }
        if(c <='f' && c >= 'a'){
            digit = c - NUM_CONV_CAPS;
        }
        result += digit * pow(16,place);
        place++;
        scanf("%c", &c);
    }
        if (error == 0)
            printf("%llu\n",result);
    }
/*********************************************************************************************************
* Function Name: decimalToGeneralBase
* Input: none
* Output:  void- none.
* Function Operation: the function getting a decimal number from the user and a count base.
 * than, the function converts the decimal number to another number of the count base that given by the user.
**********************************************************************************************************/
void decimalToGeneralBase(){
    //a variable that include the num that the user enters.
    unsigned long num;
    // variable's of the : finalNum - result after conversion.base- the base that the user enters.
    int finalNum,base;
    //variable's to keep the value of the reminder and the quotient.
    int modulo,portion;
    //the exponent that goes up each iteration.
    int temp = 0;
    //asks the user to enter base and number.
    printf("Enter base and a number:\n");
    scanf(" %d %lu",&base,&num);
    while(num > 0){
        // doing the division and saving it in portion
        portion = num / base;
        // doing the modulo and saving it in modulo
        modulo = num % base;
        // calculating the number who get printed
        finalNum = (pow(10,temp)) * modulo + finalNum;
        //  doing the value num as portion.
        num=portion;
        temp++;

    }
    printf("%d\n",finalNum);

}
/*********************************************************************************************************
* Function Name: generalToDecimal
* Input: none .
* Output: void none.
* Function Operation: the function asks the user to enter a number to convert and a count base that we want
 * of the number to be converted to .
 * the function converting the number to a decimal number and printing him.
 * if the highest digit in the num to convert is higher than the base , print error , else print the decimal
 number that we got after the result.
**********************************************************************************************************/
void generalToDecimal() {
    unsigned long numToConvert;
    //the num that the user enters.
    //the final number who get printed.
    unsigned long result = 0;
    // the base the user enters.
    int countBase;
    //the exponent that represent index of the number
    int expCounter = 0;
    //ask the user to enter base and number that he want to convert.
    printf("Enter base and a number:\n");
    scanf("%d %lu", &countBase, &numToConvert);
    //create a  temp variable in purpose to save the value of numToConvert.
    int temp = numToConvert;
    int max = 0 ,remainder;
    /*
     check what is the largest digit in numToConvert.
     */
    while (temp > 0){
        remainder = temp % 10;
        /*
         if the max (highest) digit is lower than the reminder, put remainder in max.
         */
        if (max < remainder){
            max = remainder;
        }
        //divide temp by ten, then put him in temp.
        temp = temp / 10;
    }
    /*
     if the largest digit is higher than the countBase that the user entered ,print:Error.
     */
    if (max > countBase){
        printf("Error\n");
        return;
    }
    /*
     a loop that checking what is the result of num after the conversion.
     */
    while (numToConvert > 0) {
        //getting the modulo of num by 10 and then multiply it by the pow user input of the count base and the exponent.
        result += (numToConvert % 10) * (pow(countBase, expCounter));
        // making division on the initial num  and saving it in num.
        numToConvert /= 10;
        //adding 1 to the expCounter(the exponent).
        expCounter++;

    }
    //printing the result of the conversion.
    printf("%lu\n",result);
}
/*********************************************************************************************************
* Function Name: digitOfNum
* Input:  unsigned long numToCountDigits (valid values numbers >=  0) .
* Output: digits (values - any positive number).
* Function Operation: the function getting a number and calculating how many digits he have.
**********************************************************************************************************/
int digitOfNum(unsigned long numToCountDigits){
    int digitCounter = 0;
    unsigned long temp1 = numToCountDigits;
    while (temp1 != 0) {
        temp1 = temp1 / 10;
        digitCounter++;
    }
    return digitCounter;

}
/*********************************************************************************************************
* Function Name: getMaxDigits
* Input: int digit1, int digit 2. (valid values - any numbers ) .
* Output:  int digit1 or int digit2 (values - any numder).
* Function Operation: the function getting  two numbers and calculating who is bigger , digit1 or digit2
 * and than returns the bigger number.
**********************************************************************************************************/
int getMaxDigits(int digit1,int digit2){
    if (digit1 > digit2) {
        return digit1;
    }
    return digit2;
    }
/*********************************************************************************************************
* Function Name: printCheck
* Input: int numBin1 , int numBin2 , int maxResCarry .
* Output: none void.
* Function Operation: the function printing the given numbers and puts zeros when needed in the print.
 * the function checking what number to print first numBin1 or numBin2 .
**********************************************************************************************************/
void printCheck(int numBin1, int numBin2, int maxResCarry) {
    if(numBin1 > numBin2){
        printf("%0*d\n+\n", maxResCarry, numBin1);
        printf("%0*d\n", maxResCarry, numBin2);
    }
    else {
        printf("%0*d\n", maxResCarry, numBin2);
        printf("%0*d\n+\n", maxResCarry, numBin1);
    }
}
/***********************************************************************************************************************
* Function Name: sumBinaryNums
* Input: none .
* Output: none void.
* Function Operation: the function ask the user to enter two binary nums and checking if they are really in binary.
 * the function summing between numBin1 and numBin2 and calculating the result and the carry .
 * at the end of the function , the function calling other function in purpose to calculate the width of the printing
 * and check what number has the most digits for the printing.
 * the function printing the carry above and below the highest number ---> second number ----> ----- and than the result
***********************************************************************************************************************/
void sumBinaryNums() {
    int const MOD_TEN = 10 , DIVISION_TWO = 2 , MOD_TWO = 2 , DIVISION_TEN = 10 , BASE_TEN = 10;
    
    unsigned long numBin2, numBin1;
    printf("Enter 2 binary numbers:\n");
    scanf("%lu%lu", &numBin1, &numBin2);

    int carry = 0, locationSum = 0, locationCarry=1 , tempCarry, sumCarry = 0;
    unsigned long result = 0;
    int num1Temp, num2Temp;
    //a temp variable to save the original value of numBin1 and numBin2
    num1Temp = numBin1;
    num2Temp = numBin2;

    while (num1Temp != 0 || num2Temp != 0) {
        // check if the numbers are only in base 2.
        if(num1Temp % 10 > 1 || num2Temp % 10 > 1){
            printf("Error!\n");
            return;
        }
        // digit with carry
        tempCarry = carry + num1Temp % MOD_TEN + num2Temp % MOD_TEN;

        /******************************************************************************
         * if there is a carry ,don't obtain tempCarry as zero . else, do tempCarry=0
         * in purpose to not get with the older carry to the next iteration.
        *******************************************************************************/
        // if there is a carry
        if ((carry + num1Temp % MOD_TEN + num2Temp % MOD_TEN) / DIVISION_TWO >= 1) {
            //carry for next iteration.
            carry = tempCarry / DIVISION_TWO;
        }
        else {
            //there is no carry
            carry = 0;
        }
        //calculating the initial result.
        result += (tempCarry) % MOD_TWO * pow(BASE_TEN, locationSum);
        //carry calculator
        sumCarry += carry % MOD_TWO * pow(BASE_TEN, locationCarry);
        //adding 1 to the location of sum
        locationSum++
        //adding 1 to the location of carry
        locationCarry++;
        //going to the next digit by dividing the value of num1 by 10
        num1Temp = num1Temp / DIVISION_TEN;
        num2Temp = num2Temp / DIVISION_TEN;
    }
    //calculating the final result who gonna be printed.
    result = result + (pow(BASE_TEN, locationSum) * carry);
    //checking how many digits the result has ,and putting it on digitsResult.
    int digitsResult = digitOfNum(result);
    //checking how many digits the carry has ,and putting it on digitsCarry.
    int digitsCarry = digitOfNum(sumCarry);
    //checking what number has more digits and putting it on maxResCarry.
    int maxResCarry = getMaxDigits(digitsCarry,digitsResult);
    //printing the sumCarry with the maximum length of digits. and putting zero when needed.
    printf("%0*d\n",maxResCarry,sumCarry);
    printCheck(numBin1, numBin2, maxResCarry);
    for (int i = 0; i < maxResCarry; i++) {
        printf("-");
    }
    printf("\n%lu\n", result);

}
/*********************************************************************************************************
* Function Name: printButterfly
* Input:  no parameters.
* Output: void (none).
* Function Operation: getting an unsigned number from the user .
 * printing the pattern of the butterfly with height = 2n-1  and width = 2n.
 * and covering the butterfly with #.
 * edge cases : 1. when n=0 print 2x2 square of #.
 * 2. when n-1 print ** and circle them with a square of #.
**********************************************************************************************************/
void printButterfly(){
    unsigned int n;
    printf("Enter a number:\n");
    scanf("%u",&n);
    /*
     *edge case number 1
     */
    if (n == 1) {
        printf("####\n#**#\n####\n");
        return;
    }
    /*
    *edge case number 3
    */
    if (n == 0) {
        return;
    }
    //number of initial spaces.
    const int two_nMinusSix = 2 * n - 4;
    // print first row (###.....###)
    printf("###");
    /*
    *printing the space of the first line.
     */
    for (int j = 0; j < two_nMinusSix; j++) {
        printf(" ");
    }
    printf("###\n");

    /*
    * print rows 1 until (n-1) in the indices.
    */
    for (int i = 1; i < n ; i++) {
        printf("#");
        /*
         * print the stars of the left side of line.
         */
        for (int star = 0; star < i; star++){
            printf("*");
        }
        printf("#");
        /*
         *print the middle spaces of the line
         */
        for (int space = 0; space < two_nMinusSix - 2 * (i - 1); space++) {
            printf(" ");
        }
        printf("#");
        /*
         * print the stars on the right side of the line.
         */
        for (int star = 0; star < i; star++){
            printf("*");
        }
        printf("#\n");
    }
    // middle row
    printf("#");
    /*
     * print the stars of middle row.
     */
    for (int space = 0; space < 2 * n; space++) {
        printf("*");
    }
    printf("#\n");
    // print rows n - 2n-3

    //define i decreasing
    for (int i = n - 1 ; i > 0; i--) {
        printf("#");
        /* while i(when going row down)
         *  decreasing the number of stars decreasing.
        */
        for (int star = 0; star < i; star++) {
            printf("*");
        }

        printf("#");
        // define consts in purpose to print spaces.
        const int maxSpaces = 2 * n - 4;
        const int decreaseSpaces = 2 * (i - 1);
        /*
         * when I am decreasing the number of spaces increasing.
         * and each iteration print the proper amount of spaces.
         */
        for (int space = 0; space < maxSpaces - decreaseSpaces; space++){
            printf(" ");
        }
        printf("#");
        /* while i(when going row down)
         *decreasing the number of stars decreasing.
        */
        for (int star = 0; star < i; star++) {
            printf("*");
        }
        printf("#\n");

    }
    // print last row (###.....###)
    printf("###");
    /*
     * print the spaces for the last row(without any stars)
     */
    for (int j = 0; j < two_nMinusSix; j++) {
        printf(" ");
    }
    printf("###\n");
}
/*********************************************************************************************************
* Function Name: countBits
* Input:  no parameters.
* Output: void (none).
* Function Operation:  getting unsigned long decNum (valid values-decNum>0).
 * the function counts how much bits there are in the given decimal number,
  by checking each bit in the decimal number in his binary representation by dividing by two , and counting
  up  by 1 each bit( int bitCounter  values >= 0).
**********************************************************************************************************/
void countBits() {
    //the num that the user enters.
    unsigned long decNum;
    //the counter that counts how many 1 bits the number got in his binary representation.
    int bitCounter = 0;
    printf("enter a number:\n");
    scanf("%lu", &decNum);
    /*
     * while the number after every iteration is not 0 ,go through the loop.
     */
    while (decNum > 0) {
        /*
         * check if there is 1 bit in the representation of the decimal number in binary by going from.
         */
        if ((decNum & 1) == 1)
            bitCounter++;
        //doing division by 2., in the next iteration check the next bit until the number is zero.
    decNum = decNum << 1;
    }
    // print the number of bits those are 1 in its binary representation after the while finished.
    printf("no of bits those are 1 in its binary representation: %d\n",bitCounter);
}
/*********************************************************************************************************
* Function Name: menu
* Input: no parameters.
* Output: void (none).
* Function Operation: the function showing the user a menu and asking him to enter a number between 1-7.
 * each number leading to different case in the switch case, the menu will be shown to the user until his
 * choice will be 7(exit).
 * if the user enters a number that now in the range 1-7 he will get an "wrong option" message.
**********************************************************************************************************/
    void menu(){
        int userChoice;
        do {
            printf("Choose an option:\n\t1. hexaDecimal to Decimal\n\t2. Decimal to Base\n\t3. Base to Decimal\n\t4. "
                   "PLUS\n\t5. Shape\n\t6. Count bits\n\t7. Exit\n");
            scanf("%d",&userChoice);
            switch (userChoice) {
                case 1:
                    hexDecimalToDecimal();
                    break;
                case 2:
                    decimalToGeneralBase();
                    break;
                case 3:
                    generalToDecimal();
                    break;
                case 4:
                    sumBinaryNums();
                    break;
                case 5:
                    printButterfly();
                    break;
                case 6:
                    countBits();
                    break;
                case 7:
                    break;
                default:
                    printf("Wrong option!\n");

            }

        } while (userChoice != 7);
    }

int main(){
    menu();
}
