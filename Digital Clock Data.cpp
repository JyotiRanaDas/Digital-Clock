#include<stdio.h>
#include"graphics.h"
#include<strings.h>
#include<stdlib.h>
#include<time.h>
int hours,mins,secs,day,t;
char null=' ';
int gettime(int *h,int *m,int *s)
{
	time_t now;
	struct tm *tm_now;
		now=time(NULL);
	tm_now=localtime(&now);
	*h=tm_now->tm_hour;
	if(*h>12)
	{
		*h-=12;
		t=1;
	}
	*m=tm_now->tm_min;
	*s=tm_now->tm_sec;
	return(t);
}
void getdate(int *years,char *months,char *days,int *dates)
{
  	time_t now;
	struct tm *tm_now;
	int week_day,month,i=0;
	char *mon[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	char *day[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	now=time(NULL);
	tm_now=localtime(&now);
	week_day=tm_now->tm_wday;
	*dates=tm_now->tm_mday;
	month=(tm_now->tm_mon)+1;
	*years=(tm_now->tm_year)+1900;
	for(i=1;i<13;i++)
	{
		if(month==i)
		  strcpy(months,mon[i-1]);
		  
	}
	for(i=1;i!=7;i++)
	{
		if(week_day==i)
		  strcpy(days,day[i]);
	}
}
int main()
{ 
int hours,mins,secs,tt;
  int gd=DETECT,gm,flag=0;
  int x=170,y=200,font=3,direction=0,size=2;
char h[3],m[3],s[3],time[20]="",a[5],b[5];
char day[30],month[30],full[100]="";
int year,date;
 initgraph(&gd,&gm,"");
  settextstyle(font,direction,size);
  setcolor(10);
  outtextxy(143,50,"DIGITAL CLOCK BY JYOTI RANA DAS");
  setcolor(11);
  size=3; // PM OR AM SIZE
  tt=gettime(&hours,&mins,&secs);
  (tt==1)?outtextxy(410,223,"PM"):outtextxy(410,223,"AM");
  getdate(&year,month,day,&date);
  sprintf(a,"%d",date);
  strcat(full,a);
  strcat(full,", ");
  strcat(full,month);
  strcat(full,", ");
  strcat(full,day);
  strcat(full,", ");
  sprintf(b,"%d",year);
  strcat(full,b);
  size=3;// DATE SIZE
  font=10;
  setcolor(12);
  settextstyle(font,direction,size);
  outtextxy(142,300,full);
  size=6; // TIME SIZE
  font=3;
  settextstyle(font,direction,size);
  setcolor(11);
  while(1)
  {
  tt=gettime(&hours,&mins,&secs);
    if(hours<10)
     {
     	strcat(time,"0");
       hours :
     	sprintf(h,"%d",hours);
     	strcat(time,h);
     	strcat(time,":");
     	if(mins<10)
     	{
     			strcat(time,"0");
     			mins :
     			 sprintf(m,"%d",mins);
     	         strcat(time,m);
     	         strcat(time,":");
     	         if(secs<10)
     	         {
     	           strcat(time,"0");
     			   secs :
     			    sprintf(s,"%d",secs);
     	            strcat(time,s);
     	            outtextxy(x,y,time);
				 }
				 else
				 {
				 	goto secs;
				 }
     	         
	    }
	    else
	    {
	    	goto mins;
		}
	 }
	else
	{
		goto hours;
	}
	sprintf(time,"%c",null);
  }
  cleardevice();
  closegraph();
	return 0;
}