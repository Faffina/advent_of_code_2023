#include<stdio.h>
#include<stdlib.h>

int main() {
    char *buffer = NULL;
    size_t buffer_lenght = 0;
    size_t char_read;
    int sum = 0;
    while(char_read = getline(&buffer, &buffer_lenght, stdin) != -1) {
        char *str = buffer;
        int m_digit = -1, l_digit = -1;
        
        for(;*str;str++) 
            if(*str >= '0' && *str <= '9'){
                if(m_digit == -1)
                    m_digit = *str - '0';
                else
                    l_digit = *str - '0';
            }
        
        if(m_digit != -1 && l_digit != -1)
            sum += m_digit * 10 + l_digit;
        if(m_digit != -1 && l_digit == -1)
            sum += m_digit * 10 + m_digit;
        printf("%d \n", m_digit * 10 + l_digit);
    }
    printf("%d\n", sum);
}
