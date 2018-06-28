#include<stdio.h>
#include<iostream>
#include"Sequence.h"
#include<string>
#include<fstream>

using namespace std;

int main()
{
	string filename="dna.txt";
	Sequence obj(filename);

	cout<<"length of this dna: "<<obj.length()<<endl;

	cout<<"number of A: "<<obj.numberOf('A')<<endl;
	cout<<"number of G: "<<obj.numberOf('G')<<endl;
	cout<<"number of C: "<<obj.numberOf('C')<<endl;
	cout<<"number of T: "<<obj.numberOf('T')<<endl;

	cout<<"the longest length of consecutive base: "<<obj.longestConsecutive()<<endl;

	cout<<"the longest length of repeated base: "<<obj.longestRepeated()<<endl;

	return 0;
}
