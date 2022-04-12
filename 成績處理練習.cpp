 #include <iostream>
#include <cmath>
#include <string>
using namespace std;
//交換 
void swap(float &a,float &b){
	float temp=0;
	temp=a;a=b;b=temp;
}


class Stu{
	private:
		float name;
		float classnum;
		float sum;
		float aver;
		float subject[4];
		float std;
		float sort_sub[4];
	public:
		void get_classnum();
		void show_classnum(){cout<< classnum;}
		void get_sub();
		void show_sub();
		void show_sort();
		void show_sum(){cout<< sum;}
		void show_aver(){cout<< aver;}
		void show_std(){cout<< std;}
		void show_maxmin();
		
		void searchf_num();
		void searchf_grade();
		void b_search()	;	
		void sumf();
		void averf();
		void sdf();
		void sortf();
};

int main(){
	Stu *test=NULL,stu1,stu2;
	int index=0,correct=0,count=0;
	string s;
	do{
	
		do{
			correct=0;
			cout<<"請輸入名字(stu1/stu2)"<<endl;
			cin>>s; 
			if (s=="stu1")
			{	test=&stu1;
				correct=1;
				count+=1;
			break;
			}
			else if (s=="stu2")
			{	test=&stu2;
				correct=1;
				count+=2;
			break;
			}
			else
			cout<<"輸入錯誤"<<endl;
		}while(correct!=1);
		int c2=0,c1=0,done=0;
		do 
		{	
			cout<<endl;
			cout<<"1. 輸入班級"<<endl; 
			cout<<"2. 輸入成績"<<endl;
			cout<<"3. 查看總分"<<endl;
			cout<<"4. 查看平均"<<endl;
			cout<<"5. 查看標準差"<<endl;
			cout<<"6. 查看成績排序及最高、最低分"<<endl; 
			cout<<"7. 由成績搜尋科目"<<endl; 
			cout<<"8. 由科目搜尋成績"<<endl; 
			cout<<"9. 離開/完成"<<endl;
			cout<<"輸入選項編號";
			cin>>index;
			cout<<endl;
			if (index<1||index>9)
			{	
				cout<<"輸入錯誤，請重新輸入"<<endl; 
				continue;
			}
			switch (index)
			{
				case 1:{
					
					test->get_classnum();
					cout<<"你的班級是 ";
					test->show_classnum();
					cout<<endl; 
					c1++;
					break;
				}
				case 2:
				{
					test->get_sub();
					cout<<endl<<"你的分數是"<<endl;
					test->show_sub();
					test->sumf();test->averf();test->sdf();
					cout<<endl<<endl;
					c2++;
					break;
				}
				case 3:
				{	
					if (c2==0)
					{
						cout<<"請先輸入成績"<<endl; 
					}
					else
					{
						cout<<endl<<"你的總分是: ";
						test->show_sum();
						cout<<endl;
					}
					break;
				}
				
				case 4:
				{	if (c2==0)
					{
						cout<<"請先輸入成績"<<endl; 
					}
					else
					{
						cout<<endl<<"你的平均是: ";test->show_aver();cout<<endl;
					}
					break;
				}	
			
				case 5:
				{
					if (c2==0)
					{
						cout<<"請先輸入成績"<<endl; 
					}
					else
					{
						cout<<endl<<"你的標準差是: ";test->show_std();cout<<endl;
					}
					break;
				}	
				case 6:
				{
					if (c2==0)
					{
						cout<<"請先輸入成績"<<endl; 
					}
					else
					{
						cout<<endl<<"你的成績排序是: "<<endl ;
						test->show_sort();cout<<endl;
						test->show_maxmin();
					}
					break;
				}
				case 7:
				{
					if (c2==0)
					{
						cout<<"請先輸入成績"<<endl; 
					}
					else
					{
						test->searchf_grade();	
					}
					break;
				}	
				case 8:
				{
					if (c2==0)
					{
						cout<<"請先輸入成績"<<endl; 
					}
					else
					{
						test->searchf_num();	
					}
					break;
				}
				case 9:
				{
			
					if (c2==0)
					{
						cout<<"請輸入成績"<<endl; 
						
					}
					else if(c1==0)
					{
						cout<<"請輸入班級"<<endl;					
						
					}
					else
						done++;
						continue;	
				}
			}
		}while(done==0);
		test=NULL;
 	}while(count!=3);
 	
 	cout<<"姓名"<<'\t'<<"班級"<<'\t'; for(int i=0;i<4;i++){cout<<"第"<<i+1<<"科分數"<<'\t';}cout<<"總分"<<'\t'<<"平均"<<'\t'<<"標準差"<<endl; 
	cout<<"stu1"<<'\t';stu1.show_classnum();cout<<'\t'; stu1.show_sub();stu1.show_sum();cout<<'\t';stu1.show_aver();cout<<'\t';stu1.show_std();cout<<endl; 
	cout<<"stu2"<<'\t';stu2.show_classnum();cout<<'\t'; stu2.show_sub();stu2.show_sum();cout<<'\t';stu2.show_aver();cout<<'\t';stu2.show_std();cout<<endl; 
	
	delete [] test;	
	
	return 0;
}
//sum 

