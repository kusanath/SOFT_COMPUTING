/* program to implement different disk scheduling algorithms.*/

#include<stdio.h>
#include<stdlib.h>
void main(){
    int i,j ,num_cylinder,num,seek=0,diff,start_pos,ch,a[50],index[50],s=0,cp,r[50],max=0,dloc=0,temp,prv;
    printf("Enter maximum number of cylinders:");
    scanf("%d",&num_cylinder);
    printf("Enter number of Queue elements:");
    scanf("%d",&num);
    int queue[num],wrk_queue[num];
    printf("Enter work queue:");
    for(i=0;i<num;i++)
    {
    scanf("%d",&wrk_queue[i]);
        
    }
    for(j=1;j<=num;j++){
        queue[j]=wrk_queue[j-1];
    }
    
    printf("Enter disk starting position:");
    scanf("%d",&start_pos);
    printf("Enter previous position:");
    scanf("%d",&prv);
    printf("\n MENU");
    printf("\n 1.FCFS");
    printf("\n 2.SSTF");
    printf("\n 3.SCAN");
    printf("\n 4.EXIT");
    
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch (ch){
            case 1:
            printf("FCFS\n\n");
            queue[0]=start_pos;
            for(i=0;i<num;i++){
                diff=abs(queue[i+1]-queue[i]);
                seek=seek+diff;
                
            }
            printf("\nTotal seek time=%d\n",seek);
            break;
            
            case 2:
            printf("SSTF");
            cp=start_pos;
            for(int k=0;k<num;k++){
                for(int i=0;i<num;i++){
                    index[i]=abs(start_pos-wrk_queue[i]);
                }
               int min=index[0];
               int mini=0;
               for(i=1;i<num;i++){
                   if (min>index[i]){
                       min=index[i];
                       mini=i;
                       
                   }
               }
               a[s]=wrk_queue[mini];
               s++;
               start_pos=wrk_queue[mini];
               wrk_queue[mini]=999;
            }
            seek=seek+abs(cp-a[0]);
            for(i=1;i<num;i++){
                seek=seek+abs(a[i]-a[i-1]);
            }
            printf("\nTotal seek time=%d\n",seek);
            break;
            case 3:
            printf("\nSCAN");
            if(start_pos<prv){
            wrk_queue[num]=start_pos;
            num=num+1;
            for(i=0;i<num;i++){
                for(j=i;j<num;j++){
                    if(wrk_queue[i]>wrk_queue[j]){
                        temp=wrk_queue[i];
                        wrk_queue[i]=wrk_queue[j];
                        wrk_queue[j]=temp;
                    }
                }
            }
            max=wrk_queue[num];
            for(i=0;i<num;i++){
                if (start_pos==wrk_queue[i]){
                    dloc=i;
                    break;
                }
            }
            for(i=dloc;i>=0;i--){
                r[s]=wrk_queue[i];
                s++;
            }
            r[s]=0;
            s++;
            for(i=dloc+1;i<num;i++){
                r[s]=wrk_queue[i];
                s++;
            }
            for(i=0;i<num;i++){
                diff=abs(r[i+1]-r[i]);
                seek=seek+diff;
            }
            printf("\nThe total seek time=%d",seek);
            }
            else{
                 wrk_queue[num]=start_pos;
            num=num+1;
            for(i=0;i<num;i++){
                for(j=i;j<num;j++){
                    if(wrk_queue[i]<wrk_queue[j]){
                        temp=wrk_queue[i];
                        wrk_queue[i]=wrk_queue[j];
                        wrk_queue[j]=temp;
                    }
                }
            }
            max=wrk_queue[num];
            for(i=0;i<num;i++){
                if (start_pos==wrk_queue[i]){
                    dloc=i;
                    break;
                }
            }
            for(i=dloc;i>=0;i--){
                r[s]=wrk_queue[i];
                s++;
            }
            r[s]=num_cylinder;
            s++;
            for(i=dloc+1;i<num;i++){
                r[s]=wrk_queue[i];
                s++;
            }
            for(i=0;i<num;i++){
                diff=abs(r[i+1]-r[i]);
                seek=seek+diff;
            }
            printf("\nThe total seek time=%d",seek);
                
            }
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid");
            
            
    }
    }
