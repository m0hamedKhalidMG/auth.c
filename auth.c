#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
struct User
{
    char username[100];
    char password[100];
};

    union state{
    struct {
        int type; 
        int active;
    } integerData;
    struct {
        int type;
        bool active;
    } boolData;
};
struct UserState {
    struct User user;
    union state userState;
};
void Register(struct UserState users[], int *currentindex,union state data)
{

    struct UserState _user;
    printf("Enter your name: ");
    scanf("%s", _user.user.username);
    for (int i = 0; i < * currentindex; i++)
    {

        if (strcmp(users[i].user.username, _user.user.username) == 0)
        {
            printf("Username already exists.\n");
            return;
        }
    }
    printf("Enter your password: ");
    scanf("%s", _user.user.password);
    printf("do you want active this user?.\n");
 printf("Enter true or false or 0 or 1: ");
     char input[10];
    scanf("%s", input);
       if (strcmp(input, "true") == 0) {
        data.boolData.type = 1;
        data.boolData.active=true;
} else if (strcmp(input, "false") == 0) {
 data.boolData.type = 1;
 data.boolData.active=false;
    
}
else if (strcmp(input, "0") == 0) {
 data.integerData.type = 1;
 data.integerData.active=0;
    
}else if (strcmp(input, "1") == 0) {
 data.integerData.type = 1;
 data.integerData.active=1;
    
}

_user.userState=data;
    users[*currentindex] = _user;
        (*currentindex)++;
        


    printf("Registration successful.\n");
}

int loginUser(struct UserState users[], int currentindex, char username[], char password[])
{
    for (int i = 0; i < currentindex; i++)
    {
        if (strcmp(users[i].user.username, username) == 0 && strcmp(users[i].user.password, password) == 0 )
        {
        if(users[i].userState.integerData.active==1||users[i].userState.boolData.active==true){
            return i;
        }
        else{
                       printf("not active user.\n");

                return -1;
}

           
        }
        
        }


        
    
             printf("Invalid username or password.\n");
             
               return -1;
    

}

int main()
{
        union state _state;        
    struct UserState users[1000];
    int currentindex = 0;
    int state;
    char username[100];
    char password[100];
    int loggedInUserIndex = -1;

    while (1)
    {
        printf("\nclick 1 for Register\nclick 2 for Login\nclick 3 for Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &state);

        switch (state)
        {
        case 1:
            Register(users, &currentindex,_state);
            break;
        case 2:
            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter your password: ");
            scanf("%s", password);

            loggedInUserIndex = loginUser(users, currentindex, username, password);

            if (loggedInUserIndex != -1)
            {
                printf("Login successful. Welcome, %s!\n", users[loggedInUserIndex].user.username);
            }
         
           
            break;
        case 3:
            printf("logout!\n");
            return 0;
        default:
            printf("Invalid number .\n");
            break;
        }
    }

    return 0;
}
