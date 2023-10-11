#include <stdio.h>
#include <string.h>

// Define a structure to represent a user
struct User {
    char username[100];
    char password[100];
};

void Register(struct User users[], int *currentindex) {
    struct User _user;
    printf("Enter your name: ");
    scanf("%s",_user.username);
    for(int i=0 ;i< *currentindex; i++){

        if(strcmp(users[i].username,_user.username)==0){
         printf("Username already exists.\n");
         return ;
        }
        }
            printf("Enter your password: ");
                scanf("%s",_user.password);
 users[*currentindex] = _user;
    (*currentindex)++;

    printf("Registration successful.\n");


    
   


}

int loginUser(struct User users[], int currentindex, char username[], char password[]) {
    for (int i = 0; i < currentindex; i++) {

        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {

        return i;
    }}
    
        return -1;
    

}

int main() {
    struct User users[1000]; 
    int currentindex = 0;    
    int state;
    char username[100];
    char password[100];
    int loggedInUserIndex = -1;

    while (1) {
        printf("\nclick 1 for Register\nclick 2 for Login\nclick 3 for Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &state);

        switch (state) {
            case 1:
                Register(users, &currentindex);
                break;
            case 2:
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                loggedInUserIndex = loginUser(users, currentindex, username, password);

                if (loggedInUserIndex != -1) {
                    printf("Login successful. Welcome, %s!\n", users[loggedInUserIndex].username);
                } else {
                    printf("Invalid username or password.\n");
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
