#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
float cx,cy;
long count=0,dist=0,dist2=0,dist3=0,dist4=0,dist5=0,rinn=0,rout=0,rcor=0,x=0,y=0;
char a,type[5],f,msg[255],re,file[20],path[30];
int r,g,b,w,h,max,avg,bri,l=0,stem1=0,stem2=0,stem3=0,stem4=0;
double dx,dy;
FILE *fh,*ch;
clrscr();
printf("enter the file name you want to use:");
scanf("%s",file);
strcpy(path,"images/");
strcat(path,file);
menu:
printf("=====================================================================\n");
printf("                       IMAGE EDITOR  v1.0                            \n");
printf("=====================================================================\n");
printf("         [1] Invert colours                                          \n");
printf("         [2] Greyscale image                                          \n");
printf("         [3] ASCII Art generator                                          \n");
printf("         [4] Brightness changer                                        \n");
printf("         [5] Filters                                        \n");
printf("         [6] Steganography                                          \n");
printf("         [7] Exit                                          \n");
printf("=====================================================================\n");
printf("  Enter your choice :");

scanf(" %c",&a);
switch(a)
{
case '1':
{
fh=fopen(path,"r");
ch=fopen("images/result.ppm","w");

fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
{

r=255-r;
b=255-b;
g=255-g;
fprintf(ch,"%d %d %d\n",r,g,b);
}
printf("completed action\n");
fclose(fh);
fclose(ch);
goto menu;
}
case '2':
{
fh=fopen(path,"r");
ch=fopen("images/result.ppm","w");

fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
{
avg=0;
avg=(int)(((long)r+b+g)/3);

fprintf(ch,"%d %d %d\n",avg,avg,avg);
}
printf("completed action\n");
fclose(fh);
fclose(ch);
goto menu;
}
case '3':
{
fh=fopen(path,"r");
ch=fopen("images/asciart.txt","w");
fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
{
count++;
avg=0;
avg=(r+b+g)/3;
if (avg<50)
{
fputc(' ',ch);
fputc(' ',ch);
}
else if (avg<100)
{
fputc('.',ch);
fputc('.',ch);
}
else if (avg<150)
fputs("**",ch);
else if (avg<200)
fputs("@@",ch);
else
fputs("##",ch);
	if (count>=w)
	{
	fputc('\n',ch);
	count=0;
	}
}
printf("completed action\n");
fclose(fh);
fclose(ch);
goto menu;
}
case '4':
{
fh=fopen(path,"r");
ch=fopen("images/result.ppm","w");

fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
printf("Enter the amount of brightness you want to change:");
scanf("%d",&bri);
while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
{
r=r+bri;
g=g+bri;
b=b+bri;
if ( r>255)
r=255;
else if(r<0)
r=0;
if ( g>255)
g=255;
else if(g<0)
g=0;
if ( b>255)
b=255;
else if(b<0)
b=0;
fprintf(ch,"%d %d %d\n",r,g,b);
}
printf("completed action\n");
fclose(fh);
fclose(ch);
goto menu;
}
case '5':
{       filter:
	printf("\n1)glitch\n2)static noise\n3)underwater\n4)old camera\n  Enter your choice:");
	scanf(" %c",&f);
	switch(f)
	{
	case '1':
	{
	fh=fopen(path,"r");
	ch=fopen("images/filterz.ppm","w");
	count=0;
	fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
	fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
	while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
	{
	count++;
	if (count/w %40 <10)
	{
	r=r+(rand() %80);
	b=b+(rand() %80);
	g=g+(rand() %80);
	}

	fprintf(ch,"%d %d %d\n",r,g,b);
	}
	printf("completed action\n");
	fclose(fh);
	fclose(ch);
	goto filter;
	}
	case '3':
	{
	fh=fopen(path,"r");
	ch=fopen("images/filterz.ppm","w");

	fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
	fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
	while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
	{
	rout=(w*0.05)*(w*0.05);
	rinn=(w*0.04)*(w*0.04);
	rcor=(w*0.03)*(w*0.03);

	x=count%w;
	y=count/w;
	count++;
	stem1=w*0.20+(int)(15.0*sin(y*0.05));
	stem2=w*0.80+(int)(19.0*sin(y*0.07));
	stem3=w*0.90+(int)(20.0*sin(y*0.08));
	stem4=w*0.50+(int)(17.0*sin(y*0.06));
	r=r/2;
	g=g+20;
	b=b+60;

	dist=(x-w*0.25)*(x-w*0.25)+(y-h*0.40)*(y-h*0.40);
	dist2=(x-w*0.70)*(x-w*0.70)+(y-h*0.25)*(y-h*0.25);
	dist5=(x-w*0.85)*(x-w*0.85)+(y-h*0.70)*(y-h*0.70);
	if(y>h*0.65)
	{
	if(abs(x-stem1)<4||abs(x-stem2)<4||abs(x-stem3)<4||abs(x-stem4)<4)
	{
	r=50;
	g=255;
	b=150;
	}
	}
	if (dist>=rinn && dist <=rout|| dist2>=rinn && dist2 <=rout ||dist5>=rinn && dist5 <=rout)
	{
	r=250;
	g=255;
	b=255;
	}
	else if(dist<rcor||dist2<rcor||dist5<rcor)
	{
	r=r+15;
	g=g+20;
	b=b+30;
	if (r>255)
	r=255;
	if (g>255)
	g=255;
	if (b>255)
	b=255;
	}
	else
	{
	r=r/4;
	g=g/4;
	b=b/2;
	}

	fprintf(ch,"%d %d %d\n",r,g,b);
	}
	printf("completed action\n");
	fclose(fh);
	fclose(ch);
	goto filter;
	}
	case '2':
	{
	fh=fopen(path,"r");
	ch=fopen("images/filterz.ppm","w");

	fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
	fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
	while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
	{
	r=r+(rand()%201)-100;
	b=b+(rand()%201)-100;
	g=g+(rand()%201)-100;
	if (r>255)
	r=255;
	if (g>255)
	g=255;
	if (b>255)
	b=255;
	if (r<0)
	r=0;
	if (g<0)
	g=0;
	if (b<0)
	b=0;
	fprintf(ch,"%d %d %d\n",r,g,b);
	}
	printf("completed action\n");
	fclose(fh);
	fclose(ch);
	goto filter;
	}
	case '4':
	{
	fh=fopen(path,"r");
	ch=fopen("images/filterz.ppm","w");
	count=0;
	fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
	fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
	while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
	{

	r=min(255,(int)(r*1.15+10));
	b=(int)(b*0.85);
	g=min(255,(int)(g*1.05+5));
	if (r<30)
	r=30;
	r=(r>128) ? min(255,r+15): max(0,r-15);
	g=(g>128) ? min(255,g+15): max(0,g-15);
	b=(b>128) ? min(255,b+15): max(0,b-15);

	r=r+(rand()%31)-15;
	g=g+(rand()%31)-15;
	b=b+(rand()%31)-15;
	if (r>255)
	r=255;
	if (g>255)
	g=255;
	if (b>255)
	b=255;
	if (r<0)
	r=0;
	if (g<0)
	g=0;
	if (b<0)
	b=0;

	x=count%w;
	y=count/w;

	cx=(float)w/2.0;
	cy=(float)h/2.0;
	dist3=sqrt(cx*cx+cy*cy)*0.7;
	dist4=sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy));

	r=(int)(r*(1.0-(dist4/dist3)*(dist4/dist3)* 0.6));
	g=(int)(g*(1.0-(dist4/dist3)*(dist4/dist3)* 0.6));
	b=(int)(b*(1.0-(dist4/dist3)*(dist4/dist3)* 0.6));
	if (r<0)
	r=0;
	if (g<0)
	g=0;
	if (b<0)
	b=0;
	fprintf(ch,"%d %d %d\n",r,g,b);
	count++;
	}
	printf("completed action\n");

	fclose(fh);
	fclose(ch);
	goto filter;
	}
	case '5':
	goto menu;
	default:
	{
	printf("invalid option");
	goto filter;
	}
	}
}
case '6':
{
printf("encrypt or decrypt message?(E/D)");
scanf("%s",&re);
if (re=='E'|| re=='e')
{
fh=fopen(path,"r");
ch=fopen("images/secret.ppm","w");

fscanf(fh,"%s%d%d%d",type,&w,&h,&max);
fprintf(ch,"%s\n%d %d\n%d\n",type,w,h,max);
printf("enter the message you want to encrypt:");
scanf("%[^\t]c",msg);
count=0;
while(fscanf(fh,"%d%d%d",&r,&g,&b)!=EOF)
{
l=strlen(msg);
if (count<l)
r=msg[count];
else if(count==l)
r=0;
count++;
fprintf(ch,"%d %d %d\n",r,g,b);
}
printf("completed action\n");
fclose(fh);
fclose(ch);
}
else if(re =='D'||re=='d')
{
printf("Decoded message:\n");
ch=fopen(path,"r");
fscanf(ch,"%s%d%d%d",type,&w,&h,&max);
while(fscanf(ch,"%d%d%d",&r,&g,&b)!=EOF)
{
if (r!=0)
printf("%c",r);
else
break;
}
fclose(ch);
}
goto menu;
}

case '7':
break;
default:
{
printf("invalid option");
goto menu;
}
}

fclose(fh);
fclose(ch);
getch();
}
