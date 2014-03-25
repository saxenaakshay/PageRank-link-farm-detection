#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class links
{
 public:
 int source;
 int target;
};
int main()
{
     system("cls");
     ifstream ifile;
     int output, j, i=0,k, maxm=0;
     links l[100];
     ifile.open("db.txt");
     while (!ifile.eof())
     {
            ifile>>output;
          if (output>maxm)
            maxm=output;
          l[i].source=output;
          ifile>>output;
          l[i++].target=output;
            if (output>maxm)
            maxm=output;

     }
 ifile.close();
 for ( j=0; j<i-1; j++)
 {
     cout<<"\nSource: "<<l[j].source<<" Target: "<<l[j].target;
 }

 cout<<"\n\nTotal Webpages: "<<maxm;
cout<<i<<"\n"<<1/maxm;

 double *mylinks=new double[maxm];
 double *pageRank=new double[maxm];

 for (j=0; j<maxm; j++)// for all webpages
 {
     mylinks[j]=0;
     pageRank[j]=1.0/maxm;
     for (k=0; k<i-1; k++)
     {
      if (l[k].source==j+1) mylinks[j]++;
     }
   cout<<"\nTOTAL OUTBOUND PAGES FROM "<<j+1<<": "<<mylinks[j]<<"   PAGERANK: "<<pageRank[j];
 }
 double allpages;

 for (int g=0; g<40; g++)
 {


 for (j=0;j<maxm; j++)
 {
     allpages=0;
     for (k=0; k<i-1; k++)
     {
         if (l[k].target==j+1)
            {
            allpages+=pageRank[l[k].source-1]/mylinks[l[k].source-1];
            }
     }
     //cout<<"\nALLPAGES: "<<allpages;
     pageRank[j]=(0.15/maxm)+(0.85*allpages);

 }
 cout<<"\nITERATION "<<g+1<<"\n";
 double total=0;
 for (j=0; j<maxm; j++){
 cout<<"\nPAGERANK OF "<<j+1<<": "<<pageRank[j]; total+=pageRank[j];}
 cout<<endl<<total<<endl<<endl;
 }
 return 0;

}
