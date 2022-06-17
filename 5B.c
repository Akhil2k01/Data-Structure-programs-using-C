#include <stdio.h>
int count=0;
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
  count++;
if (n == 1)
{
printf("\n Move disk 1 from rod %c to rod %c", source, destination);
return;
}
towerOfHanoi(n-1,source, destination, auxiliary);
printf("\n Move disk %d from rod %c to rod %c", n, source, destination);
towerOfHanoi(n-1, auxiliary, source, destination);
}
void main()
{
int n;
printf("Enter the number of disks\n");
scanf("%d",&n);
towerOfHanoi(n, 'A', 'B', 'C');
printf("\nTotal No. of Steps = %d\n",count);
}
