#include "autotest.h"

int main(){
	updatePos();
	readName();
	cout<<"��[Q]����ʼ��name.txt�е����ֽ��в�Ų���������[W]����������"<<"\n"; 
	while(1){
		if(KEY_DOWN('Q')){
			while(KEY_DOWN('Q'))Sleep(10);
			Start(); 
		}
		if(KEY_DOWN('W')){
			while(KEY_DOWN('W'))Sleep(10);
			Print();
		}
		Sleep(10);
	}
	return 0;
}
