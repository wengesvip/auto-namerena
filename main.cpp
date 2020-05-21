#include "autotest.h"

int main(){
	updatePos();
	readName();
	cout<<"按[Q]键开始对name.txt中的名字进行测号并分析，按[W]键进入排序"<<"\n"; 
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
