 #include <iostream>
#include <cmath>
#include <string>
using namespace std;
//�洫 
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
			cout<<"�п�J�W�r(stu1/stu2)"<<endl;
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
			cout<<"��J���~"<<endl;
		}while(correct!=1);
		int c2=0,c1=0,done=0;
		do 
		{	
			cout<<endl;
			cout<<"1. ��J�Z��"<<endl; 
			cout<<"2. ��J���Z"<<endl;
			cout<<"3. �d���`��"<<endl;
			cout<<"4. �d�ݥ���"<<endl;
			cout<<"5. �d�ݼзǮt"<<endl;
			cout<<"6. �d�ݦ��Z�ƧǤγ̰��B�̧C��"<<endl; 
			cout<<"7. �Ѧ��Z�j�M���"<<endl; 
			cout<<"8. �Ѭ�طj�M���Z"<<endl; 
			cout<<"9. ���}/����"<<endl;
			cout<<"��J�ﶵ�s��";
			cin>>index;
			cout<<endl;
			if (index<1||index>9)
			{	
				cout<<"��J���~�A�Э��s��J"<<endl; 
				continue;
			}
			switch (index)
			{
				case 1:{
					
					test->get_classnum();
					cout<<"�A���Z�ŬO ";
					test->show_classnum();
					cout<<endl; 
					c1++;
					break;
				}
				case 2:
				{
					test->get_sub();
					cout<<endl<<"�A�����ƬO"<<endl;
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
						cout<<"�Х���J���Z"<<endl; 
					}
					else
					{
						cout<<endl<<"�A���`���O: ";
						test->show_sum();
						cout<<endl;
					}
					break;
				}
				
				case 4:
				{	if (c2==0)
					{
						cout<<"�Х���J���Z"<<endl; 
					}
					else
					{
						cout<<endl<<"�A�������O: ";test->show_aver();cout<<endl;
					}
					break;
				}	
			
				case 5:
				{
					if (c2==0)
					{
						cout<<"�Х���J���Z"<<endl; 
					}
					else
					{
						cout<<endl<<"�A���зǮt�O: ";test->show_std();cout<<endl;
					}
					break;
				}	
				case 6:
				{
					if (c2==0)
					{
						cout<<"�Х���J���Z"<<endl; 
					}
					else
					{
						cout<<endl<<"�A�����Z�ƧǬO: "<<endl ;
						test->show_sort();cout<<endl;
						test->show_maxmin();
					}
					break;
				}
				case 7:
				{
					if (c2==0)
					{
						cout<<"�Х���J���Z"<<endl; 
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
						cout<<"�Х���J���Z"<<endl; 
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
						cout<<"�п�J���Z"<<endl; 
						
					}
					else if(c1==0)
					{
						cout<<"�п�J�Z��"<<endl;					
						
					}
					else
						done++;
						continue;	
				}
			}
		}while(done==0);
		test=NULL;
 	}while(count!=3);
 	
 	cout<<"�m�W"<<'\t'<<"�Z��"<<'\t'; for(int i=0;i<4;i++){cout<<"��"<<i+1<<"�����"<<'\t';}cout<<"�`��"<<'\t'<<"����"<<'\t'<<"�зǮt"<<endl; 
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
//search (�Ѭ�ةΥѦ��Z) 
void Stu::searchf_num(){
	int i;
	cout<<"�n�j�M�ĴX�쪺����? (1~4)"<<endl; 
	cin>> i;
	if (i>4||i<1){
		cout<<"��J���~!"<<endl;
		}
	else {
		cout<<"��"<<i<<"��"<<subject[i-1]<<"��"<<endl;
	}
}	
void Stu::searchf_grade(){
	bool search=0;
	float x;
	cout<<"�n�j�M������:"<<endl;
	cin>> x; 
	for (int i=0;i<4;i++){
		if (x==subject[i]){
			cout<<x<<"������"<<i+1<<"�쪺����"<<endl; 
			search=1;
		}
	}
	if (search==0){
		cout<<"�L������"<<endl; 
	}
}
//�G���j�M 
void Stu::b_search(){
	float x=0;int count=0;
	int middle=0,bottom=0,top=3;
	bool found=false;
	cout<<"�n�j�M�h�֪����Z?";
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
		cout<<x<<"�O��"<<middle+1<<"�W�����Z" <<endl;
	}
	else{
		cout<<x<<"���b���Z��"<<endl;
	}
}
//���o��� 
void Stu::get_classnum(){
	int correct=0;
			do {classnum=0;
				cout<<"�п�J�Z�Žs��(1~5)"<<endl;
				cin>>classnum; 
				if (classnum<0||classnum>5)
				{	cout<<endl<<"��J���~"<<endl; 
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
			cout<<"�аݧA��"<<i+1<<"��X��?"<<endl;
			cin>>grade;
			if (grade>100||grade<0){
				cout<<"��J���~!"<<endl;
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
	cout<<"�̰�����"<<this->sort_sub[3]<<"��"<<endl<<endl;
	cout<<"�̧C����"<<this->sort_sub[0]<<"��"<<endl; 
}
