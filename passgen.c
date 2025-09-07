#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>
//#include <windows.h> //*******must uncomment this if u are running in windows
// machine, as i made this tool using andorid devics so i commented this******

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear"); // as im using android compiler so i added this. for windows
                   // just use system("cls");
#endif
}

struct myPass {
  char title[200][64];
  char pass[200][64];
};

void isValidSession() {
  char mahbub[64];
  FILE *read = fopen("mahbub.bin", "rb");

  if (read == NULL) {
    printf("Welcome!\n***This is a tool with 'C'***\n1.Generate Strong "
           "Password with random Algorithm\n2.Give Unique Title to "
           "password\n3.Save All Generated Password with the title u "
           "gave\n4.Edit Title and Password\n5.Check all saved password with "
           "2D visual created with table style\n6.Password and Title will be "
           "backedup in your device directory so it is totaly offline\n7.Title "
           "and password will be in binary format so its kind of "
           "encrypted.\n8.Fully supported on any console\n9.After Showing all password ,it will be auto hide after 10 seconds\n\nIn version 1.69,we added Reset Password and reset Tool option\n\n\nAs this is a "
           "password generator and backuping tool,so u need to protect this "
           "tool too,\nEnter a password to encrypt this tool:");
    if (fgets(mahbub, sizeof(mahbub), stdin) != NULL) {
      mahbub[strcspn(mahbub, "\n")] = '\0';
      FILE *write = fopen("mahbub.bin", "wb");

      fwrite(mahbub, sizeof(char), 64, write);
      fclose(write);
      printf(
          "\n\nCongrats!!! Password successfully created\nNow enter password "
          "evertime u want to access the tool\nGood Luck\nRestart to continue");
      exit(1);
    }
  } else {
    char myPass[64];
    fread(myPass, sizeof(char), 64, read);
    fclose(read);
    printf("Enter password: \n");
    fgets(mahbub, sizeof(mahbub), stdin);
    mahbub[strcspn(mahbub, "\n")] = '\0';
    if (strcmp(myPass, mahbub) == 0) {
      clearScreen();
      printf("Welcome To PassGen V1.69\n");
    } else {
      printf("Invalid Password");
      exit(1);
    }
  }
}

void MainMenu() {
  printf("1-5 to Interract, any other character to Quit.\n\n1.See Saved "
         "Password\n2.Add Password\n3.Edit Password\n4.Change Tool Password\n5.Reset All\n\nEnter Your Choice: ");
}

