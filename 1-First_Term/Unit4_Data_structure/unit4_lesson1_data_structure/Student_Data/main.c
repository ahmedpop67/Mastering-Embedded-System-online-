/*
 * main.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Egypt_Laptop
 */
#include "student.h"
extern int state;
int main(){
int choise;
int ans;
system("pause");
while((choise=instr())!=9)
    {
system("cls");
      switch (choise)
        {
        case 1:
				state=0;
                Add_student();
				system("pause");
                break;
        case(2):
                 Add_student_fromfile();
				 system("pause");
                 break;
          case(3):
                  search_student();
                  break;
          case 4:
					system("cls");
				    printf("      * what do you want to delete *\n  1)-all\t\t2-)student id\n");
                    do{
                    printf("enter your choise: ");
                    scanf("%d",&ans);
                   }while(ans!=1&&ans!=2);
                   if(ans==2)
                    delete_student();
			   	   else delete_All();
                  break;
         case(5):
                  updata_student();
                  break;
         case(6):
                  get_id();
                  break;
         case 7:
	              printf("\n  number of student is %d students \n\n",get_length());
				  system("pause");
                  break;
         case 8:
                displsy_student();
				system("pause");
                break;
        }
        system("cls");
    }
            system("cls");
		    printf("\n\n\t\t\t\t **save changes** \n\t\t  (1) yes \t\t\t\t (2) NO\n\n");
              do{
                printf(" Enter your choise: ");
                scanf("%d",&ans);
               }while(ans!=1&&ans!=2);
               if(ans==1)
               {
                   write_into_file();
                   printf("\n\n\t\t************DONE**************\n\n");
               }
}
