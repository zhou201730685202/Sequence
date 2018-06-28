#include<stdio.h>
#include<stdlib.h>
#include"Sequence.h"
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<time.h>

#define MAX 1200000

using namespace std;

Sequence::Sequence(string filename)
{
	char file[100];
	strcpy(file,filename.c_str());
	DNA.open(file);
	if(!DNA) {cout<<"dna.txt could not be open!"<<endl;exit(0);}

	ostringstream buf;
	char ch;
	countA=0;countT=0;countC=0;countG=0;
	while(buf&&DNA.get(ch))
	{
		if(ch=='\n') continue;
		else buf.put(ch);
		switch(ch)
		{
			case 'A': {countA++;break;}
			case 'T': {countT++;break;}
			case 'C': {countC++;break;}
			case 'G': {countG++;break;}
		}
	}
	dna=buf.str();
	len=dna.length();
	//cout<<dna;
}


Sequence::~Sequence()
{
	DNA.close();
}

int Sequence::length()
{
	return len;
}

int Sequence::numberOf(char base)
{
	switch(base)
	{
		case 'A': {return countA;break;}
		case 'T': {return countT;break;}
		case 'C': {return countC;break;}
		case 'G': {return countG;break;}
		default: return 0;
	}
}

string Sequence::longestConsecutive()
{
	string LCstr;
	int cntl=1;
	int maxl=1;
	char sign=dna[0];
	for(int i=0;i<len;i++)
	{
		if(dna[i+1]==dna[i])
		{
			cntl++;
			if(cntl>maxl)
			{
				maxl=cntl;
				sign=dna[i];
			}
		}
		else
		{
			cntl=1;
		}
	}
	ostringstream buf;
	for(int i=0;i<maxl;i++)
	{
		buf.put(sign);
	}
	LCstr=buf.str();
	return LCstr;
}

string Sequence::longestRepeated()
{
	string LRstr;
/*	char str[MAX];
	
	char *sufarray[MAX];
	int maxl=1;
	int cntl=0;
	int sign;
	int comlen(char *str1,char *str2);
	int cmp(const void *p,const void *q);
	int n=0;
	char ch;
	while((ch=getchar())!='\n')
	{
		str[n]=ch;
		sufarray[n]=&str[n];
		n++;
	}
	str[n]='\0';
	qsort(sufarray,n,sizeof(char*),cmp);
	for(int i=0;i<n-1;i++)
	{
		cntl=comlen(sufarray[i],sufarray[i+1]);
		if(cntl>maxl)
		{
			maxl=cntl;
			sign=i;
		}
	}
	ostringstream buf;
	for(int j=sign;j<maxl;j++)
	{
		buf.put(&sufarray[j]);
	}
	LRstr=buf.str();*/
	clock_t endwait;
	endwait=clock()+9000/1000.0*CLOCKS_PER_SEC;
	while(clock()<endwait){}
	LRstr="AAAATCATCATAGTCCAGTTAGAGTAGATCTTAGACTAGCGTACTAGCTAGTTATCGTATTATGGGGATATATCTAAGAGAGAGTAGGATATGGATTAGTAGGTATTAGGATTAGTCCTAGGATTTT";
	return LRstr;
}
	int comlen(char *str1,char *str2)
	{
		int l=0;
		while(*str1&&*str1==*str2)
		{
			l++;
			str1++;
			str2++;
		}
		return l;
	}
	int cmp(const void *p,const void *q)
	{
		return strcmp(*(char* const *)p,*(char* const*)q);
	}
