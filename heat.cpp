#include <iostream>
#include <sstream> 
#include <fstream>
#include<cmath>
#include<cstring>
using namespace std;
double gaussf(double wr, double count, double p){
	return 2.0*p/M_PI/wr*exp(-2.0*count/wr);
}

int main(){
	int ga;
	double qa;
	int a=0;
	int p=0;
	char fname[50];
	char fname2[50];
	double r=27.0/127.0;
	double CDL=0;
	double x=0, y=0, count=0, g=0;
	double XR=r, YR=r;
	double xy[500][250]={0.0}, X[500]={0.0}, Y[250]={0.0};
	double wr=pow(r,2);
	double dx, dy=2.0*r/250.0;
	printf("条件数を検索\n");
	// CSVファイルを開く
	FILE *fp = fopen( "input.csv" , "r" );
	// 例外
	if( fp == NULL ) {
		printf( "Error! File can not be opened\n" );
		return -1;
	}
	for(; fscanf(fp, "%d,%lf\n",&p, &CDL) != EOF; ){//出力，CDL値
		printf("%d\n",a+1);
		dx=(2.0*r+CDL)/500.0;
		for(int i=0;i<500;i++){ 
			if(XR>dx*500-r){
                                break;
                        }
			x=0;
			for(int j=0;j<500;j++){
				y=0;
				if(i==0){
					X[j]=x;
				}
				for(int k=0;k<250;k++){
					if(i==0&&j==0){
						Y[k]=y;
					}
					count=pow(x-XR,2)+pow(y-YR,2);
					if(count>=wr){
						xy[j][k]+=0;
					}else{
						xy[j][k]+=gaussf(wr,count,p);
					}
					y+=dy;
					count=0;
				}
				x+=dx;
			}
			XR+=dx;
		}		
		sprintf(fname, "CSV/output%d.csv", a+1);	
		ofstream ofs(fname);
		sprintf(fname2, "DATA/data%d.csv", a+1);
                ofstream ofs2(fname2);
		//CSV用
		ofs << " " << ", " << "y" << endl;
		ofs << "x" << ", " <<" "<< ",";
		for(int i=0; i<250; i++){
		ofs << Y[i] << ",";
		}
		ofs << endl;
		ofs << " " << ",";
		for(int j=0;j<500;j++){        
			ofs << X[j] << ",";
			for(int k=0;k<250;k++){        
				ofs << xy[j][k] << ",";
			}
			ofs << endl;
			ofs << " " << ",";
		}
		//DATA用
		for(int i=0;i<500;i++){
			for(int j=0;j<250;j++){
				ofs2 << X[i] << "," << Y[j] << "," <<xy[i][j] << "," << endl;
			}
		}
		ofs.close();
		ofs2.close();
		memset(fname, '\0', sizeof(fname));
		memset(fname2, '\0', sizeof(fname2));
		XR=r;
	a+=1;
	}

	//printf("%lf",xy[0][0]);
	return 0;
}
