#include "autotest.h"

int main(){
	prefix="文哥F",suffix="",team_name="好基友"; 
	updatePos();
	cout<<"\n输入测号前缀（输入完以后按Enter）:";
	cin>>prefix;
	cout<<"\n输入战队名:";
	cin>>team_name;
	cout<<"\n输入最低等级（等级大于等于最低等级的保留，否则不保留）:";
	cin>>threshold_level;
	cout<<"\n输入最低粗评（粗评大于等于最低粗评的保留，否则不保留）:";
	cin>>threshold_score;
	cout<<"\n";
	cout<<"按空格键开始，再按空格键停止，按[Q]键根据粗评排序输出测号，按[W]键根据八围排序输出测号，按[E]键根据概率最高技能排序输出测号"<<"\n"; 
	while(1){
		if(KEY_DOWN(VK_SPACE)){
			while(KEY_DOWN(VK_SPACE))Sleep(10);
			Start();
		}
		if(KEY_DOWN('Q')){
			while(KEY_DOWN('Q'))Sleep(10);
			Print(0);
		}
		if(KEY_DOWN('W')){
			while(KEY_DOWN('W'))Sleep(10);
			Print(1);
		}
		if(KEY_DOWN('E')){
			while(KEY_DOWN('E'))Sleep(10);
			Print(2);
		}
		Sleep(10);
	}
	return 0;
}
