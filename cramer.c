//code to implement cramer's rule and solve a system of 3 equations
#include <stdio.h>

float matrix[12];//contains the entire equation
float solution[3];//contains the solutions(the left handside of the equation)
float array[9];//contains the right handside of the equation
char names[7]={'a','b','c','d','1','2','3'};//forasking user



void getInput(){
    //gets the user input
    int j=0;
    int k=4;
    int l=0;
    for (int i = 0; i < 12; i++)
    {
        printf("Enter %c%c:",names[j],names[k]);
        

        scanf("%f",&matrix[i]);
        
        

        j++;
        if (j>3)
        {
            k++;
            j=0;
        }
        
    }
    int m=0;int f=0;
    for (int i = 0; i < 12; i++)
    {
        if (i==3 || i==7 || i==11)
        {
            solution[f]=matrix[i];
            f++;
        }else{
            array[m]=matrix[i];
            m++;
        }
        
    }
    
    
}
int getDet(){
    //gets the overal determinant
    float det,a,b,c;
    a=array[0]*((array[4]*array[8])-(array[5]*array[7]));
    b=array[1]*((array[3]*array[8])-(array[5]*array[6]));
    c=array[2]*((array[3]*array[7])-(array[4]*array[6]));
    det=a-b+c;
    return det;
}
int getDetX(){
    //gets the determinant for X
    float det,a,b,c;
    a=solution[0]*((array[4]*array[8])-(array[5]*array[7]));
    b=array[1]*((solution[1]*array[8])-(array[5]*solution[2]));
    c=array[2]*((solution[1]*array[7])-(array[4]*solution[2]));
    
    det=a-b+c;
    return det;
}
int getDetY(){
    //gets the determinant for Y
    int det,a,b,c;
    a=array[0]*((solution[1]*array[8])-(array[5]*solution[2]));
    b=solution[0]*((array[3]*array[8])-(array[5]*array[6]));
    c=array[2]*((array[3]*solution[2])-(solution[1]*array[6]));

    det=a-b+c;
    return det;
}
int getDetZ(){
    //gets the determinant for Z
    float det,a,b,c;
    a=array[0]*((array[4]*solution[2])-(solution[1]*array[7]));
    b=array[1]*((array[3]*solution[2])-(solution[1]*array[6]));
    c=solution[0]*((array[3]*array[7])-(array[4]*array[6]));
    printf("a=%f,b=%f,c=%f\n",a,b,c);
    det=a-b+c;
    return det;
}
int main(){
    float x,y,z,det,detX,detY,detZ;

    getInput();
    det=getDet();
    detX=getDetX();
    detY=getDetY();
    detZ=getDetZ();


    
    x=detX/det;
    y=detY/det;
    z=detZ/det;

    printf("Det=%f\n",detY);
    printf("x=%f,y=%f,z=%f",x,y,z);


}

/*
1 2 3 4

5 6 7 8

9 10 11 12
*/