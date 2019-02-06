#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEVICE1 "/dev/adxl_x"
#define DEVICE2 "/dev/adxl_y"
#define DEVICE3 "/dev/adxl_z"

int convert(int);
char ch;
int main()  {
	int i,fd1,fd2,fd3,bin;
	unsigned int f;
	char ch,write_buf[100],read_buf[100];
	
	printf("Enter your choice\n x: Access adxl_x device\n y:Access adxl_y device\n z:Access adxl_z device\n");
	scanf("%c",&ch);
	
	switch(ch) {
	
	case 'x':{
		fd1 =open(DEVICE1, O_RDWR);
		if(fd1==-1){
			printf("file %s either doesn't exist or locked by other process",DEVICE1);
			exit(-1);
			}
		printf("Reading from the device adxl_x\n");
	
		read(fd1,read_buf,sizeof(read_buf));
		printf("the value of Rx is: ");
		for(i=0;i<10;i++){
		
		printf("%d",read_buf[i]);
		}
		//f=read_buf[0];
		//bin=convert(f);
		//printf("the value of Rxbin: %d\n",bin);
		close(fd1);
		break;
		}
	case 'y':{
		
		fd2 =open(DEVICE2, O_RDWR);
		if(fd2==-1){
			printf("file %s either doesn't exist or locked by other process",DEVICE2);
			exit(-1);
			}
		printf("Reading from the device adxl_y\n");
	
		read(fd2,read_buf,sizeof(read_buf));
		printf("the value of Ry is:");
		for(i=0;i<10;i++){
		
		printf("%d",read_buf[i]);
		}
		//f=read_buf[0];
		//bin=convert(f);
		//printf("the value of Rybin: %d\n",bin);
		close(fd2);
		break;
		}
	case 'z':{
	
		fd3 =open(DEVICE3, O_RDWR);
		if(fd3==-1){
			printf("file %s either doesn't exist or locked by other process",DEVICE3);
			exit(-1);
			}
		printf("Reading from the device adxl_z\n");
	
		read(fd3,read_buf,sizeof(read_buf));
                printf("the value of Rz is:");
		for(i=0;i<10;i++){
		
		printf("%d",read_buf[i]);
		}
		//f=read_buf[0];
		//bin=convert(f);
		//printf("the value of Rzbin: %d\n",bin);
		close(fd3);
		break;
		}
	default:
		printf("Enter correct choice\n");
		break;	
}	
	return 0;
}

int convert(int dec)
{

    if (dec == 0)
    {
        return 0;
    }
    else
    {
        return (dec % 2 + 10 * convert(dec / 2));
    }
}














