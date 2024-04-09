#include<stdio.h>
#include<stdlib.h>


void main()
{
	int *pagerefstr, *frame,*framecnt, pages, frames, counter=0, flag1,flag2,i,j,k,faults=0,min,pos;
       printf("\nEnter Number of pages: ");
       scanf("%d",&pages);
       printf("\nEnter number of frames: ");
       scanf("%d",&frames);
       printf("\nEnter pages reference string values: ");
       pagerefstr=(int *)malloc(pages*sizeof(int));
       for(i=0;i<pages;i++)
       {
	       printf("\nvalue %d: ",i+1);
	       scanf("%d",&pagerefstr[i]);
       }

       frame=(int*)malloc(frames*sizeof(int));
       framecnt=(int*)malloc(frames*sizeof(int));

       for(i=0;i<frames;i++)
       {
	       frame[i]=-1;
		 framecnt[i]=100;
       }

       for(i=0;i<pages;i++)
       {
	      		 flag1=0,flag2=0;
	      		 for(j=0;j<frames;j++)
	      		 {
		      		 if(frame[j]==pagerefstr[i])
		      		 {
			     		  counter++;
			      		 framecnt[j]=counter;
			      		 flag1=flag2=1;
			     		  break;
		     		  }
	      		 }

		       if(flag1==0)
		       {
			       for(j=0;j<frames;j++)
			       {
				       if(frame[j]==-1)
				       {
					       counter++;
					       faults++;
					       frame[j]=pagerefstr[i];
					       framecnt[j]=counter;
				     		flag2=1;
						break;
				       }
			       }
		       }

		       if(flag2==0)
		       {
			       //Finding minimum position
			     pos=0, min=frame[0];
			       for(j=1;j<frames;j++)
			       {
				       if(min>frame[j])
				       {
					       min=frame[j];
					       pos=j;
				       }

			       }
		       		counter++;
				faults++;
				frame[pos]=pagerefstr[i];
				framecnt[pos]=counter;
		       }

		       for(j=0;j<frames;j++)
		       {
			       printf("%d\t",frame[j]);
		       }
		       printf("\n");
	  }

	       printf("\nTotal page Faults: %d",faults);
 }


  
	    
	       
