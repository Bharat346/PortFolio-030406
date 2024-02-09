#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void delete(char *str,int index){
    for (int i = index; i < strlen(str); i++)
    {
        str[i] = str[i+1];
    }
}

void delete_special_characters(char *str){
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '$' || str[i] == '@' || str[i] == '&' || str[i] == '!' || str[i] == '?' || str[i] == '%' || str[i] == '#' || str[i] == '^' || str[i] == '*' || str[i] == '\\')
        {
            delete(str,i);
            i--;
        }
        
    }
    
}

void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // Convert uppercase letters to lowercase
            str[i] = str[i] + 32;
        }
    }
}

int is_pelindrome(char *str){
   int is_pelindrome_str = 0;
   int len = strlen(str);
   for (int i = 0; i < len/2; i++)
   {
    if (str[i] = str[len-1-i])
    {
        is_pelindrome_str = 1;
    }
    
   }
   return is_pelindrome_str;
}


int main()
{
    char str[] = "N2 i&nJA?a& jnI2n";
    delete_special_characters(str);
    printf("%s",str);
    to_lowercase(str);
    // delete(str,3);
    printf("\n%s",str);

    if (is_pelindrome(str))
    {
        printf("\nTrue!! this is palindrome");
    }
    else{
        printf("\nfalse!! this is not palindrome");
    }
    
    return 0;
}
