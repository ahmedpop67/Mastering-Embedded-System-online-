/*
 * main.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Egypt_Laptop
 */
#include "student.h"
extern int state;
int main(){
FIFO_init();
int choise;
int ans;
system("pause");
while((choise=instr())!=10)
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
                  search_student_by_rollnum();
                  break;
		  case 4:
				  search_student_by_fname();
				  break;
		  case 5:
				  search_student_by_cid();
				  break;
		  case 6:
	              printf("\n  number of student is %d students \n\n",get_length());
				  system("pause");
                  break;
          case 7:
                  delete_student();
                  break;
          case 8:
                  updata_student();
                  break;

          case 9:
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
