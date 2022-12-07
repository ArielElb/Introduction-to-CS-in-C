#include <stdio.h>
#include <math.h>
void hello(){
    printf("\"hello \\/\\/orld % %d\\n\"\n");
}
void distance() {
    int x1, y1, x2, y2;
    double distance;
    printf("Enter x1:\n");// Asks the user to enter the first coordination.
    scanf("%d", &x1);
    printf("Enter y1:\n");
    scanf("%d", &y1);
    printf("Enter x2:\n");// Asks the user to enter the second coordination.
    scanf("%d", &x2);
    printf("Enter y2:\n");
    scanf("%d", &y2);

    distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    printf("The distance between the points is: %.4lf\n", distance);// Showing the distance between the coordination's.
}
void conversions(){
    double km, m, dm, cm, mm, nm;
    double const CONVERT_NM_TO_KM =  1e-12 ;
    double const CONVERT_NM_TO_M = 1e-9;
    double const CONVERT_NM_TO_DM= 1e-8;
    double const CONVERT_NM_TO_CM = 1e-7;
    double const CONVERT_NM_TO_MM = 1e-6;
    printf("Please enter nm:\n");// requesting the user to enter a nanometer number.
    scanf("%10lf", &nm);
    printf("%010.4lf km\n%010.4lf m\n%010.4lf dm\n%010.4lf cm\n%010.4lf mm\n%010.0lf nm\n",
        nm * CONVERT_NM_TO_KM,nm * CONVERT_NM_TO_M,nm *CONVERT_NM_TO_DM,nm * CONVERT_NM_TO_CM,nm * CONVERT_NM_TO_MM,nm);
    //Converts the nanometers to the following units of measure:
    // kilometers, meters, decimetres, centimeters, millimeters,
    // and also nanometers,And displays a table of conversions.
    }
void baking(){
    int const MIN_PER_HOUR = 60;
    int const MOD_OF_HOUR = 24;
    int hhInitial,hhOven , mmInitial ,mmOven, ssInitial, ssOven;
    printf("Please enter the baking time: [hh:mm:ss]\n"); //asking the user for the baking time
    scanf("%d:%d:%d",&hhInitial,&mmInitial,&ssInitial); //Getting the baking time from the user.
    //asking the user when did he put the cake in the oven.
    printf("When did you put the cake into the oven? [hh:mm:ss]\n");
    scanf("%d:%d:%d",&hhOven,&mmOven,&ssOven);//Getting the time he put the can in the oven.
    int finalHours,finalMin,finalSec;//Variables that will show the time when the cake will be ready.
    finalSec = (ssInitial+ ssOven) % MIN_PER_HOUR;
    finalMin = ((mmInitial + mmOven)  + (ssInitial + ssOven) / MIN_PER_HOUR) % MIN_PER_HOUR;
    finalHours =( (hhInitial + hhOven ) + (mmInitial+ mmOven +
            (ssInitial + ssOven) / MIN_PER_HOUR ) / MIN_PER_HOUR ) % MOD_OF_HOUR;
    //show the time when the cake is ready.
    printf("The cake will be ready at %02d:%02d:%02d o'clock.\n",finalHours,finalMin,finalSec);

}

//void main() {
    //Calling the functions
    //hello();
    //distance();
    //conversions();
    //baking();

}
