#include<stdio.h>
#include<stdlib.h>
#include"Sequence.h"
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>

#define MAX 10010

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
	//cout<<dna;
}


Sequence::~Sequence()
{
	DNA.close();
}

int Sequence::length()
{
	return dna.length();
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
	for(int i=0;i<dna.length();i++)
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
	
}
