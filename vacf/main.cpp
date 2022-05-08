#include <fstream>
#include <iostream>
#include <cstdlib>
#include  <bits/stdc++.h>
using namespace std;
int main()
{
	   ifstream file;
	   ofstream outfile1;
	   ofstream outfile2;
	   double *TIME, *GOR; 
		  int datasize, Nbin, *Pcount;
	      cout<<"Enter size of datapoints: "<<endl;
	         cin>>datasize;
		    TIME = new double [datasize];
		    GOR = new double [datasize];
		    cout<<"Enter size of the bin "<<endl;
		    cin>>Nbin;
		    Pcount = new int [Nbin];
		    char inputfile[255];
	    cout<<"enter your input file name with extension"<<endl;
		//    cin.getline (inputfile,255);
		cin>>inputfile;
		    
	   double min, max,value1,value2;
	   int i=0;
	   int count;   
	   file.open(inputfile);
	   outfile1.open("OUT1.dat");
	   outfile2.open("OUT2.dat");

	         while(!file.eof())
                     {
		    file >> TIME[i] >> GOR[i];
		       cout << TIME[i] <<"\t" << GOR[i] <<endl; // echo of input / proof it works
		
  		       if(i==1)
			{
		        if(GOR[i] < GOR[i-1])
		        {
			min=GOR[i];
			max=GOR[i-1];
		        }
			else 
			{
			min=GOR[i-1];
			max=GOR[i];
			}
			}
		        
                       if(i>1)
			 {
                         if(GOR[i]<min)
				 min=GOR[i];
			 if(GOR[i]>max)
				 max=GOR[i];
			 } 

		          //system("pause");
			  //   file.close();
			  //      return 0;
			  //    
		        i++;
			count=i;
		       }
                       
///// BIN SIZE ////
//int Nbin=70;
double binlength=(max-min)/Nbin;
//double Pcount[60];
int l;
for(i=0;i<count;i++)
   {
    l= int (((GOR[i]-min)/binlength)+1);   
    Pcount[l]=Pcount[l]+1;
    cout<<"l="<<l<<endl;
   }

for(l=0;l<Nbin;l++)
   {
    cout<<min+(l*binlength)<<'\t'<<Pcount[l]<<endl;
    outfile1<<min+(l*binlength)<<'\t'<<Pcount[l]<<endl;
    outfile2<<min+(l*binlength)<<'\t'<<double (Pcount[l])/count<<endl;
   }
outfile1<<"minimum value="<<'\t'<<min<<endl;
outfile1<<"maximum value="<<'\t'<<max<<endl;
outfile2<<"minimum value="<<'\t'<<min<<endl;
outfile2<<"maximum value="<<'\t'<<max<<endl;
delete[] GOR;
delete[] TIME;
delete[] Pcount;
//file.close(inputfile);
//outfile1.close("OUT1.dat");
//outfile2.close("OUT2.dat");

}