int main() {

  isValidSession();
  char pass_gen[90];
  for (int i = 0; i < 90; i++) {
    if (i + 36 == 92) {
      pass_gen[i] = '%';
    } else {
      pass_gen[i] = (char)(36 + i);
    }
  }

  char encrypted_by_mahbub2[9] = "˲VJQ";
  strcat(encrypted_by_mahbub2, "K^K");
  printf("\nDecrypting encrypted data, please wait 10 seconds\nA Test Project, "
         "By ");
  for (int j = 0; j < sizeof(encrypted_by_mahbub2) - 1; j++) {
    printf("%c", encrypted_by_mahbub2[j] - 9);
    sleep(1);
    fflush(stdout);
  }

  int mahbubTanmay = 0;

  while (1) {
    if (mahbubTanmay == 10) {
      sleep(10);
      clearScreen();
    } else if (mahbubTanmay == 5) {
      sleep(5);
      clearScreen();
    } else {
      clearScreen();
    }
    mahbubTanmay = 10;

    int total_pass;
    FILE *read = fopen("total.bin", "rb");
    if (read == NULL) {
      total_pass = 0;
    } else {
      fread(&total_pass, sizeof(int), 1, read);
      fclose(read);
    }

    printf("Total Saved Password: %d\n", total_pass);

    char option;
    MainMenu();
    scanf(" %c", &option);

    struct myPass myPass;

    if (option == '1') {
      printf("All Saved Password:\nTotal : %d\n", total_pass);
      printf("**We will hide it after 10 Seconds**\n");
      printf(" _______________________________________________________\n");
      printf("| POSITION     |     TITLE    |         PASSWORD        |");
      printf("\n|______________|______________|_________________________|\n");
      FILE *read2 = fopen("pass.bin", "rb");
      if (read == NULL) {

      } else {
        fread(&myPass, sizeof(myPass), 1, read2);
        fclose(read2);
        for (int i = 0; i < total_pass; i++) {
          // printf("%d        :  %s:  %s\n",i,myPass.title[i],myPass.pass[i]);
          printf("| %d            |", i);
          printf(" %s", myPass.title[i]);
          for (int k = 0; k < 13 - (int)strlen(myPass.title[i]); k++) {
            printf(" ");
          }
          printf("| %s", myPass.pass[i]);
          for (int k = 0; k < 24 - (int)strlen(myPass.pass[i]); k++) {
            printf(" ");
          }

          printf("|");
          printf(
              "\n|______________|______________|_________________________|\n");
        }
      }

    } else if (option == '2') {

      FILE *read = fopen("total.bin", "rb");
      if (read == NULL) {
        total_pass = 0;
      } else {
        fread(&total_pass, sizeof(int), 1, read);
        fclose(read);
      }

      FILE *read2 = fopen("pass.bin", "rb");
      if (read == NULL) {

      } else {
        fread(&myPass, sizeof(myPass), 1, read2);
        fclose(read2);
      }
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      char mahbub[64];

      while (2) {
        int tmp2 = 0;
        printf("Enter a password title: ");
        fgets(mahbub, sizeof(mahbub), stdin);
        mahbub[strcspn(mahbub, "\n")] = '\0';
        if (total_pass == 0) {
          strcpy(myPass.title[total_pass], mahbub);
          break;
        } else {
          for (int i = 0; i < total_pass; i++) {
            if (strcmp(myPass.title[i], mahbub) == 0) {
              tmp2 = 1;
              printf("Already Used Title.Enter New\n");
              break;
            }
          }
          if (tmp2 == 0) {
            strcpy(myPass.title[total_pass], mahbub);
            break;
          }
        }
      }
      printf("Enter password length: ");
      fgets(mahbub, sizeof(mahbub), stdin);
      mahbub[strcspn(mahbub, "\n")] = '\0';

      int length;
      sscanf(mahbub, "%d", &length);
      char genPass[length + 1];
      srand(time(NULL));
      for (int i = 0; i < length; i++) {

      #ifdef _WIN32
      int k = rand() % 89 + 1;
      #else
      int k = random() % 89 + 1;
      #endif


        genPass[i] = pass_gen[k];
      }
      genPass[length] = '\0';
      printf("\n\nPlease wait 5 seconds while we process your password...");
      printf("\nGenerated Password: %s\n", genPass);
      mahbubTanmay = 5;
      strcpy(myPass.pass[total_pass], genPass);
      total_pass++;

      FILE *write = fopen("total.bin", "wb");

      fwrite(&total_pass, sizeof(int), 1, write);
      fclose(write);

      FILE *write2 = fopen("pass.bin", "wb");

      fwrite(&myPass, sizeof(myPass), 1, write2);
      fclose(write2);

    }

    else if (option == '3') {
      if (total_pass == 0) {
        mahbubTanmay = 5;
        printf("\n\n***You currently have 0 password saved.***\n***Enter new "
               "password before u try 2 edit***\n(Please wait 5 seconds. we "
               "are returning to main menu.....\n");
      } else {

        FILE *read = fopen("total.bin", "rb");
        if (read == NULL) {
          total_pass = 0;
        } else {
          fread(&total_pass, sizeof(int), 1, read);
          fclose(read);
        }

        FILE *read2 = fopen("pass.bin", "rb");
        if (read == NULL) {

        } else {
          fread(&myPass, sizeof(myPass), 1, read2);
          fclose(read2);
        }

        int pos;
        printf("Which Position to edit:\n");
        scanf("%d", &pos);
        while (pos > total_pass - 1 || pos < 0) {
          printf("Invalid Position\n");
          printf("Which Position to edit:\n");
          scanf("%d", &pos);
        }

        char c;
        while ((c = getchar()) != '\n' && c != EOF)
          ;
        char mahbub[64];

        while (1) {
          printf("Enter a password title: ");
          fgets(mahbub, sizeof(mahbub), stdin);
          mahbub[strcspn(mahbub, "\n")] = '\0';

          int tmp2 = 1;
          for (int i = 0; i < total_pass; i++) {
            if (i == pos) {
              continue;
            }
            if (strcmp(myPass.title[i], mahbub) == 0) {
              tmp2 = 0;
              printf("Already Used Title. Enter New\n");
              break;
            }
          }

          if (tmp2 == 1) {
            strcpy(myPass.title[pos], mahbub);
            break;
          }
        }

        printf("Enter password length: ");
        fgets(mahbub, sizeof(mahbub), stdin);
        mahbub[strcspn(mahbub, "\n")] = '\0';

        int length;
        sscanf(mahbub, "%d", &length);
        char genPass[length + 1];
        srand(time(NULL));
        for (int i = 0; i < length; i++) {

       #ifdef _WIN32
       int k = rand() % 89 + 1;
       #else
       int k = random() % 89 + 1;
       #endif

          genPass[i] = pass_gen[k];
        }
        genPass[length] = '\0';
        printf("\n\nPlease wait 5 seconds while we process your password...");
        printf("\nGenerated Password: %s\n", genPass);
        mahbubTanmay = 5;
        strcpy(myPass.pass[pos], genPass);

        FILE *write2 = fopen("pass.bin", "wb");

        fwrite(&myPass, sizeof(myPass), 1, write2);
        fclose(write2);
      }
    }

    else if (option == '4') {

      char mahbub[64];
  FILE *read = fopen("mahbub.bin", "rb");

  if (read == NULL) {
    printf("There is a problem Opening the file!! Try Again\n");
  }
  else{
        char c;
  while((c=getchar())!='\n'  && c!=EOF);

  printf("Enter New Password: ");

    if (fgets(mahbub, sizeof(mahbub), stdin) != NULL) {
      mahbub[strcspn(mahbub, "\n")] = '\0';
      FILE *write = fopen("mahbub.bin", "wb");

      fwrite(mahbub, sizeof(char), 64, write);
      fclose(write);
      printf(
          "\n\nCongrats!!! Password successfully changed");
      exit(1);
    }

    }


}

else if (option == '5'){

    if(remove("mahbub.bin")==0){
       if(remove("total.bin")==0){
        if(remove("pass.bin")==0){
       printf("Reset Completed!!");
        exit(1);

    }
    else{

        printf("Maybe Reset Failed. Try Again!!");
        exit(1);
    }

    }

    }
}

      else {
      clearScreen();
      printf("\nThanks for using my tool.\nSubmit any bugs report "
             "at:\ngithub.com/MdMahbubTanmay\n\n    -----Sincerely Mahbub\n");
      break;
    }
  }
  return 0;
}
