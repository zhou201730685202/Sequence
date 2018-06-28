#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Sequence
{
public:
	Sequence(string filename);
	~Sequence();
	int length();
	int numberOf(char base);
	string longestConsecutive();
	string longestRepeated();
	
private:
	string dna;
	ifstream DNA;
	int countA,countT,countC,countG;
};
#endif
