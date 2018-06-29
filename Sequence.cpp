#include<stdio.h>
#include<stdlib.h>
#include"Sequence.h"
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>

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

int cmp(const void* p,const void* q)
{
	return strcmp(*(const char**)p,*(const char**)q);
}
int comlen(char *p,char *q)
{
	int n=0;
	while(*p&&(*p++ == *q++))
		++n;
	return n;
}
char str[1200000];
char* sstr[1200000];
string Sequence::longestRepeated()
{
	string LRstr;
	int maxl=0;
	int cntl=0;
	int sign=0;
	for(int i=0;i<len;i++)
	{
		sstr[i]=&str[i];
		str[i]=dna[i];
	}
	str[len]=0;
	qsort(sstr,len,sizeof(char*),cmp);
	for(int i=0;i<len-1;i++)
	{
		cntl=comlen(sstr[i],sstr[i+1]);
		if(cntl>maxl)
		{
			maxl=cntl;
			sign=i;
		}
	}
	LRstr.assign(sstr[sign],maxl);
	return LRstr;
}
