/*
 * try.cpp
 *
 *  Created on: 11-Apr-2018
 *      Author: Rajat
 */
#include <iostream>

using namespace std;

int n;  //Size of ref String
int refString[20];  // integer Reference String
int buffSize;      // size of the buffer
int j; //position of found element in the memory

bool is_it_there_in_memory(int refString, int memory[])
{
	for(int i =0 ; i<buffSize ; i++)
	{
		if(refString== memory[i])
		{
			j=i;
			return true;
		}
	}
	return false;
}

void shift(int memory[]) {
	  int temp;
      for(int i=j ;i>0;i--)
      {
    	  temp=memory[i];
    	  memory[i]=memory[i-1];
    	  memory[i-1]=temp;
      }
      cout<<endl;
  }

int main() {

	cout<<"Enter the size of reference String: ";
    cin>>n;

   cout<<"Enter the reference String:";
   for( int i=0 ; i<n ; i++)
   {
	   cin>>refString[i];
   }

   cout<<"Enter buffer size: ";
   cin>>buffSize;

   int memory[buffSize];

   int pageFault=0;
   int page_hit=0;

   int m=0;
   for( int i = buffSize-1; i>=0 ; i--)
   {
	   memory[i]=refString[m];
	   m++;
	   pageFault++;
   }

   cout<<"page fault after intitial iteration:  "<<pageFault<<endl;

   cout<<"Memory after intial iteration: "<<endl;
   for(int k=0;k<buffSize;k++)
   		   cout<<memory[k]<<" ";
   cout<<endl<<endl;

   for(int i=buffSize; i<n ; i++)
   {
	   int temp_var=refString[i];

	   if(is_it_there_in_memory(refString[i],memory))
	   {
		   	  shift(memory);

    		  memory[0]=temp_var;

 		      page_hit++;

		   	  cout<<"page hit: "<<page_hit<<" for "<<temp_var<<endl;

		   	  cout<<"Memory: "<<endl;

		   	  for(int k=0;k<buffSize;k++)
		   		  cout<<memory[k]<<" ";

		   	  cout<<endl<<endl;
	   }
	   else
	   {
	   	    int temp[buffSize];

	   	    for(int k=0;k<buffSize-1;k++)
	    	{
	   		   temp[k+1]=memory[k];
	   	    }

	   	    for(int k=0;k<buffSize;k++)
	   		   memory[k]=temp[k];

	   	    memory[0]=temp_var;

            pageFault++;

		    cout<<"page fault: "<<pageFault<<" for "<<temp_var<<endl;
		    cout<<"Memory: "<<endl;

		    for(int k=0;k<buffSize;k++)
			  cout<<memory[k]<<" ";

		    cout<<endl<<endl;
	   }
   }

   cout<<endl<<"Page Fault="<<pageFault;
   cout<<endl<<"Page Hit="<<page_hit;
   return 0;
}



//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1   buffsize =3
//1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6   buffsize=4
//2 3 4 2 1 3 7 5 4 3       buffsize=3



