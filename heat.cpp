#include <iostream>
#include <sstream> 
#include <fstream>
#include<cmath>
#include<cstring>
using namespace std;
//ofstream ofs("output.csv");

double gaussf(double wr, double count, double p){
	return 2.0*p/M_PI/wr*exp(-2.0*count/wr);
	}
int main(){
	int a;
	int p[200]={};
	char fname[30];
	double r=27.0/127.0;
	double CDL[200]={};
	double x=0, y=0, count=0, g=0;
	double XR=r, YR=r;
	double xy[500][25]={0}, X[500]={0}, Y[250]={0};
	double wr=pow(r,2);
       	double dx, dy=2.0*r/250.0;
	printf("条件数を入力\n");
	scanf("%d", &a);
	// CSVファイルを開く
	FILE * fp = fopen( "input.csv" , "r" );
	// 例外
	if( fp == NULL ) {
		printf( "Error! File can not be opened\n" );
		return -1;
	}
	for(int b=0; fscanf(fp, "%d,%lf\n",&p[b], &CDL[b]) != EOF; b++){//出力，CDL値
	}
	for(int h=0; h=a+1; h++){
		dx=(2.0*r+CDL[h])/500.0;
			for(int i=0;i<1;i++){
			printf("%d\n",i);
			for(int j=0;j<500;j++){
				if(i==0){
					X[j]=x;
				}
				for(int k=0;k<250;k++){
					if(i==0&&j==0){
						Y[k]=y;
					}
					count=pow(x-XR,2)+pow(y-YR,2);
					if(count>wr){
						xy[j][k]+=0;
					}else{
						xy[j][k]+=gaussf(wr,count,p[h]);
						//printf("[x%d],[y%d],%lf\n",j,k,xy[j][k]);
					}
					y+=dy;
					count=0;
				}
				y=0;
				x+=dx;
			}
			x=0;
			XR+=dx;
		}
		sprintf(fname, "output%d.csv", h);	
		ofstream ofs(fname);
		//FILE * ofs = fopen( "output%d.csv" , "w", &h ) ;	
		ofs << " " << ", " << "y" << endl;
		ofs << "x" << ", ";
		for(int i=0; i<250; i++){
			ofs << Y[i] << ",";
		}
		ofs << endl;
		for(int j=0;j<500;j++){        
			ofs << X[j] << ",";
			for(int k=0;k<250;k++){        
				ofs << xy[j][k] << ",";
			}
			ofs << endl;
		}
		memset(fname, '\0', sizeof(fname));
	}	
	//printf("%lf",xy[0][0]);
	return 0;
}
