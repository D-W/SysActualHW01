#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//returns length of char *s;
int stringLength( char *s ) {
    int ans = 0;
    while (*s) {
        ans++;
        s++;
    }
    return ans;
}


//copies char *source into char *dest
char * stringCopy( char *dest, char *source ) {
    int i = stringLength(source);
    while (*source) {
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
    dest -= i;
    return dest;
}

//copies the first n elements of char *source into char *dest
char * stringNCopy( char *dest, char *source, int n) {
    int ctr = 0;
    while (ctr != n) {
        *dest = *source;
        source++;
        dest++;
        ctr++;
    }
    *dest = '\0';
    dest -= n;
    return dest;
}

//catenates char *source to the end of char *dest
char * stringCatenate ( char *dest, char *source ) {
    int i = stringLength(dest) + stringLength(source);
    dest += stringLength(dest);
    while (*source) {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    dest -= i;
    return dest;
}

//catenates the first n elemenents of char *source to the end of char *dest
char * stringNCatenate ( char *dest, char *source, int n) {
    int i = stringLength(dest) + n;
    int ctr = 0;
    dest += stringLength(dest);
    while (ctr != n) {
        *dest = *source;
        dest++;
        source++;
        ctr++;
    }
    *dest = '\0';
    dest -= i;
    return dest;
}

//compares char *s1 to char *s2, if they are the same returns 0, otherwise upon reaching the first character that differs returns an int showing how much the two characters differ in value
int stringCompare( char *s1, char *s2 ) {
    while (*s1) {
        if (*s1 - *s2 != 0) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}

//finds char c in char *s and returns a pointer to its location
char * stringCharacter( char *s, int c ) {
    while (*s) {
        if (*s == c) {
            return s;
        }
        s++;
    }
    return NULL;
}



//finds char *s2 in char *s1 and returns a pointer to its location
char * stringString( char *s1, char *s2 ) {
    while(*s1) {
        if (*s1 == *s2) {
            int ctr = 0;
            while ((*s2) && (*s2 == *s1)) {
                s1++;
                s2++;
                ctr++;
            }
            s1 -= ctr;
            if (!(*s2)) {
                return s1;
            }
            s2 -= ctr;
        }
        s1++;
    }
    return NULL;
}


int main() {
    
    printf("---------------------------------------\n");
    
    //testing of stringLength
    printf("Testing of stringLength:\n");
    char test1s[] = "Length";
    printf("Result of string.h strlen('Length'): %d\n", (int)strlen(test1s));
    printf("Result of my stringLength('Length'): %d\n", stringLength(test1s));
    printf("\n");
    printf("\n");
    
    
    //testing of stringCopy
    printf("Testing of stringCopy:\n");
    char test2As1[16] = "";
    char test2As2[] = "Copy";
    printf("char test2As1 before string.h strcpy('','Copy'): %s\n", test2As1);
    printf("char test2As2 before string.h strcpy('','Copy'): %s\n", test2As2);
    strcpy(test2As1, test2As2);
    printf("char test2As1 after string.h strcpy('','Copy'): %s\n", test2As1);
    printf("char test2As2 after string.h strcpy('','Copy'): %s\n", test2As2);
    
    char test2Bs1[16] = "";
    char test2Bs2[] = "Copy";
    printf("char test2Bs1 before my stringCopy('','Copy'): %s\n", test2Bs1);
    printf("char test2Bs2 before my stringCopy('','Copy'): %s\n", test2Bs2);
    stringCopy(test2Bs1, test2Bs2);
    printf("char test2Bs1 after my stringCopy('','Copy'): %s\n", test2Bs1);
    printf("char test2Bs2 after my stringCopy('','Copy'): %s\n", test2Bs2);
    printf("\n");
    
    //testing of stringNCopy
    printf("Testing of stringNCopy:\n");
    char test2NAs1[16] = "";
    char test2NAs2[] = "Copy";
    printf("char test2NAs1 before string.h strncpy('','Copy', 3): %s\n", test2NAs1);
    printf("char test2NAs2 before string.h strncpy('','Copy', 3): %s\n", test2NAs2);
    strncpy(test2NAs1, test2NAs2, 3);
    printf("char test2NAs1 after string.h strncpy('','Copy', 3): %s\n", test2NAs1);
    printf("char test2NAs2 after string.h strncpy('','Copy', 3): %s\n", test2NAs2);
    
    char test2NBs1[16] = "";
    char test2NBs2[] = "Copy";
    printf("char test2NBs1 before my stringNCopy('','Copy', 3): %s\n", test2NBs1);
    printf("char test2NBs2 before my stringNCopy('','Copy', 3): %s\n", test2NBs2);
    stringNCopy(test2NBs1, test2NBs2, 3);
    printf("char test2NBs1 after my stringNCopy('','Copy', 3): %s\n", test2NBs1);
    printf("char test2NBs2 after my stringNCopy('','Copy', 3): %s\n", test2NBs2);
    printf("\n");
    printf("\n");
    
    
    //testing of stringCatenate
    printf("Testing of stringCatenate:\n");
    char test3As1[16] = "Ki";
    char test3As2[] = "tty";
    printf("char test3As1 before string.h strcat('Ki', 'tty'): %s\n", test3As1);
    printf("char test3As2 before string.h strcat('Ki', 'tty'): %s\n", test3As2);
    strcat(test3As1, test3As2);
    printf("char test3As1 after string.h strcat('Ki', 'tty'): %s\n", test3As1);
    printf("char test3As2 after string.h strcat('Ki', 'tty'): %s\n", test3As2);
    
    char test3Bs1[16] = "Ki";
    char test3Bs2[] = "tty";
    printf("char test3Bs1 before my stringCatenate('Ki', 'tty'): %s\n", test3Bs1);
    printf("char test3Bs2 before my stringCatenate('Ki', 'tty'): %s\n", test3Bs2);
    stringCatenate(test3Bs1, test3Bs2);
    printf("char test3Bs1 after my stringCatenate('Ki', 'tty'): %s\n", test3Bs1);
    printf("char test3Bs2 after my stringCatenate('Ki', 'tty'): %s\n", test3Bs2);
    printf("\n");
    
    //testing of stringNCatenate
    printf("Testing of stringNCatenate:\n");
    char test3NAs1[16] = "Ki";
    char test3NAs2[] = "tty";
    printf("char test3NAs1 before string.h strncat('Ki', 'tty', 1): %s\n", test3NAs1);
    printf("char test3NAs2 before string.h strncat('Ki', 'tty', 1): %s\n", test3NAs2);
    strncat(test3NAs1, test3NAs2, 1);
    printf("char test3NAs1 after string.h strncat('Ki', 'tty', 1): %s\n", test3NAs1);
    printf("char test3NAs2 after string.h strncat('Ki', 'tty', 1): %s\n", test3NAs2);
    
    char test3NBs1[16] = "Ki";
    char test3NBs2[] = "tty";
    printf("char test3NBs1 before my stringNCatenate('Ki', 'tty', 1): %s\n", test3NBs1);
    printf("char test3NBs2 before my stringNCatenate('Ki', 'tty', 1): %s\n", test3NBs2);
    stringNCatenate(test3NBs1, test3NBs2, 1);
    printf("char test3NBs1 after my stringNCatenate('Ki', 'tty', 1): %s\n", test3NBs1);
    printf("char test3NBs2 after my stringNCatenate('Ki', 'tty', 1): %s\n", test3NBs2);
    printf("\n");
    printf("\n");
    
    
    //testing of stringCompare
    printf("Testing of stringCompare:\n");
    char test4s1[] = "The Cat";
    char test4s2[] = "The Cat";
    char test4s3[] = "The Bat";
    char test4s4[] = "The Rat";
    printf("Result of string.h strcmp('The Cat', 'The Cat'): %d\n", strcmp(test4s1, test4s2));
    printf("Result of my stringCompare('The Cat', 'The Cat'): %d\n", stringCompare(test4s1, test4s2));
    printf("Result of string.h strcmp('The Cat', 'The Bat'): %d\n", strcmp(test4s1, test4s3));
    printf("Result of my stringCompare('The Cat', 'The Bat'): %d\n", stringCompare(test4s1, test4s3));
    printf("Result of string.h strcmp('The Cat', 'The Rat'): %d\n", strcmp(test4s1, test4s4));
    printf("Result of my stringCompare('The Cat', 'The Rat'): %d\n", stringCompare(test4s1, test4s4));
    printf("\n");
    printf("\n");
    
    
    //testing of stringCharacter
    printf("Testing of stringCharacter:\n");
    char test5s1[] = "Character";
    int test5s2 = 97;
    printf("Result of string.h strchr('Character', 'r'): %p\n", strchr(test5s1, test5s2));
    printf("Result of my stringCharacter('Character', 'r'): %p\n", stringCharacter(test5s1, test5s2));
    printf("\n");
    printf("\n");
    
    
    //testing of stringString
    printf("Testing of stringString:\n");
    char test6s1[] = "String";
    char test6s2[] = "ring";
    printf("Result of string.h strstr('String', 'ring'): %p\n", strstr(test6s1, test6s2));
    printf("Result of my stringString('String', 'ring'): %p\n", stringString(test6s1, test6s2));
    printf("---------------------------------------\n");
    
    
    return 0;
    
}