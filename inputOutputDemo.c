#include<stdio.h>

void main()
{
  int age;
  printf("Enter your age : \n");
  scanf("%d",&age);

  printf("Age : %d",age);

  float mks;
  printf("Enter your marks : \n");
  scanf("%f",&mks);

  printf("Your marks : %f\n",mks);

  printf("Voting check!!!!\n");

  if(age >= 18)
  {
    printf("You can vote now\n");
  }
  else{
    printf("You cannot vote\n");
  }

}