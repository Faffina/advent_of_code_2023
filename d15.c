#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//faffa ;

int get_digit(char** str);

int main() {
    char *buffer = NULL;
    size_t buffer_lenght = 0;
    size_t char_read;
    int sum = 0;
    while(char_read = getline(&buffer, &buffer_lenght, stdin) != -1) {
        char *str = buffer;
        int m_digit = -1, l_digit = -1;
        int digit = -1;
        while((digit = get_digit(&str) != -1)) {
            if(m_digit == -1)
                l_digit = m_digit = digit;
            else
                l_digit = digit;
        }
        digit = m_digit * 10 + l_digit;
        printf("%s - %d\n", buffer, digit);
        sum += digit;
    }
    printf("%d\n", sum);
}

int get_digit(char** str){
    for(;**str;(*str)++){
        if(**str >= '0' && **str <= '9')
            return **str - '0';
        if(strncmp(*str, "one", 3) == 0){
            *str += 3; 
            return 1;}
        if(strncmp(*str, "two", 3) == 0){
            *str += 3; 
            return 2;}
        if(strncmp(*str, "three", 5) == 0){
            *str += 5; 
            return 3;}
        if(strncmp(*str, "four", 4) == 0){
            *str += 4; 
            return 4;}
        if(strncmp(*str, "five", 4) == 0){
            *str += 4; 
            return 5;}
        if(strncmp(*str, "six", 3) == 0){
            *str += 3; 
            return 6;}
        if(strncmp(*str, "seven", 5) == 0){
            *str += 5; 
            return 7;}
        if(strncmp(*str, "eight", 5) == 0){
            *str += 5; 
            return 8;}
        if(strncmp(*str, "nine", 4) == 0){
            *str += 4; 
            return 9;}
        if(strncmp(*str, "zero", 4) == 0){
            *str += 4; 
            return 0;}
    } 
    return -1;
}