void Stu::sumf(){
	sum=0;
	for (int j=0;j<4;j++){
		sum+=subject[j];
	}
	
}
//aver

void Stu::averf(){
	aver=sum/4;
}
//std

void Stu::sdf(){
	int is=0;
	for (int i=0;i<4;i++){
		if(aver==subject[i])
			is++;
	}
		if (is==4)
			std=0;
		else{ 
			for (int i=0;i<4;i++){
			std+=pow((subject[i]-aver),2);
			}
			std=pow(std/4,0.5);
		}
}


//sort

void Stu::sortf(){
	int min;
	for (int s=0;s<4;s++){
		min=s;
		for (int i=s+1; i<4;i++){
			if (sort_sub[i]<sort_sub[min]){
				min=i;
			}
		}
		swap(sort_sub[s],sort_sub[min]);
			
	}
}
//search (由科目或由成績) 
void Stu::searchf_num(){
	int i;
	cout<<"要搜尋第幾科的分數? (1~4)"<<endl; 
	cin>> i;
	if (i>4||i<1){
		cout<<"輸入錯誤!"<<endl;
		}
	else {
		cout<<"第"<<i<<"科"<<subject[i-1]<<"分"<<endl;
	}
}	
void Stu::searchf_grade(){
	bool search=0;
	float x;
	cout<<"要搜尋的分數:"<<endl;
	cin>> x; 
	for (int i=0;i<4;i++){
		if (x==subject[i]){
			cout<<x<<"分為第"<<i+1<<"科的分數"<<endl; 
			search=1;
		}
	}
	if (search==0){
		cout<<"無此分數"<<endl; 
	}
}
//二分搜尋 
void Stu::b_search(){
	float x=0;int count=0;
	int middle=0,bottom=0,top=3;
	bool found=false;
	cout<<"要搜尋多少的成績?";
	cin>>x;
	do{
		if (this->sort_sub[middle]==x){
			found=true;
			break;
		}
		else if(this->sort_sub[middle]<x){
			bottom = ++middle;
			middle=(bottom+top)/2;
		}
		else {
			bottom = --middle;
			middle=(bottom+top)/2;
		}
	}while(middle<=top&&middle>=bottom);
	if (found==true){
		cout<<x<<"是第"<<middle+1<<"名的成績" <<endl;
	}
	else{
		cout<<x<<"不在成績中"<<endl;
	}
}
//取得資料 
void Stu::get_classnum(){
	int correct=0;
			do {classnum=0;
				cout<<"請輸入班級編號(1~5)"<<endl;
				cin>>classnum; 
				if (classnum<0||classnum>5)
				{	cout<<endl<<"輸入錯誤"<<endl; 
					continue;
				}
				correct=1;
				break;
			}while(correct!=1);
	}
void Stu::get_sub(){
	int j=4 ,i=0;					
		do{	
			float grade=0;
			cout<<"請問你第"<<i+1<<"科幾分?"<<endl;
			cin>>grade;
			if (grade>100||grade<0){
				cout<<"輸入錯誤!"<<endl;
				continue; }
			else {
			subject[i]=grade;	
			this->sort_sub[i]=grade;
			i++; }
		}while(i<j) ;	
	this->sortf();
}


void Stu::show_sub(){
	for(int i=0;i<4;i++){
		cout<<subject[i]<<'\t'<<'\t';
	}
}
void Stu::show_sort(){
	for(int i=0;i<4;i++){
		cout<<sort_sub[i]<<'\t'<<'\t';
	}
}
void Stu::show_maxmin(){
	cout<<"最高分為"<<this->sort_sub[3]<<"分"<<endl<<endl;
	cout<<"最低分為"<<this->sort_sub[0]<<"分"<<endl; 
}
